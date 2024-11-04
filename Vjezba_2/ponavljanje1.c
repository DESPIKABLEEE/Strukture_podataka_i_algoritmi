//int* podniz(int *niz, int start, int stop) – vraća novi niz koji je kopija dijela niza od indeksa start do indeksa stop.
#include <stdio.h>
#include <stdlib.h>
int* podniz(int *niz, int start, int stop){
    int i,brojac = stop-start+1;
    int* novi_niz=malloc(brojac * sizeof(int));
    for(i = 0; i < brojac; i++){
        novi_niz[i] = niz[start + i];
    }
    return novi_niz;
}

int main(){
    int niz[] = {1, 2, 3, 4, 5};
    int start = 2;
    int stop = 4;
    int* rezultat = podniz(niz,start,stop);
    printf("Novi niz od starta do stopa je : [ ");
    int i;
    for(i = 0; i < stop - start+1; i++){
        printf("%d ", rezultat[i]);
    }
    printf("]");
    free(rezultat);
    return 0;
}