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

    bool getJumpPossibilitys(int fieldNumber);
    void resetFieldMarker();
    bool somethingMarked();
    bool isPossibleToMove(int fieldNumber);
    bool isMarked(int fieldNumber);
    void jump(int fieldNumber);

    int m_markedFieldNumber;

signals:
    
public slots:
    void fieldClicked(int fieldNumber);
    void rightClicked(int fieldNumber);
    
};

#endif // GAMEENGINE_H
