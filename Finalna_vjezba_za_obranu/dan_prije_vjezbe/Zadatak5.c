// Zadatak 5: Struktura sa nizom pokazivača na strukture
// Definiši strukturu Igrac koja sadrži ime, prezime i broj dresa.
// Definiši strukturu Tim koja sadrži naziv tima i niz pokazivača na strukture Igrac.
// Dinamički alociraj memoriju za niz od 11 igrača u strukturi Tim.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char ime[20];
    char prezime[20];
    int broj_dresa;
}Igrac;
typedef struct{
    char naziv[10];
    Igrac** niz_igraca;
}Tim;

void funkcija(){
    Tim* t = NULL;
    t = malloc(sizeof(Tim));
    if(t == NULL){
        printf("Greska");
        return;
    }
    t->niz_igraca = NULL;
    t->niz_igraca = malloc(sizeof(Igrac*) * 11);
    if(t->niz_igraca == NULL){
        free(t);
        printf("Greska");
        return;
    }
    for(int i = 0; i < 11; i++){
        t->niz_igraca[i] = malloc(sizeof(Igrac));
    }
    strcpy(t->naziv,"Batonge");
    t->niz_igraca = {
        {},{},{},{},{},{},{},{},{},{},{}
    };
    for(int j = 0; j < 11; j++){
        printf("Igrac %d je %s %s i ima broj dresa %d",j+1,t->niz_igraca[j]->ime,t->niz_igraca[j]->prezime,t->niz_igraca[j]->broj_dresa);
    }
    for(int k = 0; k < 11; k++){
        free(t->niz_igraca[k]);
    }
    free(t->niz_igraca);
    free(t);
}

int main(){
    funkcija();
    return 0;
}