//Funkcija za okretanje stringa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funkcija(char*);

int main(){
    char* str = "reverse";
    funkcija(str);
    return 0;
}

void funkcija(char* string){
    int duljina = strlen(string);
    int i;
    for(i = duljina; i >= 0; i--){
        printf("%c",string[i]);
    }
}