//niz bez duplikata
#include <stdio.h>
#include <stdlib.h>

int* funkcija1(int* niz1, int* n1){
    int i,j,k;
    int postoji;
    int brojac = 0;
    int* novi_niz = malloc(sizeof(int) * (*n1));
    for(i = 0; i < *n1; i ++){
        postoji = 0;
        for(j = 0; j < brojac; j++){
            if(niz1[i] == novi_niz[j]){
                postoji = 1;
                break;
            }
        }
        if(!postoji){
            novi_niz[brojac] = niz1[i];
            brojac++;
        }
    }
    novi_niz = realloc(novi_niz,sizeof(int) * brojac);
    *n1 = brojac;
    return novi_niz;
}

void funkcija(int* niz, int* n){
    int i,j,k;
    int brojac = 0;
    int postoji;
    for(i = 0; i < *n; i++){
        postoji = 0;
        for(j = 0; j < brojac; j++){
            if(niz[i] == niz[j]){
                postoji = 1;
                break;
            }
        }
        if(!postoji){
            niz[brojac++] = niz[i];
        }
    }
    *n = brojac;
}

int main(){
    int niz[] = {1, 1, 2, 3, 4, 4, 5, 1};
    int niz1[] = {1, 1, 2, 3, 4, 4, 5, 1};
    int n = sizeof(niz) / sizeof(niz[0]);
    int n1 = sizeof(niz) / sizeof(niz[0]);
    printf("Void funkcija : ");
    funkcija(niz,&n);
    int i;
    for(i = 0; i < n; i++)
        printf("%d ",niz[i]);
    printf("\n");
    int* rez = funkcija1(niz1,&n1);
    printf("Int* funkcija : ");
    for(i = 0; i < n1; i++){
        printf("%d ",rez[i]);
    }
    free(rez);
    return 0;
}