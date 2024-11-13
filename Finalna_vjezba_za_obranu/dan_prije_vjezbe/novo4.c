// 2. Filtriranje elemenata
// Zadatak: Napiši funkciju koja prima niz brojeva i u novi niz sprema sve brojeve koji su djeljivi s 3. Vraća novi niz i broj elemenata u njemu.
#include <stdio.h>
#include <stdlib.h>

int* funkcija(int* niz, int* n){
    int i,brojac = 0;
    int* novi_niz = malloc(sizeof(int) * (*n));
    for(i = 0; i < *n; i++){
        if(niz[i] % 3 == 0){
            novi_niz[brojac++] = niz[i];
        }
    }
    *n = brojac;
    novi_niz = realloc(novi_niz,sizeof(int) * brojac);
    return novi_niz;
}

int main(){ 
    int niz[] = {1,2,3,6,9,14};
    int n = sizeof(niz) / sizeof(niz[0]);
    int* rez = funkcija(niz,&n);
    int i;
    for(i = 0; i < n; i++){
        printf("%d ",rez[i]);
    }
    return 0;
}