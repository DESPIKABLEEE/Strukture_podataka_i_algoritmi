// Korisnik unosi string, i ako string ima paran broj rijeci
// parne su ispisane naopako
// ako kma neparan
// neparne neopako
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funkcija(char* str){
    int duljina = strlen(str);
    // izbroji rijeci
    int i,j,brojac = 0;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
            brojac++;
        }
    }
    brojac++;

    if(brojac % 2 == 0){
        int prvi_razmak = 0,drugi_razmak = 0,treci_razmak = 0;
        char tmp;
        for(i = 0; str[i] != '\0'; i++){
            if(str[i] == ' ' && prvi_razmak == 0){
                prvi_razmak = i + 1;
            } else if(str[i] == ' ' && drugi_razmak == 0){
                drugi_razmak = i - 1;
            } else if(str[i] == ' ' && treci_razmak == 0){
                treci_razmak = i + 1;
            }
        }
        for(i = prvi_razmak,j = drugi_razmak; i < ((drugi_razmak + prvi_razmak) / 2 + 1);i++,j--){
            tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
        }
        for(i = treci_razmak, j = duljina - 1; i < ((duljina + treci_razmak) / 2 + 1);i++,j--){
            tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
        }

    }

}

int main(){
    char niz[] ="Duje Spajic je kralj";
    funkcija(niz);
    printf("%s",niz);
    return 0;
}