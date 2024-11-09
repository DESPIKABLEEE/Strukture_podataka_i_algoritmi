//Funkcija prima dva niza i vraca novi do prvog indeksa i od drugog 
#include <stdio.h>
#include <stdlib.h>

int* funkcija(int*, int*,int,int);

int main(){
    int niz[] = {1, 2, 3, 4, 5};    
    int n = sizeof(niz) / sizeof(niz[0]);
    int start = 1;
    int stop = 3;
    int* rez = funkcija(niz,&n,start,stop);// 2 3 4 
    int i;
    for(i = 0; i < n; i++){
        printf("%d ",rez[i]);
    }
    free(rez);
    return 0;
}

int* funkcija(int* niz, int *n,int start, int stop){
    int brojac = stop - start + 1;
    int i,k = 0;
    int* novi_niz = NULL;
    novi_niz = malloc(sizeof(int) * brojac);
    if(novi_niz == NULL){
        printf("Greska");
        return NULL;
    }
    for(i = start; i < stop + 1; i++){
        novi_niz[k] = niz[i];
        k++;
    }
    *n = brojac;
    return novi_niz;
}