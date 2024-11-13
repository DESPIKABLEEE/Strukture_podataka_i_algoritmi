//Uklanjanje duplih brojeva iz niza brojeva ili točaka
#include <stdio.h>
#include <stdlib.h>

int* funkcija(int* niz, int n, int* duljina){
    int i,j;
    int postoji;
    int brojac = 0;
    for(i = 0; i < n; i++){
        postoji = 0;
        for(j = 0; j < brojac; j++){
            if(niz[i] == niz[j]){
                postoji = 1;
                break;
            }
        }
        if(!postoji){
            niz[brojac] = niz[i];
            brojac++;
        }
    }
    int* tmp = malloc(sizeof(int) * brojac);
    for(i = 0; i < brojac; i++){
        tmp[i] = niz[i];
    }
    *duljina = brojac;
    return tmp;
}

int main(){ 
    int niz[] = {1, 1, 2, 3, 3, 4, 5};
    int n = sizeof(niz) / sizeof(niz[0]);
    int duljina;
    int* rez = funkcija(niz,n,&duljina);
    int i;
    for(i = 0; i < duljina; i++){
        printf("%d ", rez[i]);
    }
    free(rez);
    return 0;
}
