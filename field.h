#ifndef FIELD_H
#define FIELD_H

#include <QObject>
#include <QColor>
#include <iostream>


class Field : public QObject
{
    Q_OBJECT
    friend class Iterator;

    Q_PROPERTY(bool occupied READ occupied NOTIFY occupiedChanged)
    Q_PROPERTY(bool markField READ markField NOTIFY markFieldChanged)


public:
    explicit Field(bool occupied = false, int number = 0, Field* next = 0, Field* previous = 0, Field* north = 0, Field* south= 0, Field* east = 0, Field* west = 0, QObject *parent = 0);
    int getFieldNumber();
    Field* getNorthField();
    Field* getSouthField();
    Field* getEastField();
    Field* getWestField();

    Field* getNextField();
    Field* getPreviousField();

    bool occupied() const;
    bool markField() const;

    void setOccupied(bool occupied);
    void setMarked(bool marked);

signals:
    void occupiedChanged();
    void markFieldChanged();

private:
    // data from this field
    bool m_occupied;          // true = occupied, flase = free
    bool m_marked;
    int m_number;             // the fieldnumber

    // generate pointer
    Field *m_next;            // go to the next field (fieldnumber+1), this is just to move once the hole board forward
    Field *m_previous;        // go to the previouse field (fieldnumber-1), this is just to move once the hole board forward

    Field * m_north;
    Field * m_south;
    Field * m_east;
    Field * m_west;
    
};

#endif // FIELD_H
