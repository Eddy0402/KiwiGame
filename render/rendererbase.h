#ifndef RENDERERBASE_H
#define RENDERERBASE_H

#include <QObject>

class RendererBase : public QObject
{
    Q_OBJECT
public:
    explicit RendererBase(QObject *parent = 0);

signals:

public slots:

};

#endif // RENDERERBASE_H
