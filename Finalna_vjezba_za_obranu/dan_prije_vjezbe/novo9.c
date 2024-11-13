// 4. Uklanjanje elemenata koji zadovoljavaju uvjet
// Zadatak: Napiši funkciju koja prima niz točaka i uklanja sve točke kod kojih je x veći od y. Vraća novi niz s preostalim točkama.
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int x,y;
}Tocka;

void funkcija(Tocka* niz,int* n){
    int i,j;
    int brojac = *n;
    for(i = 0; i < *n; i++){
        if((niz[i].x > niz[i].y)){
            for(j = i; j < *n - 1; j++){
                niz[j] = niz[j + 1];
            }
            brojac--;
            i--;
        }
    }
    *n = brojac;
}

int main(){
    Tocka niz[] = {
        {2,4},
        {4,1},
        {6,1},
        {2,7}
    };
    int n = sizeof(niz) / sizeof(niz[0]);
    funkcija(niz,&n);
    int i;
    for(i = 0; i < n; i++){
        printf("tocka %d ima koordinate %d i %d\n",i+1,niz[i].x,niz[i].y);
    }
    return 0;
}