#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <qmlapplicationviewer.h>
#include "fileparser.h"
#include "gameboard.h"
#include "iterator.h"
#include "gameengine.h"

class Core : public QObject
{
public:
    Core();

private:
    QmlApplicationViewer *m_viewer;
    GameEngine *m_engine;
};

#endif // CORE_H
