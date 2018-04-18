#ifndef GRILLE_H
#define GRILLE_H

//#include <QMainWindow>
//#include <QObject>
//#include <QWidget>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Grille
{
    //Q_OBJECT
public:
    //explicit Grille(QObject *parent = 0);
    Grille(int l=4, int c=4);
    Grille(const Grille &G);
    ~Grille();


    Grille operator+ (const Grille &G);

    void Init();
    void Set(int x, int y, int value);
    bool FinJeu();
    void Memoire();
    void goBack();

    void mouveDroite();
    void mouveGauche();
    void mouveBas();
    void mouveHaut();



    /*
    Q_INVOKABLE void mouveDroite();
    Q_INVOKABLE void mouveGauche();
    Q_INVOKABLE void mouveBas();
    Q_INVOKABLE void mouveHaut();

    Q_PROPERTY(QString cptQML READ readCompteur NOTIFY cptChanged);
    */

    void Print();
//public slots:
//signals:
    //void Move();

protected:
    int L;
    int C;
    int** Cordonnes;
    int compte;
    int*** Histoire;
    int step;

private:
    void Alloc(int l=4, int c=4);
    void Free();
    void AjoutTile();
    bool TileComplete();

};

#endif // GRILLE_H



