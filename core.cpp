#include "core.h"
#include <QDebug>
#include <QApplication>
#include <QtDeclarative>
#include <QDeclarativeContext>

#include <iostream>
#include <QDebug>

using namespace std;

Core::Core()
{

    FileParser parser(m_board);
    parser.parse();
    // now the empty linked Board is created
    Iterator iterator(m_board);
    iterator.resetToFirst();

    //m_board.printFieldConnections();



    m_viewer = new QmlApplicationViewer();
    m_viewer->rootContext()->setContextProperty("core", this);

    m_viewer->setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    m_viewer->setMainQmlFile(QLatin1String("qml/pegsolitair/main.qml"));
    m_viewer->showExpanded();
}
