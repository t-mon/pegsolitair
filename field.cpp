#include "field.h"

Field::Field(bool occupied, int number, Field* next, Field* previous, Field* north, Field* south, Field* east, Field* west, QObject *parent) :
    m_occupied(occupied), m_number(number), m_next(next), m_previous(previous), m_north(north), m_south(south), m_east(east), m_west(west), QObject(parent)
{
}
