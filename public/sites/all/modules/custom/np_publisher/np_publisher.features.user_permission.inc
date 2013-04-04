<?php
/**
 * @file
 * np_publisher.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function np_publisher_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer menu.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'menu',
  );

  return $permissions;
}
