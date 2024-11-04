//Napisati program koji od korisnika čita dvije koordinate. Program u datoteku (iz zadatka 3) dodaje još jednu točku na kraj datoteke. Program zatim čita i ispisuje sve koordinate unazad. (otvorite datoteku za čitanje i pisanje)
#include "zad4.h"
#include <stdio.h>
#include <stdlib.h>
void funkcija(const char* file_name){
    // unos koordinata
    KOORDINATA k;
    printf("Unesite koordinate x:");
    scanf("%f",&k.x);
    printf("    y:");
    scanf("%f",&k.y);
    //dodavanje jos jedne tocke na kraj Koordinate.bin
    FILE* file = fopen(file_name, "r+b");
    if(file == NULL){
        printf("Greska");
        return;
    }

    int n;
    fread(&n,sizeof(int),1,file);
    fseek(file,sizeof(KOORDINATA),SEEK_END);
    fwrite(&k,sizeof(KOORDINATA),1,file);
    n++;
    fseek(file,sizeof(int),SEEK_SET);
    fwrite(&n,sizeof(int),1,file);
    
    KOORDINATA* niz_koordinata = malloc(sizeof(KOORDINATA) * n);
    if(niz_koordinata == NULL){
        printf("Greska");
        return;
    }
    fseek(file,sizeof(int),SEEK_SET);
    fread(niz_koordinata,sizeof(KOORDINATA),n,file);
    for(int i = n - 1; i >= 0; i--){
        printf("indeks %d ima tocke (%f,%f)",i + 1,niz_koordinata[i].x,niz_koordinata[i].y);
    }
    fclose(file);
    free(niz_koordinata);
    printf("\nGOTOVO\n");
}

int main(){
    funkcija("/Users/gabrielmilunovic/Desktop/SPA moje vjezbe/dodatni_zadaci/Koordinate.bin");
    return 0;
}