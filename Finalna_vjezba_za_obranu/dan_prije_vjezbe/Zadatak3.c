// Zadatak 3: Rad sa duplim pokazivačima
// Definiši strukturu Predmet koja sadrži naziv predmeta i broj ECTS bodova.
// Definiši strukturu Student koja sadrži ime, prezime i pokazivač na niz pokazivača na predmete.
// Dinamički alociraj memoriju za niz od 3 predmeta za jednog studenta.
#include <stdio.h>
#include <stdlib.h>
typedef struct{ 
    char naziv[20];
    int broj_ects;
}Predmet;
typedef struct{
    char ime[20];
    char prezime[20];
    Predmet** niz_predmeta;
}Student;
Student* funkcija(int n){
    int i,j, k = 0;
    Student *p = NULL;
    p = malloc(sizeof(Student));
    if(p == NULL){
        printf("Greska");
        return NULL;
    }
    p->niz_predmeta = NULL;
    p->niz_predmeta = malloc(sizeof(Predmet*) * n);
    if(p->niz_predmeta == NULL){
        printf("Greska");
        return NULL;
    }
    for(j = 0; j < n; j++){
        p->niz_predmeta[i] = malloc(sizeof(Predmet));
    }
    printf("Unesite ime studenta : ");
    scanf("%s",p->ime);
    printf("\nUnesite prezime studenta : ");
    scanf("%s",p->prezime);
    for(i = 0; i < n; i++){
        printf("\nUnesite ime predmeta : ");
        scanf("%s",p->niz_predmeta[i]->naziv);
        printf("\nUnesite broj ectsa predmeta : ");
        scanf("%d",&p->niz_predmeta[i]->broj_ects);
    }
    return p;
}

int main(){
    int n = 3;
    Student* p = funkcija(n);
    int i;
    printf("Ime i prezime studenta je : %s %s\n",p->ime,p->prezime);
    for(i = 0; i < n; i++){
        printf("%d predmet studenta je : %s i nosi %d bodova\n",i+1,p->niz_predmeta[i]->naziv,p->niz_predmeta[i]->broj_ects);
    }
    free(p->niz_predmeta);
    free(p);
    return 0;
}