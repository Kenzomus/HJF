<?php
/**
 * @file
 * hjffeatures.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function hjffeatures_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'acquia_search_server_1';
  $environment->name = 'Acquia Search';
  $environment->url = 'http://useast1-c6.acquia-search.com/solr/EJVX-55996';
  $environment->service_class = 'AcquiaSearchService';
  $environment->conf = array(
    'apachesolr_search_facet_pages' => '',
    'apachesolr_search_show_facets' => 1,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'announcement_type',
      1 => 'article',
      2 => 'clients',
      3 => 'content_slider',
      4 => 'events',
      5 => 'faq',
      6 => 'funding_opportunity',
      7 => 'page',
      8 => 'panel',
      9 => 'program',
      10 => 'rads',
      11 => 'services',
      12 => 'sponsor',
      13 => 'srvices_category',
      14 => 'succes_story',
      15 => 'webform',
    ),
  );
  $export['acquia_search_server_1'] = $environment;

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'localhost server';
  $environment->url = 'http://localhost:8983/solr';
  $environment->service_class = '';
  $environment->conf = array();
  $environment->index_bundles = array(
    'node' => array(
      0 => 'announcement_type',
      1 => 'article',
      2 => 'clients',
      3 => 'content_slider',
      4 => 'events',
      5 => 'faq',
      6 => 'funding_opportunity',
      7 => 'job_post',
      8 => 'news',
      9 => 'page',
      10 => 'panel',
      11 => 'program',
      12 => 'rads',
      13 => 'research_program',
      14 => 'rockville_pike',
      15 => 'services',
      16 => 'sponsor',
      17 => 'srvices_category',
      18 => 'succes_story',
      19 => 'webform',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
