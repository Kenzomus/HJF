<?php
/**
 * @file
 * hjffeatures.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function hjffeatures_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'contact_service';
  $content->admin_title = 'Contact us';
  $content->admin_description = 'e-mail and phone for each service';
  $content->category = 'Service.each e-mail and phone for each service';
  $content->settings = array(
    'admin_title' => 'Contact us',
    'title' => 'Contact Us',
    'body' => '<p>E-mail : %node:field_contact_email</p>

<p>Phone :%node:field_contact_phone</p>
',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $export['contact_service'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'funding_folder';
  $content->admin_title = 'Funding ';
  $content->admin_description = 'using a custom content to add the header of the funding project instead of creating it as a content type';
  $content->category = 'funding_folder_cat';
  $content->settings = array(
    'admin_title' => 'funding folder',
    'title' => 'Funding ',
    'body' => '<div>
<p>HJF has made it easier for you to locate upcoming funding opportunities from various sponsors. We believe the select funding opportunities published on this page are most relevant to our military medical researchers.</p>

<p>Use the table below to find a research funding opportunity. You can click on each column heading to sort the list or use your browser\'s search capability to look for keywords. Click on the opportunity number to open the specific solicitation and learn more.</p>

<p>HJF will continually update the list with new opportunities. You can be added to our email notification list by <a href="http://hjfdev.devcloud.acquia-sites.com/contact_research_initiatives_office">submitting a request</a>. HJF also plans to develop new features and maximize the value of this information to our current and future clients. We welcome feedback about areas of research interest, as well as ideas for enhancing the page.</p>

<p>If you would like to pursue a funding opportunity with HJF or have questions about proposal development assistance, contact the Research Initiatives Office by calling 240-694-4016, emailing research@hjf.org or <a href="http://hjfdev.devcloud.acquia-sites.com/contact_research_initiatives_office">filling out our contact form</a>.</p>
</div>
',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $export['funding_folder'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'tes_rads_parameter';
  $content->admin_title = 'testRadCustom';
  $content->admin_description = 'testing embedded view with parameters
';
  $content->category = '';
  $content->settings = array(
    'admin_title' => 'testRadCustom',
    'title' => 'tesRads',
    'body' => '<?php
$name= "funding_opportunities_parameter";
$display_id= "page";
$args="funding_opportunities_parameter";
print views_embed_view($name, $display_id);
?>',
    'format' => 'php_code',
    'substitute' => 0,
  );
  $export['tes_rads_parameter'] = $content;

  return $export;
}
