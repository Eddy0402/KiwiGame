#ifndef MODEL_H
#define MODEL_H

#include <assimp/scene.h>
#include <QString>
#include <memory>
#include <vector>
#include <string>
#include "mesh.h"
#include "texture.h"
#include "resourcemanager.h"


class Model
{
public:
    Model(QString modelFile);
    void Render(unsigned );
private:
    void initScene(const aiScene *scene, const std::string &fileName);
    std::string getDir(const std::string &fileName);
    std::string getTextureFile(const aiScene *scene,unsigned index,const std::string &dir);

    std::vector<Mesh> mesh_;
    std::vector<std::shared_ptr<Texture>> texture_;
    bool isValid;
};

#endif // MODEL_H
