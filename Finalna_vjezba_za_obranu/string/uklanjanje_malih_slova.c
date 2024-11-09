//Funkcija za uklanjanje malih slova iz stringa
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void funkcija(char*);

int main(){
    char string[] = "AaBbCcDdAa";
    funkcija(string);
    printf("%s",string);
    return 0;
}

void funkcija(char* str){
    int i,j;
    int nova_duljina = 0;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[nova_duljina] = str[i];
            nova_duljina++;
        }
    }
    str[nova_duljina] = '\0';
}