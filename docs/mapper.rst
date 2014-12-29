.. _mapper:

Mapper
======

Mapper is a tool for systematically replacing URIs within a given RDF. When you have the mapping from original URIs to new URIs, Mapper can replace the URIs based on the mapping automatically.


Input/Output
------------


**Input**: *X2R data exchange format* and *string in a RDF serialization format*

Components of X2R share a common data exchange format: *X2R data exchange format*. The output of Extractor is in the foramt of X2R data exchange format. The detail spec. of this exchange format is described below. 

.. code-block:: json

 { "metadata": [],
   "mapping": 
     [
         {
          "status": status value,
          "originalURI": original URI value, 
          "replacedURI": updated URI value, 
          "term": term value
          }
     ]
  }


**Output**: string in a RDF serialization format 

Mapper allow user to specify the updated RDF in the format of a subset of RDF serialization formats listed in the Table below. 

======== =========== =================================================
value    name        reference
======== =========== =================================================
json     RDF/JSON    http://n2.talis.com/wiki/RDF_JSON_Specification
ntriples N-Triples   http://www.w3.org/TR/n-triples/
turtle   Turtle      http://www.dajobe.org/2004/01/turtle
rdfxml   RDF/XML     http://www.w3.org/TR/rdf-syntax-grammar
n3       N3          http://www.w3.org/2000/10/swap/grammar/n3
rdfa     RDFa        http://www.w3.org/TR/rdfa-core/
======== =========== =================================================

Web API Definition
^^^^^^^^^^^^^^^^^^

.. http:post:: /mapper{?rdfContent, mapping, format}



   :query rdfContent: (required) This specifies the content of RDF to be processed. 
   :query mapping: (required) This specifies the information needed for `mapper` to update the URIs found in rdfContent.
   :query format: (optional) This specifies the format of output.
   :resheader Content-Type: application/rdf+xml
   :statuscode 200: no error
   :statuscode 404: exception


Query Parameter Format Detail
*****************************

:rdfContent:

:mapping:

:format:

Response Format Detail
**********************

Content-Type: application/rdf+xml
    
