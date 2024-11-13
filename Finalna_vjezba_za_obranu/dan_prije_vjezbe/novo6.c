// 1. Deklaracija i manipulacija strukturama
// Zadatak: Definiraj strukturu Tocka s članovima x i y (koji predstavljaju koordinate). Zatim napiši funkciju koja prima niz takvih točaka i vraća broj točaka kojima je x manji od y.
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y;
}Tocka;

int funkcija(Tocka* niz_tocaka, int n){
    int i,j;
    int brojac = 0;
    for(i = 0; i < n; i++){
        if(niz_tocaka[i].x > niz_tocaka[i].y){
            brojac++;
        }
    }
    return brojac;
}

int main(){
    Tocka niz[]={
        {1,4},
        {5,3},
        {6,3},
        {8,2},
        {2,4},
    };
    int n = sizeof(niz) / sizeof(niz[0]);
    printf("%d", funkcija(niz,n));
    return 0;
}