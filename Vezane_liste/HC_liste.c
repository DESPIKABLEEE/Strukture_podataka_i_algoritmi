#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int data;
    struct _Node* link;
}Node;

//o    isprintaj_listu
void print_lst(Node* lst){
    lst = lst->link;
    while(lst != NULL){
        printf("%d -> ",lst->data);
        lst = lst->link;
    }
    printf("NULL\n");
    
}

//o    Na početak liste
Node* na_pocetak_liste(Node* lst, int broj){
    if(lst == NULL){
        Node* novi = malloc(sizeof(Node));
        novi->data = broj;
        novi->link = NULL;
        return novi;
    }
    Node* novi = malloc(sizeof(Node));
    novi->link = lst;
    novi->data = broj;
    
    return novi;
}
//o    Na kraj liste
Node* na_kraj_liste(Node* lst, int broj){
   
    Node* novi = malloc(sizeof(Node));
    novi->data = broj;
    novi->link = NULL;
    if(lst == NULL){
        printf("Lista je prazna, vracam novi\n");
        return novi;
    }
    Node* current = lst;
    while(current->link != NULL){
        current = current->link;
    }
    current->link = novi;
    return lst;
}

//o    Prije određenog elementa u listi
Node* prije_odredenog_elementa_u_listi(Node* lst, int broj, int prije_ovog){
    Node* novi = malloc(sizeof(Node));
    novi->data = broj;
    novi->link = NULL;
    if(lst == NULL){
        printf("Prazna lista, vracam novi\n");
        return novi;
    }
    Node* brojac = lst;
    int i = 0;
    while(brojac != NULL){
        i++;
        brojac = brojac->link;
    }
    if(i < prije_ovog){
        printf("Unesite manji indeks\n");
        exit(1);
    }
    i = 0;
    Node* current = lst;
    //Node* next = current->link;
    while(current->link != NULL){
        if(i == prije_ovog - 2){
            novi->link = current->link;
            current->link = novi;
        }
        i++;
        current = current->link;
    }
    
    return lst;
}

//o    Na određenom indeksu u listi
Node* na_odredeni_indeks_u_listi(Node* lst, int broj, int na_ovom_indeksu){
    Node* novi = malloc(sizeof(Node));
    novi->data = broj;
    novi->link = NULL;
    if(lst == NULL){
        printf("Lista je prazna, vracam novi\n");
        return novi;
    }
    Node* brojac = lst;
    int i = 0;
    while(brojac != NULL){
        i++;
        brojac = brojac->link;
    }
    if(i < na_ovom_indeksu){
        printf("Unesite manji indeks\n");
        exit(1);
    }
    i = 0;
    Node* current = lst;
    while(current->link != NULL){
        if(i == na_ovom_indeksu - 1){
            novi->link = current->link;
            current->link = novi;
        }
        i++;
        current = current->link;
    }
    
    return lst;
}

//o    Ukupan broj riječi
void ukupan_broj_nodova(Node* lst){
    int brojac = 0;
    if(lst == NULL){
        printf("Prazna lista");
        return;
    }
    while(lst != NULL){
        brojac++;
        lst = lst->link;
    }
    printf("\nBrojac je %d\n", brojac);
}
//o    Traženje najduže riječi
void trazenje_najduze_rijeci(Node* lst){
    int brojac = 0;
    if(lst == NULL){
        printf("Prazna lista");
        return;
    }
    while(lst != NULL){
        if(brojac < lst->data){
            brojac = lst->data;
        }
        lst = lst->link;
    }
    printf("\nNajveca je %d\n", brojac);
}

//o   Ukloni sa početka liste
Node* ukloni_s_pocetka_liste(Node* lst){
    if(lst == NULL){
        printf("Prazna lista");
        return NULL;
    }
    Node* tmp = lst;
    lst = lst->link;
    tmp->link = NULL;
//    free(tmp);
    return lst;
}
//o   Ukloni sa kraja liste
Node* ukloni_sa_kraja_liste(Node* lst){
    Node* current = lst;
    while(current->link->link != NULL){
        current = current->link;
    }
    current->link = NULL;
    return lst;
}
//o   Ukloni određenu broj
Node* ukloni_odredeni_node(Node* lst, int broj){
    if(lst == NULL){
        printf("Lista je prazna");
        return NULL;
    }
    Node* current = lst;
    while(current->link != NULL){
        if(current->link->data == broj){
            current->link = current->link->link;
            return lst;
        }
        current = current->link;
    }
    return lst;
}
// okreni listu ovo ne znam
Node* okreni_listu(Node* lst){
    Node* iduci = lst->link;
    Node* trenutni = lst;
    Node* prosli = NULL;
//    Node* prvi = trenutni;
    Node* tmp = NULL;
    if(lst == NULL || lst->link == NULL){
        printf("Lista ili je prazna ili se sastoji od jednog elementa");
        return lst;
    }
    while(iduci != NULL){
        tmp = iduci->link;
        prosli = trenutni;
        trenutni->link = prosli;
        
        iduci = iduci->link;
    }
    
    return prosli;
}

