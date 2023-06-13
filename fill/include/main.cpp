#include <assert.h>
#include <stdio.h>
#include <array>

#include "polyscope\surface_mesh_io.h"

int main(int argc, char** argv)
{
    std::vector<std::array<double, 3>> vertexPositionsOut;
    std::vector<std::vector<size_t>>   faceIndicesOut;
    polyscope::loadPolygonSoup_OBJ(argv[1], vertexPositionsOut, faceIndicesOut);

    return 0;
}
