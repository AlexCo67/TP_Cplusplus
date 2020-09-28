#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>


using namespace std;

//III.1.1
void prenom(){
    string prenom;
    cout<<"Veuillez entrer votre prenom"<<endl;
    cin>>prenom;
    cout<<"Bonjour "<<prenom<<endl;
}
//III.1.2 et bonus
void nomPrenom(){
    string prenom;
    string nom;
    cout<<"Veuillez entrer votre nom et votre prenom"<<endl;
    cin>>nom>>prenom;
    //Gestion des uppercase/lowercase
    prenom[0]=toupper(prenom[0]);
    for(int i=1;i<prenom.length();i++){
       prenom[i]=tolower(prenom[i]);
    };
    for(int i=0;i<nom.length();i++){
       nom[i]=toupper(nom[i]);
    };

    cout<<"Bonjour "<<nom<<" "<<prenom<<endl;
}

//III.2.1

int alea(){
    srand((unsigned int)time(0));
    return (rand()%1001);
}

void jeu1(){
    int goal=alea();
    cout<<"Un nombre aleatoire fait. Veuillez entrer un nombre entre 0 et 1000"<<endl;
    int num;
    cin>>num;
    if(goal==num){
        cout<<"Vous avez trouve le bon nombre : "<<num<<endl;
    }
    else if (goal>num){
        cout<<"Le nombre aleatoire est plus grand : c'est "<<goal<<endl;
    }
    else{
        cout<<"Le nombre aleatoire est plus petit : c'est "<<goal<<endl;
    }
}

//III.2.2
void jeu2(){
    int goal=alea();
    cout<<"Un nombre aleatoire fait."<<endl;
    int essais=1;
    int num=-1;
    while(goal!=num){
        cout<<" Veuillez entrer un nombre entre 0 et 1000"<<endl;
        cin>>num;
        if(goal==num){
            cout<<"Vous avez trouve le bon nombre : "<<num<<endl;
        }
        else if (goal>num){
            cout<<"Le nombre aleatoire est plus grand"<<endl;
            essais++;
        }
        else{
            cout<<"Le nombre aleatoire est plus petit"<<endl;
            essais++;
        }
    }
    cout<<"Vous avez gagne en : "<<essais<<" coups"<<endl;
}


//III.2.3 BONUS
void jeu3(){
    int goal=-1;
    while (goal<0 || goal>1000){
        cout<<"Veuillez entrer un nombre entre 0 et 1000"<<endl;
        cin>>goal;
        }
    cout<<"L'ordinateur va chercher le nombre"<<endl;
    int borneSup=1000;
    int borneInf=0;
    int num=-1;
    int essais=1;

    //L'ordinateur va borner de façon successive le nombre dans un intervalle, et proposer le milieu des intervalles qu'il délimite.

    while(num!=goal){
        num=borneInf+(borneSup-borneInf)/2;
        cout<<"L'ordinateur essaie : "<<num<<endl;
        if(goal==num){
            cout<<"L'ordinateur a trouve le bon nombre : "<<num<<endl;
        }
        else if (goal>num){
            cout<<"Le nombre aleatoire est plus grand"<<endl;
            essais++;
            borneInf=num;
        }
        else{
            cout<<"Le nombre aleatoire est plus petit"<<endl;
            essais++;
            borneSup=num;
        }
    }
    cout<<"L'ordinateur a trouve en : "<<essais<<" coups"<<endl;

}

int main()
{
    jeu3();
    return 0;
}
