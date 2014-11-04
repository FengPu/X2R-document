USS API Usage Scenarios
-----------------------

Operation Scenarios
===================


Search URIs by terms
+++++++++++++++++++++

#. Include the file **"urisearchservice.class.php"** in your program
#. Initialize a **UriSearchService** instance
#. Call the method **uriSearch** with a **query string** as the parameter. After receving all Endpoints' respones, the **result set** is returned




Configuration Scenarios
========================

After initializing a **UriSearchService** instance, the default components are already set. If you want to change the default setting, you can reset the components as the guidences listed below. 

The configuration methods can be chained. Here is a code example. 

.. code-block:: php

    include_once (risearchservice.class.php);
    $exampleUss = new UriSearchService();
    //... Initialize components as $parser, $selector ...etc.
    $exampleUss->setFederatedSearch($federatedSearch)
               ->setParser($parser)
               ->setProcessor($rsultProcessor) 
               ->setSelector($selector);



Set a Parser
++++++++++++

#. Initialize a parser 
#. Assign the new parser through the method **setParser($parser)**


Set FederatedSearch
++++++++++++++

#. Initialize a federatedSearch
#. Assign the new federatedSearch through the method **setFederatedSearch($federatedSearch)**

Set a Result Processor (Filter and Ranker)
+++++++++++++++++++++++++++++++++++++++

#. Initialize a rsultProcessor
#. Assign the new rsultProcessor through the method **setProcessor($rsultProcessor)**


Set a Selector
++++++++++++++
#. Initialize a selector
#. Assign the new selector through the method **setSelector($selector)**