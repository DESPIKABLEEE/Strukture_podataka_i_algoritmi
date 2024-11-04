////Napisati program koji od korisnika čita dvije koordinate. Program u datoteku (iz zadatka 3) dodaje još jednu točku na kraj datoteke. Program zatim čita i ispisuje sve koordinate unazad. (otvorite datoteku za čitanje i pisanje)
#include <stdio.h>
#include <stdlib.h>
#include "test.h"
void ispisivanje_koordinata_unazad(const char* file_name){
    TOCKE p;
    // printf("Unesite dvije koordinate  ");
    // printf("x:");
    // scanf("%f",&p.x);
    // printf("y:");
    // scanf("%f",&p.y);

    FILE* file = fopen(file_name, "r+b");
    if(file == NULL){
        printf("Greska");
        return;
    }

    int n;
    fread(&n,sizeof(int),1,file);
    n++;
    fseek(file,0,SEEK_SET);
    fwrite(&n,sizeof(int),1,file);
    fseek(file,0,SEEK_END);
    // fwrite(&p,sizeof(TOCKE),1,file);
    fseek(file,sizeof(int),SEEK_SET);

    TOCKE* niz_tocaka = malloc(n * sizeof(TOCKE));
    if(niz_tocaka == NULL){
        printf("Greska");
        return;
    }
    int i,j;
    
    fread(niz_tocaka,sizeof(TOCKE),n,file);

    printf("\nKoordinate unazad\n");
    for(j = n - 1; j >= 0; j--){
        printf("Na indeksu %d imamo tocke (%f,%f)\n",j, niz_tocaka[j].x,niz_tocaka[j].y);
    }

    fclose(file);
    free(niz_tocaka);
    printf("\nGOTOVO\n");

}
int main(){
    ispisivanje_koordinata_unazad("/Users/gabrielmilunovic/Desktop/SPA moje vjezbe/dodatni_zadaci/test_koordinate.bin");
    return 0;
}