.. _installation:

Installation
============

Three steps are needed to set up an X2R server, namely installing PHP, installing Composer and installing dependent packages. The detail instructions are listed as follows.  

Install PHP
------------

X2R is written in PHP. Before using X2R, the PHP should be installed. 

To install PHP, an official manual is available in http://php.net/manual/en/install.php. 

  * `Installation on Unix systems <http://php.net/manual/en/install.unix.php>`_
  * `Installation on Mac OS X <http://php.net/manual/en/install.macosx.php>`_
  * `Installation on Windows systems <http://php.net/manual/en/install.windows.php>`_
  * `Installation on Cloud Computing platforms <http://php.net/manual/en/install.cloud.php>`_

Install Composer
---------

The dependency of X2R is managed by 'composer,' a PHP package management tool. 
Before trying X2R, get and install composer from https://getcomposer.org/.

Run this in your terminal to get the latest Composer version::

   $ curl -sS https://getcomposer.org/installer | php

Or if you don't have curl::

   $ php -r "readfile('https://getcomposer.org/installer');" | php


Install Dependent Packages
------------------

Installing X2R is simple with `composer <https://getcomposer.org/>`_. Just use this command::

    $ php composer.phar install

If you did a global install of `composer <https://getcomposer.org/>`_, run instead::

    $ composer install