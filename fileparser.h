#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QObject>

#include "field.h"
#include "iterator.h"
#include "gameboard.h"

class FileParser
{
public:
    FileParser(GameBoard &gameBoard);
    void parse();               // pharse from the given file the connections between the boardfields

private:
    const char* m_filepath;     // filepath with the Graph.txt
    GameBoard &m_gameBoard;     // the gameBoard whitch gets created and connected
    void createEmtyBoard();     // create a empty board (a list of fields with N,S,E,W = 0, just previouse and next gets created)
    void printFieldConnections();
};

#endif // FILEPARSER_H
