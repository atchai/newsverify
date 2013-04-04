<?php
/**
 * @file
 * np_admin.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function np_admin_user_default_roles() {
  $roles = array();

  // Exported role: Administrator.
  $roles['Administrator'] = array(
    'name' => 'Administrator',
    'weight' => '2',
  );

  return $roles;
}
