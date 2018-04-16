#include "grille.h"

Grille::Grille(int l, int c)
{
    Alloc(l,c);
    Init();
    AjoutTile();
    AjoutTile();
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
}

void Grille::Alloc(int l, int c){
    L = l;
    C = c;
    Cordonnes = new int*[L];
    for(int i=0; i<L; i++)
        Cordonnes[i] = new int[C];
}

void Grille::Init(){
    for(int i=0; i<L; i++){
        for (int j=0; j<C; j++)
            Cordonnes[i][j]=0;
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
    }

}



bool Grille::FinJeu(){
    //Afficher la commentaire
    //( initialiser le jeu ou faire marche arriere)
    return false;
}


void Grille::Print(){
    cout << endl;
    for(int i=0; i<L; i++) {
        cout << endl;
        for(int j=0; j<C; j++)
            cout << Cordonnes[i][j] << "  ";
    }
    cout<<endl;
}

