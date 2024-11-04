//int* filtriraj(int *niz, int n, int th, int *nth) – vraća novi niz koji sadrži brojeve iz originalnog niza koji su manji od th. Originalni niz ima dužinu n. Dužinu novog niza sa brojevima koji su prošli filter treba spremiti u nth. 
#include <stdio.h>
#include <stdlib.h>
int* filtriraj(int *niz, int n, int th, int *nth){
    int i,brojac=0,j=0;
    for(i=0;i<n;i++){
        if(niz[i] < th)
            brojac++;
    }
    int* novi_niz = (int*) malloc(brojac * sizeof(int));
    *nth = brojac;
    for(i=0;i<n;i++){
        if(niz[i] < th)
            novi_niz[j++]=niz[i];
    }
    return novi_niz;

}
int main(){
    int niz[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(niz) / sizeof(niz[0]);
    int th = 5;
    int nth;
    int* rez = filtriraj(niz,n,th,&nth);
    printf("Filtrirani novi niz koji ima clanove manje od %d je : [ ", th);
    int i;
    for(i=0;i<nth;i++){
        printf("%d ",rez[i]);
    }
    printf("]");
    return 0;
}