//Napisati program koji od korisnika čita n struktura u niz i zatim ih sprema u binarnu datoteku. Prije samog niza se sprema broj n. Broj n se isto čita od korisnika prije čitanja struktura. Strukture su tipa Koordinata i sastoje se od dva float broja.
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    float x,y;
}KOORDINATA;

void funkcija(const char* file_name){
    FILE* file = fopen(file_name, "wb");
    if(file == NULL){
        printf("Greska");
        return;
    }

    int n;
    printf("Unesite broj n\n");
    scanf("%d",&n);

    printf("\nalociranje niza.. \n");
    KOORDINATA* niz_kordinata = malloc(sizeof(KOORDINATA) * n);
    if(niz_kordinata == NULL){
        printf("Greska s alociranjem niza");
        fclose(file);
        return;
    }

    printf("\nUnesite kordinate x i y (%d puta)",n);
    for(int i = 0; i < n; i++){
        printf("%d kordinata : ",i + 1);
        printf("\n x: ");
        scanf("%f",&niz_kordinata[i].x);
        printf("\n y: ");
        scanf("%f",&niz_kordinata[i].y);
    }
    fwrite(&n,sizeof(int),1,file);
    for(int j = 0; j < n; j++){
        fwrite(&niz_kordinata[j],sizeof(KOORDINATA),1,file);
    }

    printf("\nGOTOVO\n");
    fclose(file);
    free(niz_kordinata);
}


int main(){
    funkcija("Koordinate.bin");
    return 0;
}