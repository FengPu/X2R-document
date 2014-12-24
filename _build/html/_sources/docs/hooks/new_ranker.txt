.. _hook_ranker:

Add a new ranker
-----------------

Involved Files
================

    ResultRanker.class.php, UssContainer.php

Mechanism
=========

    #. Create a new class in /USS/ranker/
    #. The new class should exntends ResultRanker, for example 'newRanker.class.php'
    #. Open ussContainer.class.php, and add the dependency by adding "include_once ranker/newRankerclass.php;" statement in it
    #. Add a case block of the new class into getRanker() method's switch block

Template
========
    :ref:`hook_template_uss`