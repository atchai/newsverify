#
# Newsverify Fabfile #
#
# Requires: fabric 1.3.2 or above.
#
# References: http://docs.fabfile.org/en/1.9/usage/fab.html
#
# Defines the newsverify deployment process via fabric.
# Consider this file as a starting point to define a deployment process
# bespoke for your specific newsverify instance.
#
# Your deploy command will be
#   fab -f <fabfile_path> --hosts=<hosts> <serv_conf_task> <op_task>
#
# <hosts> is a comma-delimited list of host strings (http://docs.fabfile.org/en/1.9/usage/fab.html#cmdoption-H)
#
# <serv_conf_task> is a Server Configuration task which is used to define
# server-specific configurations (branch to clone, db connection parameters and so on)
#
# <op_task> is an Operation task which is used to define the operations
# that have to be performed by the deploy.
#
# Tipycally you won't need to change the Operations tasks below. Thus your cloned fabfile
# will just have to re-define the proper Server Configuration tasks.
#
# If your fabric file will have to work on different environments you might want to use
# the --set option to set default values for arbitrary Fabric env vars instead of hardcoding
# them in the Server Configuration section.
# The --set option is supported only by fabric 1.4 or above.
# See: http://docs.fabfile.org/en/1.9/usage/fab.html#cmdoption--set .
#

from fabric.state import env
from fabric.context_managers import settings
from fabric.operations import run
import drupal


#
# Server Configuration #
#
def default():
    env['repo_url'] = 'git@github.com:atchai/newsverify.git'
    env['repo_path'] = '/var/www/newsverify'
    env['repo_branch'] = 'dev'

    # Define the Drupal sites that have to be deployed
    env['sites'] = {
        # sites_subdir: {site_language, core_modules}
        'snp': {'sites_language': ['ar'], 'core_modules': ['snp_core']},
        'demo': {'sites_language': ['en'], 'core_modules': ['demo_core']},
    }


def dev():
    default()
    env['repo_path'] = '~/Sites/newsverify'


def stage():
    default()
    # Placeholder


def production():
    default()
    # Placeholder


#
# Operations #
#
def pull(repo):
    # TODO clone the repo if it hasn't been cloned yet
    # with settings(warn_only=True):
        # if run('test -d %s/.git' % env['repo_path']).failed:
        #     run('git clone -b %s %s %s' % (env['repo_branch'], env['repo_url'], env['repo_path'],))

    run('cd %s; git pull' % env['repo_path'])


def update():
    """ Update site (enabling modules, reverting features, running DB updates) """
    deploy_handlers = {}

    print "\n>>Set maintenance mode\n"

    # Initialise deploy handlers and set maintenance mode
    for current_site in env['sites'].iterkeys():
        deploy_handlers[current_site] =\
            drupal.deploy(current_site, env['repo_path'])
        deploy_handlers[current_site]\
            .drush('vset --always-set maintenance_mode 1')
        deploy_handlers[current_site].drush('cc all')

    # Pull from git repo (master branch)
    print "\n>>Pull code changes.\n"
    pull(env['repo_url'])

    print "\n>>Run Drupal deployment steps.\n"

    # Run deployment steps for every sites
    for current_site, current_site_info in env['sites'].iteritems():
        print "\n>>Current site:%s\n" % current_site

        # Enable all modules (previously enabled modules will be ignored by
        # drush)
        deploy_handlers[current_site].drush('en %s' % (' ')
                                            .join(current_site_info['core_modules']))

        # Run any pending database updates
        deploy_handlers[current_site].drush('updatedb')

        # Database updates may have applied changes that require a cache clear
        deploy_handlers[current_site].drush('cc all')

        # Revert all features
        deploy_handlers[current_site].drush('features-revert-all')

    # Unset maintenance mode
    print "\n>>Unset maintenance mode\n"
    for current_site in env['sites'].iterkeys():
        deploy_handlers[current_site]\
            .drush('vset --always-set maintenance_mode 0')
        deploy_handlers[current_site].drush('cc all')
