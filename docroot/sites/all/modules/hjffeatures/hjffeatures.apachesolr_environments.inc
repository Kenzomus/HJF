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
    'apachesolr_index_last' => array(
      'node' => array(
        'last_changed' => '1408634703',
        'last_entity_id' => '306',
      ),
    ),
    'apachesolr_index_updated' => 0,
    'apachesolr_last_optimize' => 1408673942,
    'apachesolr_search_facet_pages' => '',
    'apachesolr_search_show_facets' => 1,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'announcement_type',
      1 => 'article',
      2 => 'clients',
      3 => 'events',
      4 => 'faq',
      5 => 'funding_opportunity',
      6 => 'page',
      7 => 'panel',
      8 => 'program',
      9 => 'rads',
      10 => 'services',
      11 => 'sponsor',
      12 => 'srvices_category',
      13 => 'succes_story',
      14 => 'webform',
    ),
  );
  $export['acquia_search_server_1'] = $environment;

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'localhost server';
  $environment->url = 'http://localhost:8983/solr';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_index_last' => array(),
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'announcement_type',
      1 => 'article',
      2 => 'clients',
      3 => 'events',
      4 => 'faq',
      5 => 'funding_opportunity',
      6 => 'page',
      7 => 'panel',
      8 => 'program',
      9 => 'rads',
      10 => 'research_program',
      11 => 'rockville_pike',
      12 => 'services',
      13 => 'sponsor',
      14 => 'srvices_category',
      15 => 'succes_story',
      16 => 'webform',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
