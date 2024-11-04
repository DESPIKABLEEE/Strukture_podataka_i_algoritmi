//mystrcmp() – funkcija prima dva stringa i uspoređuje ih. Funkcija vraća: broj manji od nula ako je prvi string manji od drugog stringa (po leksikografskom poretku), broj veći od nula ako je drugi string manji od prvog i nula ako su stringovi jednaki.
#include <stdio.h>
int mystrcmp(const char* str1, const char* str2){
    int i=0;
    while(*str1 != '\0' && *str2 != '\0'){
        if(*str1 < *str2){
            return -1;
        }
        else if(*str1 > *str2){
            return 1;
        }
        str1++;
        str2++;
    }
    return 0;
}

int main(){
    const char* str1 = "abcd";
    const char* str2 = "abcd";
    int rez = mystrcmp(str1,str2);
    printf("%d",rez);
    return 0;
}