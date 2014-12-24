.. _hook_query_parser:

Add a new query parser
----------------------

Involved Files
================

    QueryParser.class.php, UssContainer.php

Mechanism
=========

    #. Create a new class in /USS/parser/
    #. The new class should exntends QueryParser, for example 'newParser.class.php'
    #. Open ussContainer.class.php, and add the dependency by adding "include_once parser/newParser.class.php;" statement in it
    #. Add a case block of the new class into getParser() method's switch block

Template
========
    :ref:`hook_template_uss`