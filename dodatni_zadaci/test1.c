//Napisati program koji od korisnika čita n brojeva u niz i zatim ih sprema u binarnu datoteku (sa fwrite). Prije samog niza se sprema broj n. Broj n se isto čita od korisnika prije čitanja samih brojeva niza.
#include <stdio.h>
#include <stdlib.h>
void spremanje_niza(const char* file_name){
    int n;
    printf("Unesite broj n ");
    scanf("%d",&n);

    int* niz = malloc(n * sizeof(int));
    if (niz == NULL){
        printf("Greska kod alociranja memorije");
        return;
    }

    for(int i = 0; i < n; i++){
        printf("\nUnesite %d clan niza\n", i + 1);
        scanf("%d",&niz[i]);
    }

    FILE* file = fopen(file_name, "wb");
    if(file == NULL){
        printf("Greska kod datoteke");
        return;
    }
    fwrite(&n,sizeof(int),1,file);
    for(int j = 0; j < n; j++){
        fwrite(&niz[j],sizeof(int),1,file);
    }
    fclose(file);
    free(niz);
    printf("\nGotovo\n");
}

int main(){
    spremanje_niza("/Users/gabrielmilunovic/Desktop/SPA moje vjezbe/dodatni_zadaci/niz_test.bin");
    return 0;
}