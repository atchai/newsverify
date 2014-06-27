<?php
/**
 * @file
 * np_story.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function np_story_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create story content'.
  $permissions['create story content'] = array(
    'name' => 'create story content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any story content'.
  $permissions['delete any story content'] = array(
    'name' => 'delete any story content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own story content'.
  $permissions['delete own story content'] = array(
    'name' => 'delete own story content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any story content'.
  $permissions['edit any story content'] = array(
    'name' => 'edit any story content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own story content'.
  $permissions['edit own story content'] = array(
    'name' => 'edit own story content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
