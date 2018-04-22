#include "grille.h"
#include "exception.h"

//Change les couleurs des carreaux selon ses valeurs
QColor Grille::color(const int &n,const int &m)
{
    int number = Cordonnes[n][m];
    QColor color;
    switch(number) {
    case 0: color = QColor(255, 255, 255); break;
    case 2: color = QColor(245, 222, 179); break;
    case 4: color = QColor(246, 194, 120); break;
    case 8: color = QColor(236, 127, 76); break;
    case 16: color = QColor(252, 242, 22);break;
    case 32: color = QColor(254, 94, 24); break;
    case 64: color = QColor(250, 5, 5); break;
    case 128: color = QColor(255, 99, 71); break;
    case 256: color = QColor(248, 246, 108); break;
    case 512: color = QColor(235, 231, 1); break;
    case 1024: color = QColor(202, 227, 20); break;
    case 2048: color = QColor(0, 255, 0); break;
    case 4096: color = QColor(17, 167, 223); break;
    case 8192: color = QColor(17, 167, 223); break;
    default: color = QColor(0, 0, 0); break; // black
    }
    return color;
}

Grille::Grille(QObject *parent) : QObject(parent)
{
    Alloc(4,4);
    Init();
}

Grille::~Grille()
{
    if (Cordonnes != NULL) {
        Free();
        Cordonnes = NULL;
    }
}

//Donner les chiffres des grilles a l'interface
int Grille::lireChiffre(int a, int b){
    int chiffre = Cordonnes[a][b];
    return chiffre;
}

QString Grille::terminer()
{
    return QString::number(opacite);
}

//Donner le nombre de la marche a l'interface
QString Grille::readstep()
{
    return QString::number(estep+1);
}

void Grille::Free(){
    for (int i=0; i<L; i++)
        delete [] Cordonnes[i];
    delete [] Cordonnes;

    for(int n=0; n<500; n++){
        for(int m=0; m<L; m++){
            delete [] Histoire[n][m];}
        delete [] Histoire[n];
    }
    delete [] Histoire;
}

void Grille::Alloc(int l, int c){
    L = l;
    C = c;
    Cordonnes = new int*[L];
    for(int i=0; i<L; i++)
        Cordonnes[i] = new int[C];

    Histoire = new int**[200];
    for(int n=0; n<200; n++){
        Histoire[n] = new int*[L];
        for(int m=0; m<L; m++){
            Histoire[n][m] = new int[C];}
    }
}

