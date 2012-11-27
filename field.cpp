#include "field.h"

using namespace std;

Field::Field(bool occupied, int number, Field* next, Field* previous, Field* north, Field* south, Field* east, Field* west, QObject *parent) :
    m_occupied(occupied), m_number(number), m_next(next), m_previous(previous), m_north(north), m_south(south), m_east(east), m_west(west), QObject(parent)
{
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

