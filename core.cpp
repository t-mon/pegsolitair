#include "core.h"
#include "field.h"
#include "gameboard.h"

#include <QDebug>
#include <QApplication>
#include <QtDeclarative>
#include <QDeclarativeContext>

#include <iostream>
#include <QDebug>


Core::Core()
{

    m_engine = new GameEngine(this);

    qmlRegisterUncreatableType<Field>("pegsolitaire", 1, 0, "Field", "get it from engine.board.fieldAt()");
    qmlRegisterUncreatableType<GameBoard>("pegsolitaire", 1, 0, "Board", "get it from engine.board");

    m_viewer = new QmlApplicationViewer();
    m_viewer->rootContext()->setContextProperty("engine", m_engine);
    m_viewer->rootContext()->setContextProperty("board", m_engine->board());
    m_viewer->rootContext()->setContextProperty("core",this);

    m_viewer->setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    m_viewer->setMainQmlFile(QLatin1String("qml/pegsolitair/main.qml"));
    m_viewer->showExpanded();
}
