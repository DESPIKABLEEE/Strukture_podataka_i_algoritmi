//Funkcija za brojanje toÄaka u kojima je x manji od y
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y;
}Tocka;

void funkcija(Tocka *niz,int n){
    int i,j, brojac = 0;
    for(i = 0; i < n; i++){
        if(niz[i].x > niz[i].y)
            brojac++;
    }
    printf("%d",brojac);
}

int main(){
    Tocka niz[] = {
        {1,3},
        {4,2},
        {6,2},
        {5,9}
    };
    int duljina = 4;
    funkcija(niz,duljina);
    return 0;
}