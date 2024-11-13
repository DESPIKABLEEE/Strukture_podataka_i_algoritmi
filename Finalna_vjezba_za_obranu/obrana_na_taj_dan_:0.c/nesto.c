#include <stdio.h>
#include <stdlib.h>

int vec_u_nizu(int* niz, int n, int broj){
    for(int i = 0; i < n; i++){
        if(niz[i] == broj)
            return 1;
    }
    return 0;
}

void funkcija(int* niz1, int* niz2, int n1, int n2){
    int i,j;
    int brojac = 0;
    int* novi_niz = malloc(sizeof(int) * (n1 + n2));
    for(i = 0; i < n1; i++){
        for(j = 0; j < n2; j++){
            if((niz1[i] == niz2[j]) && !(vec_u_nizu(novi_niz,brojac,niz1[i]))){
                printf("%d ", niz1[i]);
                novi_niz[brojac++] = niz1[i];
                break;
            }
        }
    }

}


int main() {
    int niz1[] = {1, 2, 3, 3, 4, 5, 6};
    int niz2[] = {1, 1, 2, 3, 4, 7, 8};
    int n1 = sizeof(niz1) / sizeof(niz1[0]);
    int n2 = sizeof(niz2) / sizeof(niz2[0]);

    funkcija(niz1, niz2, n1, n2);

    return 0;
}