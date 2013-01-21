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

  // Exported permission: delete terms in 1.
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 1.
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
