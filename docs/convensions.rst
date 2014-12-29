Convensions
------------

Coding Style
++++++++++++

This project follows the Python official coding style `PSR`_.

.. _PSR: http://www.php-fig.org/psr/


Here are some examples for developers' reference. 

 * Class names MUST be declared in StudlyCaps. 

    For example: 

    .. code-block:: php

        <?php    
	    class  HtmlHelper
	    class  XmlParser
	    class  Model

 * Class constants MUST be declared in all upper case with underscore separators. For example:

    For example: 
  
    .. code-block:: php

		<?php
		namespace Vendor\Model;

		class Foo
		{
		    const VERSION = '1.0';
		    const DATE_APPROVED = '2012-06-01';
		}

 * Method names MUST be declared in camelCase.

    For example: 

    .. code-block:: php

        <?php
		connect();
		getData();
		buildSomeWidget();
		jImport();
		jDoSomething();

Namespaces and classes MUST follow an "autoloading" PSR: [PSR-0,PSR-4].
This means each class is in a file by itself, and is in a namespace of at least one level: a top-level vendor name.

  *. Class names MUST be declared in StudlyCaps. Code written for PHP 5.3 and after MUST use formal namespaces.

    For example: 

    .. code-block:: php

		<?php
		// PHP 5.3 and later:
		namespace Vendor\Model;

		class Foo
		{
		}

 * Code written for 5.2.x and before SHOULD use the pseudo-namespacing convention of Vendor_ prefixes on class names.

     For example: 

    .. code-block:: php

		 <?php
		// PHP 5.2.x and earlier:
		class Vendor_Model_Foo
		{
		}

Versioning
++++++++++++

The versioning follows `Semantic Versioning 2.0`_.

.. _Semantic Versioning 2.0: http://semver.org/

Here quote the summary of Semantic Version below:

Given a version number MAJOR.MINOR.PATCH, increment the:

    MAJOR version when you make incompatible API changes,
    MINOR version when you add functionality in a backwards-compatible manner, and
    PATCH version when you make backwards-compatible bug fixes.

Additional labels for pre-release and build metadata are available as extensions to the MAJOR.MINOR.PATCH format.


Documentation
+++++++++++++

For documentation, this project uses `Sphinx`_, which is a Python documentation generator. 
The syntax used in Sphinx is `reStructuredText`_.  

.. _Sphinx: http://sphinx-doc.org/
.. _reStructuredText: http://docutils.sourceforge.net/rst.html


Here is a full code comment example quoted from `Documenting Your Project Using Sphinx`_. 
