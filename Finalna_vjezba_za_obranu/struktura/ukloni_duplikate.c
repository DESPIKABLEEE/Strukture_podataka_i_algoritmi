//Funkcija za uklanjanje duplikata iz niza toÄaka
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y;
}Tocka;

Tocka* funkcija(Tocka* niz, int *n){
    int brojac = 0;
    int i,j, k = 0;
    int zastavica;
    Tocka* novi_niz = NULL;
    for(i = 0; i < *n; i++){
        zastavica = 0;
        for(j = 0; j < i; j++){
            if((niz[i].x == niz[j].x) && (niz[i].y == niz[j].y)){
                zastavica = 1;
                break;
            }
        }
        if(zastavica == 0){
            brojac++;
        }
    }
    novi_niz = malloc(sizeof(Tocka) * brojac);
    if(novi_niz == NULL){
        printf("Greska");
        return NULL;
    }
    for(i = 0; i < *n; i++){
        zastavica = 0;
        for(j = 0; j < i; j++){
            if((niz[i].x == niz[j].x) && (niz[i].y == niz[j].y)){
                zastavica = 1;
                break;
            }
        }
        if(zastavica == 0){
            novi_niz[k].x = niz[i].x;
            novi_niz[k].y = niz[i].y;
            k++;
        }
    }
    *n = brojac;
    return novi_niz;
}

int main(){
    Tocka niz[] = {
        {1,3},
        {4,2},
        {4,2},
        {1,3},
        {2,6}
    };
    int duljina = 5;
    Tocka* rez = funkcija(niz,&duljina);
    int i;
    for(i = 0; i < duljina; i++){
        printf("Za tocku %d imamo koordinate %d i %d\n", i + 1, rez[i].x,rez[i].y);
    }
    free(rez);
    return 0;
}