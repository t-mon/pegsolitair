#include "gameengine.h"
#include <QDebug>

GameEngine::GameEngine(QObject *parent) :
    QObject(parent)
{
    FileParser parser;
    m_gameBoard = parser.createBoard(":/european.txt");
    // now the empty linked Board is created
    m_markedFieldNumber = -1;
}

GameBoard *GameEngine::board()
{
    return m_gameBoard;
}

bool GameEngine::getJumpPossibilitys(int fieldNumber)
{

    bool canJumpNorth;
    bool canJumpSouth;
    bool canJumpEast;
    bool canJumpWest;

    // controll if jumping is possible
    Iterator it(m_gameBoard);
    it.resetToFirst();
    while(it.getCurrentNumber() != fieldNumber){
        ++it;
    }

    // if its not occupied dont mark it
    if(!it.getCurrentField()->occupied()){
        return false;
    }

    //controll every direction

    // controll NORTH direction
    // if firectionfield exists  and   is occupied                  and   the field after that exist              and  is not occupied
    if((it.getNorthField() != 0) && (it.getNorthField()->occupied()) && (it.getNorthField()->getNorthField() != 0) && (!it.getNorthField()->getNorthField()->occupied())){
        canJumpNorth = true;
        it.getCurrentField()->setMarked(true);
        it.getNorthField()->getNorthField()->setpossibleToMove(true);
        qDebug() << "can jump north direction";

    }else{
        canJumpNorth = false;
    }

    // controll South direction
    // if firectionfield exists  and   is occupied                  and   the field after that exist              and  is not occupied
    if((it.getSouthField() != 0) && (it.getSouthField()->occupied()) && (it.getSouthField()->getSouthField() != 0) && (!it.getSouthField()->getSouthField()->occupied())){
        canJumpSouth = true;
        it.getCurrentField()->setMarked(true);
        it.getSouthField()->getSouthField()->setpossibleToMove(true);
        qDebug() << "can jump south direction";

    }else{
        canJumpSouth = false;
    }

    // controll East direction
    // if firectionfield exists  and   is occupied                  and   the field after that exist              and  is not occupied
    if((it.getEastField() != 0) && (it.getEastField()->occupied()) && (it.getEastField()->getEastField() != 0) && (!it.getEastField()->getEastField()->occupied())){
        canJumpEast = true;
        it.getCurrentField()->setMarked(true);
        it.getEastField()->getEastField()->setpossibleToMove(true);
        qDebug() << "can jump east direction";

    }else{
        canJumpEast = false;
    }

    // controll West direction
    // if firectionfield exists  and   is occupied                  and   the field after that exist              and  is not occupied
    if((it.getWestField() != 0) && (it.getWestField()->occupied()) && (it.getWestField()->getWestField() != 0) && (!it.getWestField()->getWestField()->occupied())){
        canJumpWest = true;
        it.getCurrentField()->setMarked(true);
        it.getWestField()->getWestField()->setpossibleToMove(true);
        qDebug() << "can jump west direction";
    }else{
        canJumpWest = false;
    }

    if(canJumpNorth || canJumpSouth || canJumpEast || canJumpWest){
        qDebug() << "field" << fieldNumber << "marked";
        return true;
    }else{
        qDebug() << "no jump possibilitys for field" << fieldNumber;
        return false;
    }
}

void GameEngine::resetFieldMarker()
{
    Iterator it(m_gameBoard);
    it.resetToFirst();

    while(it.getCurrentField()->getFieldNumber() != m_gameBoard->getLastField()->getFieldNumber()){
        it.getCurrentField()->setMarked(false);
        it.getCurrentField()->setpossibleToMove(false);
        ++it;
    }
    it.getCurrentField()->setMarked(false);
    it.getCurrentField()->setpossibleToMove(false);
    m_markedFieldNumber = -1;
}

bool GameEngine::somethingMarked()
{
    Iterator it(m_gameBoard);
    it.resetToFirst();

    while(it.getCurrentField()->getFieldNumber() != m_gameBoard->getLastField()->getFieldNumber()){

        if(it.getCurrentField()->marked() == true){
            m_markedFieldNumber = it.getCurrentNumber();
            return true;
        }
        ++it;
    }
    if(it.getCurrentField()->marked() == true){
        m_markedFieldNumber = it.getCurrentNumber();
        return true;

    }
    return false;
}

