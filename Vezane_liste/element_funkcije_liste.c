#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _Element{
    char* str;
    struct _Element* link;
}Element;

void _print(Element* lst){
    int i = 0;
    while(lst != NULL){
        printf("Na %d mjestu je rijec : %s\n", i + 1, lst->str);
        i++;
        lst = lst->link;
    }
}

//o    Traženje najduže riječi
//char* _nadi_najduzu_ric(Element* lst){
//    int velicina = 0;
//    char* najdulji;
//    Element* current = lst;
//    velicina = strlen(current->str) + 1;
//    najdulji = malloc(sizeof(char) * (velicina));
//    strcpy(najdulji, current->str);
//    while (current != NULL) {
//        if(velicina < strlen(current->str)){
//            velicina = strlen(current->str) + 1;
//            najdulji = realloc(najdulji, velicina);
//            strcpy(najdulji, current->str);
//        }
//        current = current->link;
//    }
//    return najdulji;
//}

//o    Ukupan broj riječi
int _ukupan_broj_rici(Element* lst){
    int brojac = 0;
    Element* current = lst;
    while(current != NULL){
        brojac++;
        current = current->link;
    }
    return brojac;
}
//o    Na početak liste
Element* _na_pocetak_liste(Element* lst, char* str){
    Element* novi = malloc(sizeof(Element));
    novi->link = lst;
    novi->str = malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(novi->str, str);
    lst = novi;
    return lst;
}
//o    Na kraj liste
Element* _dodaj_na_kraj(Element* lst, char* str){
    Element* current = lst;
    Element* novi = malloc(sizeof(Element));
    novi->str = malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(novi->str, str);
    novi->link = NULL;
    while(current->link != NULL){
        current = current->link;
    }
    current->link = novi;
    return lst;
}

//o    Prije određenog elementa u listi
Element* _prije_odredenog_elementa(Element* lst, char* str, int indeks){
    int i = 0;
    Element* current = lst;
    Element* novi = malloc(sizeof(Element));
    novi->str = malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(novi->str, str);
    novi->link = NULL;
    while(current->link != NULL){
        if(indeks - 2 == i){ // 3 - 2 = i  prije suze
            novi->link = current->link;
            current->link = novi;
            break;
        }
        i++;
        current = current->link;
    }
    return lst;
}
//o    Na određenom indeksu u listi
Element* _dodaj_na_odredeni_indeks(Element* lst, char* str, int indeks){
    int i = 0;
    Element* novi = malloc(sizeof(Element));
    novi->str = malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(novi->str, str);
    novi->link = NULL;
    
    Element* current = lst;
    while(current != NULL){
        if(i == indeks - 2){
            Element* tmp = current->link;
            current->link = novi;
            novi->link = tmp;
            break;
        }
        i++;
        current = current->link;
    }
    
    return lst;
}

//o    makni sa početka liste
Element* _ukloni_s_glave(Element* glava){
    if(glava == NULL){
        printf("Glava je prazna");
        return NULL;
    }
    Element* current = glava->link;
//    free(glava->str);
//    free(glava);
    return current;
}
//o    Sa kraja liste
Element* _makni_s_kraja(Element* lst){
    Element* current = lst;
    while(current->link->link != NULL){
        current = current->link;
    }
    current->link = NULL;
    return lst;
}

