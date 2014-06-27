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

  // Exported permission: 'create author content'.
  $permissions['create author content'] = array(
    'name' => 'create author content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any author content'.
  $permissions['delete any author content'] = array(
    'name' => 'delete any author content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own author content'.
  $permissions['delete own author content'] = array(
    'name' => 'delete own author content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in author_rating'.
  $permissions['delete terms in author_rating'] = array(
    'name' => 'delete terms in author_rating',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in verification_status'.
  $permissions['delete terms in verification_status'] = array(
    'name' => 'delete terms in verification_status',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any author content'.
  $permissions['edit any author content'] = array(
    'name' => 'edit any author content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own author content'.
  $permissions['edit own author content'] = array(
    'name' => 'edit own author content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in author_rating'.
  $permissions['edit terms in author_rating'] = array(
    'name' => 'edit terms in author_rating',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in verification_status'.
  $permissions['edit terms in verification_status'] = array(
    'name' => 'edit terms in verification_status',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
