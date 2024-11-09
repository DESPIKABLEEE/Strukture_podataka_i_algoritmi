//Funkcija za uklanjanje drugog slova iz stringa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funkcija(char* );

int main(){
    char string[] = "prvi";
    funkcija(string);
    printf("%s",string);
    return 0;
}

void funkcija(char* str){
    int i,j = 0;
    for(i = 1; str[i] != '\0'; i++){
        str[i] = str[i+1];
        j++;
    }
    str[j] = '\0';
}