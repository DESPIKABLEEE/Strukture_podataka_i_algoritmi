//Napisati program koji od korisnika čita jedan broj odnosno indeks. Program iz datoteke iz prethodnog zadatka čita i ispisuje na ekran koordinatu koja odgovara tom indeksu. (koristite fseek)
#include <stdio.h>
#include <stdlib.h>
#include "test.h"
void ispisivanje_n_koordinate(const char* file_name){
    int i,j,indeks,n;
    printf("Unesi indeks : ");
    scanf("%d", &indeks);
    FILE* file = fopen(file_name,"rb");
    if(file == NULL){
        printf("Greska");
        return;
    }
    fread(&n,sizeof(int),1,file);
    TOCKE p;
    fseek(file,sizeof(TOCKE) * indeks + sizeof(int),SEEK_SET);
    fread(&p,sizeof(TOCKE),1,file);
    printf("Dvije tocke na %d indeksu su (%f,%f)",indeks,p.x,p.y);
    fclose(file);
    printf("\nGotovo\n");
}
int main(){
    ispisivanje_n_koordinate("/Users/gabrielmilunovic/Desktop/SPA moje vjezbe/dodatni_zadaci/test_koordinate.bin");
    return 0;
}