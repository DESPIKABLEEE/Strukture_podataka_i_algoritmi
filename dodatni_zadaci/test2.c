//Napisati program koji čita datoteku iz prethodnog zadatka (sa fread) i ispisuje brojeve na ekran.
#include <stdio.h>
#include <stdlib.h>
void citanje_niza(const char* file_name){
    int n,i,j;
    FILE* file = fopen(file_name, "rb");
    if(file == NULL){
        printf("Greska kod otvaranja datoteke");
        return;
    }

    fread(&n,sizeof(int),1,file);
    int* niz = malloc(n * sizeof(int));
    if(niz == NULL){
        printf("Greska pri alociranju memorije");
        return;
    }
    for(i = 0; i < n; i++){
        fread(&niz[i],sizeof(int),1,file);
    }
    printf("\nClanovi niza su : \n");
    for(j = 0; j < n; j++)
        printf("%d ", niz[j]);
    fclose(file);
    free(niz);
    printf("\nGotovo\n");
}
int main(){
    citanje_niza("/Users/gabrielmilunovic/Desktop/SPA moje vjezbe/dodatni_zadaci/niz_test.bin");
    return 0;
}