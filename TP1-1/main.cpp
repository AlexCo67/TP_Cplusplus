#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;


//1.1.1 Somme de deux nombres
int sum(int a, int b){
    return a+b;
}

//1.1.2 Swap de deux valeurs avec pointeurs
void swap(int*a,int*b){
    int c=*a;
    *a=*b;
    *b=c;
}

//1.1.2 Swap de deux valeurs avec références
void swap2(int &a,int &b){
    int c=a;
    a=b;
    b=c;
}

//1.1.3 Swap avec somme référence
int sumswapR(int a,int b, int&c){
    return c=a+b;
}

//Swap avec somme pointeur
int sumswapP(int a,int b, int*c){
    return *c=a+b;
}

//1.1.4 Tableau d'entiers aléatoires de taille définie par l'utilisateur avec choix du tri croissant/décroissant
int* tableau(){
    srand (time(NULL));
    std::cout<<"Entrez une taille de tableau"<<endl;
    int size;
    std::cin>>size;
    int* tab= new int[size];
    std::cout<<"valeurs non tries"<<endl;
   for(int c=0; c<size;c++){
            tab[c]=rand()%12;
            std::cout<<tab[c]<<" ";
        }
    std::cout<<endl;
    int choix=-1;
    while(choix<1||choix>2){
        cout<<"Entrez 1 pour un tri croissant, 2 pour un tri decroissant"<<endl;
        cin>>choix;}

    switch(choix){
    case 1:
        //tri par ordre croissant : pour i de 0 à size-1, on compare la valeur de tab[i] et de chaque nombre en partant de la fin tab[k]. Si tab[i]<tab[k], k-- jusqu'à k=i.si tab[i]>tab[k], on swap les valeurs et on continue.
        for(int i=0;i<size;i=i+1){
            for(int k=size-1;k>i;k=k-1){
                if (tab[i]>tab[k]){
                    swap2(tab[i],tab[k]);
                }
            }
        }
        break;
    case 2:
        //tri par ordre décroissant : pour i de 0 à size-1, on compare la valeur de tab[i] et de chaque nombre en partant de la fin tab[k]. Si tab[i]>tab[k], k-- jusqu'à k=i.si tab[i]<tab[k], on swap les valeurs et on continue.
        for(int i=0;i<size;i=i+1){
            for(int k=size-1;k>i;k=k-1){
                if (tab[i]<tab[k]){
                    swap2(tab[i],tab[k]);
                }
            }
        }
        break;

    }

    std::cout<<"valeurs triees"<<endl;
    for(int c=0; c<size;c++){
             std::cout<<tab[c]<<" ";
         }
    int*  tab2= tab;
    for(int c=0;c<(size-1)/2;c++){
        swap(tab2[c],tab2[(size-1)-c]);
    }
    cout<<endl;
    std::cout<<"valeurs triees inverses"<<endl;
    for(int c=0; c<size;c++){
             std::cout<<tab2[c]<<" ";
         }

    return tab;
}

int main()
{
  //  cout << "Hello World!" << endl;

    int a=2;
    int b=5;
    int c = sum(a,b);

    swap(&a,&b);

    std::cout<<"a : "<<a<<" b : "<<b<<" c : "<<c<<endl;

    tableau();



    return 0;
}
