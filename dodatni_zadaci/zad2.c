//Napisati program koji čita datoteku iz prethodnog zadatka (sa fread) i ispisuje brojeve na ekran.
#include <stdio.h>
#include <stdlib.h>
void funkcija(const char* file_name){
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Greska pri otvaranju datoteke\n");
        return;
    }
    int n;
    fread(&n,sizeof(int),1,file);
    int* niz = malloc(sizeof(int) * n);
    fread(niz,sizeof(int),n,file);
    int i;
    for(i = 0; i < n; i++){
        printf("%d ",niz[i]);
    }
    fclose(file);
    printf("\ngotovo\n");
    free(niz);
}

int main(){
    funkcija("/Users/gabrielmilunovic/Desktop/SPA moje vjezbe/dodatni_zadaci/niz.bin");

    return 0;
}