//Commencer un jeu 2048
void Grille::commencer(){
    Alloc(4,4);
    Init();
    AjoutTile();
    AjoutTile();
    try{
        Memoire();
    }
    catch(MyException& e)
        {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch(std::exception& e)
        {
        //Les autres erreurs
    }
    catch (...)
        {std::cout << "Erreur inconnue" << endl;}
}

void Grille::Init(){
    for(int p=0; p<200; p++){
        for(int i=0; i<L; i++){
            for (int j=0; j<C; j++){
                Histoire[p][i][j]=0;
                Cordonnes[i][j]=0;
            }
        }
    }
    step = -1;
    estep = -1;
    opacite = 0;
}

void Grille::AjoutTile(){
    int x;
    int y;
    int numero;

    do{
        x = (int)(rand() / (RAND_MAX +1.0)*C);
        y = (int)(rand() / (RAND_MAX +1.0)*L);
    }while(Cordonnes[x][y]!=0);

    int p = (int)(rand() / (RAND_MAX +1.0)*10)+1;
    if (p>8)
        numero=4;
    else
        numero=2;
    Cordonnes[x][y]=numero;
    if(FinJeu())Terme();
}

//Noter l'etat du jeux
void Grille::Memoire(){
    step++;
    estep++;
    if(step<0)
        throw MyException();
    if (step>199)
        step -= 200;
    for(int n=0; n<L; n++){
        for(int m=0; m<C; m++){
            Histoire[step][n][m] = Cordonnes[n][m];
        }
    }
    Stepchanged();
}

//Faire une marche arriere
void Grille::goBack(){
    if (step>0){
        for(int n=0; n<L; n++){
            for(int m=0; m<C; m++){
                Cordonnes[n][m] = Histoire[step-1][n][m];}
        }
        step--;
        estep--;
    }
    if(FinJeu())Terme();
    else opacite=0;
    Stepchanged();
}

void Grille::mouve(int d){
    //direction: 0=Haut; 1=Bas; 2=Gauche; 3=Droite
    int direction=d;
    //La matrice tempolaire qui stock une matrice transformée
    int Stocks[L][C];

    //Transformer la matrice: Degager la différence issue de chaque direction
    switch(direction){
    //Haut: Transport
    case 0:
        for(int i=0; i<L; i++){
            for(int j=0; j<C; j++){
                Stocks[j][i]=Cordonnes[i][j];
            }
        }
        break;
    //Bas:symetrie ponctuelle
    case 1:
        for(int i=0; i<L; i++){
            for(int j=0; j<C; j++){
                Stocks[L-1-j][C-1-i]=Cordonnes[i][j];
            }
        }
        break;
    //Gauche: Aucune transforme
    case 2:
        for(int i=0; i<L; i++){
            for(int j=0; j<C; j++){
                Stocks[i][j]=Cordonnes[i][j];
            }
        }
        break;
    //Droite: Symetrie lineaire
    case 3:
        for(int i=0; i<L; i++){
            for(int j=0; j<C; j++){
                Stocks[i][C-1-j]=Cordonnes[i][j];
            }
        }
        break;
    }


   //Detecter s'il y a un changement est possible
    int compte=0;

    for(int i=0; i<L; i++){
         //La partie du calcul:s'il y a des cases fusionnés on les appliaue
        for(int j=0; j<C-1; j++){
            if(Stocks[i][j]!=0){
                //flag: Detecter une fusion ou une case!=0
                int flag=0;
                for(int h=1; h<C-j;h++){
                    if(Stocks[i][j]==Stocks[i][j+h]){
                        Stocks[i][j]*=2;
                        Stocks[i][j+h]=0;
                        compte=1;
                        flag=1;
                    }else if(Stocks[i][j+h]!=0){
                        flag=1;
                    }

                    if (flag==1)
                        break;
                }
            }
        }

        //La partie du déplacement: On deplace des cases si necéssaire
        for(int j=0; j<C; j++){
            if (Stocks[i][j]==0){
                for(int k=1; k<C-j;k++){
                    if (Stocks[i][j+k]!=0){
                        Stocks[i][j]=Stocks[i][j+k];
                        Stocks[i][j+k]=0;
                        compte=1;
                        k=C-j;
                    }
                }
            }
        }
    }

    //Revenir à la matrice avec les cordonnées originales
    switch(direction){
    case 0:
        // transporter la matrice
        for(int i=0; i<L; i++){
            for(int j=0; j<C; j++){
                Cordonnes[j][i]=Stocks[i][j];
            }
        }
        break;

    case 1:
        for(int i=0; i<L; i++){
            for(int j=0; j<C; j++){
                Cordonnes[L-1-j][C-1-i]=Stocks[i][j];
            }
        }
        break;

    case 2:
        for(int i=0; i<L; i++){
            for(int j=0; j<C; j++){
                Cordonnes[i][j]=Stocks[i][j];
            }
        }
        break;

    case 3:
        for(int i=0; i<L; i++){
            for(int j=0; j<C; j++){
                Cordonnes[i][C-1-j]=Stocks[i][j];
            }
        }
        break;
    }

    if(compte!=0){
        AjoutTile();
        Memoire();
    }
}



//Verifier si le jeu est fini
bool Grille::FinJeu(){
    for(int n=0; n<L; n++){
        for(int m=0; m<C-1; m++){
            if ((Cordonnes[n][m] == Cordonnes[n][m+1]) || (Cordonnes[n][m]==0) || (Cordonnes[n][m+1]==0))
                return false;
        }
    }
    for(int x=0; x<C; x++){
        for(int y=0; y<L-1; y++){
            if ((Cordonnes[y][x] == Cordonnes[y+1][x]) || (Cordonnes[y][x]==0)|| (Cordonnes[y+1][x]==0))
                return false;
        }
    }
    opacite = 10;
    return true;
    }



//Grille::Grille(const Grille &G)
//{
//    Alloc(G.L, G.C);
//    for(int i=0; i<L; i++)
//        for(int j=0; j<C; j++)
//            Cordonnes[i][j] = G.Cordonnes[i][j];
//}

//void Grille::Print(){
//    cout<<"Status"<<endl;
//    for(int i=0; i<L; i++) {
//        cout << endl;
//        for(int j=0; j<C; j++)
//            cout << Cordonnes[i][j] << "  ";
//    }
//    cout<<endl;
//}




