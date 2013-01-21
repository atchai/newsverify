<?php
/**
 * @file
 * np_post.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function np_post_user_default_permissions() {
  $permissions = array();

  // Exported permission: create post content.
  $permissions['create post content'] = array(
    'name' => 'create post content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any post content.
  $permissions['edit any post content'] = array(
    'name' => 'edit any post content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own post content.
  $permissions['edit own post content'] = array(
    'name' => 'edit own post content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
