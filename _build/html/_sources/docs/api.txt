.. _api:

API
===

Extractor
---------

.. php:class:: Extractor

  Extractor class implements 
  URI extracting & analyzing process as below. 
        
  #. Load the RDF content to a Graph data structure.

  #. Traverse the Graph to find all the URIs, and generate a filtered URI list.

  #. Transform URIs to search terms.

  #. Wrap search terms in JSON output. 

  .. php:method:: getQueryTerms()

      Extract terms from URIs of given RDF, and wrapp terms
      with their contextual information.

      :returns: A JSON string of terms derived from extracted URIs of a given RDF file with corresponding metadata, 
      including `originalURI`, `replacedURI`, `status`, `lineNumbers`.


  .. php:method:: getFiltedUris()

      Get current URI filter list.

      :returns: An array of filtered URI.


  .. php:method:: addFilteredUri($furi)

      Add the given URI, $furi, to the URI filter list.

      :param string $furi: The URI to be filtered
      :returns: Either false on failure, or the true for success.

  .. php:method:: removeFilteredUri($furi)

      Remove the given URI, $furi, from the URI filter list.

      :param string $furi: The URI to be filtered
      :returns: Either false on failure, or the true for success

RdfGraph
--------


.. php:class:: RdfGraph

  RdfGraph class is a standard interface for wrapping or adapting existing RDF parsers into X2R.

  .. php:method:: parseRdf($data)

      :param string $data: The content of RDF file.
      :returns: Either false on failure, or the true for success.


  .. php:method:: serializeRdfAs($format)

      :param string $format: The file format of serialized RDF.
      :returns: Either false on failure, or the string representation of serialized RDF in specified format.


EasyRdfAdapter
^^^^^^^^^^^^^^

.. php:class:: EasyRdfAdapter

  EasyRdfAdapter class is an implemantion of RdfGraph. It is a warpper of an open source RDF parser - EasyRDF. 

  .. php:method:: parseRdf($data)

      :param string $data: The content of RDF file.
      :returns: Either false on failure, or the true for success.
      :raises ValueError: Raise if the $data cannot be parsed successfully.

  .. php:method:: serializeRdfAs($format)

      :param string $format: The file format of serialized RDF.
      :returns: Either false on failure, or the string representation of serialized RDF in specified format.
      :raises ValueError: The $format is not an element of 'supported_format', which includes 'jsonld', 'rdfxml'.



Tokenizer
---------

.. php:class:: Tokenizer

  Tokenizer class is a standard interface for X2R developers to extend X2R with new types of tokenizers. Currently, two tokenizers, i.e. CaseBasedTokenizer and DelimitBasedTokenizer, are implemented and bundled with X2R::Extractor. 

  .. php:method:: tokenizeString($str)

      :param string $str: The string to be tokenized.
      :returns: An array of tokenized strings.

  .. php:method:: tokenizeArrayOfStrings($arr)


      :param array $arr: The array of strings to be tokenized
      :returns: An array of tokenized strings.


  .. php:method:: arrayToString($arr)


      :param array $arr: The array of strings to be tokenized
      :returns: A string which is consisted of elements from given array $arr and is concatenated by whitespace.




CaseBasedTokenizer
^^^^^^^^^^^^^^^^^^

.. php:class:: CaseBasedTokenizer

  CaseBasedTokenizer class

  .. php:method:: tokenizeString($str)


      :param string $str: The string to be tokenized.
      :returns: An array of tokenized strings.


  .. php:method:: tokenizeArrayOfStrings($arr)


      :param array $arr: The array of strings to be tokenized
      :returns: An array of tokenized strings.

DelimitBasedTokenizer
^^^^^^^^^^^^^^^^^^^^^

.. php:class:: DelimitBasedTokenizer

  DelimitBasedTokenizer class

  .. php:method:: tokenizeString($str)


      :param string $str: The string to be tokenized.
      :returns: An array of tokenized strings.


  .. php:method:: tokenizeArrayOfStrings($arr)


      :param array $arr: The array of strings to be tokenized
      :returns: An array of tokenized strings.


Refactor
--------

