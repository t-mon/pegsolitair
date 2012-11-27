#include "gameboard.h"
#include "iterator.h"
#include <QDebug>

GameBoard::GameBoard(QObject *parent) :
    QObject(parent)
{
    m_first = 0;
    m_last = 0;
}

Field *GameBoard::getFirstField()
{
    return m_first;
}

Field *GameBoard::getLastField()
{
    return m_last;
}

void GameBoard::setFirstField(Field *first)
{
    m_first = first;
}

void GameBoard::setLastField(Field *last)
{
    m_last = last;
}


bool GameBoard::isEmpty()
{
    // returns true if there is no Field in the board
    return (m_first == 0);
}

void GameBoard::printFieldConnections()
{
    Field* n = m_first;
    while (n != m_last){
        qDebug() << "Field" << n->getFieldNumber() << "has neighbours:";
        qDebug() << "\tn = " << n->getNorthField()->getFieldNumber();
        qDebug() << "\ts = " << n->getSouthField()->getFieldNumber();
        qDebug() << "\te = " << n->getEastField()->getFieldNumber();
        qDebug() << "\tw = " << n->getWestField()->getFieldNumber();
        qDebug();
        n = n->getNextField();
    }

}


Field *GameBoard::addField(bool &occupied, int &number, Field* next, Field* previous, Field *north, Field *south, Field *east, Field *west, QObject *parent)
{
    Field * field = new Field(occupied, number, next, previous, north, south, east, west, parent);
    return field;
}
