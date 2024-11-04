//int* filtriraj(int *niz, int n, int th, int *nth) – vraća novi niz koji sadrži brojeve iz originalnog niza koji su manji od th. Originalni niz ima dužinu n. Dužinu novog niza sa brojevima koji su prošli filter treba spremiti u nth. 
#include <stdio.h>
#include <stdlib.h>
int* filtriraj(int *niz, int n, int th, int *nth){
    int i,j=0,brojac=0;
    for(i = 0; i < n; i++){
        if(niz[i] < th)
            brojac++;
    }
    int* novi_niz = malloc(brojac * sizeof(int));
    for(i = 0; i < n; i++){
        if(niz[i] < th)
            novi_niz[j] = niz[i];
            j++;
    }
    *nth = brojac;
    return novi_niz;
}
int main(){
    int niz[] = {1, 2, 3, 4, 5};
    int n = sizeof(niz) / sizeof(niz[0]);
    int th = 3;
    int nth;
    int* rez = filtriraj(niz,n,th,&nth);
    int i;
    printf("Novi niz \n");
    for(i = 0; i < nth; i++){
        printf("%d ", rez[i]);
    }
    free(rez);
    return 0;
}