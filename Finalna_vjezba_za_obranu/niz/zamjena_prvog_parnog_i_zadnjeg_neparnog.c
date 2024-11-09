//Funkcija za zamjenu prvog parnog i zadnjeg neparnog broja u nizu
#include <stdio.h>
void zamjena(int*, int);
int main(){
    int niz[] = {1, 2, 3, 4, 5};
    int n = sizeof(niz) / sizeof(niz[0]);
    int i;
    for(i = 0; i < n; i++){
        printf("%d ",niz[i]);
    }
    printf("\n\n");
    zamjena(niz,n);
    for(i = 0; i < n; i++){
        printf("%d ",niz[i]);
    }
    return 0;
}

void zamjena(int* niz, int n){
    int temp, i, j,prvi_parni,zadnji_neparni;
    for(i = 0; i < n; i++){
        if(niz[i] % 2 == 0){
            prvi_parni = i;
            break;
        }
    }
    for(j = n - 1; j >= 0; j--){
        if(niz[j] % 2 != 0){
            zadnji_neparni = j;
            break;
        }
    }
    temp = niz[prvi_parni];
    niz[prvi_parni] = niz[zadnji_neparni];
    niz[zadnji_neparni] = temp;
}