bool GameEngine::isPossibleToMove(int fieldNumber)
{
    Iterator it(m_gameBoard);
    it.resetToFirst();

    // go to the field
    while(it.getCurrentNumber() != fieldNumber){
        ++it;
    }
    if(it.getCurrentField()->possibleToMove()){
        return true;
    }else{
        return false;
    }
}

bool GameEngine::isMarked(int fieldNumber)
{
    Iterator it(m_gameBoard);
    it.resetToFirst();

    while(it.getCurrentNumber() != fieldNumber){
        ++it;
    }
    if(it.getCurrentField()->marked()){
        return true;
    }else{
        return false;
    }
}

void GameEngine::jump(int fieldNumber)
{
    // make the marked field not occupied
    Iterator itMarked(m_gameBoard);
    itMarked.resetToFirst();
    while(itMarked.getCurrentNumber() != m_markedFieldNumber){
        ++itMarked;
    }
    itMarked.getCurrentField()->setOccupied(false);

    // make the field where i jumped to occupied
    Iterator itPossible(m_gameBoard);
    itPossible.resetToFirst();
    while(itPossible.getCurrentNumber() != fieldNumber){
        ++itPossible;
    }
    itPossible.getCurrentField()->setOccupied(true);

    // make the overjumped field not occupied
    // if i jumped North
    if(itMarked.getNorthField() != 0){
        if(itMarked.getNorthField()->getNorthField() != 0){
            if(itMarked.getNorthField()->getNorthField() == itPossible.getCurrentField()){
                itMarked.goNorth();
                itMarked.getCurrentField()->setOccupied(false);
                qDebug() << "jumped north";
            }
        }
    }

    // if i jumped South
    if(itMarked.getSouthField() != 0){
        if(itMarked.getSouthField()->getSouthField() != 0){
            if(itMarked.getSouthField()->getSouthField() == itPossible.getCurrentField()){
                itMarked.goSouth();
                itMarked.getCurrentField()->setOccupied(false);
                qDebug() << "jumped south";

            }
        }
    }
    // if i jumped East
    if(itMarked.getEastField() != 0){
        if(itMarked.getEastField()->getEastField() != 0){
            if(itMarked.getEastField()->getEastField() == itPossible.getCurrentField()){
                itMarked.goEast();
                itMarked.getCurrentField()->setOccupied(false);
                qDebug() << "jumped east";

            }
        }
    }

    // if i jumped West
    if(itMarked.getWestField() != 0){
        if(itMarked.getWestField()->getWestField() != 0){
            if(itMarked.getWestField()->getWestField() == itPossible.getCurrentField()){
                itMarked.goWest();
                itMarked.getCurrentField()->setOccupied(false);
                qDebug() << "jumped west";

            }
        }
    }

}


void GameEngine::fieldClicked(int fieldNumber)
{
    qDebug() << "###################################################";
    qDebug() << "Field Number " << fieldNumber << "clicked";


    // check if something is marked
    switch(somethingMarked()){
    // nothing marked
    case false:
        qDebug() << "nothing marked, check jumppossibilitys";
        getJumpPossibilitys(fieldNumber);
        break;

        // something is marked
    case true:
        qDebug() << "marked field =" << m_markedFieldNumber;
        // if i have clicked on a not possible move make the move
        if(!isPossibleToMove(fieldNumber)){
            //qDebug() << "something marked but not clicked on a possibility to jump";
            resetFieldMarker();
            break;
            // else i have clicked on a possible Field to make the move
        }else{
            qDebug() << "---------> JUMP from " << m_markedFieldNumber << "->" << fieldNumber << " <---------";
            jump(fieldNumber);
            resetFieldMarker();
            break;
        }
    }

}

void GameEngine::rightClicked(int fieldNumber)
{
    Iterator it(m_gameBoard);
    it.resetToFirst();
    while(it.getCurrentNumber() != fieldNumber){
        ++it;
    }
    qDebug() << "~~~~~~~~~~~~~~~~occupacy from field" << fieldNumber << "changed by User from" << it.getCurrentField()->occupied() << "to" << !it.getCurrentField()->occupied();
    it.getCurrentField()->setOccupied(!it.getCurrentField()->occupied());

}