//o    Određenu riječ
Element* _makni_odredenu_ric(Element* lst, char* str){
    if(lst == NULL){
        return NULL;
    }
    Element* current = lst;
    if(strcmp(current->str,str) == 0){
        current = current->link;
        return current;
    }
    while(!(strcmp(current->link->str,str) == 0)){
        current = current->link;
    }
    if(current == NULL){
        printf("Ne postoji");
        return NULL;
    }
    Element* tmp = current->link->link;
    current->link = tmp;
    return lst;
}
//Okretanje liste    ?????????
Element* _okreni_lst(Element* lst){
    Element* current = lst;
    Element* next_current = NULL;
    Element* last_current = NULL;
    while(current != NULL){
        next_current = current->link;
        current->link = last_current;
        last_current = current;
        current = next_current;
    }
    
    return last_current;
}
//Uklanjanje više elemenata iz liste po nekom kriteriju (npr. zadnjih 10 elemenata ili sve elemente sa više od 10 znakova)
Element* _ukloni_sve_s_kriterijem(Element* lst, int n){
    if(lst == NULL){
        printf("lista je prazna");
        return NULL;
    }
    Element* current_last = lst;
    Element* current_next = current_last->link;
//    if(strlen(current_last->str) > n){
//        current_last = current_last->link;
//        current_next = current_last->link;
//    }
    while(current_next != NULL){
        if(strlen(current_next->str) > n){
            current_last->link = current_next->link;
        }
        current_last = current_last->link;
        current_next = current_next->link;
    }
    
    Element* pocetak = lst;
    if(strlen(pocetak->str) > n){
        pocetak = pocetak->link;
    }
    lst = pocetak;
    
    return lst;
}
//ukloni zadnjih par elemenata
Element* _ukloni_zadnjih_par(Element* lst, int n){ // je li ovo legitimno? zadnji ce mi ostat povezani ali ne s glavnom lisotm nego medusobno
    Element* current = lst;
//    Element* tmp;
//    Element* brojac_element = lst;
    int i = 0;
//    while(brojac_element != NULL){
//        i++;
//        brojac_element = brojac_element->link;
//    }
    i = i - n;
    while(current != NULL){
        if(i == 0){
            current->link = NULL;
            break;
        }
        i++;
        current = current->link;
    }
    
    
    return lst;
}
//dodavanje elementa ispred npr rijeci duze od 5
Element* _dodaj_ispred_kriterija(Element* lst, char* str, int n){
    if(strlen(lst->str) > n){
        Element* novi = malloc(sizeof(Element));
        novi->str = malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(novi->str, str);
        
        novi->link = lst;
        lst = novi;
    }
    Element* current = lst->link;
    Element* next = current->link;
    while(next != NULL){
        if(strlen(next->str) > n){
            Element* novi = malloc(sizeof(Element));
            novi->str = malloc(sizeof(char) * (strlen(str) + 1));
            strcpy(novi->str, str);
            
            novi->link = next;
            current->link = novi;
        }
        current = next;
        next = next->link;
    }
    
    return lst;
}
//Prebacivanje elementa u listi (npr. sa kraja na početak liste)
Element* _dodaj_s_kraja_na_pocetak(Element* lst){
    Element* current_next = lst->link;
    Element* current = lst;
    while(current_next->link != NULL){
        current_next = current_next->link;
        current = current->link;
    }
    current_next->link = lst;
    current->link = NULL;
    return current_next;
}

//Prebacivanje dijela liste u novu listu po nekom kriteriju (npr. sve riječi duže od 10 znakova)   ??????
Element* _prebaci_u_novu_kriterije(Element* lst, int n){
//    Element* current = lst;
    Element* prodi = lst;
    Element* nova_start = NULL;
    Element* nova_end = NULL;
//    int brojac = 0;
    while(prodi != NULL){
        if(strlen(prodi->str) > n){
            Element* nova = malloc(sizeof(Element));
            nova->str = malloc(sizeof(char) * (strlen(prodi->str) + 1));
            strcpy(nova->str, prodi->str);
            nova->link = NULL;
            if(nova_start == NULL){ // ovo ce biti samo prvi put kada nademo vise od n
                nova_start = nova; // nova_start ce imati adresu nova ali nece dereferencirati
                nova_end = nova; // isto kao i nova_start
            } else {
                nova_end->link = nova; // ovo ce se dogoditi drugi put, cim napunimo nova_start s vrijednosti, sada ce ovo nova_end ce pokazivati na nova
                nova_end = nova; // nova_end ce sacuvati varijablu nova i iduci krug ce spojiti cvor na nju
            }
        }
        prodi = prodi->link;
    }
    
    return nova_start;
}

//Zamjena dva elementa u listi (npr. prvi i zadnji)
Element* _zamjeni_dva_elementa(Element* lst){
    if(lst == NULL){
        printf("lista je prazna");
        return NULL;
    }
    Element* last = lst;
    Element* first = lst;
    Element* prev_to_last = NULL;
    while(last->link != NULL){// dode do predzadnjeg
        prev_to_last = last; // ovo ce biti predzanji
        last = last->link; // ovo ce biti zadnji
    }
    last->link = first->link; // zadnji se povezuje s prvim
    prev_to_last->link = first; // predzadnji se povezuje s prvim(zadnjim)
    first->link = NULL; // ovo stavljamo kako bi izbjegli beskonacnost
    
    return last;
}

