#include <stdio.h>
char* funkcija(char* prvi, char* drugi){
    if (!*drugi){
        return (char*)prvi;
    }
    for (char* p = prvi;*p != '\0'; p++){
        char* p1 = p;
        char* p2 = drugi;
        while (*p1 && *p2 && (*p1 == *p2)){
            p1++;
            p2++;
        }
        if(!*p2){
            return (char*)p;
        }
    }
    return NULL;
}    
int main(){
    char* str1 = "Hello, world";
    char* str2 = "world";
    char* rezultat = funkcija(str1,str2);
    if (rezultat)
        printf("Podudaranje je %s", rezultat);
    else
        printf("Nema podudaranja");
    return 0;
}