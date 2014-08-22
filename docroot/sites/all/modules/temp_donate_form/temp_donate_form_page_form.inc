<?php


/**
 * Donation form.
 */
function donate_form($form, &$form_state) {
  
  //drupal_add_js(drupal_get_path('module','donate') . '/js/donate.js');
  
  // Display page 2 if $form_state['page_num'] == 2
  if (!empty($form_state['page_num']) && $form_state['page_num'] == 2) {
    return donate_form_page_two($form, $form_state);
  }

    // Display page 3 if $form_state['page_num'] == 3
  if (!empty($form_state['page_num']) && $form_state['page_num'] == 3) {
    return donate_form_page_three($form, $form_state);
  }
  
<<<<<<< HEAD

=======
  $form['quaterdeck_donation'] = array(
    '#type' => 'markup',
    '#prefix' => '<div id="quarterdeck-donation">',
    '#markup' => '<p>For <a href=""></a> or monthly donation, please click here to <a href="">join today</a>.</p>',
    '#suffix' => '</div>',
  );
  
>>>>>>> 7ccb839fe5f403ee6a2a82a487e57761a62ef692
  $options_donate_type = _donate_type_get_list_options();
  //$donation_type_select = isset($form_state['values']['donation_type']) ? $form_state['values']['donation_type'] : key($options_donate_type);
  $form['donation_type'] = array(
    '#type' => 'select',
    '#title' => t('Make a donation to'),
    '#required' => TRUE,
    '#options' => $options_donate_type,
    '#default_value' =>!empty($form_state['values']['donation_type']) ? $form_state['values']['donation_type'] : '',
    '#ajax' => array(
      'callback' => 'donation_type_ajax_callback',
      'wrapper' => 'donation-type-dropdown',
    ),
  );
  
  $donation_type_selected = isset($form_state['values']['donation_type']) ? $form_state['values']['donation_type'] : GENERAL_GIFT;
  $form['donation_type_select'] = array(
    '#type' => 'select',
    '#title' => $donation_type_selected . ' type',
    '#prefix' => '<div id="donation-type-dropdown">',
    '#suffix' => '</div>',
    '#options' => _donation_type_get_second_dropdown_options($donation_type_selected),
    '#default_value' => !empty($form_state['values']['donation_type_select']) ? $form_state['values']['donation_type_select'] : '',
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => 'donation_type_select_ajax_callback',
      'wrapper' => 'donation-memoriam-honor',
    ),
  );
  
  $form['donation_amount'] = array(
    '#type' => 'select',
    '#title' => t('Donation amount'),
    '#options' => array(
                    '20'=>'$20',
                    '25'=>'$25',
                    '50'=>'$50',
                    '100'=>'$100',
                    '250'=>'$250',
                    '1000'=>'$1000',
                    '1500'=>'$1500',
                    'other' => t('Other'),
    ),
    '#default_value' =>!empty($form_state['values']['donation_amount']) ? $form_state['values']['donation_amount'] : '20',
     '#ajax' => array(
      'callback' => 'donation_other_amount_ajax_callback',
      'wrapper' => 'donation-other-amount-wrapper',
    ),
  );

  $form['donation_other_amount'] = array(
    '#type' => 'markup',
    '#title_display' => 'invisible',
    '#prefix' => '<div id="donation-other-amount-wrapper">',
    '#suffix' => '</div>',
  );

  if (!empty($form_state['values']['donation_amount']) && $form_state['values']['donation_amount'] == 'other') {
    $form['donation_other_amount']['#type'] = 'textfield';
    $form['donation_other_amount']['#field_prefix'] = '$';
    $form['donation_other_amount']['#size'] = 15;
//    $form['donation_other_amount']['#required'] = TRUE;
    $form['donation_other_amount']['#default_value'] = !empty($form_state['values']['donation_other_amount']) ? $form_state['values']['donation_other_amount'] : '';
  }
   
  $form['payment_type'] = array(
    '#type' => 'radios',
    '#title' => t('Payment type'),
    '#options' => array(CREDIT_CARD => t('Credit Card'), CHECK => t('Personal/Business Check')),
    '#default_value' =>!empty($form_state['values']['payment_type']) ? $form_state['values']['payment_type'] : CREDIT_CARD,
  );
  
  $form['donation_dedicate'] = array(
    '#type' => 'markup',
    '#prefix' => '<div id="donation-memoriam-honor">',
    '#suffix' => '</div>',
  );
  
  if ( !empty($form_state['values']['donation_type']) && !empty($form_state['values']['donation_type_select']) &&
      ($form_state['values']['donation_type_select'] == 'In Memoriam' || $form_state['values']['donation_type_select'] == 'In Honor'))  {
    
    $form['donation_dedicate']['#type'] = 'fieldset';

    if($form_state['values']['donation_type_select'] == 'In Memoriam'){
      $form['donation_dedicate']['#title'] = 'Who would you like to memorialize?';
      
      $form['donation_dedicate']['memoriam_msg'] = array(
        '#type' => 'item',
        '#title' =>  t('Donation In Memory Of:'),
        '#markup' => '<p>' . t('Optional. If you have the following information available for the person you are remembering, it will help us keep accurate records of the gifts made in their memory.') . '</p>',
      );
      
    }
    
    if($form_state['values']['donation_type_select'] == 'In Honor'){
      $form['donation_dedicate']['#title'] = 'Who would you like to honor?';
      
      $form['donation_dedicate']['memoriam_msg'] = array(
        '#type' => 'item',
        '#title' =>  t('Donation In Honor Of:'),
        '#markup' => '<p>' . t('Optional. If you have the following information available for the person you are honoring, it will help us keep accurate records of the gifts made in their honor.') . '</p>',
      );
    }
      
    
    $form['donation_dedicate']['dedicate_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Name'),
      '#size' => 60,
      '#required' => TRUE,
      '#default_value' =>!empty($form_state['values']['dedicate_name']) ? $form_state['values']['dedicate_name'] : '',
    );
  
    
    $form['donation_dedicate']['donation_acknowledgement_question'] = array(
      '#type' => 'radios',
      '#title' => t('Would you like to send an Acknowledgement to the family?'),
      '#options' => array(0 => t('No'), 1 => t('Yes')),
      '#default_value' =>!empty($form_state['values']['donation_acknowledgement_question']) ? $form_state['values']['donation_acknowledgement_question'] : 0,
      '#ajax' => array(
        'callback' => 'donation_acknowledgement_ajax_callback',
        'wrapper' => 'donation-acknowledgement',
      ),
    );
    
    //start
    
    
    //end
  }
  
   
  //Acknowledgement fieldset
  $form['donation_acknowledgement'] = array(
    '#prefix' => '<div id="donation-acknowledgement">',
    '#suffix' => '</div>',
  );
  
  if ( isset($form_state['values']['donation_acknowledgement_question']) && $form_state['values']['donation_acknowledgement_question'] == 1 ) {
    
    $form['donation_acknowledgement']['#type'] = 'fieldset';
    $form['donation_acknowledgement']['#title'] = 'Acknowledgement';
    
    $form['donation_acknowledgement']['ack_type'] = array(
    '#type' => 'radios',
    '#options' => drupal_map_assoc(array(t(MAIL_CARD), t(EMAIL_CARD))),
    '#title' => t('How would you like to notify the the family?'),
    '#default_value' =>!empty($form_state['values']['ack_type']) ? $form_state['values']['ack_type'] : MAIL_CARD,
  );
  
   $form['donation_acknowledgement']['ack_send_to'] = array(
    '#type' => 'item',
    '#markup' => '<p>' . t("This is the family's address") . '</p>',
  );
  
  $form['donation_acknowledgement']['ack_title'] = array(
    '#type' => 'select',
    '#title' => t('Title'),
    '#options' => drupal_map_assoc(array('', 'Ms.','Mr.', 'Mrs.')),
    '#default_value' =>!empty($form_state['values']['ack_title']) ? $form_state['values']['ack_title'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="ack_type"]' => array('value' => MAIL_CARD),
      ),
    ),
  );

  $form['donation_acknowledgement']['ack_fname'] = array(
    '#type' => 'textfield',
    '#title' => t('First name'),
    '#size' => 60,
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['ack_fname']) ? $form_state['values']['ack_fname'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="ack_type"]' => array('value' => MAIL_CARD),
      ),
    ),
  );

  $form['donation_acknowledgement']['ack_midname'] = array(
    '#type' => 'textfield',
    '#title' => t('MI'),
    '#size' => 2,
    '#maxlength' => 1,
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['ack_midname']) ? $form_state['values']['ack_midname'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="ack_type"]' => array('value' => MAIL_CARD),
        ),
      ),
  );
  
  $form['donation_acknowledgement']['ack_lname'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
    '#size' => 60,
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['ack_lname']) ? $form_state['values']['ack_lname'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="ack_type"]' => array('value' => MAIL_CARD),
      ),
    ),
  );

  $form['donation_acknowledgement']['ack_address1'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 1'),
    '#size' => 60,
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['ack_address1']) ? $form_state['values']['ack_address1'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="ack_type"]' => array('value' => MAIL_CARD),
      ),
    ),
  );

   $form['donation_acknowledgement']['ack_address2'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 2'),
    '#size' => 60,
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['ack_address2']) ? $form_state['values']['ack_address2'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="ack_type"]' => array('value' => MAIL_CARD),
      ),
    ),
    
  );

  $form['donation_acknowledgement']['ack_city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#size' => 60,
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['ack_city']) ? $form_state['values']['ack_city'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="ack_type"]' => array('value' => MAIL_CARD),
      ),
    ),    
  );
  
  $form['donation_acknowledgement']['ack_states'] = array(
    '#type' => 'select',
    '#title' => t('States'),
    '#options' => donate_us_states_list(),
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['ack_states']) ? $form_state['values']['ack_states'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="ack_type"]' => array('value' => MAIL_CARD),
      ),
    ),
    
  );

 $form['donation_acknowledgement']['ack_zipcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Zip code'),
    '#size' => 6,
    '#maxlength' => 5,
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['ack_zipcode']) ? $form_state['values']['ack_zipcode'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="ack_type"]' => array('value' => MAIL_CARD),
      ),
    ),    
  );
 
  $form['donation_acknowledgement']['ack_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#size' => 60,
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['ack_email']) ? $form_state['values']['ack_email'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="ack_type"]' => array('value' => EMAIL_CARD),
      ),
    ),    
  );
  
   $form['donation_acknowledgement']['ack_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Greeting'),
    '#description' => t('Up to 60 characters'),
    '#maxlength' => 60,
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['ack_message']) ? $form_state['values']['ack_message'] : '',
  );
   
 $form['donation_acknowledgement']['ack_sender_name'] = array(
    '#type' => 'textfield',
    '#title' => t('From'),
    '#size' => 60,
    '#maxlength' => 60,
    '#description' => t('Sender name.'),
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['ack_sender_name']) ? $form_state['values']['ack_sender_name'] : '',
  ); 
    
  }//end aknowledgement ajax
  
  //Payment method fieldset form
  $form['donation_payment'] = array(
    '#type' => 'fieldset',
    '#title' => t('Payment method'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['donation_payment']['check'] = array(
    '#type' => 'item',
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    '#markup' => '<p>'. t('If you would like to pay by check, please review and submit the donation then print and mail a copy with a check to:'). '</p>'.'<p>HJF Attn: Donation<br>s 6720-A Rockledge Drive Suite 100<br> Bethesda, MD 208174</p>',
=======
    '#markup' => '<p>'. t('If you would like to pay by check, please review and submit the donation then print and mail a copy with a check to:'). HJF Attn: Donations 6720-A Rockledge Drive Suite 100 Bethesda, MD 20817 '</p>'.'<p><br> </p>',
>>>>>>> 7ccb839fe5f403ee6a2a82a487e57761a62ef692
=======
    '#markup' => '<p>'. t('If you would like to pay by check, please review and submit the donation then print and mail a copy with a check to:'). HJF Attn: Donations 6720-A Rockledge Drive Suite 100 Bethesda, MD 20817 '</p>'.'<p><br> </p>',
>>>>>>> 7ccb839fe5f403ee6a2a82a487e57761a62ef692
=======
    '#markup' => '<p>'. t('If you would like to pay by check, please review and submit the donation then print and mail a copy with a check to:'). HJF Attn: Donations 6720-A Rockledge Drive Suite 100 Bethesda, MD 20817 '</p>'.'<p><br> </p>',
>>>>>>> 7ccb839fe5f403ee6a2a82a487e57761a62ef692
    '#states' => array(
      'visible' => array(
        ':input[name="payment_type"]' => array( 'value' => CHECK),
      ),
    ),
  );
  
  $form['donation_payment']['card_num'] = array(
    '#type' => 'textfield',
    '#title' => t('Card number'),
    '#maxlength' => 19,
    '#size' => 20,
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['card_num']) ? $form_state['values']['card_num'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="payment_type"]' => array( 'value' => CREDIT_CARD),
      ),
    ),
  );

  $form['donation_payment']['card_holder_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name on card'),
    '#maxlength' => 64,
    '#size' => 32,
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['card_holder_name']) ? $form_state['values']['card_holder_name'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="payment_type"]' => array('value' => CREDIT_CARD)
      ),
    ),
  );

  $form['donation_payment']['card_cvv'] = array(
    '#type' => 'textfield',
    '#title' => t('Security code'),
    '#size' => 4,
    '#maxlength' => 4,
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['card_cvv']) ? $form_state['values']['card_cvv'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="payment_type"]' => array('value' => CREDIT_CARD)
      ),
    ),
    '#field_suffix' => theme('donate_credit_cvv_help'),

  );

  $form['donation_payment']['card_exp_month'] = array(
    '#type' => 'select',
    '#title' => t('Expiration date'),
    '#options' => donate_months(),
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['card_exp_month']) ? $form_state['values']['card_exp_month'] : '01',
    '#states' => array(
      'visible' => array(
        ':input[name="payment_type"]' => array('value' => CREDIT_CARD)
      ),
    ),
  );

   $form['donation_payment']['card_exp_year'] = array(
    '#type' => 'select',
    '#options' => donate_years(),
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['card_exp_year']) ? $form_state['values']['card_exp_year'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="payment_type"]' => array('value' => CREDIT_CARD)
      ),
    ),
  );
    
  //Billing Address fieldset.
  $form['donation_billing_address'] = array(
    '#type' => 'fieldset',
    '#title' => t('Billing address'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="payment_type"]' => array( 'value' => CREDIT_CARD),
      ),
    ),
  );
  
  $form['donation_billing_address']['bill_fname'] = array(
    '#type' => 'textfield',
    '#title' => t('First name'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['bill_fname']) ? $form_state['values']['bill_fname'] : '',
  );

  $form['donation_billing_address']['bill_lname'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['bill_lname']) ? $form_state['values']['bill_lname'] : '',
  );

  $form['donation_billing_address']['bill_address1'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 1'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['bill_address1']) ? $form_state['values']['bill_address1'] : '',
  );

   $form['donation_billing_address']['bill_address2'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 2'),
    '#size' => 60,
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['bill_address2']) ? $form_state['values']['bill_address2'] : '',
  );

  $form['donation_billing_address']['bill_city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['bill_city']) ? $form_state['values']['bill_city'] : '',
  );
  
  $form['donation_billing_address']['bill_states'] = array(
    '#type' => 'select',
    '#title' => t('States'),
    '#options' => donate_us_states_list(),
    '#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['bill_states']) ? $form_state['values']['bill_states'] : '',
  );
  

 $form['donation_billing_address']['bill_zipcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Zip code'),
    '#size' => 6,
    '#maxlength' => 5,
    '#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['bill_zipcode']) ? $form_state['values']['bill_zipcode'] : '',
  );
  
   $form['donation_billing_address']['bill_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone'),
    '#size' => 15,
    '#maxlength' => 15,
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['bill_phone']) ? $form_state['values']['bill_phone'] : '',
  );
   
   $form['donation_billing_address']['bill_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#size' => 60,
    '#maxlength' => 120,
    '#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['bill_email']) ? $form_state['values']['bill_email'] : '',
  );   
  
 $form['donation_billing_address']['bill_subcribe_newsletter'] = array(
    '#type' => 'checkbox',
    '#title' => t('Yes, I would like to sign up for the newsletter.'),
    //'#required' => TRUE,
    '#default_value' =>!empty($form_state['values']['bill_subcribe_newsletter']) ? $form_state['values']['bill_subcribe_newsletter'] : 0,
  );     
  
  //Thank You fieldset.
  $form['donation_thank_you'] = array(
    '#type' => 'fieldset',
    '#title' => t('Thank you for making your donation'),
    '#collapsible' => FALSE,
    '#collapsed'  => FALSE,
  );
  
  $form['donation_thank_you']['thank_you_type'] = array(
    '#type' => 'radios',
    '#options' => drupal_map_assoc(array(t(MAIL_LETTER), t(EMAIL_LETTER))),
    '#title' => t('How would you like to be thanked?'),
    '#default_value' =>!empty($form_state['values']['thank_you_type']) ? $form_state['values']['thank_you_type'] : MAIL_LETTER,
  );
    
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => t('Review Donation'),
    '#submit' => array('donate_form_next_submit'),
    '#validate' => array('donate_form_next_validate'),
  );

  return $form;
}

