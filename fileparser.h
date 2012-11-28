#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QObject>
#include <QString>

#include "gameboard.h"

class FileParser
{
public:
    FileParser();
    GameBoard *createBoard(const char *file);

private:
    void createEmtyBoard(int fields);     // create a empty board (a list of fields with N,S,E,W = 0, just previouse and next gets created)

};

#endif // FILEPARSER_H
