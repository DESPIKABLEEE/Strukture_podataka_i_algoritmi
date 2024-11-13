// Npr
// iz stringa Duje Kralj
// ispisi samo D S
#include <stdio.h>
#include <stdlib.h>

char* funkcija(char* str){
    int i,j;
    int brojac = 0;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] != ' '){
            brojac++;
            break;
        }
    }
    for(j = i; str[j] != '\0'; j++){
        if((str[j] == ' ') && (str[j + 1] != ' ')){
            brojac++;
            break;
        }
    }
    char* novi_string = malloc(sizeof(char) * (brojac + 1));
    int k = 0;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] != ' '){
            novi_string[k] = str[i];
            k++;
            break;
        }
    }
    for(j = k; str[j] != '\0'; j++){
        if((str[j] == ' ') && (str[j + 1] != ' ')){
            novi_string[k] = str[j + 1];
            k++;
            break;
        }
    }
    novi_string[k] = '\0';
    return novi_string;

}

int main(){
    char string[] = "Dujkan batonga";
    char* rez = funkcija(string);
    printf("%s",rez);
    return 0;
}