// zamini prvi parni sa zadnjin neparnin
#include <stdio.h>
#include <stdlib.h>

void funkcija(int* niz, int n){
    int prvi_parni,zadnji_neparni;
    int i,j;
    for(i = 0; i < n; i++){
        if(niz[i] % 2 == 0){
            prvi_parni = i;
            break;
        }
    }
    for(j = n - 1; j > 0; j--){
        if(niz[j] % 2 != 0){
            zadnji_neparni = j;
            break;
        }
    }
    int temp = niz[prvi_parni];
    niz[prvi_parni] = niz[zadnji_neparni];
    niz[zadnji_neparni] = temp;

}

int main(){
    int niz[] = {1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 8, 9, 10, 10, 10};
    int n = sizeof(niz) / sizeof(niz[0]);
    funkcija(niz,n);
    printf("Novi niz je : ");
    int i;
    for(i = 0; i < n; i++){
        printf("%d ",niz[i]);
    }
    return 0;
}