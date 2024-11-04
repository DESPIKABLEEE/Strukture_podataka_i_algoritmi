//mystrcpy() – funkcija prima dva stringa i kopira drugi string u prvi string.
#include <stdio.h>
char* mystrcpy(char* str1, char* str2){
    int i;
    for(i=0;str1[i] != '\0';i++){
        str2[i] = str1[i];
    }
    str2[i] = '\0';
    return str2;
}
int main(){
    char *str1 = "Toni";
    char str2[10];
    mystrcpy(str1,str2);
    printf("Kopirani string je %s\n",str2);
    return 0;
}