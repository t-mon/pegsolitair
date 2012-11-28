#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
#include "fileparser.h"
#include "gameboard.h"
#include "iterator.h"

class GameEngine : public QObject
{
    Q_OBJECT
public:
    explicit GameEngine(QObject *parent = 0);

private:
    GameBoard m_board;

signals:
    
public slots:
    
};

#endif // GAMEENGINE_H
