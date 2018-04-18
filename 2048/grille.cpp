#include "grille.h"

Grille::Grille(int l, int c)
{
    Alloc(l,c);
    Init();
    step = 0;
    AjoutTile();
    AjoutTile();
    Memoire();
}

Grille::Grille(const Grille &G)
{
    Alloc(G.L, G.C);
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            Cordonnes[i][j] = G.Cordonnes[i][j];
}

Grille::~Grille(){
    if (Cordonnes != NULL) {
        Free();
        Cordonnes = NULL;
    }
}

void Grille::Free(){
    for (int i=0; i<L; i++)
        delete [] Cordonnes[i];
    delete [] Cordonnes;

    for(int n=0; n<50; n++){
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

    Histoire = new int**[50];
    for(int n=0; n<50; n++){
        Histoire[n] = new int*[L];
        for(int m=0; m<L; m++){
            Histoire[n][m] = new int[C];}
    }
}

void Grille::Init(){
    for(int p=0; p<50; p++){
        for(int i=0; i<L; i++){
            for (int j=0; j<C; j++){
                Histoire[p][i][j]=0;
                Cordonnes[i][j]=0;
            }
        }
    }
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
}

void Grille::Memoire(){
    step++;
    for(int n=0; n<L; n++){
        for(int m=0; m<C; m++){
            Histoire[step][n][m] = Cordonnes[n][m];}
}
}

void Grille::goBack(){
    for(int n=0; n<L; n++){
        for(int m=0; m<C; m++){
            Cordonnes[n][m] = Histoire[step-1][n][m];}
    }
    step--;
}

void Grille::mouveGauche(){
    int compte=0;
    for(int i=0; i<L; i++){
        for(int j=0; j<C-1; j++){
            if(Cordonnes[i][j]!=0){
                int flag=0;
                for(int h=1; h<C-j;h++){
                    if(Cordonnes[i][j]==Cordonnes[i][j+h]){
                        Cordonnes[i][j]*=2;
                        Cordonnes[i][j+h]=0;
                        compte=1;
                        flag=1;
                    }else if(Cordonnes[i][j+h]!=0){
                        flag=1;
                    }

                    if (flag==1)
                        break;
                }
            }
        }

        for(int j=0; j<C; j++){
            if (Cordonnes[i][j]==0){
                for(int k=1; k<C-j;k++){
                    if (Cordonnes[i][j+k]!=0){
                        Cordonnes[i][j]=Cordonnes[i][j+k];
                        Cordonnes[i][j+k]=0;
                        compte=1;
                        k=C-j;
                    }
                }
            }
        }
    }

    if(compte!=0){
        if(FinJeu()){

        }else
            AjoutTile();
            Memoire();
    }
}

void Grille::mouveDroite(){
    int compte=0;
    for(int i=0; i<L; i++){
        for(int j=C-1; j>0; j--){
            if(Cordonnes[i][j]!=0){
                int flag=0;
                for (int h=1; h<=j;h++){
                    if (Cordonnes[i][j]==Cordonnes[i][j-h]){
                        Cordonnes[i][j]*=2;
                        Cordonnes[i][j-h]=0;
                        compte=1;
                        flag=1;
                    }else if(Cordonnes[i][j-h]!=0){
                        flag=1;
                    }

                    if (flag==1)
                        break;
                }
            }
        }

        for(int j=L-1; j>0; j--){
            if (Cordonnes[i][j]==0){
                for(int k=1; k<=j;k++){
                    if (Cordonnes[i][j-k]!=0){
                        Cordonnes[i][j]=Cordonnes[i][j-k];
                        Cordonnes[i][j-k]=0;
                        compte=1;
                        k=j;
                    }
                }
            }
        }
    }

    if(compte!=0){
        if(FinJeu()){

        }else
            AjoutTile();
            Memoire();
    }



}

void Grille::mouveHaut(){
    int compte=0;
    for(int i=0; i<C; i++){
        for(int j=0; j<L-1; j++){
            if(Cordonnes[j][i]!=0){
                int flag=0;
                for (int h=1; h<L-j;h++){
                    if (Cordonnes[j][i]==Cordonnes[j+h][i]){
                        Cordonnes[j][i]*=2;
                        Cordonnes[j+h][i]=0;
                        compte=1;
                        flag=1;
                    }else if(Cordonnes[j+h][i]!=0){
                        flag=1;
                    }

                    if (flag==1)
                        break;
                }
            }
        }

        for(int j=0; j<L; j++){
            if (Cordonnes[j][i]==0){
                for(int k=1; k<L-j;k++){
                    if (Cordonnes[j+k][i]!=0){
                        Cordonnes[j][i]=Cordonnes[j+k][i];
                        Cordonnes[j+k][i]=0;
                        compte=1;
                        k=L-j;
                    }
                }
            }
        }

    }
    if(compte!=0){
        if(FinJeu()){

        }else
            AjoutTile();
            Memoire();
    }

}

void Grille::mouveBas(){
    int compte=0;
    for(int i=0; i<C; i++){
        for(int j=L-1; j>0; j--){
            if(Cordonnes[j][i]!=0){
                int flag=0;
                for (int h=1; h<=j;h++){
                    if (Cordonnes[j][i]==Cordonnes[j-h][i]){
                        Cordonnes[j][i]*=2;
                        Cordonnes[j-h][i]=0;
                        compte=1;
                        flag=1;
                    }else if(Cordonnes[j-h][i]!=0){
                        flag=1;
                    }

                    if (flag==1)
                        break;
                }
            }
        }

        for(int j=L-1; j>0; j--){
            if (Cordonnes[j][i]==0){
                for(int k=1; k<=j;k++){
                    if (Cordonnes[j-k][i]!=0){
                        Cordonnes[j][i]=Cordonnes[j-k][i];
                        Cordonnes[j-k][i]=0;
                        compte=1;
                        k=j;
                    }
                }
            }
        }
    }

    if(compte!=0){
        if(FinJeu()){

        }else
            AjoutTile();
            Memoire();
    }

}

bool Grille::FinJeu(){


    return false;
}

void Grille::Print(){
    cout<<"Status"<<endl;
    for(int i=0; i<L; i++) {
        cout << endl;
        for(int j=0; j<C; j++)
            cout << Cordonnes[i][j] << "  ";
    }
    cout<<endl;
}



//Faire une marche
//void Grille::move(Move_Direction direction)
//{
//    added(direction);
//    moved(direction);
//    ajoutTile(flag);
//    if(m_bestScore < m_score) {
//        m_bestScore = m_score;
//    }
//}

//Change les couleurs des carreaux selon ses valeurs
//QColor Grille::color(const int &index)
//{
//    int number = m_number[index];
//    QColor color;
//    switch(number) {
//    case 0: color = QColor(255, 255, 255); break; // white
//    case 2: color = QColor(245, 222, 179); break; // wheat
//    case 4: color = QColor(238, 130, 238); break; // violet
//    case 8: color = QColor(0, 255, 127); break; // springgreen
//    case 16: color = QColor(255, 192, 203); break; // pink
//    case 32: color = QColor(255, 165, 0); break; // orange
//    case 64: color = QColor(173, 255, 47); break; // greenyellow
//    case 128: color = QColor(255, 99, 71); break; // tomato
//    case 256: color = QColor(154, 205, 50); break; // yellowgreen
//    case 512: color = QColor(255, 215, 0); break; // gold
//    case 1024: color = QColor(0, 255, 255); break; // cyan
//    case 2048: color = QColor(0, 255, 0); break; // green
//    case 4096: color = QColor(255, 255, 0); break; // yellow
//    case 8192: color = QColor(255, 0, 0); break; // red
//    default: color = QColor(0, 0, 0); break; // black
//    }
//    return color;
//}
