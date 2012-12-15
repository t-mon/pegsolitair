#include "gameboard.h"
#include "iterator.h"
#include <iostream>
#include <QDebug>

using namespace std;

GameBoard::GameBoard(int fieldCount, QObject *parent) :
    QObject(parent),
    m_first(0),
    m_last(0),
    m_fieldCount(fieldCount)
{
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

void GameBoard::print()
{
    Iterator it(this);
    it.resetToFirst();
    cout << "   ";
    for(int i = 0; i<3; i++){
        cout << it.getCurrentField()->occupied() ? "#" : "0";
    }

}

int GameBoard::fieldCount()
{
    return m_fieldCount;
}

Field *GameBoard::fieldAt(int index)
{
    //Q_ASSERT(index < m_fieldCount);

    Iterator it(this);
    it.resetToFirst();
    //qDebug() << "starting";
    while (it.getCurrentNumber() < index) {
        //qDebug() << "got current" << it.getCurrentNumber();
        ++it;
    }
    return it.getCurrentField();
}


Field *GameBoard::addField(bool &occupied, int &number, Field* next, Field* previous, Field *north, Field *south, Field *east, Field *west, QObject *parent)
{
    Field * field = new Field(occupied, number, next, previous, north, south, east, west, parent);
    return field;
}