//  Uklanjanje više elemenata iz liste po nekom kriteriju (npr. zadnjih 10 elemenata ili sve elemente sa više od 10 znakova)
Node* ukloni_zadnjih_z_funkcija(Node* lst, int x){ // 2
    if(lst->link == NULL){
        printf("Lista je prazna");
        return lst;
    }
    Node* izbroji = lst->link;
    int brojac = 0;
    while(izbroji != NULL){
        brojac++;
        izbroji = izbroji->link;
    }
    if(x > brojac){
        printf("Unijeli ste prevelik broj");
        return lst;
    }
    Node* current = lst->link;
    int velicina = brojac - x;
    brojac = 0;
    while(current->link != NULL){
        if(brojac == velicina - 1){
            current->link = NULL;
            break;
        }
        brojac++;
        current = current->link;
    }
    
    return lst;
}
// ukloni sve koji imaju neki broj : nastavak od proslog zadatka
Node* ukloni_sve_koji_imaju_z_funkcija(Node* lst, int broj){
    if(lst->link == NULL){
        printf("Lista je prazna\n");
        return lst;
    }
//    int flag = 0;
    Node* current = lst->link;
    Node* prev = lst;
    int iduci;
    while(current->link != NULL){
        iduci = 0; // 0 = nepostoji, 1 = postoji
        if(current->data == broj){
            Node* nadi_iduci = current->link;
            while(nadi_iduci->link != NULL){
                if (nadi_iduci->data != broj){
                    iduci = 1;
                    break;
                }
                nadi_iduci = nadi_iduci->link;
            }
            if(iduci == 1){
                prev->link = nadi_iduci;
            } else {
                prev->link = NULL;
                return lst;
            }
            current = nadi_iduci;
        }
        current = current->link;
        prev = prev->link;
    }
    if(current->data){
        prev->link = NULL;
    }
    
    return lst;
}

// Dodavanje više elemenata u listu (npr. ispred svake riječi duže od 10 znakova)
Node* dodaj_ispred_z_funkcija(Node* lst, int dodaj, int broj){
    Node* current = lst->link;
    Node* prev = lst;
    while(current->link != NULL){
        if(current->data == broj){
            Node* novi = malloc(sizeof(Node));
            novi->data = dodaj;
            novi->link = current;
            prev->link = novi;
            prev = prev->link;
        }
        prev = prev->link;
        current = current->link;
    }
    if(current->data == broj){
        Node* novi = malloc(sizeof(Node));
        novi->data = dodaj;
        novi->link = current;
        prev->link = novi;
        prev = prev->link;
    }
    
    
    return lst;
}

//-  Zamjena dva elementa u listi (npr. prvi i zadnji)  !!!!!
Node* funkcija_za_zamjenu_dva_elementa(Node* lst, int prvi, int drugi) {
    if(lst->link == NULL || lst->link->link == NULL){
        printf("Lista je prazna ili ima jedan element");
        return lst;
    }
    if(prvi > drugi){
        int tmp = prvi;
        prvi = drugi;
        drugi = tmp;
    }
    
    Node* prvi_brojac = lst->link;
    Node* prvi_pamti = NULL;
    for(int i = 0; i < prvi; i++){
        prvi_pamti = prvi_brojac;
        prvi_brojac = prvi_brojac->link;
    }
    Node* drugi_brojac = lst->link;
    Node* drugi_pamti = NULL;
    for(int j = 0; j < drugi; j++){
        drugi_pamti = drugi_brojac;
        drugi_brojac = drugi_brojac->link;
    }
    
    //prvi korak
    Node* tmp = prvi_pamti->link;
    //drugi korak
    prvi_pamti->link = drugi_pamti->link;
    //treci korak
    drugi_pamti->link = tmp;
    //cetvrti korak
    tmp->link = prvi_pamti;
    //peti korak
    Node* nesto = lst->link;
    for(int k = 0; k < prvi - 1; k++){
        nesto->link = drugi_pamti;
        nesto->link = nesto->link;
    }
    

    return lst;
}
//- Prebacivanje dijela liste u novu listu po nekom kriteriju (npr. sve riječi duže od 10 znakova)
Node* nova_lista_prebacuj(Node* lst, int broj){
    Node* nova_lst = malloc(sizeof(Node));
    nova_lst->link = NULL;
    Node* current = lst;
    Node* nova_current = nova_lst;
    while(current->link != NULL){
        if(current->link->data == broj){
            nova_current->link = current->link;
            current->link = current->link->link;
            nova_current = nova_current->link;
            nova_current->link = NULL;
        } else {
            current = current->link;
        }
    }
    
    return nova_lst;
}

