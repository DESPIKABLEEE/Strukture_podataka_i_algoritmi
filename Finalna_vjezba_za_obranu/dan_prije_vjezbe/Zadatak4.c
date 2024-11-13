// Zadatak 4: Struktura sa pokazivačem na drugu strukturu
// Definiši strukturu Adresa koja sadrži ulicu, broj i grad.
// Definiši strukturu Osoba koja sadrži ime, prezime i pokazivač na strukturu Adresa.
// Inicijalizuj strukturu Osoba i popuni je sa odgovarajućom adresom.
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char ulica[20];
    int broj;
    char grad[10];
}Adresa;
typedef struct{
    char ime[20];
    char prezime[20];
    Adresa* pokazivac;
}Osoba;

void funkcija(){
    int i,j;
    Osoba* p = NULL;
    p = malloc(sizeof(Osoba));
    if (p == NULL){
        printf("Greska");
        return ;
    }
    p->pokazivac = NULL;
    p->pokazivac = malloc(sizeof(Adresa));
    if(p->pokazivac == NULL){
        printf("Greska");
        free(p);
        return ;
    }
    printf("Unesi ime osobe : ");
    scanf("%s",p->ime);
    printf("\nUnesi prezime osobe : ");
    scanf("%s",p->prezime);
    printf("\nUnesi adresu osobe : \n");
    printf("Ulica : ");
    scanf("%s",p->pokazivac->ulica);
    printf("\broj : ");
    scanf("%d",&p->pokazivac->broj);
    printf("\ngrad : ");
    scanf("%s",p->pokazivac->grad);

    printf("%s %s , %s %d %s",p->ime,p->prezime,p->pokazivac->ulica,p->pokazivac->broj,p->pokazivac->grad);

    free(p->pokazivac);
    free(p);
}

int main(){
    funkcija();
    return 0;
}