#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <iostream>
#include "model.h"
#include "window.h"

using namespace std;

Model::Model(QString modelFile) : isValid(false) {

    Assimp::Importer importer;
    string fileName = "../Project2/Model/";
    for(auto c : modelFile) fileName.push_back( c.toLatin1() );
    const aiScene* scene = importer.ReadFile(fileName,
                               aiProcess_CalcTangentSpace       |
                               aiProcess_Triangulate            |
                               aiProcess_JoinIdenticalVertices  |
                               aiProcess_GenSmoothNormals       |
                               aiProcess_SortByPType            |
                               0);


    if(scene){
        initScene(scene,fileName);
    }else{
        cerr << "Error while assimp is parsing" + fileName << endl;
        cerr << importer.GetErrorString() << endl;
    }
    isValid = true;
}

void Model::Render(unsigned meshIndex)
{
    assert(meshIndex < mesh_.size());

    GLfunc -> glEnableVertexAttribArray(0);
    GLfunc -> glEnableVertexAttribArray(1);
    GLfunc -> glEnableVertexAttribArray(2);

    GLfunc -> glBindBuffer(GL_ARRAY_BUFFER, mesh_[meshIndex].VB);
    GLfunc -> glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(GLfloat)*8,0);
    GLfunc -> glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(GLfloat)*8,(GLvoid*)(sizeof(GLfloat) * 3) );
    GLfunc -> glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(GLfloat)*8,(GLvoid*)(sizeof(GLfloat) * 6) );

    GLfunc -> glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,mesh_[meshIndex].IB);
    const unsigned textureIndex = mesh_[meshIndex].TextureIndex;

    if(textureIndex < texture_.size() && texture_[textureIndex])
        texture_[textureIndex] -> bind(GL_TEXTURE0);

    glDrawElements(GL_TRIANGLES,mesh_[meshIndex].NumIndices,GL_UNSIGNED_INT,0);
    GLfunc -> glDisableVertexAttribArray(0);
    GLfunc -> glDisableVertexAttribArray(1);
    GLfunc -> glDisableVertexAttribArray(2);
}

/* Private */

void Model::initScene(const aiScene *scene, const string &fileName)
{
    mesh_   .reserve( scene -> mNumMeshes );
    texture_.reserve( scene -> mNumMaterials );

    for(unsigned i = 0;i < scene -> mNumMeshes ;++i){
        mesh_.emplace_back( Mesh( scene -> mMeshes[i] ) );
    }

    const string dir = getDir(fileName);
    for(unsigned i = 0;i < scene -> mNumMaterials;++i){
        const string textureFile = getTextureFile(scene,i,dir);
        texture_.push_back( sTextureManager::Instance().texture(textureFile));
    }
}

string Model::getDir(const string &fileName)
{
    std::string::size_type SlashIndex = fileName.find_last_of("/");
    if (SlashIndex == std::string::npos) {
        return ".";
    }else if (SlashIndex == 0) {
        return "/";
    }else {
        return fileName.substr(0, SlashIndex);
    }
}

string Model::getTextureFile(const aiScene *scene, unsigned index, const string &dir)
{
    const aiMaterial *material = scene -> mMaterials[index];
    if(material -> GetTextureCount(aiTextureType_DIFFUSE) > 0){
        aiString path;
        if(material -> GetTexture(aiTextureType_DIFFUSE,0,&path) == AI_SUCCESS){
            return dir + "/" + path.data;
        }
    }
    return "Test.bmp";
}

#include "model.h"
