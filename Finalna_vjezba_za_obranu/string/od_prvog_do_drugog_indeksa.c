//Funkcija prima dva niza i vraca novi do prvog indeksa i od drugog 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* funkcija(char*,char*,int,int);

int main(){
    char* prvi_string = "Obama"; //ob
    char* drugi_string = "Trump"; //mp
    char* rez = funkcija(prvi_string,drugi_string,1,2);
    printf("%s",rez);
    free(rez);
    return 0;
}

char* funkcija(char* str1, char* str2,int prvi_indeks,int drugi_indeks){ 
    int duzina1 = strlen(str1);
    int duzina2 = strlen(str2);
    int k = 0;
    char* skupa = NULL;
    skupa = malloc(sizeof(char) * ((prvi_indeks + 1) + (drugi_indeks + 1) + 1));
    if(skupa == NULL){
        printf("Greska");
        return NULL;
    }
    for(int i = 0; i < prvi_indeks + 1; i++){
        skupa[k] = *str1;
        str1++;
        k++;
    }
    for(int j = drugi_indeks + 1; j < duzina2; j++){
        skupa[k] = str2[j];
        k++;
    }
    skupa[k] = '\0';
    return skupa;
}