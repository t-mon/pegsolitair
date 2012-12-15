#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QObject>

#include "field.h"
#include "iterator"


class GameBoard : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int fieldCount READ fieldCount)

public:
    explicit GameBoard(int fieldCount, QObject *parent = 0);

    Field* getFirstField();
    Field* getLastField();
    void setFirstField(Field* first);
    void setLastField(Field* last);
    Field* addField(bool &occupied, int &number, Field* next, Field* previous, Field* north, Field* south, Field* east, Field* west, QObject *parent);
    bool isEmpty();         // returns true if the board is emtpty
    void print();

    Q_INVOKABLE int fieldCount();
    Q_INVOKABLE Field* fieldAt(int index);

private:

    Field* m_first;       // the first field in the board (1)
    Field* m_last;        // the last field in the board  (121)
    int m_fieldCount;


signals:
    
public slots:
    
};

#endif // GAMEBOARD_H
