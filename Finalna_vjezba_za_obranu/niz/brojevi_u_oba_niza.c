//Funkcija koja trazi sve brojeve koji se pojavljuju u oba niza
#include <stdio.h>
#include <stdlib.h>

int* funkcija(int* niz1,int* niz2,int n1, int n2,int* n3){
    int brojac = 0,postoji,z,i,j;
    int* novi_niz = NULL;
    int* temp_niz = NULL;
    temp_niz = malloc(sizeof(int) * n1);
    if(temp_niz == NULL){
        printf("Greska");
        return NULL;
    }
    //{1, 2, 3, 4, 5, 6, 1};
    //{4, 5, 6, 7, 8, 9, 1, 2 , 1, 4};
    for(i = 0; i < n1; i++){
        for(j = 0; j < n2; j++){
            if(niz1[i] == niz2[j]){
                postoji = 0;
                for(z = 0; z < brojac; z++){
                    if(temp_niz[z] == niz1[i]){
                        postoji = 1;
                        break;
                    }
                }
                if(postoji == 0){
                    temp_niz[brojac] = niz1[i];
                    brojac++;
                }
            }
        }
    }
    novi_niz = malloc(sizeof(int) * brojac);
    if(novi_niz == NULL){
        printf("Greska");
        return NULL;
    }
    for(i = 0; i < brojac; i++){
        novi_niz[i] = temp_niz[i];
    }
    free(temp_niz);
    *n3 = brojac;
    return novi_niz;
}

int main(){
    int niz1[] = {1, 2, 3, 4, 5, 6, 1};
    int niz2[] = {4, 5, 6, 7, 8, 9, 1, 2 , 1, 4};
    int n1 = sizeof(niz1) / sizeof(niz1[0]);
    int n2 = sizeof(niz2) / sizeof(niz2[0]);
    int n3;
    int* rez = funkcija(niz1,niz2,n1,n2, &n3);
    int i;
    for(i = 0; i < n3; i++){
        printf("%d ",rez[i]);
    }
    free(rez);
    return 0;
}
