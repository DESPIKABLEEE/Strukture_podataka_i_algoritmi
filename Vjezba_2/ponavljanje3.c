//int** podijeli(int *niz, int n) – dijeli niz dužine n na dva jednaka dijela i stvara kopije prvog i drugog dijela. Funkcija vraća dva pokazivača koji pokazuju na prvi i na drugi dio.
#include <stdio.h>
#include <stdlib.h>
int** podijeli(int *niz, int n){
    int duljina = n / 2;
    int* prva_polovica = malloc(duljina * sizeof(int));
    int* druga_polovica = malloc((n - duljina) * sizeof(int));
    int i,j;
    for(i = 0; i < duljina; i++){
        prva_polovica[i] = niz[i];
    }
    for(j = 0; j < n - duljina; j++){
        druga_polovica[j] = niz[n - duljina + j];
    }
    int** novi_niz = malloc(2 * sizeof(int*));
    novi_niz[0] = prva_polovica;
    novi_niz[1] = druga_polovica;
    return novi_niz;
}

int main(){
    int niz[] = {1,2,3,4,5};
    int n = sizeof(niz) / sizeof(niz[0]);
    int** rezultat = podijeli(niz,n);
    printf("Prva polovica je : \n");
    int i;
    for(i = 0; i < n/2;i++){
        printf("%d ",rezultat[0][i]);
    }
    printf("\n");
    printf("Druga polovica niza je\n");
    for(i = 0; i < n - n/2;i++){
        printf("%d ",rezultat[1][i]);
    }
    free(rezultat[0]);
    free(rezultat[1]);
    free(rezultat);
    return 0;
}