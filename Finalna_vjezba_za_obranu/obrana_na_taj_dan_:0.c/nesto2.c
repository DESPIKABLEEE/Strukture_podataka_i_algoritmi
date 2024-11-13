//unesi broj u sredinu i vrati niz
#include <stdio.h>
#include <stdlib.h>

int* funkcija(int* niz, int n, int broj){
    int i,j;
    int sredina = n / 2;
    int* novi_niz = malloc(sizeof(int) * (n + 1));
    for(i = 0; i < sredina; i++){
        novi_niz[i] = niz[i];
    }
    novi_niz[i] = broj;
    for(j = i + 1; j < n + 1; j++){
        novi_niz[j] = niz[j - 1];
    }
    return novi_niz;
}

int main(){
    int niz[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(niz) / sizeof(niz[0]);
    int* rez = funkcija(niz,n, 99);
    int i;
    printf("Niz je : ");
    for(i = 0; i < n + 1; i++){
        printf("%d ", rez[i]);
    }
    return 0;
}