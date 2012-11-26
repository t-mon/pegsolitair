#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QObject>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>

#include "field.h"
#include "gameboard.h"

class FileParser
{
public:
    FileParser(const char* pathToGraph);
    GameBoard parse();          // pharse from the given file the connections between the boardfields

private:
    const char* m_filepath;     // filepath with the Graph.txt
    GameBoard *m_gameBoard;      // the gameBoard whitch gets created and connected
    void createEmtyBoard();     // create a empty board (a list of fields with N,S,E,W = 0, just previouse and next gets created)

};

#endif // FILEPARSER_H
