//int** podijeli(int *niz, int n) – dijeli niz dužine n na dva jednaka dijela i stvara kopije prvog i drugog dijela. Funkcija vraća dva pokazivača koji pokazuju na prvi i na drugi dio.
#include <stdio.h>
#include <stdlib.h>
int** podijeli(int *niz, int n){
    int mid = n / 2;
    int* prva_polovica = (int*) malloc(mid * sizeof(int));
    int* druga_polovica = (int*) malloc((n-mid) * sizeof(int));

    int i;
    for(i = 0; i < mid; i++){
        prva_polovica[i] = niz[i];
    }

    for(i = mid; i < n; i++){
        druga_polovica[i-mid] = niz[i]; 
    }
    int** rezultat = (int**) malloc(2 * sizeof(int*));
    rezultat[0] = prva_polovica;
    rezultat[1] = druga_polovica;

    return rezultat;
}

int main(){
    int niz[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(niz) / sizeof(niz[0]);
    int** polovice = podijeli(niz,n);
    printf("Prva polovica je : [ ");
    int i=0;
    for(i=0; i < n/2; i++)
        printf("%d, ", polovice[0][i]);
    printf(" ]\n");
    printf("Druga polovica je : [ ");
    for(i=0; i <  n - n/2; i++)
        printf("%d, ", polovice[1][i]);
    printf(" ]\n");
    free(polovice[0]);
    free(polovice[1]);
    free(polovice);
    return 0;
}
