#include "mesh.h"
#include "window.h"
#include<iostream>
using namespace std;

Mesh::Mesh(const aiMesh *mesh)
{
    TextureIndex = mesh -> mMaterialIndex;

    vector<GLfloat>      vertices;
    vector<unsigned int> indices;

    for(unsigned i = 0;i < mesh -> mNumVertices;++i){
        // Position
        vertices.push_back(mesh->mVertices[i].x);
        vertices.push_back(mesh->mVertices[i].y);
        vertices.push_back(mesh->mVertices[i].z);
        // Normal
        vertices.push_back(mesh->mNormals[i].x);
        vertices.push_back(mesh->mNormals[i].y);
        vertices.push_back(mesh->mNormals[i].z);
        // Texture Coordinate
        if(mesh -> HasTextureCoords(0)){
            vertices.push_back(mesh -> mTextureCoords[0][i].x);
            vertices.push_back(mesh -> mTextureCoords[0][i].y);
        }else{
            vertices.push_back(0.0f);
            vertices.push_back(0.0f);
        }
    }

    for(unsigned i = 0;i < mesh -> mNumFaces;++i){
        const aiFace &face = mesh -> mFaces[i];
        indices.push_back( face.mIndices[0] );
        indices.push_back( face.mIndices[1] );
        indices.push_back( face.mIndices[2] );
    }
    GLfunc -> glGenBuffers(1, &VB);
    GLfunc -> glBindBuffer(GL_ARRAY_BUFFER, VB);
    GLfunc -> glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)  * 8 * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    GLfunc -> glGenBuffers(1, &IB);
    GLfunc -> glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
    GLfunc -> glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned) * indices.size(), &indices[0], GL_STATIC_DRAW);
}

Mesh::~Mesh()
{
    if (VB != INVALID_OGL_VALUE){
        GLfunc -> glDeleteBuffers(1, &VB);
    }

    if (IB != INVALID_OGL_VALUE){
        GLfunc -> glDeleteBuffers(1, &IB);
    }
}
