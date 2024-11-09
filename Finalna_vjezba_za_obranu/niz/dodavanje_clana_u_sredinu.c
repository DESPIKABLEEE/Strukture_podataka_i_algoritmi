//Funkcija za dodavanje novog broja u sredinu niza
#include <stdio.h>
#include <stdlib.h>
void dodavanje(int*,int* ,int);
int main(){
    int niz[] = {1, 2, 3, 4, 5};
    int n = sizeof(niz) / sizeof(niz[0]);
    int i;
    printf("Niz : ");
    for(i = 0; i < n; i++){
        printf("%d ",niz[i]);
    }
    dodavanje(niz,&n,44);
    printf("\nNovi niz  : ");
    for(i = 0; i < n; i++){
        printf("%d ",niz[i]);
    }
    return 0;
}

void dodavanje(int* niz, int* n, int broj){
    int i,sredina = *n/2;
    for(i = *n; i > sredina; i--){
        niz[i] = niz[i - 1];
    }
    (*n)++;
    niz[sredina] = broj;

}