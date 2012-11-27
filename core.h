#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <qmlapplicationviewer.h>
#include "fileparser.h"
#include "gameboard.h"
#include "iterator.h"

class Core : public QObject
{
public:
    Core();

private:
    QmlApplicationViewer *m_viewer;
    GameBoard m_board;
};

#endif // CORE_H
