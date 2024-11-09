//Funkcija za uklanjanje duplikata iz niza brojeva
#include <stdio.h>
#include <stdlib.h>
int* ukloni(int*, int, int*);

int main(){
    int niz[] = {1, 1, 2, 3, 4, 4, 5, 5};
    int n = sizeof(niz) / sizeof(niz[0]);
    int novi_n;
    int* rez = ukloni(niz,n,&novi_n);
    int i;
    for(i = 0; i < novi_n; i++){
        printf("%d ",rez[i]);
    }
    free(rez);
    return 0;
}

//1, 1, 2, 3, 4, 4, 5, 5
int* ukloni(int* niz, int n, int* novi_n){
    int* novi_niz = NULL;
    int i,j,duplikat,brojac = 0,k=0;
    for(i = 0;i < n; i++){
        duplikat = 0;
        for(j = 0; j < i; j++){
            if(niz[i] == niz[j]){
                duplikat = 1;
                break;
            }
        }
        if(duplikat == 0){
            brojac++;
        }
    }
    novi_niz = malloc(sizeof(int) * brojac);
    if(novi_niz == NULL){
        printf("Greska");
        return NULL;
    }
    for(i = 0;i < n; i++){
        duplikat = 0;
        for(j = 0; j < i; j++){
            if(niz[i] == niz[j]){
                duplikat = 1;
                break;
            }
        }
        if(duplikat == 0){
            novi_niz[k] = niz[i];
            k++;
        }
    }
    *novi_n = brojac;
    return novi_niz;
}