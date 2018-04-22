#ifndef GRILLE_H
#define GRILLE_H
#include <cstdlib>
#include <ctime>
#include <QObject>
#include <QColor>

using namespace std;

class Grille : public QObject
{
    Q_OBJECT
public:
    explicit Grille(QObject *parent = 0);
    ~Grille();
    Q_INVOKABLE void commencer();
    Q_INVOKABLE void mouve(int d);
    Q_INVOKABLE void goBack();
    Q_INVOKABLE int lireChiffre(int a, int b);
    Q_INVOKABLE QColor color(const int &n,const int &m);
    Q_PROPERTY(QString QMLtermine READ terminer NOTIFY Stepchanged)
    Q_PROPERTY(QString QMLstep READ readstep NOTIFY Stepchanged)
    QString terminer();
    QString readstep();

public slots:

signals:
    void Terme();
    void Stepchanged();

protected:
    int L;
    int C;
    int** Cordonnes;
    int*** Histoire;
    int compte;
    int step;
    int estep;
    int opacite;

private:
    void Alloc(int l=4, int c=4);
    void Free();
    void AjoutTile();
    bool TileComplete();
    Grille(const Grille &G);
    void Init();
    bool FinJeu();
    void Memoire();
    //void Print();
};

#endif // GRILLE_H



