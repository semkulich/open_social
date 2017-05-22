<?php

use Drupal\Core\StringTranslation\TranslatableMarkup;
use Drupal\Core\Link;

/**
 * Implements hook_preprocess_activity().
 * @param $variables
 */
function socialbase_preprocess_activity(&$variables) {
  // Check if the view mode is one of the notification view modes.
  if (in_array($variables['content']['field_activity_output_text']['#view_mode'], array(
    'notification',
    'notification_archive'
  ))) {
    // Remove href from date.
    if (!empty($variables['date']) && is_object($variables['date'])) {
      if ($variables['date'] instanceof TranslatableMarkup) {
        $variables['date'] = strip_tags($variables['date']->__toString());
      } elseif ($variables['date'] instanceof Link) {
        $variables['date'] = strip_tags($variables['date']->toString());
      }
    }
    // Remove href from output text.
    $variables['content']['field_activity_output_text'][0]['#text'] = strip_tags($variables['content']['field_activity_output_text'][0]['#text']);
    // Remove href from profile image.
    if (!empty($variables['actor'])) {
      if (is_object($variables['actor'])) {
        $variables['actor'] = $variables['actor']->getText();
      }
    }
  }
}
