#ifndef ITERATOR_H
#define ITERATOR_H

#include <QObject>
#include "field.h"
#include "gameboard.h"
#include "fileparser.h"

class Field;
class GameBoard;

class Iterator : public QObject
{
    Q_OBJECT
public:
    explicit Iterator(GameBoard *gameBoard, QObject *parent = 0);
    
    // reset the iterator to the first field (field number 1)
    void resetToFirst();

    // movements
    int operator++();           // go with the iterator to the next fiel (actual fieldnumber +1)
    int operator--();           // go with the iterator to the previous fiel (actual fieldnumber -1)

    // read access methodes
    Field* getCurrentField();
    Field* getNorthField();
    Field* getSouthField();
    Field* getEastField();
    Field* getWestField();

    Field* getNextFromCurrentField();
    Field* getPreviousFromCurrentField();

    int getCurrentNumber();
    bool getCurrentOccupacy();

    void setNeighbors(Field* northField, Field* southField, Field* eastField, Field* westField);
    void setCurrentOccupation(bool occupation);
    void setCurrentNumber(int numField);


    bool goNorth();              // go to the north field from the current field if it's != 0
    bool goSouth();              // go to the south field from the current field if it's != 0
    bool goEast();               // go to the east field from the current field if it's != 0
    bool goWest();               // go to the west field from the current field if it's != 0

    // insert a new field and make the previous and next connection for it
    void insert(bool occupied, int number, Field* next, Field* previous, Field* north, Field* south, Field* east, Field* west, QObject *parent);

private:
    Field* m_current;     // points to the current field
    Field* m_previous;    // points to the previous field

    GameBoard *m_gameBoard;   // board to transverse with this iterator


signals:
    
public slots:
    
};

#endif // ITERATOR_H
