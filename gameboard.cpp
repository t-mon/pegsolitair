#include "gameboard.h"

GameBoard::GameBoard(QObject *parent) :
    QObject(parent)
{
    m_first = 0;
    m_last = 0;
}

GameBoard::~GameBoard()
{
    Field *temp = new Field;
    // go through the list form the front
    for (Field *n = m_first; n; ){
        // actual point ist tmp
        temp = n;
        // go to the next field
        n = n->m_next;
        // and delete the temp field
        delete temp;
    }

}

bool GameBoard::isEmpty()
{
    // returns true if there is no Field in the board
    return (m_first == 0);
}

Field *GameBoard::addField(bool &occupied, int &number, Field* next, Field* previous, Field *north, Field *south, Field *east, Field *west, QObject *parent)
{
    Field * field = new Field(occupied, number, next, previous, north, south, east, west, parent);
    return field;
}