function donate_form_next_submit($form, &$form_state) {
  
  // Values are saved for each page.
  // to carry forward to subsequent pages in the form.
  // and we tell FAPI to rebuild the form.
  $form_state['page_values'][1] = $form_state['values'];

  if (!empty($form_state['page_values'][2])) {
    $form_state['values'] = $form_state['page_values'][2];
  }

  // When form rebuilds, it will look at this to figure which page to build.
  $form_state['page_num'] = 2;
  $form_state['rebuild'] = TRUE;
  
  
}

function donate_form_page_two_back($form, &$form_state) {
  $form_state['values'] = $form_state['page_values'][1];
  $form_state['page_num'] = 1;
  $form_state['rebuild'] = TRUE;
}

function donate_form_next_validate($form, &$form_state) {
  
  if($form_state['values']['donation_amount'] == 'other'){
    $donation_other_amount = $form_state['values']['donation_other_amount'];
    if( empty($donation_other_amount) ) {
      form_set_error('donation_other_amount', t('Please enter donation other amount.'));
    }
   /* 
    else if(!donate_validate_other_amount_number($donation_other_amount)) {
      form_set_error('donation_other_amount', t('Please enter a valid number for donation amount.'));
    }
    */
  }
  
  $payment_type = $form_state['values']['payment_type'];  
  if($payment_type == CREDIT_CARD){
    $card_num =  $form_state['values']['card_num'];
    if( empty($card_num) || !donate_validate_credit_card_number($card_num)){
      form_set_error('card_num', t('Please enter a valid credit card number.'));
    }
    
    $card_name =  $form_state['values']['card_holder_name'];
     if(empty($card_name)){
      form_set_error('card_holder_name', t('Please enter the name one your credit card.'));
    }
    
    $card_exp_month = $form_state['values']['card_exp_month'];
    $card_exp_year = $form_state['values']['card_exp_year'];
    if (donate_validate_credit_card_start_date($card_exp_month,$card_exp_year)) {
      form_set_error('card_exp_month', t('You have entered an expired credit card.'));
    }
    
    $card_cvv = $form_state['values']['card_cvv'];
    if(!donate_validate_credit_card_security_code($card_num,$card_cvv)) {
      form_set_error('card_cvv', t('You have entered an invalid card security code.'));
    }
    
    if(empty($form_state['values']['bill_fname'])){
      form_set_error('bill_fname', t('Please enter you billing first name.'));
    }
    
    if(empty($form_state['values']['bill_lname'])){
      form_set_error('bill_lname', t('Please enter you billing last name.'));
    }
    
    if(empty($form_state['values']['bill_address1'])){
      form_set_error('bill_address1', t('Please enter you billing address.'));
    }
    
    if(empty($form_state['values']['bill_city'])){
      form_set_error('bill_city', t('Please enter you billing city.'));
    }
    
    if(empty($form_state['values']['bill_states'])){
      form_set_error('bill_city', t('Please enter you billing state.'));
    }
    
    if(empty($form_state['values']['bill_zipcode'])){
      form_set_error('bill_city', t('Please enter you billing zipcode.'));
    }
    
    if (!valid_email_address($form_state['values']['bill_email'])) {
      form_set_error('bill_email', t('That e-mail address is not valid.'));
    }
    
 } 

}