.. php:class:: Refactor


    Refactor is the class that reserves
    the flexibility for introducing 
    new kind of RDF refactoring into 
    this RDF analyzing and manupilation 
    framework.

  .. php:method:: refactoring($change)


      :param int $change: The change spec. for the refacroring.
      :returns: Either false on failure, or the true for success.

ReplaceUri
^^^^^^^^^^


.. php:class:: ReplaceUri


        ReplaceUri is an implemetation of 
        Refactor class. It is the default
        refactoring used in X2R project. 
        The replaceUri is to replace an existing URI 
        with a new URI.  

  .. php:method:: refactoring($change)


      :param int $change: The change spec. for the refacroring.
      :returns: Either false on failure, or the true for success.

MappingEntry
------------
.. php:class:: MappingEntry

        X2R's components are integrated by standard message passing, where the standard message is the `mapping from original URI, terms and replaced URI`. This MappingEntry is the class used to model one entry of such mapping message.  

  .. php:method:: MappingEntry($originalURI, $replacedURI, \
                               $term, $lineNumbers)

      :param string $originalURI: The change spec. for the refacroring.
      :param string $replacedURI: The change spec. for the refacroring.
      :param string $term: The change spec. for the refacroring.
      :param string $lineNumbers: The change spec. for the refacroring.
      :returns: Either false on failure, or the true for success.

  .. php:method:: getOriginalURI()

      :returns: Either false on failure, or the `Original URI` for success.

  .. php:method:: getReplacedURI()

      :returns: Either false on failure, or the `Replaced URI` for success.

  .. php:method:: getQueryTerm()

      :returns: Either false on failure, or the `Query Term` for success.

  .. php:method:: getLineNumbers()

      :returns: Either false on failure, or the `Line Numbers` for success.



MappingCollection
-----------------
.. php:class:: MappingCollection

        The MappingCollection is a collection of MappingEntry. The MappingCollection object can be serialized as JSON, and serves as the integration glue among X2R's components.  

  .. php:method:: addMappingEntry($mappingentry)

      :param MappingEntryint $mappingentry: An entry of mapping.
      :returns: Either false on failure, or the true for success.

  .. php:method:: toJson()

      :returns: Serialize the collection of mappings in Json format.


Mapper
------

.. php:class:: Mapper


      Mapper is the class for modeling the RDF transformation (refactoring) process.

      Currently, the Mapper only support one kind of 
      transformation (refactoring) - replaceURI. 

      The replaceURI is to replace an existing URI 
      with a new URI..


  .. php:method:: Mapper($graph)


      :param rdfGraph $graph: The RDF, which is holded in the rdfGraph data structure, to be refactored.


  .. php:method:: refactoring($refactorType, $change)

      Based on the type of refactoring ($refactorType) and the desired change ($change) to conduct the refactoring on target RDF.

      :param string $refactorType: The type of rafactor.
      :param array $change: The month.
      :returns: Either false on failure, or the datetime object for method chaining.

  .. code-block:: php

      //This is an example of $change
      array('http://127.0.0.1/sport_center' => 'http://openisdm.iis.sinica.edu.tw/sport_center', 
           'http://127.0.0.1/park' => 'http://openisdm.iis.sinica.edu.tw/park');

  .. note::

     Currently, only one type refactor is supported, that is, 
     `replaceUri`. More refactors can be implemented and 
     integrated into Mapper.    

  .. php:method:: serialize($format)

      Return the RDF content in the format specified by $format.

      :param string $format: The format of output file. 
      :returns: Either false on failure, or the string of refactored RDF's content in the specified format.

 


WebUtilities
------------
.. php:function:: GetParameter($para)

      Get the value of HTTP GET request by parameter's name

      :param string $para: The parameter's name.
      :returns: The value of given parameter's name.
      :raises ValueError: Raise if the $para cannot be found in the request.



USS
---

.. php:class:: Endpoint


      Endpoint is the class for modeling the public Endpoint, such as DBpedia. (refer to :ref:`uss`)


  .. php:method:: issueSparqlQuery($sparqlQuery, $resultFormat)


      :param string $sparqlQuery: The SPARQL query.
      :param string $resultFormat: The format of returned result.
      :returns: The string of result in the specified format.
      :raises NoResponseError: Raise if the timeout is reached.
      :raises ValueError: Raise if the sparql is invalid.
      

