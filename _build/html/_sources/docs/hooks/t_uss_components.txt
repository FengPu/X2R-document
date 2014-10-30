.. _hook_template_uss:

Template: Add USS Components
----------------------------


Involved Classes
================

    **{List of involved classes with links}**

Mechanism
=========

    #. Based on component's type, create a new class in /USS/**{component_type}**/
    #. Based on the component's type, the new class should exntends corresponding parent class
    #. Open ussContainer.class.php, and add the dependency by adding "incclude_once" statement in it
    #. Based on component's type, find corresponding method and add the {id, class_factory} mapping to the method's switch/case block.


Instances
==========

   - :ref:`hook_refiner`
   - :ref:`hook_filter`
   - :ref:`hook_ranker` 
   - :ref:`hook_selector`
   - :ref:`hook_query_parser`   
