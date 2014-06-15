#include "texture.h"

Texture::Texture(GLenum textureTarget, const QString &fileName)
   : data_( fileName ),
     textureTarget_(textureTarget)
{
    //(QImage::Format_RGBA8888);

    glGenTextures(1,&textureObject_);
    glBindTexture(textureTarget,textureObject_);
    glTexImage2D(textureObject_,0,GL_RGBA,data_.width(),data_.height(),
                 0,GL_RGBA,GL_UNSIGNED_BYTE,data_.bits());
    // TODO
    glTexParameterf(textureTarget_,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameterf(textureTarget_,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

Texture::~Texture()
{

}

void Texture::bind(GLenum textureUnit)
{
    glActiveTexture(textureUnit);
    glBindTexture(textureTarget_,textureObject_);
}
