#ifndef SEARCHALGORITHM_H
#define SEARCHALGORITHM_H
#define N 9
#include <QStack>

#include "gameboard.h"
#include "iterator.h"
#include "field.h"

class SearchAlgorithm
{

public:
    SearchAlgorithm(GameBoard *gameBoard);
    bool solve();
    bool search();
    QString printSolution();

private:
    GameBoard* m_gameBoard;
    int m_pegs;
    long int m_steps;
    QString m_solution;

    struct boardSituation{
        GameBoard* board;
        int from;
        int to;
    };
    void pushMove(GameBoard *currentBoard, int from, int to);

    QStack<boardSituation> boardStack;

    bool canJumpNorth;
    bool canJumpSouth;
    bool canJumpEast;
    bool canJumpWest;

    void jumpNorth(Field* currentFiedl);
    void jumpSouth(Field *currentFiedl);
    void jumpEast(Field* currentFiedl);
    void jumpWest(Field* currentFiedl);


    bool getJumpPossibilitysWithoutMarking(int fieldNumber);
    int countPegs();

};

#endif // SEARCHALGORITHM_H
