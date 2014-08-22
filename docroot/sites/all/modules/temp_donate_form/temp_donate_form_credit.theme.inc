<?php

/**
 * @file
 * Theme functions for the uc_credit module.
 */

/**
 * Themes the credit card CVV help link.
 */
function temp_donate_form_theme_donate_credit_cvv_help($variables) {
  $output = '<div class="uc-credit-cvv-help">';
  $output .= theme('image', array('path' => drupal_get_path('module', 'donate') . '/images/info.png'));
  $output .= ' ' . l(t("What's the Security code?"), 'donate/credit-cart/cvv-info', array('attributes' => array(
    'onclick' => "window.open(this.href, 'CVV_Info', 'toolbar=0,scrollbars=1,location=0,statusbar=0,menubar=0,resizable=1,width=480,height=460'); return false;",
  )));
  $output .= '</div>';

  return $output;
}
