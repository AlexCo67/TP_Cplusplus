#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int points(int ech){
    if(ech<=0){
        return 0;
    }
    else if (ech==1){
        return 15;
    }
    else if (ech==2){
        return 30;
    }
    else {
        return 40;
        }
}


void score(int echA, int echB){
    int pointsA=points(echA);
    int pointsB=points(echB);
    if(echA<=3&&echB<=3){
        cout<<"Partie en cours : "<<pointsA<<" - "<<pointsB<<endl;
    }
    else if(echA<3&&echB>3){
        cout<<"Jeu termine, le joueur B a gagne : "<<pointsA<<" - "<<pointsB<<endl;
    }
    else if(echB<3&&echA>3){
        cout<<"Jeu termine, le joueur A a gagne : "<<pointsB<<" - "<<pointsA<<endl;
    }
    else{
        int diff = echA-echB;
        if (diff==0){
            cout<<"40 - 40, pas d'avantage"<<endl;
        }
        else if (diff==1){
            cout<<"40 - 40, avantage joueur A"<<endl;
        }
        else if (diff>1){
            cout<<"Jeu termine, le joueur A a gagne avec avantage"<<endl;
        }
        else if (diff==-1){
            cout<<"40 - 40, avantage joueur B"<<endl;
        }
        else{
            cout<<"Jeu termine, le joueur B a gagne avec avantage"<<endl;
        }
    }


}

int main()
{
    score (6,4);
    return 0;
}
