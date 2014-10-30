.. _hook_selector:

Add a new selector
-----------------

Involved Files
================

    resultselector.class.php, ussContainer.php

Mechanism
=========

    #. Create a new class in /USS/selector/
    #. The new class should exntends ResultSelector, for example 'newSelector.class.php'
    #. Open ussContainer.class.php, and add the dependency by adding "include_once selector/newSelector.class.php;" statement in it
    #. Add a case block of the new class into getSelector() method's switch block

Template
========
    :ref:`hook_template_uss`