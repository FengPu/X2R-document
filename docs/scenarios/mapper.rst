Mapper API Usage Scenarios
----------------------------

Operation Scenarios
====================

Replace Original URIs with Specified URIs
+++++++++++++++++++++++++++++++++++++++++

#. Include the file **"mapper.class.php"** in your program
#. Initialize a **Mapper** instance by passing a **rdfGraph**
#. Call the method **refactoring($refType, $change)**
#. Call the method **serialize($format)**

Configuration Scenarios
=======================

Change a Refactor (URI Replacement)
+++++++++++++++++++++++++++++++++

Change different refactors can let Mapper be able to do different refactoring on the given RDF. In order to decouple the **Mapper** from specific **Refactor**, their dependency is injected during runtime through the method **refactoring($refType, $change)**. 

Currently, we only implement one type of **Refactor**, called **Rename** (defined in "refaRename.class.php"). Its corresponding change is an associative array, which saves the mapping from original URI to replaced URI. There is one example of **change** that the refactor, **Rename**, accepted.  

.. code-block:: php

    $exampleChange = array('http://original.uri.1' => 'http://replaced.uri.1', 
	                   'http://original.uri.2' => 'http://replaced.uri.2');



Set a RDF Parser
+++++++++++++++++

There are many RDF parsers available. In X2R, we allow developers to set or even introduce new RDF parsers for reasons, such as better performace or wider range of input formats. 

Currently, we implement one wrapper, **Easy_Rdf_Adapter**, for EasyRdf. EasyRdf is a popular RDF parser implemented in PHP, and more information can be found in it `official site <http://www.easyrdf.org/>`_. 

To set **Easy_Rdf_Adapter** as the RDF parser. 

#. Initialize an instance of **Easy_Rdf_Adapter**
#. Initialize a **Mapper** instance by passing the instance just initialized