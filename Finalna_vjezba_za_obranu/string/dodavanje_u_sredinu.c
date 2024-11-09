//Funkcija za dodavanje slova u sredinu stringa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funkcija(char*, char);

int main(){
    char string[] = "hao";
    char znak = 'z';
    funkcija(string,znak);
    printf("%s",string);
    return 0;
}

void funkcija(char* str,char znak){
    int duljina = strlen(str);
    int sredina = duljina / 2;
    int i,j = duljina + 1;
    for(i = duljina; i > sredina; i--){
        str[i] = str[i - 1];
    }
    str[sredina] = znak;
    str[j] = '\0';
}