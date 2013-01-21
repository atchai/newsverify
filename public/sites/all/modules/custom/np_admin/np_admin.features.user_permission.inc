<?php
/**
 * @file
 * np_admin.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function np_admin_user_default_permissions() {
  $permissions = array();

  // Exported permission: view the administration theme.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'system',
  );

  return $permissions;
}
