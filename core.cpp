#include "core.h"
#include <QDebug>
#include <QApplication>
#include <QtDeclarative>
#include <QDeclarativeContext>

#include <iostream>
#include <QDebug>


Core::Core()
{

    m_engine = new GameEngine(this);

    m_viewer = new QmlApplicationViewer();
    m_viewer->rootContext()->setContextProperty("core", this);

    m_viewer->setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    m_viewer->setMainQmlFile(QLatin1String("qml/pegsolitair/main.qml"));
    m_viewer->showExpanded();
}
