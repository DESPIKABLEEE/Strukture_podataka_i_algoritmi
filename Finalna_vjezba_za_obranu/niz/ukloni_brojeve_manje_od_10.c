//Funkcija za uklanjanje brojeva manjih od 10 iz niza
#include <stdio.h>
#include <stdlib.h>

void manji(int*,int*);

int main(){
    int niz[] = {5, 10, 15, 2, 22, 6};
    int n = sizeof(niz) / sizeof(niz[0]);
    int i;
    printf("Prvi niz : ");
    for(i = 0; i < n; i++){
        printf("%d ",niz[i]);
    }
    manji(niz,&n);
    printf("Drugi niz : ");
    for(i = 0; i < n; i++){
        printf("%d ",niz[i]);
    }
    return 0;
}

void manji(int* niz, int* n){
    int k = 0,i;
    for(i = 0; i < *n; i++){
        if(niz[i] >= 10){
            niz[k] = niz[i];
            k++;
        }
    }
    *n = k;
}


