#include "gameengine.h"
#include <QDebug>

GameEngine::GameEngine(QObject *parent) :
    QObject(parent)
{
    FileParser parser;
    m_gameBoard = parser.createBoard("european.txt");
    // now the empty linked Board is created

}

GameBoard *GameEngine::board()
{
    return m_gameBoard;
}

bool GameEngine::getJumpPossibilitys(int fieldNumber)
{
    // controll if jumping is possible
    Iterator it(m_gameBoard);
    it.resetToFirst();
    while(it.getCurrentNumber() != fieldNumber){
        ++it;
    }

    if(!it.getCurrentField()->occupied()){
        return false;
    }

    //controll every direction

    // controll NORTH direction
    // if firectionfield exists  and   is occupied                  and   the field after that exist              and  is not occupied
    if((it.getNorthField() != 0) && (it.getNorthField()->occupied()) && (it.getNorthField()->getNorthField() != 0) && (!it.getNorthField()->getNorthField()->occupied())){
        canJumpNorth = true;
        it.getCurrentField()->setMarked(true);
        qDebug() << "can jump north direction";

    }else{
        canJumpNorth = false;
    }

    // controll South direction
    // if firectionfield exists  and   is occupied                  and   the field after that exist              and  is not occupied
    if((it.getSouthField() != 0) && (it.getSouthField()->occupied()) && (it.getSouthField()->getSouthField() != 0) && (!it.getSouthField()->getSouthField()->occupied())){
        canJumpSouth = true;
        it.getCurrentField()->setMarked(true);
        qDebug() << "can jump south direction";

    }else{
        canJumpSouth = false;
    }

    // controll East direction
    // if firectionfield exists  and   is occupied                  and   the field after that exist              and  is not occupied
    if((it.getEastField() != 0) && (it.getEastField()->occupied()) && (it.getEastField()->getEastField() != 0) && (!it.getEastField()->getEastField()->occupied())){
        canJumpEast = true;
        it.getCurrentField()->setMarked(true);
        qDebug() << "can jump east direction";

    }else{
        canJumpEast = false;
    }

    // controll West direction
    // if firectionfield exists  and   is occupied                  and   the field after that exist              and  is not occupied
    if((it.getWestField() != 0) && (it.getWestField()->occupied()) && (it.getWestField()->getWestField() != 0) && (!it.getWestField()->getWestField()->occupied())){
        canJumpWest = true;
        it.getCurrentField()->setMarked(true);
        qDebug() << "can jump west direction";
    }else{
        canJumpWest = false;
    }


}


void GameEngine::fieldClicked(int fieldNumber)
{
    qDebug() << "Field Number " << fieldNumber << "clicked";

    getJumpPossibilitys(fieldNumber);


}
