// 2. Podjela stringa u riječi
//     * Zadatak: Napiši funkciju koja prima string s više riječi i sprema svaku riječ u zaseban string unutar niza stringova. Na primjer, ako je ulazni string "obrana zadataka sutra", funkcija treba vratiti niz koji sadrži "obrana", "zadataka" i "sutra".
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** funkcija(char* string, int* n){
    while (*string == ' ') {
        string++;
    }
    // broj razmaka
    int i, brojac = 0,duljina = strlen(string);
    for(i = 0; string[i] != '\0';i++){
        if((string[i] == ' ') && (string[i + 1] != '\0')){
            brojac++;
        }
    }
    //broj rici
    brojac++;
    char** sve_rijeci = malloc(sizeof(char*) * brojac);

    //spremit mjesta razmaka u niz
    int niz[brojac];
    int f = 0;
    for(i = 0; string[i] != '\0'; i++){
        if(string[i] == ' '){
            niz[f] = i;
            f++;
        }
    }

    //punjenje sve_rijeci
    int j = 0,k;
    for(i = 0; i < brojac; i++){
        k = 0;
        sve_rijeci[i] = malloc(sizeof(char) * (niz[f]+1));
        f++;
        while((string[j] != ' ') && (string[j] != '\0')){
            sve_rijeci[i][k] = string[j];
            k++;
            j++;
        }
        sve_rijeci[i][k] = '\0';
        if(string[j] == ' '){
            j++;
        }
    }
    *n = brojac;
    return sve_rijeci;
}

int main(){
    char recenica[] = "    Ovo je bas jako puno rijeci";
    int n;
    char** rez = funkcija(recenica,&n);
    int i;
    printf("\n%d\n",n);
    for(i = 0; i < n; i++){
        printf("%s\n",rez[i]);
    }
    return 0;
}