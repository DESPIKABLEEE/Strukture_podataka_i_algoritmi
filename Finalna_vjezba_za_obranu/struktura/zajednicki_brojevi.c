//Funkcija za pronalaĹženje zajedniÄkih brojeva iz dvije strukture
#include <string.h>
#include <stdio.h>

typedef struct{
    int *niz;
    int duljina;
}Struktura;

void funkcija(Struktura* prva, Struktura* druga){
    int i,j,flag;
    for(i = 0; i < prva->duljina; i++){
        flag = 0;
        for(j = 0; j < druga->duljina; j++){
            if(prva->niz[i] == druga->niz[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            printf("%d",prva->niz[i]);
        }
    }
}

int main(){
    // Struktura prva,druga;
    int niz_prva[] = {1,2,3,4,5};
    int niz_druga[] = {3,4,5,6,7,8,9};
    Struktura prva = { niz_prva, 5 };
    Struktura druga = { niz_druga, 7 };
    funkcija(&prva,&druga);
    return 0;
}