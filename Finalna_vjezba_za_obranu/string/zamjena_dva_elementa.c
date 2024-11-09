//Funkcija za zamjenu dva elementa u nizu slova

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funkcija(char* ,int,int);

int main(){
    char string[] = "Dujkan";
    int start = 2;
    int stop = 4;
    funkcija(string,start,stop);
    printf("%s",string);
    return 0;
}
void funkcija(char* str, int start, int stop){
    char temp = str[start];
    str[start] = str[stop];
    str[stop] = temp;
    
}