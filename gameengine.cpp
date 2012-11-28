#include "gameengine.h"

GameEngine::GameEngine(QObject *parent) :
    QObject(parent)
{
    FileParser parser(m_board);
    parser.parse();
    // now the empty linked Board is created

}
