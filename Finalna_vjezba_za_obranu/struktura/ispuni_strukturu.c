//Funkcija iz ispunjavanje niza strukutra
#include <stdio.h>
typedef struct{
    char ime[20];
    int godina;
}Osoba;

Osoba* funkcija(Osoba* niz, int n){
    int i,j;
    int brojac = 0, k = 0;
    for(i = 0; i < n; i++){
        printf("Unesite podatke za %d osobu : \n",i+1);
        printf("Unesite ime : ");
        scanf("%s", niz[i].ime);
        printf("\nUnesite godinu : ");
        scanf("%d",&niz[i].godina);
    }
    return niz;
}

int main(){
    int n = 3;
    Osoba niz[3];
    Osoba *rez = funkcija(niz,n);
    int i;
    for(i = 0; i < n; i++){
        printf("Osoba %d ima ime : %s i godinu %d\n",i+1,rez[i].ime,rez[i].godina);
    }
    return 0;
}