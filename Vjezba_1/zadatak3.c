//mystrcmp() – funkcija prima dva stringa i uspoređuje ih. Funkcija vraća: broj manji od nula ako je prvi string manji od drugog stringa (po leksikografskom poretku), broj veći od nula ako je drugi string manji od prvog i nula ako su stringovi jednaki.
#include <stdio.h>
#include <string.h>
int mystrcmp(char *str1, char* str2){
    int i;
    for(i=0;str1[i] != '\0' || str2[i] != '\0'; i++){
        if (str1[i] < str2[i]){
            return -1;
        }
        else if (str1[i] > str2[i]){
            return 1;
        }
    }
    return 0;
}
int main(){
    char* str1 = "abde";
    char* str2 = "abde";
    int rezultat = mystrcmp(str1,str2);
    printf("%d", rezultat);
    return 0;
}