//mystrcat() – funkcija „dodaje“ drugi string na kraj prvog stringa
#include <stdio.h>
#include <string.h>
char* mystrcat(char* prvi,char* drugi){
    char* pokazivac = prvi + strlen(prvi);

    while(*drugi != '\0'){
        *pokazivac++ = *drugi++;
    }
    *pokazivac = '\0';
    return prvi;
}
int main(){
    char str1[20] = "Toni";
    char* str2 = "Montana";
    mystrcat(str1,str2);
    printf("%s",str1);
    return 0;
}