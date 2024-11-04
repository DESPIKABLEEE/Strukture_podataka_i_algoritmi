//mystrcpy() – funkcija prima dva stringa i kopira drugi string u prvi string.
#include <stdio.h>
char* mystrcpy(char *string1,const char* string2){
    int i=0;
    while(*string2 != '\0'){
        string1[i] = *string2;
        i++;
        string2++;
    }
    string1[i] = '\0';
    return string1;
}

int main(){
    char* string1[20];
    const char* string2 = "Kopirani";
    char* rez = mystrcpy(string1,string2);
    printf("%s",rez);
    return 0;

}