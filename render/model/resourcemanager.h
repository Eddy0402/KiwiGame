#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <QMap>
#include <QString>
#include <QSharedPointer>
#include <QWeakPointer>
#include <loki/Singleton.h>
#include "texture.h"

template<typename T>
class ResourceManager
{
public:
    ResourceManager();
    QWeakPointer<T> getResource(const QString &path);
private:
    QMap<QString,QSharedPointer<T>> resourceMap_;
};

typedef Loki::SingletonHolder<ResourceManager<Texture>> TextureManager;

#endif // RESOURCEMANAGER_H
