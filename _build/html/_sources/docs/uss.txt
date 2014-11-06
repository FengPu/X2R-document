.. _uss:

URI Search Service
==================

URI Search Service (USS) is a federated search service. The general process of USS is listed below. 

#. USS accepts a set of URI search requests 
#. USS refines the search requests (e.g. fixing typos or replace with a better term)
#. USS composes corresponding SPARQL for each query request
#. USS issues SPARQL queries to a set of Endpoints, which are defined in USS's configuration

#. USS integrates all results returned from Endpoints

#. USS applies filters and rankers to remove the ambiguity or promote results, which are more popular

#. USS selects one result for each request


All steps mentioned above should be easily replacable. These steps can also be outsourced to human instead of heuristics. In order to make USS a flexible system, we conduct adaptive maintainance on USS 0.1. 

USS 0.1 is monolithic, hard wired with the GUI and not take batch-mode search into consideration. In this revision, we conduct refactoring and introduce some flexibilities through several hooks. In the following paragraphs, the refactored USS is presented with several useful hooks.  


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