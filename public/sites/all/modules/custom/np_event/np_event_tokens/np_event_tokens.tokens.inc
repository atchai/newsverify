<?php

/**
 * @file
 * Token callbacks for the np_event_token module.
 */

/**
 * Implements hook_token_info().
 *
 */
function np_event_tokens_token_info() {
  // Node tokens.
  $info['tokens']['node']['sources'] = array(
    'name' => t('Event author source nids'),
    'description' => t('A list of sources that contribute to this node'),
  );

  return $info;
}

/**
 * Implements hook_tokens().
 *
 */
function np_event_tokens_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  // Node tokens.
  if ($type == 'node' && !empty($data['node'])) {
    $node = $data['node'];
    if ($node->type != 'event') {
      return;
    }
    
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'sources':
          $replacements[$original] = '';
          $authors = _np_event_tokens_author_nids_by_event_id($node->nid);
          if (count($authors)) {
            $replacements[$original] = implode(',', $authors);
          }
          break;
      }
    }
  }
  return $replacements;
}

function _np_event_tokens_author_nids_by_event_id($event_nid) {
  $query = '
    (
      select 
        na.nid
      from 
        node na 
      inner join 
        field_data_field_post_author pa on na.nid = pa.field_post_author_target_id and pa.deleted = 0
      inner join 
        node np on pa.entity_id = np.nid and pa.revision_id = np.vid 
      inner join 
        field_data_field_when_posts posts_when on np.nid = posts_when.field_when_posts_target_id and posts_when.deleted = 0
      inner join 
        node ne on posts_when.entity_id = ne.nid and posts_when.revision_id = ne.vid 
      where
        1 = 1 
        and ne.nid = :event_nid
    )
    union
    (
      select 
        na.nid
      from 
        node na 
      inner join 
        field_data_field_post_author pa on na.nid = pa.field_post_author_target_id and pa.deleted = 0
      inner join 
        node np on pa.entity_id = np.nid and pa.revision_id = np.vid 
      inner join 
        field_data_field_where_posts posts_where on np.nid = posts_where.field_where_posts_target_id and posts_where.deleted = 0
      inner join 
        node ne on posts_where.entity_id = ne.nid and posts_where.revision_id = ne.vid 
      where
        1 = 1 
        and ne.nid = :event_nid
     )
     union
     (
       select 
         na.nid
       from 
         node na 
       inner join 
         field_data_field_post_author pa on na.nid = pa.field_post_author_target_id and pa.deleted = 0
       inner join 
         node np on pa.entity_id = np.nid and pa.revision_id = np.vid 
       inner join 
         field_data_field_what_posts posts_what on np.nid = posts_what.field_what_posts_target_id and posts_what.deleted = 0
       inner join 
         node ne on posts_what.entity_id = ne.nid and posts_what.revision_id = ne.vid 
       where
         1 = 1 
         and ne.nid = :event_nid
     );
  ';
  
  $result = db_query($query, array(':event_nid' => array($event_nid)));
  return $result->fetchCol();
}
