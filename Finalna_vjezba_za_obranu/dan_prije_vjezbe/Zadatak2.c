// Zadatak 2: Dinamička alokacija memorije za niz struktura
// Definiši strukturu Knjiga koja sadrži naslov, autora i broj stranica.
// Definiši strukturu Biblioteka koja sadrži naziv biblioteke i pokazivač na niz knjiga.
// Dinamički alociraj memoriju za niz od 10 knjiga u strukturi Biblioteka.
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char naslov[20];
    char autor[20];
    int broj_stranica;
}Knjiga;

typedef struct{
    char naziv_biblioteke[20];
    Knjiga* niz_knjiga;
}Biblioteka;

Biblioteka* funkcija(int n){
    Biblioteka *p = NULL;
    p = malloc(sizeof(Biblioteka));
    if(p == NULL){
        printf("Greska");
        return NULL;
    }
    p->niz_knjiga = NULL;
    p->niz_knjiga = malloc(sizeof(Knjiga) * n);
    if(p->niz_knjiga == NULL){
        printf("Greska");
        return NULL;
    }
    return p;
}

int main(){
    int n = 10;
    Biblioteka* p = funkcija(n);
    free(p->niz_knjiga);
    free(p);
    return 0;
}