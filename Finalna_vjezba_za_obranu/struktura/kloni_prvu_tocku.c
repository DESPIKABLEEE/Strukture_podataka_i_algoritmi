//Funkcija za uklanjanje prve toÄke iz niza toÄaka u strukturi
#include <stdio.h>

typedef struct{
    int x,y;
}Tocka;

void funkcija(Tocka* niz,int* n){
    int i,j;
    for(i = 0; i < *n; i++){
        niz[i].x = niz[i + 1].x;
        niz[i].y = niz[i + 1].y;
    }
    (*n)--;
}

int main(){
    Tocka niz[] = {
        {1,3},
        {4,4},
        {5,5}
    };
    int duljina = 3;
    funkcija(niz,&duljina);
    int i;
    for( i = 0; i < duljina; i++){
        printf("Tocka %d ima koordinate %d i %d\n", i+1,niz[i].x,niz[i].y);
    }
    return 0;
}