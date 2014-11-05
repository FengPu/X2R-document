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

