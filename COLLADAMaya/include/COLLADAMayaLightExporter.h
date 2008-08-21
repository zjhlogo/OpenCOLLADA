/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_LIGHT_EXPORTER_H__
#define __COLLADA_MAYA_LIGHT_EXPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAStreamWriter.h"
#include "COLLADALibraryLights.h"


namespace COLLADAMaya
{

    /** This class writes the <library_lights>. */
    class LightExporter : public COLLADA::LibraryLights
    {
    private:

        /** Pointer to the document exporter */
        DocumentExporter* mDocumentExporter;

    public:
        /**
        * @param streamWriter The stream the output will be written to
        * @param documentExporter The document exporter this material exporter is used in
        */
        LightExporter ( COLLADA::StreamWriter* streamWriter, DocumentExporter* documentExporter );
        virtual ~LightExporter() {};

        /** Exports the lights in the scene graph. */
        void exportLights (  );

        /** Exports the current scene element and all it's children. */
        void exportLights ( SceneElement* sceneElement );

    private:

        /** Exports the geometry data of the current object, if it is a valid mesh object to export. */
        bool exportLight ( const MDagPath& dagPath );

    };

}

#endif //__COLLADA_MAYA_LIGHT_EXPORTER_H__