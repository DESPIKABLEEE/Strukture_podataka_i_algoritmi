//Napisati program koji od korisnika čita n brojeva u niz i zatim ih sprema u binarnu datoteku (sa fwrite). Prije samog niza se sprema broj n. Broj n se isto čita od korisnika prije čitanja samih brojeva niza.
#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Unesite broj n\n");
    scanf("%d",&n);
    int* niz = malloc(sizeof(int) * n);
    if(niz == NULL){
        printf("Greska kod memorije");
        return 1;
    }
    for(int i = 0; i < n; i++){
        scanf("%d",&niz[i]);
    }
    FILE* file = fopen("niz.bin","wb");
    if(file == NULL){
        printf("Greska");
        free(niz);
        return 1;
    }
    fwrite(&n,sizeof(int),1,file);
    fwrite(niz,sizeof(int),n,file);
    fclose(file);
    free(niz);
    printf("\ngotovo\n");
    return 0;
}