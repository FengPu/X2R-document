Introduction
------------

**X2R** is a tool for helping Semantic Web application developers to translate existing data in a variety of formats into Linked-data compatible formats, where the **X**, **2** and **R** stand for existing data in a variety formats, to (the homonym of two) and Linked-data compatible formats (i.e., RDF/XML), respectively. 

Our motivation is to smooth the transition from existing *Web* to *Semantic Web* by providing tools, which can dramatically lower the entry barrier of generating Linked-data, to developers. By providing such tools, i.e., X2R, more and more developers can translate existing data on-demands, and the final vision of Semantic Web can be approached incrementally.  

.. toctree::
    :maxdepth: 1

    docs/roadmap
    docs/audience
    docs/howto

The index can be found in :ref:`genindex`, and the search page, :ref:`search`, can be used to search within this document. 


User Guide
---------------
This part of the guide focuses on setting up your environment for X2R and all its components, including Extractor, Mapper and USS. A quickstart is then presented to give an overview of X2R and its components. Finally, details of each components are presented. 

.. toctree::
    :maxdepth: 1


    docs/install
    docs/quickstart
    docs/map


Components 
-----------------------
.. toctree::
    :maxdepth: 1

    docs/extractor
    docs/mapper
    docs/uss
    docs/x2r

API Usage Scenarios
------------------
Targeted Audience: **API users**

.. toctree::
    :maxdepth: 3

    docs/scenarios/x2r


    docs/scenarios/extractor


    docs/scenarios/uss


    docs/scenarios/mapper




Framework Hooks
---------------
Targeted Audience: **Code contributators**

This section focuses on two topics, i.e. **hook templates** and **hook instances**. The term "hook" is used to present the cookbook or guidence for extending X2R in many different aspects. Because some hooks are similar to each other, the hook templates are extracted based on the similarity among existing hooks. Extracted hook templates can be used to instainate more hook instances to cover more aspects for increasing X2R's flexability.   

**Hook Templates**

.. toctree::
    :maxdepth: 1
    
    docs/hooks/t_uss_components
    docs/hooks/t_rdf_parser
    docs/hooks/t_tokenizer

**Hook Instances**

.. toctree::
    :maxdepth: 1

    docs/hooks/new_endpoint
    docs/hooks/new_tokenizer
    docs/hooks/new_parser
    docs/hooks/new_refactor
    docs/hooks/new_selector
    docs/hooks/new_ranker
    docs/hooks/new_refiner
    docs/hooks/new_filter




API Reference
-------------
This part of the documentation dedicates to prople who are looking for information on a specific function, class or method.

.. toctree::
    :maxdepth: 3

    docs/api



Additional Note
---------------
This part of note declares the license of X2R. 

.. toctree::
    :maxdepth: 1

    docs/license