function donate_form_page_two($form, &$form_state) {

  $page_one_values = $form_state['page_values'][1];

  $donate_amount = $page_one_values['donation_amount'];
  if ($page_one_values['donation_amount'] == 'other') {
    $donate_amount = $page_one_values['donation_other_amount'];
  }
  
  $form['review_info'] = array(
    '#type' => 'markup',
    '#prefix' => '<div id="donation-review-info" class="donate-review-box">',
    '#markup' => '<p>Make a donation to: '. t($page_one_values['donation_type']) .'</p>' .
                 '<p>Donation type: '. t($page_one_values['donation_type_select']) .'</p>' .
                 '<p>Donation amount: $' . $donate_amount .'</p>',
    '#suffix' => '</div>',
  );
  
  $payment_type = ($page_one_values['payment_type'] == 'credit_card') ? 'Credit card' : 'Personal/Bussiness check' ;
  $card_num = 'XXXX-XXXX-XXXX-' . substr($page_one_values['card_num'],-4,4);
  $card_name = $page_one_values['card_holder_name'];
  $card_exp_date= $page_one_values['card_exp_month'] . '/'. $page_one_values['card_exp_year'] ;
  
  if($page_one_values['payment_type'] == CREDIT_CARD){
    $form['review_payment'] = array(
      '#type' => 'markup',
      '#prefix' => '<div id="donation-review-payment" class="donate-review-box">',
      '#markup' => '<h2>'. t('Payment Method') .'</h2>' .
                 '<p>Payment type: '. t($payment_type) .'</p>' .
                 '<p>Card number: '. t($card_num) .'</p>' .
                 '<p>Card holder name: ' . $card_name .'</p>' .
                 '<p>Card expiration date: ' . $card_exp_date .'</p>' ,
      '#suffix' => '</div>',
    );
  }else {
  
    $form['review_payment'] = array(
      '#type' => 'markup',
      '#prefix' => '<div id="donation-review-payment" class="donate-review-box">',
      '#markup' => '<h2>'. t('Payment Method') .'</h2>' .
                 '<p>Payment type: '. t($payment_type) .'</p>',
      '#suffix' => '</div>',
    );
  }

  if( !empty($page_one_values['bill_address2'])){
    $billing_address = '<span>' . $page_one_values['bill_fname'] . ' ' . $page_one_values['bill_lname'] . '</span><br>' . 
                       '<span>' . $page_one_values['bill_address1'] . '</span><br>' . 
                       '<span>' . $page_one_values['bill_address2'] . '</span><br>' . 
                       '<span>' . $page_one_values['bill_city'] . ', ' . $page_one_values['bill_states'] . ', ' . $page_one_values['bill_zipcode'] . '</span>';
  }else{
        $billing_address = '<span>' . $page_one_values['bill_fname'] . ' ' . $page_one_values['bill_lname'] . '</span><br>' . 
                       '<span>' . $page_one_values['bill_address1'] . '</span><br>' . 
                       '<span>' . $page_one_values['bill_city'] . ', ' . $page_one_values['bill_states'] . ', ' . $page_one_values['bill_zipcode'] . '</span>';
  }
  
  $form['donation_review_billing_address'] = array(
    '#type' => 'markup',
    '#prefix' => '<div id="donation-review-billing-address" class="donate-review-box">',
    '#markup' => '<h2>'. t('Billing Adress') .'</h2>' .
                 '<p>'. $billing_address .'</p>' .
                 '<p>'. $page_one_values['bill_phone'] .'</p>'.
                 '<p>'. $page_one_values['bill_email'] .'</p>',
    '#suffix' => '</div>',
  );
  
  //$form['submit'] = array(
  //  '#type' => 'submit',
  //  '#value' => t('Donate'),
  //  '#submit' => array('donate_form_page_two_submit'),
  //);
  
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => t('Donate'),
    '#submit' => array('donate_form_page_two_submit'),
  );

    
  
  $form['back'] = array(
    '#type' => 'submit',
    '#value' => t('<< Back'),
    '#submit' => array('donate_form_page_two_back'),
  );
  
  return $form;
}


