#include "searchalgorithm.h"
#include <QDebug>

SearchAlgorithm::SearchAlgorithm(GameBoard *gameBoard) : m_gameBoard(gameBoard)
{
    m_steps = 0;
    m_pegs = 0;

    canJumpNorth = false;
    canJumpSouth = false;
    canJumpEast = false;
    canJumpWest = false;

}

bool SearchAlgorithm::solve()
{
    if(m_steps%10000 == 0 && m_steps != 0){
        qDebug() << "Steps: " << m_steps;
    }
    if(countPegs() == 1){
        qDebug() << "Solution found :)";
        return true;
    }
    Iterator it(m_gameBoard);
    //it.resetToFirst();
    for(it.resetToFirst(); it.getCurrentField() != m_gameBoard->getLastField(); ++it){
        if(it.getCurrentField()->occupied()){
            // if its occupied try to jump in every direction
            if(getJumpPossibilitysWithoutMarking(it.getCurrentField()->getFieldNumber())){
                if(canJumpNorth){
                    m_steps++;
                    jumpNorth(it.getCurrentField());
                    pushMove(m_gameBoard,it.getCurrentField()->getFieldNumber(),it.getNorthField()->getNorthField()->getFieldNumber());
                    countPegs();
                    //it.resetToFirst();
                    if(solve()){
                        return true;
                    }
                    //undo move
                    it.getCurrentField()->setOccupied(true);
                    it.getCurrentField()->getNorthField()->setOccupied(true);
                    it.getCurrentField()->getNorthField()->getNorthField()->setOccupied(false);
                    countPegs();
                    boardStack.pop();
                }
                if(canJumpSouth){
                    m_steps++;
                    jumpSouth(it.getCurrentField());
                    pushMove(m_gameBoard,it.getCurrentField()->getFieldNumber(),it.getSouthField()->getSouthField()->getFieldNumber());
                    countPegs();
                    if(solve()){
                        return true;
                    }
                    it.getCurrentField()->setOccupied(true);
                    it.getCurrentField()->getSouthField()->setOccupied(true);
                    it.getCurrentField()->getSouthField()->getSouthField()->setOccupied(false);
                    countPegs();
                    boardStack.pop();
                }
                if(canJumpEast){
                    m_steps++;
                    jumpEast(it.getCurrentField());
                    pushMove(m_gameBoard,it.getCurrentField()->getFieldNumber(),it.getEastField()->getEastField()->getFieldNumber());
                    countPegs();
                    if(solve()){
                        return true;
                    }
                    it.getCurrentField()->setOccupied(true);
                    it.getCurrentField()->getEastField()->setOccupied(true);
                    it.getCurrentField()->getEastField()->getEastField()->setOccupied(false);
                    countPegs();
                    boardStack.pop();
                }
                if(canJumpWest){
                    m_steps++;
                    jumpWest(it.getCurrentField());
                    pushMove(m_gameBoard,it.getCurrentField()->getFieldNumber(),it.getWestField()->getWestField()->getFieldNumber());
                    countPegs();
                    if(solve()){
                        return true;
                    }
                    it.getCurrentField()->setOccupied(true);
                    it.getCurrentField()->getWestField()->setOccupied(true);
                    it.getCurrentField()->getWestField()->getWestField()->setOccupied(false);
                    countPegs();
                    boardStack.pop();
                }
            }
        }
    }
    return false;
}

bool SearchAlgorithm::search()
{
    countPegs();
    if(solve()){
        //printSolution();
        return true;
    }else{
        qDebug() << "---------------NO SOLUTION FOUND";
        qDebug() << "---------------TOTAL MOVES " << m_steps;
        return false;
    }

}

void SearchAlgorithm::pushMove(GameBoard *currentBoard, int from, int to)
{
    boardSituation s;
    s.board = currentBoard;
    s.from = from;
    s.to = to;

    boardStack.push(s);
}

void SearchAlgorithm::jumpNorth(Field *currentFiedl)
{
    Iterator it(m_gameBoard);
    it.resetToFirst();
    while(it.getCurrentField() != currentFiedl){
        ++it;
    }
    // make the current field not occupied
    it.getCurrentField()->setOccupied(false);

    // make the field where i jumped to occupied
    it.getNorthField()->getNorthField()->setOccupied(true);

    // make the field overjumped field not occupied
    it.getNorthField()->setOccupied(false);

}

void SearchAlgorithm::jumpSouth(Field *currentFiedl)
{
    Iterator it(m_gameBoard);
    it.resetToFirst();
    while(it.getCurrentField() != currentFiedl){
        ++it;
    }
    // make the current field not occupied
    it.getCurrentField()->setOccupied(false);

    // make the field where i jumped to occupied
    it.getSouthField()->getSouthField()->setOccupied(true);

    // make the field overjumped field not occupied
    it.getSouthField()->setOccupied(false);

}

void SearchAlgorithm::jumpEast(Field *currentFiedl)
{
    Iterator it(m_gameBoard);
    it.resetToFirst();
    while(it.getCurrentField() != currentFiedl){
        ++it;
    }
    // make the current field not occupied
    it.getCurrentField()->setOccupied(false);

    // make the field where i jumped to occupied
    it.getEastField()->getEastField()->setOccupied(true);

    // make the field overjumped field not occupied
    it.getEastField()->setOccupied(false);

}

void SearchAlgorithm::jumpWest(Field *currentFiedl)
{
    Iterator it(m_gameBoard);
    it.resetToFirst();
    while(it.getCurrentField() != currentFiedl){
        ++it;
    }
    // make the current field not occupied
    it.getCurrentField()->setOccupied(false);

    // make the field where i jumped to occupied
    it.getWestField()->getWestField()->setOccupied(true);

    // make the field overjumped field not occupied
    it.getWestField()->setOccupied(false);

}

bool SearchAlgorithm::getJumpPossibilitysWithoutMarking(int fieldNumber)
{
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


int SearchAlgorithm::countPegs()
{
    Iterator it(m_gameBoard);
    it.resetToFirst();
    m_pegs = 0;
    while(it.getCurrentField() != m_gameBoard->getLastField()){
        if(it.getCurrentField()->occupied()){
            m_pegs++;

        }
        ++it;
    }
    return m_pegs;
}

QString SearchAlgorithm::printSolution()
{
    while(!boardStack.empty()){
        boardSituation x = boardStack.first();
        m_solution.append(QString::number(x.from) + "->" + QString::number(x.to) + "\n");

        boardStack.pop_front();
    }
    qDebug() << "==========Solution: \n" << m_solution;
    return m_solution;
}
