//int* filtriraj(int *niz, int n, int th, int *nth) – vraća novi niz koji sadrži brojeve iz originalnog niza koji su manji od th. Originalni niz ima dužinu n. Dužinu novog niza sa brojevima koji su prošli filter treba spremiti u nth. 
#include <stdio.h>
#include <stdlib.h>
int* filtriraj(int *niz, int n, int th, int *nth){
    int i,duljina=0;
    for(i = 0; i < n ; i++){
        if (niz[i] < th){
            duljina++;
        }
    }
    int* novi_niz = (int*) malloc(duljina * sizeof(int));

    int j=0;
    for(i = 0; i < n; i++){
        if (niz[i] < th){
            novi_niz[j++] = niz[i];
        }
    }
    *nth = duljina;
    return novi_niz;
}

int main(){
    int niz[] = {10, 20, 30, 40, 50};
    int n = sizeof(niz) / sizeof(niz[0]);
    int th = 25;
    int nth;
    int* niz1 = filtriraj(niz,n,th,&nth);
    printf("Filtrirani niz je : { ");
    int i;
    for(i=0; i<nth;i++){
        printf("%d ",niz1[i]);
    }
    printf("}");
    free(niz1);
    return 0;
}