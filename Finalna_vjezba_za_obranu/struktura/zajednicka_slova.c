//Funkcija koja trazi ista slova u dvije strukture
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *string;
}Struktura;

void funkcija(Struktura* prva, Struktura* druga){
    int i,j,flag;
    for(i = 0; prva->string[i] != '\0'; i++){
        flag = 0;
        for(j = 0; druga->string[j] != '\0'; j++){
            if(prva->string[i] == druga->string[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            printf("%c",prva->string[i]);
        }
    }

}

int main(){
    Struktura prva = {"Lolcek"};
    Struktura druga = {"Bolcek"};
    funkcija(&prva,&druga);
    return 0;
}