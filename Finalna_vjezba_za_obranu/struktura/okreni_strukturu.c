//Funkcija za okretanje strukture
#include <stdio.h>

typedef struct{
    int x,y;
}Struktura;

void funkcija(Struktura* prva){
    int temp = prva->x;
    prva->x = prva->y;
    prva->y = temp;

}

int main(){
    Struktura prva = {1,3};
    printf("Prva tocka je %d a druga je %d\n\n",prva.x,prva.y);
    funkcija(&prva);
    printf("Prva tocka je %d a druga je %d",prva.x,prva.y);
    return 0;
}