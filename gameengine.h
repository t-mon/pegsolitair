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

    Q_INVOKABLE GameBoard *board();
private:
    GameBoard *m_gameBoard;
    bool canJumpNorth;
    bool canJumpSouth;
    bool canJumpEast;
    bool canJumpWest;

    bool getJumpPossibilitys(int fieldNumber);


signals:
    
public slots:
    void fieldClicked(int fieldNumber);
    
};

#endif // GAMEENGINE_H
