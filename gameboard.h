#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QObject>

#include "field.h"
#include "iterator"

class Field;
class Iterator;

class GameBoard : public QObject
{
    Q_OBJECT
    friend class Iterator;

public:
    explicit GameBoard(QObject *parent = 0);
    ~GameBoard();
private:
    bool isEmpty();         // returns true if the board is emtpty

    Field* m_first;       // the first field in the board (1)
    Field* m_last;        // the last field in the board  (121)

    Field* addField(bool &occupied, int &number, Field* next, Field* previous, Field* north, Field* south, Field* east, Field* west, QObject *parent);


signals:
    
public slots:
    
};

#endif // GAMEBOARD_H