//-    Prebacivanje elementa u listi (npr. sa kraja na početak liste)
Node* prebaci_element_funkcija(Node* lst, int sa_mjesta, int na_mjesto){
    Node* prvi = lst->link;
    Node* tmp1 = NULL;
    int i;
    for(i = 0; i <= sa_mjesta; i++){
        tmp1 = prvi;
        prvi = prvi->link;
    }
    if(tmp1 == NULL){
        tmp1 = lst->link;
    }
    Node* drugi = lst->link;
    Node* tmp2 = NULL;
    for(i = 0; i <= na_mjesto; i++){
        tmp2 = drugi;
        drugi = drugi->link;
    }
    //prvi korak
    Node* tmp = tmp1->link;
    //drugi korak
    tmp1->link = tmp2->link;
    //treci korak
    tmp2->link = tmp1;
    //cetvrti korak
    lst->link = tmp;
    
    return lst;
}

//-    Kopiranje jednog ili više elemenata u novu listu
Node* nova_lista_kopiranje(Node* lst, int broj_elemenata){
    Node* nova_glava = lst;
    Node* prev = nova_glava;
    Node* current = lst->link;
    
    while(current->link != NULL && broj_elemenata != 0){
        broj_elemenata--;
        prev->link = current;
        prev = prev->link;
        current = current->link;
    }
    prev->link = NULL;
    
    return nova_glava;
}

//-    Kopiranje jednog ili više elemenata u niz
int* niz_funkcija(Node* lst, int broj_elemenata){
    int* novi_niz = NULL;
    novi_niz = malloc(sizeof(int) * broj_elemenata);
    Node* current = lst->link;
    int i = 0;
    while(current != NULL && broj_elemenata != 0){
        novi_niz[i] = current->data;
        i++;
        broj_elemenata--;
        current = current->link;
    }
    
    return novi_niz;
}

//-    Dodavanje elemenata iz niza u listu
Node* dodaj_iz_niza_u_listu(Node* lst, int* niz, int n, int broj_elemenata){
    Node* current = lst->link;
//    Node* prev = lst;
    while(current->link != NULL){
        current = current->link;
    }
    for(int i = 0; i < broj_elemenata && i < n; i++){
        Node* novi = malloc(sizeof(Node));
        novi->data = niz[i];
        novi->link = NULL;
        current->link = novi;
        current = current->link;
    }
    
    return lst;
}



int main8(){
    
    Node a, b, c, d, e;
    Node* pokazivac = malloc(sizeof(Node));
    pokazivac->link = &a; // pokazivac = &a;
    a.link = &b;
    b.link = &c;
    c.link = &d;
    d.link = &e;
    e.link = NULL;
    
    a.data = 2;
    b.data = 4;
    c.data = 8;
    d.data = 16;
    e.data = 32;
    
//    pokazivac = na_pocetak_liste(pokazivac, 0);
//    
//    pokazivac = na_kraj_liste(pokazivac, 64);
    
//    pokazivac = prije_odredenog_elementa_u_listi(pokazivac, 99, 4);
    
//    pokazivac = na_odredeni_indeks_u_listi(pokazivac, 99, 2);
    
//    pokazivac = ukloni_s_pocetka_liste(pokazivac);
    
//    pokazivac = ukloni_sa_kraja_liste(pokazivac);
    
//    pokazivac = ukloni_odredeni_node(pokazivac, 16);
    
//    pokazivac = ukloni_zadnjih_z_funkcija(pokazivac, 2);
    
//    pokazivac = ukloni_sve_koji_imaju_z_funkcija(pokazivac, 32);
    
//    pokazivac = dodaj_ispred_z_funkcija(pokazivac, 99, 16);
    
//    pokazivac = funkcija_za_zamjenu_dva_elementa(pokazivac, 2, 5);
    
//    pokazivac = nova_lista_prebacuj(pokazivac, 4);
    
//    pokazivac = prebaci_element_funkcija(pokazivac, 0, 2);
    
//    pokazivac = nova_lista_kopiranje(pokazivac, 3);
    
//    int* niz = niz_funkcija(pokazivac, 3);
//    for(int i = 0; i < 3; i++){
//        printf("%d ", niz[i]);
//    }
//    printf("\n\n");
    
    int niz[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(niz) / sizeof(niz[0]);
    pokazivac = dodaj_iz_niza_u_listu(pokazivac, niz, n, 3);
    
    
    
    print_lst(pokazivac);
//    trazenje_najduze_rijeci(pokazivac);
//    ukupan_broj_nodova(pokazivac);
    return 0;
}




//    Node* a = malloc(sizeof(Node));
//    Node* b = malloc(sizeof(Node));
//    Node* c = malloc(sizeof(Node));
//    Node* d = malloc(sizeof(Node));
//    Node* e = malloc(sizeof(Node));
//
//    // Povezujemo čvorove
//    a->link = b;
//    b->link = c;
//    c->link = d;
//    d->link = e;
//    e->link = NULL;
//
//    a->data = 2;
//    b->data = 4;
//    c->data = 8;
//    d->data = 16;
//    e->data = 32;
//
//    Node* pokazivac = a;
//
//    // Uklanjanje sa početka liste
//    pokazivac = ukloni_s_pocetka_liste(pokazivac);
//
//    print_lst(pokazivac);
//
//    // Oslobađanje preostale memorije
//    while (pokazivac != NULL) {
//        pokazivac = ukloni_s_pocetka_liste(pokazivac);
//    }
