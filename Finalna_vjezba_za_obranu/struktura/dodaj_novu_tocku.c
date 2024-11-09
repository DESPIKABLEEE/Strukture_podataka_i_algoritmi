//Funkcija za dodavanje nove toÄke na kraj niza
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int x,y;
}Tocka;

Tocka* funkcija(Tocka* niz, int* n){
    int i,j;
    int brojac = 0, k = 0;
    Tocka *novi_niz = NULL;
    novi_niz = malloc(sizeof(Tocka) * (*n + 1));
    if(novi_niz == NULL){
        printf("Greska");
        return NULL;
    }
    for(i = 0; i < *n; i++){
        novi_niz[k].x = niz[i].x;
        novi_niz[k].y = niz[i].y;
        k++;
    }
    Tocka nova;
    // printf("Unesite nove tocke : ");
    // printf("Sada prva tocka : \n");
    // scanf("%d",&nova.x);
    // printf("Sada druga tocka : \n");
    // scanf("%d",&nova.y);
    nova.x = 8;
    nova.y = 8;
    *n = *n + 1;
    novi_niz[*n - 1].x = nova.x;
    novi_niz[*n - 1].y = nova.y;

    return novi_niz;
}

int main(){
    Tocka niz[] = {
        {1,3},
        {1,4},
        {1,5}
    };
    int n = 3;
    Tocka* rez = funkcija(niz,&n);
    int i;
    for(i = 0; i < n; i++){
        printf("Tocka %d ima koordinate %d i %d\n",i+1,rez[i].x,rez[i].y);
    }
    free(rez);
    return 0;
}