.. _hook_refiner:

Add a new refiner
-----------------

Involved Files
================

    queryrefiner.class.php, ussContainer.php

Mechanism
=========

    #. Create a new class in /USS/refiner/
    #. The new class should exntends QueryRefiner, for example 'newRefiner.class.php'
    #. Open ussContainer.class.php, and add the dependency by adding "include_once refiner/newRefiner.class.php;" statement in it
    #. Add a case block of the new class into getRefiner() method's switch block

Template
========
    :ref:`hook_template_uss`