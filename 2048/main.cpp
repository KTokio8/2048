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
    G1.mouveGauche();
    G1.Print();
    G1.mouveDroite();
    G1.Print();
    G1.mouveHaut();
    G1.Print();
    G1.mouveBas();
    G1.Print();
    G1.goBack();
    G1.Print();
    G1.goBack();
    G1.Print();
    G1.goBack();
    G1.Print();
    G1.goBack();
    G1.Print();
    G1.~Grille ();
    return 0;
}
