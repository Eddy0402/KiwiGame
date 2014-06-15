#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <QImage>
#include <QtGui>

class Texture
{
public:
    Texture(GLenum textureTarget,const QString& fileName);
    ~Texture();
    void bind(GLenum textureUnit);
private:
    QImage data_;
    GLenum textureTarget_;
    GLuint textureObject_;
};

#endif // TEXTURE_H
