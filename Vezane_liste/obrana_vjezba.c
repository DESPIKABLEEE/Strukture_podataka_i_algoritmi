#include <stdio.h>
#include <stdlib.h>

typedef struct _Element{
    int data;
    struct _Element* link;
}Element;

Element* dodaj_element(Element*, int);

Element* dodaj_element_na_pocetak(Element*, int);

void print_elemente(Element*);

int ukupan_broj_elemenata(Element*);

Element* dodaj_element_prije_odredenog(Element* , int ,int );

Element* dodaj_element_na_indeks(Element*, int, int);

Element* ukloni_s_pocetka(Element*);

Element* ukloni_s_kraja(Element* );

Element* ukloni_odredeni_broj(Element* , int );

//Element* okreni_listu(Element*);

int main1(void){
    Element* glava = malloc(sizeof(Element));
    glava->data = -1;
    glava->link = NULL;
    Element* ptr = malloc(sizeof(Element));
    ptr = glava;
    ptr = dodaj_element(ptr, 9);
    ptr = dodaj_element(ptr, 3);
    ptr = dodaj_element(ptr, 7);
    
    //print_elemente(ptr);
    
    //int brojac = ukupan_broj_elemenata(glava);
    //printf("Brojac je : %d\n",brojac);
    
//    ptr = dodaj_element_na_pocetak(ptr, 13);
//    
//    //print_elemente(ptr);
//    
//    ptr = dodaj_element_prije_odredenog(ptr, 22, 3);
//    
//    //print_elemente(ptr);
//    
//    ptr = dodaj_element_na_indeks(ptr, 99, 4);
//    
//    ptr = ukloni_s_pocetka(ptr);
//    
//    ptr = ukloni_s_kraja(ptr);
//    
//    ptr = ukloni_odredeni_broj(ptr, 9);
    
//    ptr = okreni_listu(ptr);
    
    print_elemente(ptr);
    
    return 0;
}

void print_elemente(Element* glava){
    Element* tmp = glava;
    while(tmp != NULL){
        printf("Data je : %d\n",tmp->data);
        tmp = tmp->link;
    }
    printf("Gotov print\n");
}

Element* dodaj_element(Element* glava, int broj){
    Element* novi = malloc(sizeof(Element));
    novi->data = broj;
    novi->link = NULL;
    Element* tmp = glava;
    while(tmp->link != NULL){
        tmp = tmp->link;
    }
    tmp->link = novi;
    return glava;
}

int ukupan_broj_elemenata(Element* glava){
    int brojac = 0;
    Element* tmp = glava;
    while(tmp != NULL){
        brojac++;
        tmp = tmp->link;
    }
    return brojac;
}

Element* dodaj_element_na_pocetak(Element* glava, int broj){
    Element* novi = malloc(sizeof(Element));
    novi->data = broj;
    novi->link = glava;
    return novi;
}

Element* dodaj_element_prije_odredenog(Element* glava, int broj,int indeks){
    Element* novi = malloc(sizeof(Element));
    Element* tmp = glava;
    for(int i = 0; i < indeks; i++){
        if(indeks - 1 == i){
            novi->data = broj;
            Element* sacuvaj;
            sacuvaj = tmp->link;
            tmp->link = novi;
            novi->link = sacuvaj;
            //break;
        }
        tmp = tmp->link;
    }
    return glava;
}

Element* dodaj_element_na_indeks(Element* glava, int broj, int indeks){
    Element* novi = malloc(sizeof(Element));
    novi->data = broj;
    Element* tmp = glava;
    for(int i = 0; i <= indeks + 1; i++){
        if(i == indeks - 1){
            Element* sacuvaj;
            sacuvaj = tmp->link;
            tmp->link = novi;
            novi->link = sacuvaj->link;
            free(sacuvaj);
        }
        tmp = tmp->link;
    }
    return glava;
}


Element* ukloni_s_pocetka(Element* glava){
    Element* tmp = glava;
    glava = tmp->link;
    tmp->link = NULL;
    free(tmp);
    return glava;
}

Element* ukloni_s_kraja(Element* glava){
    Element* tmp = glava;
    while(tmp->link->link != NULL){
        tmp = tmp->link;
    }
    Element* brisi = tmp->link;
    tmp->link = NULL;
    free(brisi);
    return glava;
}


Element* ukloni_odredeni_broj(Element* glava, int broj){ // broj = 9
    Element* tmp = glava;
    while(tmp != NULL){
        if(tmp->data){
            if(tmp->link->data == broj){
                Element* brisi = tmp->link;
                tmp->link = tmp->link->link;
                brisi = NULL;
                free(brisi);
                break;
            }
        }
        tmp = tmp->link;
    }
    return glava;
}

//Element* okreni_list(Element* glava){
//    Element* prethodni = NULL;
//    Element* trenutni = glava;
//    Element* iduci = NULL;
//    while(trenutni != NULL){
//        iduci = trenutni->link;
//        trenutni->link = prethodni;
//        prethodni = trenutni;
//        trenutni = iduci;
//    }
//    
//    return prethodni;
//}
