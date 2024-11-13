// 3. Dinamičko alociranje i dodavanje elemenata
// Zadatak: Napiši funkciju koja prima niz točaka i dinamički alocira memoriju za novi niz koji će sadržavati dodatnu točku na kraju. Nova točka ima koordinate (0,0). Funkcija treba vratiti prošireni niz i osloboditi memoriju originalnog niza.
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y;
}Tocka;

Tocka* funkcija(Tocka* niz, int* n){
    int i,j;
    *n = *n + 1;
    Tocka* nov_niz = malloc(sizeof(Tocka) * (*n));
    for(i = 0; i < *n; i++){
        if(i == (*n - 1)){
            // printf("Unesite dvije nove tocke : ");
            // printf("\nTocka x:");
            // scanf("%d",&nov_niz[i].x);
            // printf("\nTocka y:");
            // scanf("%d",&nov_niz[i].y);
            nov_niz[i].x = 0;
            nov_niz[i].y = 0;
        }else{
            nov_niz[i].x = niz[i].x;
            nov_niz[i].y = niz[i].y;
        }
    }
    return nov_niz;
}

int main(){
    Tocka niz[] = {
        {1,4},
        {2,3},
        {5,7},
        {9,2},
    };
    int n = sizeof(niz) / sizeof(niz[0]);
    Tocka* p = funkcija(niz,&n);
    int i;
    for(i = 0; i < n; i++){
        printf("%d tocka ima koordinate %d i %d\n",i+1,p[i].x,p[i].y);
    }
    return 0;
}