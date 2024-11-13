//Okretanje niza
#include <stdio.h>
#include <stdlib.h>

void funkcija(int* niz, int n){
    int i,j;
    for(i = 0, j = n - 1; i < n/2; i++, j--){
        int temp = niz[j];
        niz[j] = niz[i];
        niz[i] = temp;
    }
}

int main(){
    int niz[] = {1, 2, 3, 4, 5};
    int n = sizeof(niz) / sizeof(niz[0]);
    int i;
    funkcija(niz,n);
    for(i = 0; i < n; i++){
        printf("%d ", niz[i]);
    }
    return 0;
}