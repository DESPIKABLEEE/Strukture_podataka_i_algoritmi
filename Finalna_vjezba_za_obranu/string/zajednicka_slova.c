//Funkcija za pronalaĹženje zajedniÄkih slova iz dva stringa
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>

void funkcija(char* ,char*);

int main(){
    char* string1 = "Abeceda";
    char* string2 = "Abcf";
    funkcija(string1,string2);
    return 0;
}

void funkcija(char* str1, char* str2){
    
    for(char* p = str1; *p != '\0'; p++){
        for(char* c = str2; *c != '\0'; c++){
            if((*p) == (*c)){//tolower
                printf("%c",*p);
                break;
            }
        }
    }

}