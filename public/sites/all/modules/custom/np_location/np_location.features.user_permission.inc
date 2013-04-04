<?php
/**
 * @file
 * np_location.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function np_location_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete terms in 2.
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 2.
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
