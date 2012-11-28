#include "iterator.h"

#include <QDebug>

Iterator::Iterator(GameBoard *gameBoard, QObject *parent) :
    m_gameBoard(gameBoard), QObject(parent)
{
}

void Iterator::resetToFirst()
{
    m_previous = 0;
    m_current = m_gameBoard->getFirstField();
}

int Iterator::operator ++()
{
    if (m_current == NULL)		// reset current pointer
        if (m_previous == NULL)
            m_current = m_gameBoard->getFirstField();
        else
            m_current = m_previous->m_next;
    else				// advance current pointer
    {
        m_previous = m_current;
        m_current = m_current->m_next;
    }
    return (m_current != NULL);
}

int Iterator::operator --()
{
    if (m_current == NULL)		// reset current pointer
        if (m_previous == NULL)
            m_current = m_gameBoard->getFirstField();
        else
            m_current = m_previous->m_next;
    else				// advance current pointer
    {
        m_previous = m_previous->m_previous;
        m_current = m_current->m_previous;
    }
    return (m_current != NULL);
}

Field *Iterator::getCurrentField()
{
    return m_current;
}

Field *Iterator::getNorthField()
{
    return m_current->m_north;
}

Field *Iterator::getSouthField()
{
    return m_current->m_south;
}

Field *Iterator::getEastField()
{
    return m_current->m_east;
}

Field *Iterator::getWestField()
{
    return m_current->m_west;
}

Field *Iterator::getNextFromCurrentField()
{
    return m_current->m_next;
}

Field *Iterator::getPreviousFromCurrentField()
{
    return m_current->m_previous;
}

int Iterator::getCurrentNumber()
{
    return m_current->m_number;
}

bool Iterator::getCurrentOccupacy()
{
    return m_current->m_occupied;
}

void Iterator::setNeighbors(Field *northField, Field *southField, Field *eastField, Field *westField)
{
    if(northField!=0) m_current->m_north = northField;
    if(southField!=0)m_current->m_south = southField;
    if(eastField!=0)m_current->m_east = eastField;
    if(westField!=0)m_current->m_west = westField;
}

void Iterator::setCurrentOccupation(bool occupation)
{
    m_current->m_occupied = occupation;
}

void Iterator::setCurrentNumber(int numField)
{
    m_current->m_number = numField;
}

bool Iterator::goNorth()
{
    // if this neighbor doesnt exist do nothing
    if (m_current->m_north == 0){
        return false;
    }else{
        m_current = m_current->m_north;
        m_previous = m_current->m_west;
        return true;
    }
}

bool Iterator::goSouth()
{
    // if this neighbor doesnt exist do nothing
    if (m_current->m_south == 0){
        return false;
    }else{
        m_current = m_current->m_south;
        m_previous = m_current->m_west;
        return true;
    }
}

bool Iterator::goEast()
{
    // if this neighbor doesnt exist do nothing
    if (m_current->m_east == 0){
        return false;
    }else{
        m_current = m_current->m_east;
        m_previous = m_current->m_west;
        return true;
    }
}

bool Iterator::goWest()
{
    // if this neighbor doesnt exist do nothing
    if (m_current->m_west == 0){
        return false;
    }else{
        m_current = m_current->m_west;
        m_previous = m_current->m_west;
        return true;
    }
}

void Iterator::insert(bool occupied, int number, Field* next, Field* previous, Field* north, Field* south, Field* east, Field* west, QObject *parent)
{
    Field *p = m_gameBoard->addField(occupied,number,next,previous,north,south,east,west,parent);

    // if the board is emty the new field is the first and last of the board
    if (m_gameBoard->isEmpty()){
        m_gameBoard->setFirstField(p);
        m_gameBoard->setLastField(p);
    }else{
        // new field is not the first field
        if (m_current==m_gameBoard->getLastField()){
            m_gameBoard->setLastField(p);
        }
        // connect the new field with the current field
        p->m_next = m_current->m_next;
        p->m_previous = m_current;
        m_current->m_next = p;
    }
}
