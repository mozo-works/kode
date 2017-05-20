<?php

/**
 * @file
 * Custom theme hooks.
 */

function one_theme_suggestions_page_alter(array &$suggestions, array $variables) {
  $current_path = \Drupal::service('path.current')->getPath();
  $result = \Drupal::service('path.alias_manager')->getAliasByPath($current_path);

  $path_alias = trim($result, '/');
  $path_alias = str_replace(['/','-'], '_', $path_alias);

  $suggestions[] = 'page__'.$path_alias;
}
