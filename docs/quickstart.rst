.. _quickstart:

Quickstart
==========

This page give a a minimal usage scenario for grasping the whole picture of X2R by example. It assumes you already have X2R installed. If you do not, head over to the :ref:`installation` section.

A Minimal Usage Scenario
------------------------

X2R aims to improve the quality of RDF by replacing temporary or invalid URIs with valid and representive URIs. 

Before letting X2R do the URIs replacemant task for you, you should make sure the configuration file, X2R.conf, are 
consistent with your requirements.  


**X2R.conf**::

 { "USS":       [ 
                  {"endpoints": [
                                  { "name"  : "dbpedia",
                                    "class" : "endpoints/dbpedia.php"
                                  },
                                  { "name"  : "linkedgeodata",
                                    "class" : "endpoints/linkedgeodata.php"
                                  }

                                ]
                   },
                   {"refiners": [
                                  { "name"  : "dbpedia",
                                    "class" : "endpoints/dbpedia.php"
                                  },
                                  { "name"  : "linkedgeodata",
                                    "class" : "endpoints/linkedgeodata.php"
                                  }
                                ]
                   },
                   {"parser": {"name"  : "dbpedia",
                               "class" : "endpoints/dbpedia.php"
                              }
                   },
                   {"selector": {"name"  : "dbpedia",
                                 "class" : "endpoints/dbpedia.php"
                                }
                   },
                   {"rankers": [
                                  { "name"  : "dbpedia",
                                    "class" : "endpoints/dbpedia.php"
                                  },
                                  { "name"  : "linkedgeodata",
                                    "class" : "endpoints/linkedgeodata.php"
                                  }
                               ]

                   }



                ],

   "Extractor": [ {"tokenizers": [
                                  { "name"  : "CaseBasedTokenizer",
                                    "class" : "EM/caseBasedTokenizer.class.php"
                                  },
                                  { "name"  : "DelimitBasedTokenizer",
                                    "class" : "EM/delimitBasedTokenizer.class.php"
                                  }  
                                 ] 
                  }

                ],

   "Mapper":    [
                   {"output_format": "xml/rdf"
                   }
                ],
 }

