//mystrcat() – funkcija „dodaje“ drugi string na kraj prvog stringa.
#include <stdio.h>
char* mystrcat(char* str1,char* str2){
    char* i=str1;
    while(*str1 != '\0'){
        str1++;
    }
    while(*str2 != '\0'){
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1='\0';
    return i;
}
int main(){
    char str1[20] = "Lol";
    char* str2 = "cek";
    char* rez = mystrcat(str1,str2);
    printf("Spojeni string je %s",rez);
    return 0;
}


