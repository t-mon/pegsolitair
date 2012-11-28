#include "gameengine.h"

GameEngine::GameEngine(QObject *parent) :
    QObject(parent)
{
    FileParser parser;
    m_gameBoard = parser.createBoard("european.txt");
    // now the empty linked Board is created

}

GameBoard *GameEngine::board()
{
    return m_gameBoard;
}
