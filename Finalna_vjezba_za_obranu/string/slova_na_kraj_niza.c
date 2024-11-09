//Dodajemo slova na kraj stringa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funkcija(char*, char);

int main(){
    char string[] = "Hello worl";
    char novi_znak = 'd';
    funkcija(string,novi_znak);
    printf("%s",string);
    return 0;
}

void funkcija(char* string, char znak){
    int i,j = 0;
    for(i = 0; string[i] != '\0'; i++){
        j++;
    }
    string[j] = znak;
    string[j + 1] = '\0';
}