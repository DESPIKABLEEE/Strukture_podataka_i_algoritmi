//Traženje svih brojeva koji se pojavljuju u oba niza brojeva
#include <stdio.h>
#include <stdlib.h>

int* isti_brojevi(int* niz1,int n1, int* niz2, int n2, int* n3){
    int i,j;
    int brojac = 0;
    int zajednicki;
    int *temp = malloc(sizeof(int) * (n1 + n2));
    for(i = 0; i < n1; i++){
        zajednicki = 0;
        for(j = 0; j < n2; j++){
            if(niz1[i] == niz2[j]){
                zajednicki = 1;
                break;
            }
        }
        if(zajednicki){
            for(int k = 0; k < brojac; k++){
                if(temp[k] == niz1[i]){
                    zajednicki = 0;
                    break;
                }
            }
            if(zajednicki){
                temp[brojac] = niz1[i];
                brojac++;
            }
        }
    }
    temp = realloc(temp,sizeof(int) * brojac);
    *n3 = brojac;
    return temp;
}

int main(){
    int niz1[] = {1, 2, 3, 4, 5, 5};
    int niz2[] = {7, 8, 2, 3, 6, 5}; //2 3 5
    int n1 = sizeof(niz1) / sizeof(niz1[0]);
    int n2 = sizeof(niz2) / sizeof(niz2[0]);
    int n3;
    int* rez = isti_brojevi(niz1,n1,niz2,n2,&n3);
    int i;
    for(i = 0; i < n3; i++){
        printf("%d ",rez[i]);
    }
    free(rez);
    return 0;
}