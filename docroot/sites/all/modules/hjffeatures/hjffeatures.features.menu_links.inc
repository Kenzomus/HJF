<?php
/**
 * @file
 * hjffeatures.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function hjffeatures_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_:Funding_parameters
  $menu_links['main-menu_:Funding_parameters'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'Funding_parameters',
    'router_path' => 'Funding_parameters',
    'link_title' => '',
    'options' => array(
      'identifier' => 'main-menu_:Funding_parameters',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: main-menu_:contact_research_initiatives_office
  $menu_links['main-menu_:contact_research_initiatives_office'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'contact_research_initiatives_office',
    'router_path' => 'contact_research_initiatives_office',
    'link_title' => '',
    'options' => array(
      'identifier' => 'main-menu_:contact_research_initiatives_office',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 7,
    'customized' => 1,
  );
  // Exported menu link: main-menu_contact-us:http://hjfdev.devcloud.acquia-sites.com/contact_research_initiatives_office
  $menu_links['main-menu_contact-us:http://hjfdev.devcloud.acquia-sites.com/contact_research_initiatives_office'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://hjfdev.devcloud.acquia-sites.com/contact_research_initiatives_office',
    'router_path' => '',
    'link_title' => 'Contact Us',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_contact-us:http://hjfdev.devcloud.acquia-sites.com/contact_research_initiatives_office',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 8,
    'customized' => 1,
  );
  // Exported menu link: main-menu_home:<front>
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: management_administration-menu:admin/config/administration/admin_menu
  $menu_links['management_administration-menu:admin/config/administration/admin_menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/administration/admin_menu',
    'router_path' => 'admin/config/administration/admin_menu',
    'link_title' => 'Administration menu',
    'options' => array(
      'attributes' => array(
        'title' => 'Adjust administration menu settings.',
      ),
      'identifier' => 'management_administration-menu:admin/config/administration/admin_menu',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin/config/administration',
  );
  // Exported menu link: management_advanced-help:admin/advanced_help
  $menu_links['management_advanced-help:admin/advanced_help'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/advanced_help',
    'router_path' => 'admin/advanced_help',
    'link_title' => 'Advanced help',
    'options' => array(
      'identifier' => 'management_advanced-help:admin/advanced_help',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 9,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_current-search-blocks:admin/config/search/current_search
  $menu_links['management_current-search-blocks:admin/config/search/current_search'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/current_search',
    'router_path' => 'admin/config/search/current_search',
    'link_title' => 'Current search blocks',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure current search blocks.',
      ),
      'identifier' => 'management_current-search-blocks:admin/config/search/current_search',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_search-and-metadata:admin/config/search',
  );
  // Exported menu link: management_date-popup:admin/config/date/date_popup
  $menu_links['management_date-popup:admin/config/date/date_popup'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/date/date_popup',
    'router_path' => 'admin/config/date/date_popup',
    'link_title' => 'Date Popup',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the Date Popup settings.',
      ),
      'identifier' => 'management_date-popup:admin/config/date/date_popup',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_date-api:admin/config/date',
  );
  // Exported menu link: management_jquery-update:admin/config/development/jquery_update
  $menu_links['management_jquery-update:admin/config/development/jquery_update'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/jquery_update',
    'router_path' => 'admin/config/development/jquery_update',
    'link_title' => 'jQuery update',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure settings related to the jQuery upgrade, the library path and compression.',
      ),
      'identifier' => 'management_jquery-update:admin/config/development/jquery_update',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_development:admin/config/development',
  );
  // Exported menu link: management_main-menu:admin/structure/menu/manage/main-menu
  $menu_links['management_main-menu:admin/structure/menu/manage/main-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/main-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Main menu',
    'options' => array(
      'identifier' => 'management_main-menu:admin/structure/menu/manage/main-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: management_management:admin/structure/menu/manage/management
  $menu_links['management_management:admin/structure/menu/manage/management'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/management',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Management',
    'options' => array(
      'identifier' => 'management_management:admin/structure/menu/manage/management',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: management_migrate-fields:admin/structure/content_migrate
  $menu_links['management_migrate-fields:admin/structure/content_migrate'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/content_migrate',
    'router_path' => 'admin/structure/content_migrate',
    'link_title' => 'Migrate fields',
    'options' => array(
      'attributes' => array(
        'title' => 'Migrate field settings and data from the Drupal 6 version to the Drupal 7 version.',
      ),
      'identifier' => 'management_migrate-fields:admin/structure/content_migrate',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_navigation:admin/structure/menu/manage/navigation
  $menu_links['management_navigation:admin/structure/menu/manage/navigation'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/navigation',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Navigation',
    'options' => array(
      'identifier' => 'management_navigation:admin/structure/menu/manage/navigation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: management_search-api:admin/config/search/search_api
  $menu_links['management_search-api:admin/config/search/search_api'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/search_api',
    'router_path' => 'admin/config/search/search_api',
    'link_title' => 'Search API',
    'options' => array(
      'attributes' => array(
        'title' => 'Create and configure search engines.',
      ),
      'identifier' => 'management_search-api:admin/config/search/search_api',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_search-and-metadata:admin/config/search',
  );
  // Exported menu link: management_trigger-scheduler:admin/config/system/job_scheduler
  $menu_links['management_trigger-scheduler:admin/config/system/job_scheduler'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/job_scheduler',
    'router_path' => 'admin/config/system/job_scheduler',
    'link_title' => 'Trigger scheduler',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure timely triggers',
      ),
      'identifier' => 'management_trigger-scheduler:admin/config/system/job_scheduler',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_system:admin/config/system',
  );
  // Exported menu link: management_trigger-scheduler:admin/config/system/job_scheduler/add
  $menu_links['management_trigger-scheduler:admin/config/system/job_scheduler/add'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/job_scheduler/add',
    'router_path' => 'admin/config/system/job_scheduler/add',
    'link_title' => 'Trigger scheduler',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure timely triggers',
      ),
      'identifier' => 'management_trigger-scheduler:admin/config/system/job_scheduler/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_trigger-scheduler:admin/config/system/job_scheduler',
  );
  // Exported menu link: management_user-menu:admin/structure/menu/manage/user-menu
  $menu_links['management_user-menu:admin/structure/menu/manage/user-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/user-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'User menu',
    'options' => array(
      'identifier' => 'management_user-menu:admin/structure/menu/manage/user-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: navigation_funding-ops:funding_opportunity_panels
  $menu_links['navigation_funding-ops:funding_opportunity_panels'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'funding_opportunity_panels',
    'router_path' => 'funding_opportunity_panels',
    'link_title' => 'Funding Ops',
    'options' => array(
      'identifier' => 'navigation_funding-ops:funding_opportunity_panels',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Administration menu');
  t('Advanced help');
  t('Contact Us');
  t('Current search blocks');
  t('Date Popup');
  t('Funding Ops');
  t('Home');
  t('Main menu');
  t('Management');
  t('Migrate fields');
  t('Navigation');
  t('Search API');
  t('Trigger scheduler');
  t('User menu');
  t('jQuery update');


  return $menu_links;
}