/**
 * Submit function for form_donation().
 */
function donate_form_page_two_submit($form, &$form_state) {
  // Values are saved for each page.
  // to carry forward to subsequent pages in the form.
  // and we tell FAPI to rebuild the form.
 /*
  $form_state['page_values'][1] = $form_state['values'];

  if (!empty($form_state['page_values'][2])) {
    $form_state['values'] = $form_state['page_values'][2];
  }
*/
  
  $values = $form_state['page_values'][1];
  $invnum = variable_get('donate_invoice_id') + 1;
  $customer_id = variable_get('donate_customer_id') + 1;
  
  $customer_fname = $values['bill_fname'];
  $customer_lname = $values['bill_lname'];
  $customer_email = $values['bill_email'];
  $customer_phone = $values['bill_phone'];
  
  $card_name = $values['card_holder_name'];
  $card_num = $values['card_num'];
  $card_exp_date = $values['card_exp_month'] . $values['card_exp_year'];
  $card_cvv = $values['card_cvv'];
  $card_address1 = $values['bill_address1'];
  $card_address2 = $values['bill_address2'];
  $card_city = $values['bill_city'];
  $card_state = $values['bill_states'];
  $card_zip = $values['bill_zipcode'];
      
  $donate_amount = $values['donation_amount'];
  if ($values['donation_amount'] == 'other') {
    $donate_amount = $values['donation_other_amount'];
  }
  
  $args = '';
  $args = '&Username=' . PL_API_USERNAME;
  $args .= '&Password=' . PL_TRANSACTION_KEY;
  
  $payleap_url = '';
     
  $payleap_url = PL_SINGLE_CREDIT_CARD_URL;
  
  $args .= '&TransType=Sale';  
  $args .= '&NameOnCard=' . $card_name;
  $args .= '&CardNum='.$card_num;
  $args .= '&ExpDate=' . $card_exp_date ; //MMYY Format
  $args .= '&CVNum=' . $card_cvv;
  $args .= '&Amount=' . $donate_amount;
  $args .= '&InvNum=' . $invnum;
  $args .= '&ExtData=<TrainingMode>F</TrainingMode><CustomerID>'.
          $customer_id.'</CustomerID><Invoice><BillTo><Name>'.
          $card_name .'</Name><Address><Street>'.
          $card_address1 .'</Street><City>'.
          $card_city .'</City><State>'.
          $card_state.'</State><Zip>'.
          $card_zip.'</Zip><Country>US</Country></Address><Email>'.
          $customer_email.'</Email><Phone>' .
          $customer_phone.'</Phone></BillTo></Invoice>';
  $args .= "&PNRef=";
  $args .= "&MagData=";  

  $result = temp_donate_form_payleap_send($args, $payleap_url);
  $result = str_replace(' xmlns="http://www.payleap.com/payments"', '', $result);
  watchdog('donate', $result );
  variable_set('payleap_result_XML', $result);
   
  // When form rebuilds, it will look at this to figure which page to build.
  $form_state['page_num'] = 3;
  $form_state['rebuild'] = TRUE;
}


