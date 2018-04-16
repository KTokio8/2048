#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <iostream>
#include <string>


#include "grille.h"

using namespace std;


int main(int argc, char *argv[])
{

    Grille G1(4,4);
    G1.Print();

    return 0;
}