//Kopiranje jednog ili više elemenata u novu listu   ??????
Element* _jedan_ili_vise_u_novu(Element* lst, int n){
    int i = 0;
    Element* current = lst;
    Element* novi_start = NULL;
    Element* novi_end = NULL;
    while (current != NULL) {
        if(i == n)
            break;
        Element* nova = malloc(sizeof(Element));
        nova->str = malloc(sizeof(char) * (strlen(current->str) + 1));
        strcpy(nova->str, current->str);
        if(novi_start == NULL){
            novi_start = nova;
            novi_end = nova;
        } else {
            novi_end->link = nova;
            novi_end = nova;
        }
        current = current->link;
        i++;
    }
    
    return novi_start;
}
//Kopiranje jednog ili više elemenata u niz
void _iz_liste_u_niz(int** niz, int n, Element* lst){
    int brojac = 0;
    *niz = malloc(sizeof(int) * (n));
    for(int i = 0; i < n; i++){
        (*niz)[i] = lst->str;
        lst = lst->link;
    }
}

//kopiranje iz niza u listu   ??????????????
Element* _iz_niza_u_listu(int* niz, int n){
    Element* lst = malloc(sizeof(Element));
    Element* current = lst;
    for(int i = 0; i < n; i++){
        Element* novi = malloc(sizeof(Element));
        novi->str = niz[i];
        novi->link = NULL;
        
        current->link = novi;
        current = current->link;
    }
//    current->link = NULL;
    lst = lst->link;
    return lst;
}
int main2(void){
    Element a, b, c, d, e;
    Element* glava = malloc(sizeof(Element));
    glava = &a;
    a.link = &b;
    b.link = &c;
    c.link = &d;
    d.link = &e;
    e.link = NULL;
    
    a.str = "Pocetak";
    b.str = "Gabo";
    c.str = "Roko";
//    c.str = "Pocetak";
    d.str = "Duje";
    e.str = "Kraj";
    
//    a.str = 1;
//    b.str = 2;
//    c.str = 3;
//    d.str = 4;
//    e.str = 5;
    
    // funkcije
//    char* rez1 = _nadi_najduzu_ric(glava);
//    printf("Najduza ric je %s\n",rez1);
//    int rez1 = _ukupan_broj_rici(glava);
//    printf("Ukupan broj rici je : %d\n",rez1);
//    glava = _na_pocetak_liste(glava, "Dodajem na pocetak");
//    glava = _dodaj_na_kraj(glava, "Dodajem na kraj");
//    glava = _prije_odredenog_elementa(glava, "Prije elementa", 3);
//    glava = _dodaj_na_odredeni_indeks(glava, "Na taj indeks", 3);
//    glava = _ukloni_s_glave(glava);
//    glava = _makni_s_kraja(glava);
//    glava = _makni_odredenu_ric(glava, "Gabo");
//    glava = _okreni_lst(glava);
//    glava = _ukloni_sve_s_kriterijem(glava, 5);
//    glava = _ukloni_zadnjih_par(glava, 2);
//    glava = _dodaj_ispred_kriterija(glava, "dodaj_prije_kriterija", 5);
//    glava = _dodaj_s_kraja_na_pocetak(glava);
//    glava = _prebaci_u_novu_kriterije(glava, 5);
//    glava = _zamjeni_dva_elementa(glava);
//    glava = _jedan_ili_vise_u_novu(glava, 2);
//    int *niz;
//    int n = 3;
//    _iz_liste_u_niz(&niz, n, glava);
//    int i;
//    for(i = 0; i < n; i++){
//        printf("%d ",niz[i]);
//    }
    
//    int niz[] = {1,2,3,4,5};
//    int n = sizeof(niz) / sizeof(niz[0]);
//    Element* rez = _iz_niza_u_listu(niz,n);
//    
//    _print(rez);
    _print(glava);
    return 0;
}
