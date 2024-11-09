//Funkcija za uklanjanje samoglasnika iz stringa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funkcija(char* str, char* provjeri){
    int i,j,postoji,duljina = 0;
    for(i = 0; str[i] != '\0'; i++){
        postoji = 0;
        for(j = 0; provjeri[j] != '\0'; j++){
            if(str[i] == provjeri[j]){
                postoji = 1;
                break;
            }
        }
        if(postoji == 0){
            str[duljina] = str[i];
            duljina++;
        }
    }
    str[duljina] = '\0';
}

int main(){
    char string[] = "abecedaABIO";
    char samoglasnici[] = "aeiouAEIOU";
    funkcija(string,samoglasnici);
    printf("%s",string);
    return 0;
}