function donate_form_page_three($form, &$form_state) {
  $values = $form_state['page_values'][1];
  
   $donate_amount = $values['donation_amount'];
  if ($values['donation_amount'] == 'other') {
    $donate_amount = $values['donation_other_amount'];
  }
  
  $result = variable_get('payleap_result_XML');
  $xml = new SimpleXMLElement($result);
  
  if ( check_plain($xml->RespMSG) == 'Approved' || check_plain($xml->Message) == 'APPROVAL') {
    
    $xml_AuthCode = check_plain($xml->AuthCode);
    $xml_PNRef = check_plain($xml->PNRef);
    variable_set('donate_pnref', $xml_PNRef );
  }

  
  $response = '';
  $response .= '<div class="transaction-info">';
  $response .= '<h3>Please keep the information below for your records</h3>';
  
  if(check_plain($xml->RespMSG) == 'Approved' || check_plain($xml->Message) == 'APPROVAL') {
    //send email
    temp_donate_form_mail_send_contributor($values);
    temp_donate_form_mail_send_navy($values);
   
    $response .= '<span>' . t('Your transaction has been approved.') . '</span>';
    $response .= '<span>' . t('The authorization code for your transaction: ') . $xml_AuthCode . '</span>';
    $response .= '<span>' . t('The reference number is: '). $xml_PNRef . '</span>';
      
  }else {
     
    $response .= '<span>'. check_plain($xml->RespMSG) . '</span>';  
  }
    
   
  
  
  $response .= '</div>';
  
  $thankyou = '';
  $thankyou .= '<p>' . 'Dear ' . $values['bill_fname'] . ','. '</p>';
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  $thankyou .= '<p>' . 'Thank you for supporting HJF ' . '$' . $donate_amount .
                     '. HJF thank you text .' . '</p>';
  $thankyou .= $response;
  $thankyou .= '<p>' . 'Welcome Aboard!' . '<br>' . 'HJF.org' . '</p>';
=======
=======
>>>>>>> 7ccb839fe5f403ee6a2a82a487e57761a62ef692
=======
>>>>>>> 7ccb839fe5f403ee6a2a82a487e57761a62ef692
  $thankyou .= '<p>' . 'Thank you for supporting HJF  through your generous donation of ' . '$' . $donate_amount .
                     '. Your contribution is working hard at HJF.  Your assistance will help the..........' . '</p>';
  $thankyou .= $response;
  $thankyou .= '<p>' . 'Welcome Aboard!' . '<br>' . 'HJF' . '</p>';
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 7ccb839fe5f403ee6a2a82a487e57761a62ef692
=======
>>>>>>> 7ccb839fe5f403ee6a2a82a487e57761a62ef692
=======
>>>>>>> 7ccb839fe5f403ee6a2a82a487e57761a62ef692
  
  $form['confirmation'] = array(
    '#markup' => '<div>' . $thankyou . '</div>',
  );
  
  $form['exit'] = array(
    '#type' => 'submit',
    '#value' => t('Exit'),
    '#submit' => array('donate_form_page_three_submit') ,
  );

  variable_set('payleap_result_XML','');
  variable_set('donate_invoice_id', variable_get('donate_invoice_id')+ 1);
  variable_set('donate_customer_id', variable_get('donate_customer_id')+ 1);
  
  return $form;
}

