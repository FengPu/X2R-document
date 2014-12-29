.. _hook_new_endpoint:

Add a new Endpoint
----------------------------


Involved Classes
================

    Endpoint.class.php

Mechanism
=========

    #. Create a new class in /USS/endpoints
    #. New class should implement two methods, *composeQuery()* and *query()*, where the composeQuery() defines how to compose a SPARQL query according to this endpoint and query() defines how to send query to this endpoint
    #. The endpoint.class.php should include this new endpoint class
    #. Add new case in methods composeSparqlQuery() and performQuery() of endpoint.class.php


Example
==========


   - :php:class:`Dbpedia`
   - :php:class:`LinkedGeoData`
