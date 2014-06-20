#include "resourcemanager.h"


template<typename T>
ResourceManager<T>::ResourceManager()
{

}


template<>
ResourceManager<Texture>::ResourceManager()
{

}

template<typename T>
QWeakPointer<T> ResourceManager<T>::getResource(const QString &path)
{
    if(resourceMap_.contains(path)) return QWeakPointer<T>(resourceMap_[path]);
    else{
        resourceMap_.insert( path, QSharedPointer<T>::create(path) );
        return QWeakPointer<T>(resourceMap_[path]);
    }
}

template<>
QWeakPointer<Texture> ResourceManager<Texture>::getResource(const QString &path)
{
    if(resourceMap_.contains(path)) return QWeakPointer<Texture>(resourceMap_[path]);
    else{
        resourceMap_.insert( path, QSharedPointer<Texture>::create(GL_TEXTURE_2D,path) );
        return QWeakPointer<Texture>(resourceMap_[path]);
    }
}
