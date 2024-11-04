//mystrlen() funkcija prima string (char*) i vraća integer koji predstavlja dužinu stringa.
#include <stdio.h>
int mystrlen(char *string){
    int brojac=0;
    for (int i=0;string[i] != '\0';i++){
        brojac++;
    }
    return brojac;
}
int main(){
    char *string = "abcddd";
    int rezultat = mystrlen(string);
    printf("%d", rezultat);
    return 0;
}