//Funkcija za okretanje niza brojeva
#include <stdio.h>
#include <stdio.h>
void okreni(int*, int);
int main(){ 
    int niz[] = {1, 2, 3, 4, 5};
    int n = sizeof(niz) / sizeof(niz[0]);
    int i;
    for(i = 0; i < n; i++){
        printf("%d ",niz[i]);
    }
    printf("\n\n");
    okreni(niz,n);
    for(i = 0; i < n; i++){
        printf("%d ",niz[i]);
    }
    return 0;
}
void okreni(int* niz, int n){
    int i,j,temp;
    for(i = 0, j = n - 1; i < n/2; i++, j--){
        temp = niz[i];
        niz[i] = niz[j];
        niz[j] = temp;
    }
}