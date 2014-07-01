from fabric.context_managers import cd
from fabric.context_managers import settings
from fabric.operations import run


class deploy:

    def __init__(self, uri, path, public_path='/public'):
        self.uri = uri
        self.path = path
        self.public = path + public_path

    def drush(self, cmd, ignore_error=False):
        with settings(warn_only=ignore_error):
            run('drush --uri=\'%s\' --root=\'%s\' %s -y' %
                (self.uri, self.public, cmd,))

    # def install(
    #     self, db_user='test', db_pass='test', db_host='localhost', db_name='test', locale='en-GB', subdir='',
    #     site_name='Test', admin_user='Admin', admin_pass='password'):
    #     self.drush('si minimal --db-url=\'mysql://%s:%s@%s/%s\' --locale=\'%s\' --sites-subdir=\'%s\' --site-name=\'%s\' --account-name=\'%s\' --account-pass=\'%s\''
    #                % (db_user, db_pass, db_host, db_name, locale, subdir, site_name, admin_user, admin_pass,))

    # def test(self, php='/usr/bin/php'):
    #     self.drush('en simpletest')
    #     run('cd %s; php ./scripts/run-tests.sh --php %s --url http://%s --all' %
    #         (self.public, php, self.uri,))