function donate_form_page_three_submit($form, &$form_state) {
  
  $form_state['redirect'] = array('http://www.hjf.org/');
}

function donate_form_page_three_back($form, &$form_state){
  $form_state['values'] = $form_state['page_values'][1];
  $form_state['page_num'] = 1;
  $form_state['rebuild'] = TRUE;
}

function donation_type_ajax_callback($form, &$form_state) {
  
  return $form['donation_type_select'];
 
}


function donation_type_select_ajax_callback($form, &$form_state) {
  return $form['donation_dedicate'];
}

function donation_acknowledgement_ajax_callback($form, &$form_state) {
  return $form['donation_acknowledgement'];
}

function _donate_type_get_list_options(){
  return drupal_map_assoc(array(USU, Research_Edn));
}

function _donation_type_get_second_dropdown_options($key = '') {
  $options = array(
    Researc_Edu => drupal_map_assoc(array(
      ''In Memoriam',
      'In Honor',
    )),
    
   
  );
  if (isset($options[$key])) {
    return $options[$key];
  }
  else {
    return array();
  }
}

/**
 * Ajax callback for donate other amount.
 */
function donation_other_amount_ajax_callback($form,  &$form_state) {
  return $form['donation_other_amount'];
}

/**
 * Credit card experation months.
 */
