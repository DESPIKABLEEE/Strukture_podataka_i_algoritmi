//Funkcija za uklanjanje istih slova iz stringa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funkcija(char* );

int main(){
    char string[] = "aabbccdda";
    funkcija(string);
    printf("%s",string);
    return 0;
}

void funkcija(char* str){
    int i,j,brojac = 0;
    int nova_duljina = 1;
    for(i = 1; str[i] != '\0'; i++){
        brojac = 0;
        for(j = 0; j < nova_duljina; j++){
            if(str[i] == str[j]){
                brojac = 1;
                break;
            }
        }
        if(brojac == 0){
            str[nova_duljina] = str[i];
            nova_duljina++;
        }
    }
    str[nova_duljina] = '\0';
}