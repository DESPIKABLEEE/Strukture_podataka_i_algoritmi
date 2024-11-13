//Zadatak 1: Kreiranje i inicijalizacija strukture sa nizom struktura
// Definiši strukturu Student koja sadrži ime, prezime i broj indeksa.
// Definiši strukturu Grupa koja sadrži naziv grupe i niz od 5 studenata.
// Inicijalizuj strukturu Grupa i popuni je sa 5 studenata.
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char ime[20];
    char prezime[20];
    int broj_indeksa;
}Student;
typedef struct{
    Student *studenti;
    char naziv[10];
}Grupa;

Grupa* funkcija(int n){
    int i,j,k = 0;
    Grupa* p = NULL;
    p = malloc(sizeof(Grupa));
    if(p == NULL){
        printf("Greska");
        return NULL;
    }
    p->studenti = NULL;
    p->studenti = malloc(sizeof(Student) * n);
    if(p->studenti == NULL){
        printf("Greska");
        return NULL;
    }
    printf("Unesite naziv grupe : ");
    scanf("%s",p->naziv);
    for(i = 0; i < n; i++){
        printf("\nUnesite ime studenta : ");
        scanf("%s",p->studenti[i].ime);
        printf("\nUnesite prezime studenta : ");
        scanf("%s",p->studenti[i].prezime);
        printf("\nUnesite broj indeksa : ");
        scanf("%d",&p->studenti[i].broj_indeksa);
    }
    return p;
}

int main(){
    int n = 5;
    Grupa* p = funkcija(n);
    int i;
    printf("Naziv grupe je %s\n",p->naziv);
    for(i = 0; i < n; i++){
        printf("%d. student je : %s %s i broj indeksa je : %d\n",i+1,p->studenti[i].ime,p->studenti[i].prezime,p->studenti[i].broj_indeksa);
    }
    printf("\nOslobadanje memorije\n");
    free(p->studenti);
    free(p);
    return 0;
}