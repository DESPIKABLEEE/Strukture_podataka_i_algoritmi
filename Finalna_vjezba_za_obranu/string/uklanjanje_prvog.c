//Funkcija za uklanjanje prvog znaka iz stringa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funkcija(char*);

int main(){
    char string[] = "prvi";
    funkcija(string);
    printf("%s",string);
    return 0;
}

void funkcija(char* str){
    int i,brojac = 0;
    for(i = 0; str[i] != '\0'; i++){
        str[i] = str[i + 1];
        brojac++;
    }
    str[brojac] = '\0';
}