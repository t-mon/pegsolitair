#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QObject>
#include <QString>

#include "gameboard.h"

class FileParser
{
public:
    FileParser();
    //void parse();               // pharse from the given file the connections between the boardfields
    GameBoard *createBoard(const char *file);

private:
    void createEmtyBoard(int fields);     // create a empty board (a list of fields with N,S,E,W = 0, just previouse and next gets created)
    void printFieldConnections();
};

#endif // FILEPARSER_H
