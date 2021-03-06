#include "gameengine.h"
#include "searchalgorithm.h"
#include <QDebug>
#include <QDateTime>

GameEngine::GameEngine(QObject *parent) :
    QObject(parent)
{
    FileParser parser;
    m_boardType = ":/european.txt";
    m_gameBoard = parser.createBoard(m_boardType);
    // now the empty linked Board is created
    m_stillCanWinn = true;
    checkMovesLeft();

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

bool GameEngine::getJumpPossibilitysWithoutMarking(int fieldNumber)
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


    }else{
        canJumpNorth = false;
    }

    // controll South direction
    // if firectionfield exists  and   is occupied                  and   the field after that exist              and  is not occupied
    if((it.getSouthField() != 0) && (it.getSouthField()->occupied()) && (it.getSouthField()->getSouthField() != 0) && (!it.getSouthField()->getSouthField()->occupied())){
        canJumpSouth = true;
    }else{
        canJumpSouth = false;
    }

    // controll East direction
    // if firectionfield exists  and   is occupied                  and   the field after that exist              and  is not occupied
    if((it.getEastField() != 0) && (it.getEastField()->occupied()) && (it.getEastField()->getEastField() != 0) && (!it.getEastField()->getEastField()->occupied())){
        canJumpEast = true;
    }else{
        canJumpEast = false;
    }

    // controll West direction
    // if firectionfield exists  and   is occupied                  and   the field after that exist              and  is not occupied
    if((it.getWestField() != 0) && (it.getWestField()->occupied()) && (it.getWestField()->getWestField() != 0) && (!it.getWestField()->getWestField()->occupied())){
        canJumpWest = true;
    }else{
        canJumpWest = false;
    }

    if(canJumpNorth || canJumpSouth || canJumpEast || canJumpWest){
        return true;
    }else{
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

int GameEngine::checkMovesLeft()
{
    int jumpPossibilitys = 0;
    Iterator it(m_gameBoard);
    it.resetToFirst();

    while(it.getCurrentField()->getFieldNumber() != m_gameBoard->getLastField()->getFieldNumber()){

        // if field occupied
        if(it.getCurrentField()->occupied()){
            // if getJumpPossibilitys returns true, ++jumpPossibilitys
            if(getJumpPossibilitysWithoutMarking(it.getCurrentField()->getFieldNumber())){
                jumpPossibilitys++;
            }
        }
        ++it;
    }
    if(it.getCurrentField()->occupied()){
        // if getJumpPossibilitys returns true, ++jumpPossibilitys
        if(getJumpPossibilitysWithoutMarking(it.getCurrentField()->getFieldNumber())){
            jumpPossibilitys++;
        }
    }

    m_movesLeft = jumpPossibilitys;
    emit movesLeftChanged();
    return jumpPossibilitys;
}

bool GameEngine::isBoardSolvable()
{
    qDebug() << "START SEARCH SOLUTION";
    //m_gameBoard->print();
    SearchAlgorithm df(m_gameBoard);
    df.search();
    QString solution = df.printSolution();
    appendToHistory(solution);
}

QString GameEngine::history() const
{
    return m_gameHistory;
}

QString GameEngine::boardType() const
{
    return m_boardType;
}

int GameEngine::movesLeft() const
{
    return m_movesLeft;
}

bool GameEngine::stillCanWinn() const
{
    return m_stillCanWinn;
}

bool GameEngine::winnState() const
{
    return m_winnState;
}

void GameEngine::appendToHistory(QString moveString)
{
    m_gameHistory.append(moveString);
    emit historyChanged();
}

void GameEngine::appendToSafeHistory(QString moveString)
{
    m_safeHistoryString.append(moveString);
}

void GameEngine::resetHistory()
{
    m_gameHistory = "";
    m_safeHistoryString = "";
    emit historyChanged();
}

void GameEngine::checkWinnState()
{
    //
    int countOccupied = 0;
    Iterator it(m_gameBoard);
    it.resetToFirst();

    while(it.getCurrentField()->getFieldNumber() != m_gameBoard->getLastField()->getFieldNumber()){

        // if field occupied
        if(it.getCurrentField()->occupied()){
            countOccupied++;
        }
        ++it;
    }
    if(it.getCurrentField()->occupied()){
        countOccupied++;
    }

    // if every field is occupied
    if(countOccupied == m_gameBoard->getLastField()->getFieldNumber()+1){
        return;
    }

    if (countOccupied == 1){
        m_winnState = true;
        emit winnStateChanged();
    }


    if(checkMovesLeft()== 0 && countOccupied >1){
        m_winnState = false;
        emit winnStateChanged();
        m_stillCanWinn = false;
        emit stillCanWinnChanged();
    }

}


void GameEngine::fieldClicked(int fieldNumber)
{
    qDebug() << "###################################################";
    qDebug() << "Field Number " << fieldNumber << "clicked";
    checkWinnState();

    // check if something is marked
    switch(somethingMarked()){
    // nothing marked
    case false:
        qDebug() << "nothing marked, check jumppossibilitys";
        getJumpPossibilitys(fieldNumber);
        checkWinnState();
        break;

        // something is marked
    case true:
        qDebug() << "marked field =" << m_markedFieldNumber;
        // if i have clicked on a not possible move make the move
        if(!isPossibleToMove(fieldNumber)){
            //qDebug() << "something marked but not clicked on a possibility to jump";
            resetFieldMarker();
            checkWinnState();
            break;
            // else i have clicked on a possible Field to make the move
        }else{
            qDebug() << "---------> JUMP from " << m_markedFieldNumber << "->" << fieldNumber;
            appendToHistory(QString::number(m_markedFieldNumber) + "->" + QString::number(fieldNumber) +"\n");
            appendToSafeHistory(QString::number(m_markedFieldNumber) + "->" + QString::number(fieldNumber) + ", ");
            jump(fieldNumber);
            resetFieldMarker();
            checkWinnState();
            break;
        }
    }
    checkWinnState();


}

void GameEngine::rightClicked(int fieldNumber)
{
    Iterator it(m_gameBoard);
    it.resetToFirst();
    while(it.getCurrentNumber() != fieldNumber){
        ++it;
    }
    qDebug() << "~~~~~~~~~~occupacy from field" << fieldNumber << "changed by User from" << it.getCurrentField()->occupied() << "to" << !it.getCurrentField()->occupied();
    it.getCurrentField()->setOccupied(!it.getCurrentField()->occupied());
    appendToHistory(QString::number(fieldNumber) + "->" + "!\n");
    appendToSafeHistory(QString::number(fieldNumber) + "->" + "! , ");
    checkWinnState();
}

void GameEngine::newGameClicked(QString boardType)
{
    if(boardType == m_boardType){
        Iterator it(m_gameBoard);
        it.resetToFirst();
        while(it.getCurrentField() != m_gameBoard->getLastField()){
            it.getCurrentField()->setOccupied(true);
            ++it;
        }
        it.getCurrentField()->setOccupied(true);
        resetHistory();
        m_stillCanWinn = true;
        emit stillCanWinnChanged();
    }else{
        FileParser parser;
        m_boardType = boardType;
        if(m_gameBoard) {
            m_gameBoard->deleteLater();
        }
        m_gameBoard = parser.createBoard(boardType);
        emit boardTypeChanged();

    }

}

void GameEngine::safeHistory()
{

    QFile safeGame("/home/timon/PegSolitair_PlayedGames.txt");
    if(!safeGame.open(QIODevice::Append |QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "could not open history file";
    }

    QDataStream *output = new QDataStream(&safeGame);
    QString safeString = QDateTime::currentDateTime().toString("ddd dd.MM.yyyy hh:mm:ss").toLatin1() + "  boardtype" + m_boardType +"\n" + m_safeHistoryString.toLatin1() +"\n\n";
    *output << safeString.toLatin1();

    qDebug() << safeString;

    safeGame.close();
    delete output;
    m_safeHistoryString = "";

}

