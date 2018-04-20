#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "grille.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Grille un2048;

    engine.rootContext()->setContextProperty("vueGrille", &un2048);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
