/* ============================================================================
 * Copyright (c) 2012 Michael A. Jackson (BlueQuartz Software)
 * Copyright (c) 2012 Dr. Michael A. Groeber (US Air Force Research Laboratories)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * Neither the name of Michael A. Groeber, Michael A. Jackson, the US Air Force,
 * BlueQuartz Software nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior written
 * permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  This code was written under United States Air Force Contract number
 *                           FA8650-07-D-5800
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#ifndef _ArraySelectionExample_H_
#define _ArraySelectionExample_H_

#include <QtCore/QString>

#include "DREAM3DLib/DREAM3DLib.h"
#include "DREAM3DLib/Common/DREAM3DSetGetMacros.h"
#include "DREAM3DLib/DataArrays/IDataArray.h"
#include "DREAM3DLib/Common/AbstractFilter.h"

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
/*
 * Look at Generic/RemoveArrays class for code on how to write the values to the .dream3d file.
 */


/**
 * @class ArraySelectionExample ArraySelectionExample.h ExamplePlugin/Code/ExamplePluginFilters/ArraySelectionExample.h
 * @brief
 * @author
 * @date
 * @version 1.0
 */
class ArraySelectionExample : public AbstractFilter
{
  public:
    DREAM3D_SHARED_POINTERS(ArraySelectionExample)
    DREAM3D_STATIC_NEW_MACRO(ArraySelectionExample)
    DREAM3D_TYPE_MACRO_SUPER(ArraySelectionExample, AbstractFilter)

    virtual ~ArraySelectionExample();
    DREAM3D_INSTANCE_STRING_PROPERTY(DataContainerName)

    /* Place your input parameters here. You can use some of the DREAM3D Macros if you want to */

    // -----------------------------------------------------------------------------
    /* These methods are needed if you use the ArraySelectionWidget as an input */
    typedef QSet<QString> ArrayList_t;

    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedVolumeVertexArrays)
    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedVolumeEdgeArrays)
    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedVolumeFaceArrays)
    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedVolumeCellArrays)
    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedVolumeCellFieldArrays)
    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedVolumeCellEnsembleArrays)

    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedSurfaceVertexArrays)
    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedSurfaceEdgeArrays)
    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedSurfaceFaceArrays)
    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedSurfaceFaceFieldArrays)
    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedSurfaceFaceEnsembleArrays)

    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedEdgeVertexArrays)
    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedEdgeEdgeArrays)
    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedEdgeEdgeFieldArrays)
    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedEdgeEdgeEnsembleArrays)

    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedVertexVertexArrays)
    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedVertexVertexFieldArrays)
    DREAM3D_INSTANCE_PROPERTY(QSet<QString>, SelectedVertexVertexEnsembleArrays)
    /* END BLOCK FOR ArraySelectionWidget Input */
    // -----------------------------------------------------------------------------



    /**
    * @brief This returns the group that the filter belonds to. You can select
    * a different group if you want. The string returned here will be displayed
    * in the GUI for the filter
    */
    virtual const QString getGroupName() { return "ExamplePlugin"; }

    /**
    * @brief This returns a string that is displayed in the GUI. It should be readable
    * and understandable by humans.
    */
    virtual const QString getHumanLabel() { return "ArraySelectionExample"; }

    /**
    * @brief This returns a string that is displayed in the GUI and helps to sort the filters into
    * a subgroup. It should be readable and understandable by humans.
    */
    virtual const QString getSubGroupName() { return "Misc"; }

    /**
    * @brief This method will instantiate all the end user settable options/parameters
    * for this filter
    */
    virtual void setupFilterParameters();

    /**
    * @brief This method will write the options to a file
    * @param writer The writer that is used to write the options to a file
    */
    virtual int writeFilterParameters(AbstractFilterParametersWriter* writer, int index);

    /**
    * @brief This method will read the options from a file
    * @param reader The reader that is used to read the options from a file
    */
    virtual void readFilterParameters(AbstractFilterParametersReader* reader, int index);

    /**
     * @brief Reimplemented from @see AbstractFilter class
     */
    virtual void execute();

    /**
    * @brief This function runs some sanity checks on the DataContainer and inputs
    * in an attempt to ensure the filter can process the inputs.
    */
    virtual void preflight();


    virtual void setVolumeSelectedArrayNames(QSet<QString> selectedVertexArrays,
                                             QSet<QString> selectedFaceArrays,
                                             QSet<QString> selectedEdgeArrays,
                                             QSet<QString> selectedCellArrays,
                                             QSet<QString> selectedFieldArrays,
                                             QSet<QString> selectedEnsembleArrays);
    virtual void setSurfaceSelectedArrayNames(QSet<QString> selectedVertexArrays,
                                              QSet<QString> selectedEdgeArrays,
                                              QSet<QString> selectedFaceArrays,
                                              QSet<QString> selectedFieldArrays,
                                              QSet<QString> selectedEnsembleArrays);
    virtual void setEdgeSelectedArrayNames(QSet<QString> selectedVertexArrays,
                                           QSet<QString> selectedEdgeArrays,
                                           QSet<QString> selectedFieldArrays,
                                           QSet<QString> selectedEnsembleArrays);
    virtual void setVertexSelectedArrayNames(QSet<QString> selectedVertexArrays,
                                             QSet<QString> selectedFieldArrays,
                                             QSet<QString> selectedEnsembleArrays);

  protected:
    ArraySelectionExample();

    /**
    * @brief Checks for the appropriate parameter values and availability of
    * arrays in the data container
    * @param preflight
    * @param voxels The number of voxels
    * @param fields The number of fields
    * @param ensembles The number of ensembles
    */
    void dataCheck(bool preflight, size_t voxels, size_t fields, size_t ensembles);

  private:

    ArraySelectionExample(const ArraySelectionExample&); // Copy Constructor Not Implemented
    void operator=(const ArraySelectionExample&); // Operator '=' Not Implemented
};

#endif /* _ArraySelectionExample_H_ */