function donate_months() {
  return array(
    '01' => t('January'),
    '02' => t('February'),
    '03' => t('March'),
    '04' => t('April'),
    '05' => t('May'),
    '06' => t('June'),
    '07' => t('July'),
    '08' => t('August'),
    '09' => t('September'),
    '10' => t('October'),
    '11' => t('November'),
    '12' => t('December'),
  );
}

/**
 * Credit card experation years.
 */
function donate_years(){
  $current_year_2 = date('y');
  $current_year_4 = date('Y');

  $years = array();

  for ($i = 0; $i < 10; $i++) {
    $years[$current_year_2 + $i] = str_pad($current_year_4 + $i, 2, '0', STR_PAD_LEFT);
  }

  return $years;
}


function donate_us_states_list() {
  return array(
      ''   => t('--'),
      'AL' => t('Alabama'),
      'AK' => t('Alaska'),
      'AZ' => t('Arizona'),
      'AR' => t('Arkansas'),
      'CA' => t('California'),
      'CO' => t('Colorado'),
      'CT' => t('Connecticut'),
      'DE' => t('Delaware'),
      'DC' => t('District Of Columbia'),
      'FL' => t('Florida'),
      'GA' => t('Georgia'),
      'HI' => t('Hawaii'),
      'ID' => t('Idaho'),
      'IL' => t('Illinois'),
      'IN' => t('Indiana'),
      'IA' => t('Iowa'),
      'KS' => t('Kansas'),
      'KY' => t('Kentucky'),
      'LA' => t('Louisiana'),
      'ME' => t('Maine'),
      'MD' => t('Maryland'),
      'MA' => t('Massachusetts'),
      'MI' => t('Michigan'),
      'MN' => t('Minnesota'),
      'MS' => t('Mississippi'),
      'MO' => t('Missouri'),
      'MT' => t('Montana'),
      'NE' => t('Nebraska'),
      'NV' => t('Nevada'),
      'NH' => t('New Hampshire'),
      'NJ' => t('New Jersey'),
      'NM' => t('New Mexico'),
      'NY' => t('New York'),
      'NC' => t('North Carolina'),
      'ND' => t('North Dakota'),
      'OH' => t('Ohio'),
      'OK' => t('Oklahoma'),
      'OR' => t('Oregon'),
      'PA' => t('Pennsylvania'),
      'RI' => t('Rhode Island'),
      'SC' => t('South Carolina'),
      'SD' => t('South Dakota'),
      'TN' => t('Tennessee'),
      'TX' => t('Texas'),
      'UT' => t('Utah'),
      'VT' => t('Vermont'),
      'VA' => t('Virginia'),
      'WA' => t('Washington'),
      'WV' => t('West Virginia'),
      'WI' => t('Wisconsin'),
      'WY' => t('Wyoming'),
      ' ' => t('--'),
      'AS' => t('American Samoa'),
      'FM' => t('Federated States of Micronesia'),
      'GU' => t('Guam'),
      'MH' => t('Marshall Islands'),
      'MP' => t('Northern Mariana Islands'),
      'PW' => t('Palau'),
      'PR' => t('Puerto Rico'),
      'VI' => t('Virgin Islands'),
    );
  
}

