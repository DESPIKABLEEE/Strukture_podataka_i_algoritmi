//prima string s 3 rijeci i vraca srednju, odvojene su razmacima
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* funkcija(char* string){
    int prvi_razmak = 0,drugi_razmak = 0;
    int i,j,k=0;
    char *temp = string;
    char* novi_str = NULL;
    while(*temp != '\0'){
        i++;
        temp++;
    }
    i++;
    for(j = 0; j < i; j++){
        if((prvi_razmak == 0) && (string[j] == ' ')){
            prvi_razmak = j;
        }
        else if((drugi_razmak == 0) && (string[j] == ' ')){
            drugi_razmak = j;
        }
    }
    novi_str = malloc(sizeof(char) * (drugi_razmak - prvi_razmak + 1));
    if(novi_str == NULL){
        printf("Greska");
        return NULL;
    }
    for(j = prvi_razmak + 1; j < drugi_razmak; j++){
        novi_str[k] = string[j];
        k++;
    }
    novi_str[k] = '\0';
    return novi_str;
}

int main(){
    char string[] = "Jucer danas sutra";
    char* rez = funkcija(string);
    printf("%s",rez);
    free(rez);
    return 0;
}