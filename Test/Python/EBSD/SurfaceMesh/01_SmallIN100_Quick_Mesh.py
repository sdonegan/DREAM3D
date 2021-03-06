# Pipeline : (01) SmallIN100 Quick Mesh (from EBSD Surface Meshing)

import simpl
import simplpy as d3d
import simpl_helpers as sc
import simpl_test_dirs as sd
import samplingpy as sampling
import surfacemeshingpy as surfacemeshing

def small_in100_quickmesh():
    # Create Data Container Array
    dca = simpl.DataContainerArray()

    # Read DREAM3D File
    err = sc.ReadDREAM3DFile(dca, sd.GetBuildDirectory() + '/Data/Output/Statistics/SmallIN100_CrystalStats.dream3d')
    
    if err < 0:
        print('DataContainerReader ErrorCondition %d' % err)

    # Crop Geometry (Image)
    err = sampling.crop_image_geometry(dca, '',
                                       simpl.DataArrayPath('Small IN100', 'EBSD Scan Data', ''),
                                       simpl.DataArrayPath('Small IN100', 'Grain Data', ''),
                                       41, 41, 0, 140, 140, 99, True, False, True,
                                       simpl.DataArrayPath('Small IN100', 'EBSD Scan Data', 'FeatureIds'))
    if err < 0:
        print('CropImageGeometry ErrorCondition %d' % err)

    # Quick Surface Mesh
    err = surfacemeshing.quick_surface_mesh(dca,
                                            [],
                                            'TriangleDataContainer',
                                            'VertexData',
                                            'FaceData',
                                            simpl.DataArrayPath('Small IN100', 'EBSD Scan Data', 'FeatureIds'),
                                            'FaceLabels',
                                            'NodeType',
                                            'FaceFeatureData')
    if err < 0:
        print('QuickSurfaceMesh ErrorCondition %d' % err)

    # Write to DREAM3D file
    err = sc.WriteDREAM3DFile(sd.GetBuildDirectory() + '/Data/Output/SurfaceMesh/SmallIN100_Meshed.dream3d',
                              dca)
    if err < 0:
        print('WriteDREAM3DFile ErrorCondition: %d' % err)

if __name__ == '__main__':
    small_in100_quickmesh()
