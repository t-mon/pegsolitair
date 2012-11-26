#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"

#include "core.h"
Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    Core core;

    return app->exec();
}
