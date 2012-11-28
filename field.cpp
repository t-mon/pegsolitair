#include "field.h"

#include <QDebug>
using namespace std;

Field::Field(bool occupied, int number, Field* next, Field* previous, Field* north, Field* south, Field* east, Field* west, QObject *parent) :
    m_occupied(occupied), m_number(number), m_next(next), m_previous(previous), m_north(north), m_south(south), m_east(east), m_west(west), QObject(parent)
{
    m_marked = false;
}

int Field::getFieldNumber()
{
    return m_number;
}

Field *Field::getNorthField()
{
    return m_north;
}

Field *Field::getSouthField()
{
    return m_south;
}

Field *Field::getEastField()
{
    return m_east;
}

Field *Field::getWestField()
{
    return m_west;
}

Field *Field::getNextField()
{
    return m_next;
}

Field *Field::getPreviousField()
{
    return m_previous;
}

bool Field::occupied() const
{
    return m_occupied;
}

bool Field::markField() const
{
    return m_marked;
}

void Field::setOccupied(bool occupied)
{
    m_occupied = occupied;
    emit occupiedChanged();
}

void Field::setMarked(bool marked)
{
    m_marked = marked;
    emit markFieldChanged();
}

