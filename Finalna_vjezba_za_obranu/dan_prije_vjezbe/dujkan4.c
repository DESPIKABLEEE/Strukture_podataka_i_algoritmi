// zamjeni rijeci
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funkcija(char* str){
    int i,j,k;
    int razmak;
    int brojac = 0;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
            razmak = i; //4
            break;
        }
    }
    //prva u neki niz
    char* temp = malloc(sizeof(char) * (razmak + 1));
    for(i = 0; str[i] != ' '; i++){
        temp[i] = str[i];
    }
    temp[razmak] = '\0';

    //druga rijec na pocetak
    int kopirano = 0;
    for(i = razmak + 1; str[i] != '\0'; i++){
        str[kopirano++] = str[i];
    }
    str[kopirano] = ' ';
    k = 0;
    for(j = kopirano + 1; temp[k] != '\0'; j++){
        str[j] = temp[k++];
    }
    str[j] = '\0';

    free(temp);
}

int main(){
    char string[] = "Pero Peric"; // Peric Pero
    funkcija(string);
    printf("%s\n",string);
    return 0;
}