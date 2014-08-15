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
        'last_changed' => '1408122108',
        'last_entity_id' => '216',
      ),
    ),
    'apachesolr_index_updated' => 1408122991,
    'apachesolr_last_optimize' => 1408122991,
    'apachesolr_search_facet_pages' => '',
    'apachesolr_search_show_facets' => 1,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'announcement_type',
      1 => 'article',
      2 => 'clients',
      3 => 'events',
      4 => 'funding_opportunity',
      5 => 'page',
      6 => 'panel',
      7 => 'program',
      8 => 'rads',
      9 => 'services',
      10 => 'sponsor',
      11 => 'srvices_category',
      12 => 'succes_story',
      13 => 'webform',
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
      4 => 'funding_opportunity',
      5 => 'page',
      6 => 'panel',
      7 => 'program',
      8 => 'rads',
      9 => 'rockville_pike',
      10 => 'services',
      11 => 'sponsor',
      12 => 'srvices_category',
      13 => 'succes_story',
      14 => 'webform',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
