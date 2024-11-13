//Traženje svih brojeva koji se pojavljuju u oba niza brojeva
#include <stdio.h>
#include <stdlib.h>

int* funkcija(int* niz1,int* niz2,int n1, int n2, int* finalna_duljina){
    int i,j,k;
    int brojac_istih = 0;
    int zajednicki;
    int* novi_niz = malloc(sizeof(int) * (n1+n2));
    for(i = 0; i < n1;i++){
        zajednicki = 0;
        for(j = 0; j < n2; j++){
            if(niz1[i] == niz2[j]){
                zajednicki = 1;
                break;
            }
        }
        if(zajednicki){
            for(k = 0; k < brojac_istih;k++){
                if(novi_niz[k] == niz1[i]){
                    zajednicki = 0;
                    break;
                }
            }
            if(zajednicki){
                novi_niz[brojac_istih] = niz1[i];
                brojac_istih++;
            }
        }
    }
    int* novi_niz_finalni = realloc(novi_niz,sizeof(int) * brojac_istih);
    *finalna_duljina = brojac_istih;
    return novi_niz_finalni;
}

int main(){
    int prvi_niz[] = {1, 2, 3, 4, 5, 1};
    int drugi_niz[] = {1, 2, 3, 6, 7, 2, 1};
    int prva_duljina = sizeof(prvi_niz) / sizeof(prvi_niz[0]);
    int druga_duljina = sizeof(drugi_niz) / sizeof(drugi_niz[0]);
    int n3;
    int* rez = funkcija(prvi_niz,drugi_niz,prva_duljina,druga_duljina,&n3);
    int i;
    for(i = 0; i < n3; i++){
        printf("%d ",rez[i]);
    }
    free(rez);
    return 0;
}