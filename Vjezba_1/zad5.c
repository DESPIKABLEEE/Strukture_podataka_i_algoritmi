//mystrstr() – funkcija vraća pokazivač (unutar prvog stringa) koji pokazuje na prvo pojavljivanje drugog stringa. Ako ga ne pronađe, funkcija vraća NULL.
#include <stdio.h>
char* mystrstr(char* haystack, char* needle){
    if (!*needle) return haystack;
    for(char* p = haystack; *p != '\0'; p++){
        char* p1 = p;
        char* p2 = needle;

        while( *p1 && *p2 && (*p1 == *p2)){
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
    char* str1 = "This is the way.";
    char* str2 = "the";
    char* rez = mystrstr(str1,str2);
    printf("%s",rez);
    return 0;
}