function donate_validate_other_amount_number($number) {
  // Ensure every character in the number is numeric.
  if (!ctype_digit($number)) {
    return FALSE;
  }
  
  return TRUE;
}

/**
 * Validates a credit card number using the Luhn algorithm.
 *
 * @param $number
 *   The credit card number to validate.
 *
 * @return
 *   TRUE or FALSE indicating the number's validity.
 *
 * @see http://www.merriampark.com/anatomycc.htm
 */
function donate_validate_credit_card_number($number) {
  // Ensure every character in the number is numeric.
  if (!ctype_digit($number)) {
    return FALSE;
  }

  // Validate the number using the Luhn algorithm.
  $total = 0;

  for ($i = 0; $i < strlen($number); $i++) {
    $digit = substr($number, $i, 1);
    if ((strlen($number) - $i - 1) % 2) {
      $digit *= 2;
      if ($digit > 9) {
        $digit -= 9;
      }
    }
    $total += $digit;
  }

  if ($total % 10 != 0) {
    return FALSE;
  }

  return TRUE;
}


/**
 * Validates a credit card start date.
 *
 * @param $month
 *   The 1 or 2-digit numeric representation of the month, i.e. 1, 6, 12.
 * @param $year
 *   The 2-digit numeric representation of the year, i.e. 13.
 *
 * @return
 *   TRUE for cards whose start date is blank (both month and year) or in the
 *   past, 'year' or 'month' for expired cards indicating which value should
 *   receive the error.
 */
function donate_validate_credit_card_start_date($month, $year) {

  if ($month < date('m') && ($year == date('y')) )
    return TRUE;
 
  return FALSE;

}


/**
 * Validates a card security code based on the type of the credit card.
 *
 * @param $number
 *   The number of the credit card to validate the security code against.
 * @param $code
 *   The card security code to validate with the given number.
 *
 * @return
 *   TRUE or FALSE indicating the security code's validity.
 */
function donate_validate_credit_card_security_code($number, $code) {
  // Ensure the code is numeric.
  if (!ctype_digit($code)) {
    return FALSE;
  }

  // Check the length based on the type of the credit card.
  switch (substr($number, 0, 1)) {
    case '3':
      if (strlen($number) == 15) {
        return strlen($code) == 4;
      }
      else {
        return strlen($code) == 3;
      }

    case '4':
    case '5':
    case '6':
      return strlen($code) == 3;
  }
}


