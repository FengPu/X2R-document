.. _uss:

URI Search Service
==================

URI Search Service (USS) is a federated search service. The general process of USS is listed below. 

#. USS accepts a set of URI search requests 
#. USS refines the search requests (e.g. fixing typos or replace with a better term)
#. USS composes corresponding SPARQL for each query request
#. USS issues SPARQL queries to a set of Endpoints, which are defined in USS's configuration

#. USS integrates all results returned from Endpoints

#. USS applies filters and rankers to remove the ambiguity or promote results that are commonly used

#. USS selects one result for each request


All steps listed above should be easily replacable. These steps can also be outsourced to human instead of heuristics. In order to make USS a flexible system, we provide the system with the following hooks.  


In refined USS, seven **atomic hooks** can be replaced and extended, they are: 

* **Query Parser**

  Query Parser parses the plain text query string into set of query terms, term refinement qualifiers, result set qualifiers and corresponding integration commands.

* **Endpoint Cotainer**
  
.. _Endpoint:
* **Endpoint** (see also: :php:class:`Endpoint`)

  Endpoint wraps the public Endpoint, such as DBpedia, and handles the errors, such as Endpoint service downtime. Endpoint accepts SQARQL query and return the result set in standard format of Endpoint. 

* **Term Refiner**

  Term Refiner takes one query term as its input and output a refined query term.  

* **Result Ranker**

  Result Ranker reorders the ranks of result set based on the heuristic that it wants to realize. In addition to heuristic, Result Ranker can also be a crowd sourcing task, which can be delegated to the crowd. 

* **Result Filter**

  Result Filter filters result set by patterns. The typical usage of Result Filter is to resolve ambiguity.  

..  (Term filters: filter some terms) Result Filter takes two input parameters: the filtered size and the result set. The filtered size, which determine the size of returned result set, sholud be larger than zero. The first ''filtered size'' results will be returned as the filtered result set. 

* **Result Integrator**

  Result Integrator takes two or more result sets and integrates them as one ranked result set. 

* **Result Selector**


Composition of atomic hooks
^^^^^^^^^^^^^^^^^^^^^^^^^^^

  The atomic hooks can be composited through method chaining.   


**Examples:**

 #. This request returns the results that match the search query terms "typhoon" AND "weather" from "http://dbpedia.org/sparql".

 #. Example 2: This request returns the results that match the search query terms "country" from "http://dbpedia.org/sparql" and "http://linkedgeodata.org/sparql". 


.. figure:: ./figs/uss_2.PNG
     :scale: 80%
     :alt: test




Web API Definition
^^^^^^^


.. http:get:: /uss{?q, sites, output, start, num}

   :query q: *(required)* Search term of interest.
   :query sites: *(required)* The sites to search term. Has default value.
   :query format: *(required)* The format of returned result. 
   :query start: *(optional)* The offset to specify the index of returned result.
   :query num: *(optional)* The number of returned result. Use with start in the search query.
   :resheader Content-Type: application/json
   :statuscode 200: no error
   :statuscode 404: exception


Response template:

.. sourcecode:: json

  {
   “term”:”typhoon”,
   “data”:[array of searched URI results]
  }

Data entry:

.. sourcecode:: json

  "data": [
   {
    "dataSourceName": "http://dbpedia.org",
    "response": {
     "head": {
      "link": [],
      "vars": [
       "s",
       "o"
      ]
     },
     "results": {objects of returned URI results}
     }
  }
  ]

Result entry

.. sourcecode:: json

  "results": {
      "distinct": false,
      "ordered": true,
      "bindings": [
       {
        "s": {
         "type": "uri",
         "value": "http://wikidata.dbpedia.org/uri_1"
        },
        "o": {
         "type": "literal",
         "xml:lang": "en",
         "value": "typhoon"
        }
       }
     ]
  }


Example
^^^^^^^

**Example request:**


 .. sourcecode:: http

    GET /uss?q=typhoon&sites&output=json


**Example response:**

.. sourcecode:: json

  {
   "term": "typhoon",
   "data": [
   {
    "dataSourceName": "http://dbpedia.org",
    "response": {
     "head": {
      "link": [],
      "vars": [
       "s",
       "o"
      ]
     },
     "results": {
      "distinct": false,
      "ordered": true,
      "bindings": [
       {
        "s": {
         "type": "uri",
         "value": "http://wikidata.dbpedia.org/uri_1"
        },
        "o": {
         "type": "literal",
         "xml:lang": "en",
         "value": "typhoon"
        }
       },
       {
        "s": {
         "type": "uri",
         "value": "http://dbpedia.org/resource/uri_2"
        },
        "o": {
         "type": "literal",
         "xml:lang": "en",
         "value": "Typhoon shelters in Hong Kong"
        }
       }                        
      ]
     }
    }
   }
  ]
  } 






