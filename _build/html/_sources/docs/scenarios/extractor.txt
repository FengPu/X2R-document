Extractor API Usage Scenarios
------------------------------


Operation Scenarios
====================



Extract URIs from a Given RDF 
+++++++++++++++++++++++++++++

#. Include the file **"extractor.class.php"** in your program
#. Initialize a **Extractor** instance by passing a **rdfGraph**
#. Call the method **getQueryTerms()**



Tokenize an URI into Query Terms
++++++++++++++++++++++++++++++++

Extractor can help in tokenizing URI task. To tokenize a given URI, you can use the method **tokenize($str)**, where the $str is the URI that you want to tokenize. 

Currently, we implements two representive tokenizers, **DelimitBasedTokenizer** and **CaseBasedTokenizer**, and the **tokenize($str)** applies these two tokenizers on the $str. 


Configuration Scenarios
========================


Set a RDF Parser
++++++++++++

There are many RDF parsers available. In X2R, we allow developers to set or even introduce new RDF parsers for reasons, such as better performace or wider range of input formats. 

Currently, we implement one wrapper, **Easy_Rdf_Adapter**, for EasyRdf. EasyRdf is a popular RDF parser implemented in PHP, and more information can be found in it `official site <http://www.easyrdf.org/>`_. 

To set **Easy_Rdf_Adapter** as the RDF parser. 

#. Initialize an instance of **Easy_Rdf_Adapter**
#. Initialize a **Extractor** instance by passing the instance just initialized

Set an URI Filter
+++++++++++++++++

If there are some URIs that you want to ignore in the whole URI replacement process, you can use **addFilteredUri($furi)** to incrementally build the URI filter. 

You can also use **getFiltedUris()** method to get the current list of URIs that are ignored. 


