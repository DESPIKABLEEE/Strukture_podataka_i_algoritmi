//Funkcija za kopiranje brojeva veÄih od 5 iz dva stringa u novi string 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* funkcija(char* , char* );

int main(){
    char* string1 = "1526";
    char* string2 = "3748";
    char* rez = funkcija(string1,string2);
    printf("%s",rez);
    free(rez);
    return 0;
}

char* funkcija(char* str1, char* str2){
    int brojac = 0, broj = 0,k = 0;
    char* novi_niz = NULL;
    for(char *p = str1; *p != '\0'; p++){
        broj = *p - '0';
        if(broj > 5){
            brojac++;
        }
    }
    for(char *f = str2; *f != '\0'; f++){
        broj = *f - '0';
        if(broj > 5){
            brojac++;
        }
    }
    novi_niz = malloc(sizeof(char) * (brojac + 1));
    if(novi_niz == NULL){
        printf("Greska");
        return NULL;
    }
    for(char *p = str1; *p != '\0'; p++){
        broj = *p - '0';
        if(broj > 5){
            novi_niz[k++] = *p;
        }
    }
    for(char *f = str2; *f != '\0'; f++){
        broj = *f - '0';
        if(broj > 5){
            novi_niz[k++] = *f;
        }
    }
    novi_niz[k] = '\0';
    return novi_niz;
}
