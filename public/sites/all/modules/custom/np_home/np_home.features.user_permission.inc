<?php
/**
 * @file
 * np_home.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function np_home_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer nodequeue'.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'manipulate all queues'.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'manipulate queues'.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'nodequeue',
  );

  return $permissions;
}
