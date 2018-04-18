#include "compteur.h"

Compteur::Compteur(QObject *parent) : QObject(parent)
{
    fCompteur=10;
    cptChanged();
}

QString Compteur::readCompteur()
{
    return QString::number(fCompteur);
}

void Compteur::increment() {
    fCompteur++;
    cptChanged();
}

void Compteur::decrement() {
    if (fCompteur>-1) {
        fCompteur--;
        cptChanged();
    }
}
