//reverse() – prima dva stringa i kopira prvi string u drugi string naopako (funkcija ne postoji u string.h)
#include <stdio.h>
int duljina(const char* string){
    int i,brojac=0;
    for(i=0;string[i]!='\0';i++){
        brojac++;
    }
    return brojac;
}

char* funkcija(char* prvi,const char* drugi){
    if(!*drugi) return prvi;        //(char*)
    int i;
    int duzina = duljina(drugi);
    for(i=0; i < duzina != '\0'; i++){
        prvi[i] = drugi[duzina - 1 - i];
    }
    prvi[duzina] = '\0';
    return prvi;
}

int main(){
    char str1[20];
    const char* str2 = "Slovenija";
    // int rez = duljina(str1);
    // printf("%d", rez);
    char* rez = funkcija(str1,str2);
    printf("%s",rez);
    return 0;
}