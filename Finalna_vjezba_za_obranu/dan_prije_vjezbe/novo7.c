// 2. Uklanjanje dupliciranih točaka
// Zadatak: Napiši funkciju koja prima niz točaka, uklanja sve duplikate (točke koje imaju identične x i ykoordinate) i vraća novi niz bez dupliciranih točaka.
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y;
}Tocka;

Tocka* funkcija(Tocka* niz, int *n){
    int i,j,k = 0;
    int brojac = 0;
    int postoji;
    for(i = 0; i < *n; i++){
        postoji = 0;
        for(j = 0; j < i; j++){
            if((niz[i].x == niz[j].x) && (niz[i].y == niz[j].y)){
                postoji = 1;
                break;
            }
        }
        if(!postoji){
            brojac++;
        }
    }
    Tocka* novi_niz = malloc(sizeof(Tocka) * brojac);
    for(i = 0; i < *n; i++){
        postoji = 0;
        for(j = 0; j < i; j++){
            if((niz[i].x == niz[j].x) && (niz[i].y == niz[j].y)){
                postoji = 1;
                break;
            }
        }
        if(!postoji){
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
        {2,3},
        {2,3},
        {3,2},
        {2,3}
    };
    int n = sizeof(niz) / sizeof(niz[0]);
    Tocka* p = funkcija(niz,&n);
    int i;
    for(i = 0; i < n; i++){
        printf("Tocka %d ima koordinate %d i %d",i+1,p[i].x,p[i].y);
    }
    free(p);
    return 0;
}