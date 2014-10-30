.. _hook_filter:

Add a new filter
----------------


Involved Classes
================

    resultfilter.class.php, ussContainer.php

Mechanism
=========

    #. Create a new class in /USS/filter/
    #. The new class should exntends ResultFilter, for example 'newFilter.class.php'
    #. Open ussContainer.class.php, and add the dependency by adding "include_once filter/newFilter.class.php;" statement in it
    #. Add a case block of the new class into getFilter() method's switch block

Template
========
    :ref:`hook_template_uss`