//Napisati program koji od korisnika čita jedan broj odnosno indeks. Program iz datoteke iz prethodnog zadatka čita i ispisuje na ekran koordinatu koja odgovara tom indeksu. (koristite fseek)
#include <stdio.h>
#include <stdlib.h>
#include "zad4.h"
void funkcija(const char* file_name){
    FILE* file = fopen(file_name, "rb");
    if(file == NULL){
        printf("Greska");
        return;
    }

    int indeks;
    printf("Unesite neki broj [indeks]:");
    scanf("%d",&indeks);
    fseek(file,sizeof(KOORDINATA) * indeks + sizeof(float),SEEK_SET);
    KOORDINATA k;
    fread(&k,sizeof(KOORDINATA),1,file);
    printf("Na indeksu %d, nalaze se tocke %f i %f",indeks, k.x, k.y);
    printf("\nGotovo\n");
    fclose(file);
}
int main(){
    funkcija("/Users/gabrielmilunovic/Desktop/SPA moje vjezbe/dodatni_zadaci/Koordinate.bin");
    return 0;
}