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

  // Exported permission: 'delete terms in location'.
  $permissions['delete terms in location'] = array(
    'name' => 'delete terms in location',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in location'.
  $permissions['edit terms in location'] = array(
    'name' => 'edit terms in location',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
