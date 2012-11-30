#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
#include "fileparser.h"
#include "gameboard.h"
#include "iterator.h"

class GameEngine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString history READ history NOTIFY historyChanged)
    Q_PROPERTY(QString boardType READ boardType NOTIFY boardTypeChanged)

    Q_PROPERTY(int movesLeft READ movesLeft() NOTIFY movesLeftChanged)
    Q_PROPERTY(bool stillCanWinn READ stillCanWinn() NOTIFY stillCanWinnChanged)
    Q_PROPERTY(bool winnState READ winnState() NOTIFY winnStateChanged)


public:
    explicit GameEngine(QObject *parent = 0);

    Q_INVOKABLE GameBoard *board();

private:
    GameBoard *m_gameBoard;
    QString m_boardType;

    QString history() const;
    QString boardType() const;
    int movesLeft() const;
    bool stillCanWinn() const;
    bool winnState() const;

    void appendToHistory(QString moveString);
    void resetHistory();
    void checkWinnState();

    bool getJumpPossibilitys(int fieldNumber);
    bool getJumpPossibilitysWithoutMarking(int fieldNumber);
    void resetFieldMarker();
    bool somethingMarked();
    bool isPossibleToMove(int fieldNumber);
    bool isMarked(int fieldNumber);
    void jump(int fieldNumber);
    int checkMovesLeft();

    int m_markedFieldNumber;
    int m_movesLeft;
    QString m_gameHistory;
    bool m_stillCanWinn;
    bool m_winnState;


signals:
    void historyChanged();
    void boardTypeChanged();
    void movesLeftChanged();
    void stillCanWinnChanged();
    void winnStateChanged();
    
public slots:
    void fieldClicked(int fieldNumber);
    void rightClicked(int fieldNumber);
    void newGameClicked(QString boardType);
};

#endif // GAMEENGINE_H
