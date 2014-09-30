.. _uss:

URI Search Service
==================

URI Search Service (USS) 1.0 is monolithic, hard wired with the GUI and not take batch-mode search into consideration. In this revision, we conduct refactoring and introduce some flexibilities through several hooks. In the following paragraphs, the refactored USS is presented with several useful hooks.  


Refactored USS kernel
---------------------



Hooks
-----

In refined USS, three **atomic hooks** can be replaced and extended, they are: 

* **Query Refiner**

  Query Refiner takes one query string as its input and output a refined query string.  

* **Result Ranker**

  Result Ranker reorder the ranks of result set based on the heuristic that it wants to realize. In addition to heuristic, Result Ranker can also be a crowd sourcing task, which can be delegated to the crowd. 

* **Result Filter**

  Result Filter takes two input parameters: the filtered size and the result set. The filtered size, which determine the size of returned result set, sholud be larger than zero. The first ''filtered size'' results will be returned as the filtered result set. 


Composition of atomic hooks
^^^^^^^^^^^^^^^^^^^^^^^^^^^

  The atomic hooks can be composited through method chaining.   