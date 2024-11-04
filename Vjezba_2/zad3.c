//int** podijeli(int *niz, int n) – dijeli niz dužine n na dva jednaka dijela i stvara kopije prvog i drugog dijela. Funkcija vraća dva pokazivača koji pokazuju na prvi i na drugi dio.
#include <stdio.h> 
#include <stdlib.h>
int** podijeli(int *niz, int n){
    int duljina = n/2;
    int* prva_polovica = (int*) malloc(duljina * sizeof(int));
    int* druga_polovica = (int*) malloc((n - duljina) * sizeof(int));
    int i,j;
    for(i=0; i < duljina; i++){
        prva_polovica[i] = niz[i];
    }
    for(j=0; j < n - duljina; j++){
        druga_polovica[j] = niz[duljina + j];
    }
    int** spojeni = (int**) malloc(2 * sizeof(int*));
    spojeni[0] = prva_polovica;
    spojeni[1] = druga_polovica;
    return spojeni;
}

int main(){
    int niz[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(niz) / sizeof(niz[0]);
    int** rez = podijeli(niz,n);
    int i,j;
    printf("Prva polovica : [");
    for(i=0;i<n/2;i++){
        printf("%d ", rez[0][i]);
    }
    printf("]");
    printf("\n");
    printf("Druga polovica : [");
    for(j=0;j < n - n/2; j++){
        printf("%d ", rez[1][j]);
    }
    printf("]");
    
    return 0;
}