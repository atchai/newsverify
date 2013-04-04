<?php
/**
 * @file
 * np_author.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function np_author_user_default_permissions() {
  $permissions = array();

  // Exported permission: create author content.
  $permissions['create author content'] = array(
    'name' => 'create author content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any author content.
  $permissions['delete any author content'] = array(
    'name' => 'delete any author content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own author content.
  $permissions['delete own author content'] = array(
    'name' => 'delete own author content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 3.
  $permissions['delete terms in 3'] = array(
    'name' => 'delete terms in 3',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 4.
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any author content.
  $permissions['edit any author content'] = array(
    'name' => 'edit any author content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own author content.
  $permissions['edit own author content'] = array(
    'name' => 'edit own author content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in 3.
  $permissions['edit terms in 3'] = array(
    'name' => 'edit terms in 3',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 4.
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
