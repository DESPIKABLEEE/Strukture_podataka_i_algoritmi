//int* podniz(int *niz, int start, int stop) – vraća novi niz koji je kopija dijela niza od indeksa start do indeksa stop.
#include <stdio.h>
#include <stdlib.h>
int* podniz(int *niz, int start, int stop){
    int duljina = stop - start + 1;
    int i;
    int* novi_niz = (int*) malloc(duljina * sizeof(int));
    for(i=0;i<duljina;i++){
        novi_niz[i] = niz[i + start]; 
    }
    return novi_niz;
}

int main(){
    int niz[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int start = 4;
    int stop = 8;
    int *rez = podniz(niz,start,stop);
    int i;
    printf("Novi podniz od indeksa %d do indeksa %d je : [ ",start,stop);
    for(i=0;i<stop-start + 1;i++){
        printf("%d ", rez[i]);
    }
    printf("]");
    return 0;
}