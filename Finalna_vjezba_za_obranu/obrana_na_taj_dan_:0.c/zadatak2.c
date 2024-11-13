//Okretanje niza
#include <stdio.h>
#include <stdlib.h>

void poredaj(int* niz, int n){
    int i,j;
    int temp;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(niz[j] < niz[i]){
                temp = niz[j];
                niz[j] = niz[i];
                niz[i] = temp;
            }
        }
    }
}

int main(){
    int niz[] = {4, 2, 1, 3, 5};
    int n = sizeof(niz) / sizeof(niz[0]);
    printf("Niz prije poredka : ");
    int i,j;
    for(i = 0; i < n; i++){
        printf("%d ",niz[i]);
    }
    poredaj(niz,n);
    printf("\nNakon poredka : ");
    for(j = 0; j < n; j++){
        printf("%d ",niz[j]);
    }
    return 0;
}