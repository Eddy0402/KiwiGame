#ifndef MESH_H
#define MESH_H

#include "assimp/mesh.h"
#include <vector>
#include <QOpenGLFunctions_4_3_Core>

class Mesh
{
public:
    Mesh(const aiMesh *mesh);
    ~Mesh();
    GLuint VB;
    GLuint IB;
    unsigned NumIndices;
    unsigned TextureIndex;
};

#define INVALID_OGL_VALUE 0xFFFFFFFF

#endif // MESH_H
