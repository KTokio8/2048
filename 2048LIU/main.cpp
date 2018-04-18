#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQuickView>
#include "tableau.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<QT2048>("qml2048", 1, 0, "QT2048");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
