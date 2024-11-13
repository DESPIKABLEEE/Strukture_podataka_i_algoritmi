// Vježba 2 - Operacije s nizovima brojeva
// 1. Spajanje nizova
// zadatak: Napiši funkciju koja prima tri niza brojeva: dva niza koja će se spojiti i treći prazan niz koji će funkcija popuniti s elementima iz prva dva niza, ali uklanjajući duple vrijednosti.
#include <stdio.h>
#include <stdlib.h>

int** funkcija(int* prvi_niz,int* drugi_niz,int* treci_niz, int prva_duljina,int druga_duljina, int* treca_duljina){
    //napravi veliki niz
    int** finalni_niz = malloc(sizeof(int*) * 2);
    // memorija za prva dva
        //spoji prva dva
    int* prva_dva_niza = malloc(sizeof(int) * (prva_duljina + druga_duljina));
    int i,j,pamti = 0;
    for(i = 0; i < prva_duljina; i++){
        prva_dva_niza[i] = prvi_niz[i];
        pamti++;
    }
    for(j = 0; j < druga_duljina; j++){
        prva_dva_niza[j + pamti] = drugi_niz[j];
    }
    finalni_niz[0] = prva_dva_niza;

    int* niz_bez_duplikata = malloc(sizeof(int) * (prva_duljina + druga_duljina));
    int k = 0, postoji, brojac = 0;
    for(i = 0; i < prva_duljina; i++){
        postoji = 0;
        for(j = 0; j < brojac; j++){
            if (prvi_niz[i] == niz_bez_duplikata[j]){
                postoji = 1;
                break;
            }
        }
        if(postoji == 0){
            niz_bez_duplikata[brojac] = prvi_niz[i];
            brojac++;
        }
    }
    for(i = 0; i < druga_duljina; i++){
        postoji = 0;
        for(j = 0; j < brojac; j++){
            if (drugi_niz[i] == niz_bez_duplikata[j]){
                postoji = 1;
                break;
            }
        }
        if(postoji == 0){
            niz_bez_duplikata[brojac] = drugi_niz[i];
            brojac++;
        }
    }
    niz_bez_duplikata = realloc(niz_bez_duplikata,sizeof(int) * brojac);
    finalni_niz[1] = niz_bez_duplikata;
    *treca_duljina = brojac;

    return finalni_niz;
}

int main(){
    int niz1[] = {1, 2, 3, 4, 5, 6, 1};
    int niz2[] = {5, 6, 7, 8, 5};
    int* niz3;
    int n1 = sizeof(niz1) / sizeof(niz1[0]);
    int n2 = sizeof(niz2) / sizeof(niz2[0]);
    int n3;
    int** rez = funkcija(niz1,niz2,niz3,n1,n2,&n3);
    int i,j;
    printf("Prvi niz je: ");
    for(i = 0; i < n1+n2; i++){
        printf("%d ",rez[0][i]);
    }
    printf("\nDrugi niz : ");
    for(j = 0; j < n3; j++){
        printf("%d ",rez[1][j]);
    }
    free(rez[1]);
    free(rez[0]);
    free(rez);
    return 0;
}