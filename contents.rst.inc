Important Information
---------------
For code contributors' information, this part of note declares the license of X2R. In addition to license, this part of note also lists convensions enforced within X2R, including the coding style, versioning and documentation. 

.. toctree::
    :maxdepth: 1

    docs/license
    docs/convensions


Introduction
------------

**X2R** is a tool for helping developers to translate existing data in a variety of formats into linked-data compatible formats. The **X**, **2** and **R** in its name stand for existing data in a variety formats, to (the homonym of two) and linked-data compatible formats (i.e., RDF/XML), respectively. 

The motivation is to ease the transformation of data into linked-data and thus lower the entry barrier of generating linked-data. Using X2R, more developers can easily translate existing data on-demands, and creating linked-data incrementally.  

.. figure:: ./docs/figs/dataflow_small.png
     :scale: 80%
     :alt: test

     The dataflow of X2R converter.


X2R is comprised of four components: Extractor, USS, UMS and Mapper. Figure above shows the dataflow of these four components and existing RDFizer(translators). For a given raw data input in X (XML, CSV, JSON ...etc.) format, existing RDFizers can translated it into RDF serialization formats, such as Turtle, N-Triples, JSON-LD or RDF/XML. However,     


.. toctree::
    :maxdepth: 1


    docs/audience
    docs/howto

The index of this document can be found in :ref:`genindex`. The search page, :ref:`search`, can be used to search within this document. 


User Guide
---------------
This part of the document focuses on how to set up an environment for X2R and all its components: Extractor, Mapper and USS. A quickstart is then presented to give an overview of X2R and its components. 

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

API Usage 
------------------
Targeted Audience: **API users**

.. toctree::
    :maxdepth: 3

    docs/scenarios/x2r


    docs/scenarios/extractor


    docs/scenarios/uss


    docs/scenarios/mapper


API Reference
-------------
This part of the documentation dedicates to prople who are looking for information on a specific function, class or method.

.. toctree::
    :maxdepth: 3

    docs/api


Hooks
---------------
Targeted Audience: **Code contributators**

This section focuses on two topics, i.e. **hook templates** and **hook instances**. The term "hook" is used to present the cookbook or guidence for extending X2R in many different aspects. Because some hooks are similar to each other, the hook templates are extracted based on the similarity among existing hooks. Extracted hook templates can be used to instainate more hook instances to cover more aspects for increasing X2R's flexability.   

**Hook Templates**

.. toctree::
    :maxdepth: 1
    
    docs/hooks/t_uss_components


**Hook Instances**

.. toctree::
    :maxdepth: 1

    docs/hooks/new_endpoint
    docs/hooks/new_parser
    docs/hooks/new_refactor
    docs/hooks/new_selector
    docs/hooks/new_ranker
    docs/hooks/new_refiner
    docs/hooks/new_filter
    docs/hooks/t_rdf_parser
    docs/hooks/t_tokenizer








