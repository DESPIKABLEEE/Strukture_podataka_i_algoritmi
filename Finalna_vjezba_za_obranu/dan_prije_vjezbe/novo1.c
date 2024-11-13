// 1. Izdvajanje riječi iz stringa
//     * Zadatak: Napiši funkciju koja prima string i vraća broj riječi u tom stringu. Riječ je definirana kao skup znakova odvojenih razmakom.
#include <stdio.h>
#include <stdlib.h>

//funkcija
    //nac broj razmaka

int funkcija(char* string){
    int i, brojac = 0;
    for(i = 0; string[i] != '\0';i++){
        if(string[i] == ' '){
            brojac++;
        }
    }
    return brojac + 1;    
}

int main(){
    char recenica[] = "Batongiranje je zakon";
    printf("%d",funkcija(recenica));
    return 0;
}