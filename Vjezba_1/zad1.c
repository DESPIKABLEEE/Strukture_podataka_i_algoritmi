//mystrlen() – funkcija prima string (char*) i vraća integer koji predstavlja dužinu stringa.
#include <stdio.h>
int mystrlen(const char* str){
    int i=0;
    while(*str != '\0'){
        i++;
        str++;
    }
    return i;
}
int main(){
    const char* string = "Zebra";
    int rezultat = mystrlen(string);
    printf("duljina stringa je %d", rezultat);
    return 0;
}