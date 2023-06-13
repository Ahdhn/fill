#include <assert.h>
#include <stdio.h>
#include <array>
#include <fstream>
#include <iostream>
#include <iterator>

#include "polyscope/surface_mesh.h"
#include "polyscope/surface_mesh_io.h"

int main(int argc, char** argv)
{
    polyscope::init();

    // just for the gargoyal
    polyscope::view::upDir = polyscope::UpDir::NegYUp;

    // read the mesh
    std::vector<std::array<double, 3>> vertex_coord;
    std::vector<std::vector<size_t>>   fv;
    polyscope::loadPolygonSoup_OBJ(argv[1], vertex_coord, fv);

    // register the mesh into polyscope
    polyscope::SurfaceMesh* mesh = polyscope::registerSurfaceMesh(
        polyscope::guessNiceNameFromPath(argv[1]), vertex_coord, fv);

    // read the permuation
    std::ifstream              is(argv[2]);
    std::istream_iterator<int> start(is), end;
    std::vector<int>           perm(start, end);

    // sanity check
    if (perm.size() != mesh->nVertices()) {
        std::cerr << "\nmismatch between number of vertices in the mesh and "
                     "number of lines in the input permuation file";
        exit(EXIT_FAILURE);
    }

    // add some colors to the mesh
    mesh->addVertexScalarQuantity("vPermutation", perm)->setEnabled(true);

    // render
    polyscope::show();

    return 0;
}
