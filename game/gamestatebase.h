#ifndef GAMESTATEBASE_H
#define GAMESTATEBASE_H

#include <QObject>

class GameStateBase : public QObject
{
    Q_OBJECT
public:
    explicit GameStateBase(QObject *parent = 0);

signals:

public slots:

};

#endif // GAMESTATEBASE_H