.. php:class:: SparqlQueryComposer


      SparqlQueryComposer is a class to aggregate a varity of SPARQL composition methods. Currently, only plain text terms are supported.


  .. php:method:: term2Sparql($term)
       
       Turn plain text terms to SPARQL query.

      :param string $term: The desired query term..
      :returns: The SPARQL query string. 



.. php:class:: Dbpedia

     Dbpedia is a wrapper of Dbpedia Endpoint.

  .. php:method:: composeQuery(term, $dataSourceName = '', $limit = 10, $filters = array(''))

      :param string $term: The SPARQL query in plain text.
      :param string $dataSourceName: the name of data source
      :param int $limit: the max number of results
      :param array $filters: an array of URIs that will be ignored

  .. php:method:: query($sparqlQueryString)

      :param string $sparqlQuery: The SPARQL query.

.. php:class:: LinkedGeoData

     LinkedGeoData is a wrapper of LinkedGeoData Endpoint.

  .. php:method:: composeQuery(term, $dataSourceName = '', $limit = 10, $filters = array(''))

      :param string $term: The SPARQL query in plain text.
      :param string $dataSourceName: the name of data source
      :param int $limit: the max number of results
      :param array $filters: an array of URIs that will be ignored

  .. php:method:: query($sparqlQueryString)

      :param string $sparqlQuery: The SPARQL query.



.. php:class:: FederatedSearch
  
     FederatedSearch is the class provide search and operation to endpoints.
 
  .. php:method:: addEndpoints($endpointList)
     
     :param:  $endpointList: List of endpoints.

  .. php:method:: getEndpointList()
     :returns: List of endpoints.

  .. php:method:: removeEndpoints($endpointList)
     :param:  $endpointList: List of endpoints.

  .. php:method:: search($sparqlQuery)
     :param:  $ sparqlQuery: The composed SPARQL query string.
     :returns:  The search result from endpoints.


.. php:class:: ResultProcessor

     ResultProcessor is the class for filtering or re-ranking a given result set.

  .. php:method:: addOneRefiner($refiner)
    
     :param:  $refiner: The name of the refiner.

  .. php:method:: addOneRanker($ranker)
    
      :param:  $ranker: The name of the ranker.

  .. php:method:: addConfiguration($config)

      :param:  $config: The configuration of result processor.

  .. php:method:: getConfiguration()
    
      :returns:  The configuration of result processor.

  .. php:method:: process()
    
      :returns:  The processed search result.

.. php:class:: UriSearchResults

     UriSearchResults is the class for representing search results from different Endpoints with different rank scores

  .. php:method:: addOneResult($dataSourceName, $processedResult)

      :param:  $dataSourceName: The name of endpoint which the result search from. 
      :param:  $processedResult: The processed search result.

  .. php:method:: hasNextResult()
      :returns:  TRUE or FALSE

  .. php:method:: getNextResult()
      :returns:  The processed search result.
  .. php:method:: removeOneResult($uri)
      :returns:  $uri – The URI which want to remove from result.
  .. php:method:: removeMultipleResult($uris)
      :param:  $uris – The list of URIs which want to remove from result.




X2R
---

.. php:class:: X2R

     X2R models the process of translating an imperfect RDF, especially for those with invalid URIs, to RDF with relatively higher quality.  


  .. php:method:: transform($rdfGraph, $configuration)


      :param rdfGraph $graph: The RDF, which is holded in the rdfGraph data structure, to be refactored.
      :param configuration: to be defined. 
      :returns: The refactored RDF. 


Hot Spots
-----

.. php:class:: QueryRefiner

     QueryRefiner is an one-to-one adapter, which processes the raw query with the logics defined in it. A varity of refinement heuristics or methods can be introduced into X2R through extending this class.    


  .. php:method:: refine($query)


      :param string $query: The query that is directly extracted and tokenized from original URI.
      :returns: The refined query. 



.. php:class:: SearchResultSelector

     SearchResultSelector is a many-to-one selector, which selects one fittest result from a given result set. A varity of fitness function can be introduced into X2R through extending this class.   


  .. php:method:: select($resultSet)


      :param array $resultSet: A given result set. 
      :returns: The fittest result. 

