//Uklanjanje duplih brojeva iz niza brojeva 
#include <stdio.h>
#include <stdlib.h>

void funkcija(int* niz, int* n){
    int i,j,k;
    int brojac = 0;
    int dupli;
    for(i = 0; i < *n; i++){
        dupli = 0;
        for(j = 0; j < brojac; j++){
            if(niz[i] == niz[j]){
                dupli = 1;
                break;
            }
        }
        if(!dupli){
            niz[brojac] = niz[i];
            brojac++;
        }
    }
    *n = brojac;
}

int main(){
    int niz[] = {1, 1, 2, 3, 4, 4, 4, 5, 7, 1};
    int n = sizeof(niz) / sizeof(niz[0]);
    printf("Niz prije : ");
    int i,j;
    for(i = 0; i < n; i++){
        printf("%d ",niz[i]);
    }
    funkcija(niz,&n);
    printf("\nNakon : ");
    for(j = 0; j < n; j++){
        printf("%d ",niz[j]);
    }
    return 0;
}