Example
^^^^^^^

   **Example request**:

   .. sourcecode:: http

      POST /mapper?rdfContent=input_value&mapping=mapping_value&format=rdfxml HTTP/1.1


   *input_value*:
       .. sourcecode:: http

           <?xml version="1.0" encoding="UTF-8"?>
               <rdf:RDF
                   xmlns:rdfs="http://www.w3.org/2000/01/rdf-schema#"
                   xmlns:geo="http://www.w3.org/2003/01/geo/wgs84_pos#"
                   xmlns:xsd="http://www.w3.org/2001/XMLSchema#"
                   xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">

           <rdf:Description rdf:about="http://127.0.0.1/DaTongSportsCenter">
               <rdf:type rdf:resource="http://www.w3.org/2003/01/geo/wgs84_pos#SpatialThing"/>
               <updatedAt xmlns="http://openisdm.iis.sinica.edu.tw/VR/" 
                   rdf:datatype="http://www.w3.org/2001/XMLSchema#dateTime">2013-07-31T03:23:47Z</updatedAt>
               <geo:long>121.516</geo:long>
               <hasTelephone xmlns="http://openisdm.iis.sinica.edu.tw/VR/">2592-0055</hasTelephone>
               <hasName xmlns="http://openisdm.iis.sinica.edu.tw/VR/">Da Tong Sports Center</hasName>
               <geo:location>No.51, Dalong St., Datong Dist., Taipei City 103, Taiwan (R.O.C.)</geo:location>
               <usedFor xmlns="http://openisdm.iis.sinica.edu.tw/VR/">Sport</usedFor>
               <createdAt xmlns="http://openisdm.iis.sinica.edu.tw/VR/" 
                   rdf:datatype="http://www.w3.org/2001/XMLSchema#dateTime">2012-11-28T09:05:13Z</createdAt>
               <geo:lat>25.0648</geo:lat>
           </rdf:Description>

          <rdf:Description rdf:about="http://127.0.0.1/ShilinSportsCenter">
            <rdf:type rdf:resource="http://www.w3.org/2003/01/geo/wgs84_pos#SpatialThing"/>
            <updatedAt xmlns="http://openisdm.iis.sinica.edu.tw/VR/" 
                rdf:datatype="http://www.w3.org/2001/XMLSchema#dateTime">2013-07-31T03:23:47Z</updatedAt>
            <geo:long>121.521</geo:long>
            <hasTelephone xmlns="http://openisdm.iis.sinica.edu.tw/VR/">2880-6066</hasTelephone>
            <hasName xmlns="http://openisdm.iis.sinica.edu.tw/VR/">Shilin Sports Center</hasName>
            <geo:location>No.1, Shishang Rd., Shilin Dist., Taipei City 111, Taiwan (R.O.C.)</geo:location>
            <usedFor xmlns="http://openisdm.iis.sinica.edu.tw/VR/">Sport</usedFor>
            <createdAt xmlns="http://openisdm.iis.sinica.edu.tw/VR/" 
                rdf:datatype="http://www.w3.org/2001/XMLSchema#dateTime">2012-11-28T09:05:13Z</createdAt>
            <geo:lat>25.0897</geo:lat>
          </rdf:Description>

           </rdf:RDF>
    
     *mapping_value*:
       .. sourcecode:: json

           { "metadata": [],
             "mapping": 
               [
                   {
                    "status": "N/A",
                    "originalURI": "http://127.0.0.1/DaTongSportsCenter", 
                    "replacedURI": "http://openisdm.iis.sinica.edu.tw/VR/DaTongSportsCenter", 
                    "term": "Datong Sports Center"
                    },
                    {
                    "status": "N/A",
                    "originalURI": "http://127.0.0.1/ShilinSportsCenterr", 
                    "replacedURI": "http://openisdm.iis.sinica.edu.tw/VR/ShilinSportsCenter", 
                    "term": "Shilin Sports Center"
                    }
               ]
            }




   **Example response**:

   .. sourcecode:: http

      HTTP/1.1 200 OK
      Vary: Accept
      Content-Type: application/rdf+xml

     <?xml version="1.0" encoding="UTF-8"?>
         <rdf:RDF
             xmlns:rdfs="http://www.w3.org/2000/01/rdf-schema#"
             xmlns:geo="http://www.w3.org/2003/01/geo/wgs84_pos#"
             xmlns:xsd="http://www.w3.org/2001/XMLSchema#"
             xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">

      <rdf:Description rdf:about="http://openisdm.iis.sinica.edu.tw/VR/DatongSportsCenter">
         <rdf:type rdf:resource="http://www.w3.org/2003/01/geo/wgs84_pos#SpatialThing"/>
         <updatedAt xmlns="http://openisdm.iis.sinica.edu.tw/VR/" 
             rdf:datatype="http://www.w3.org/2001/XMLSchema#dateTime">2013-07-31T03:23:47Z</updatedAt>
         <geo:long>121.516</geo:long>
         <hasTelephone xmlns="http://openisdm.iis.sinica.edu.tw/VR/">2592-0055</hasTelephone>
         <hasName xmlns="http://openisdm.iis.sinica.edu.tw/VR/">Datong Sports Center</hasName>
         <geo:location>No.51, Dalong St., Datong Dist., Taipei City 103, Taiwan (R.O.C.)</geo:location>
         <usedFor xmlns="http://openisdm.iis.sinica.edu.tw/VR/">Sport</usedFor>
         <createdAt xmlns="http://openisdm.iis.sinica.edu.tw/VR/" 
             rdf:datatype="http://www.w3.org/2001/XMLSchema#dateTime">2012-11-28T09:05:13Z</createdAt>
         <geo:lat>25.0648</geo:lat>
      </rdf:Description>

      <rdf:Description rdf:about="http://openisdm.iis.sinica.edu.tw/VR/ShilinSportsCenter">
        <rdf:type rdf:resource="http://www.w3.org/2003/01/geo/wgs84_pos#SpatialThing"/>
        <updatedAt xmlns="http://openisdm.iis.sinica.edu.tw/VR/" 
            rdf:datatype="http://www.w3.org/2001/XMLSchema#dateTime">2013-07-31T03:23:47Z</updatedAt>
        <geo:long>121.521</geo:long>
        <hasTelephone xmlns="http://openisdm.iis.sinica.edu.tw/VR/">2880-6066</hasTelephone>
        <hasName xmlns="http://openisdm.iis.sinica.edu.tw/VR/">Shilin Sports Center</hasName>
        <geo:location>No.1, Shishang Rd., Shilin Dist., Taipei City 111, Taiwan (R.O.C.)</geo:location>
        <usedFor xmlns="http://openisdm.iis.sinica.edu.tw/VR/">Sport</usedFor>
        <createdAt xmlns="http://openisdm.iis.sinica.edu.tw/VR/" 
            rdf:datatype="http://www.w3.org/2001/XMLSchema#dateTime">2012-11-28T09:05:13Z</createdAt>
        <geo:lat>25.0897</geo:lat>
      </rdf:Description>

     </rdf:RDF>