#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <qmlapplicationviewer.h>


class Core : public QObject
{
public:
    Core();

private:
    QmlApplicationViewer *m_viewer;

};

#endif // CORE_H
