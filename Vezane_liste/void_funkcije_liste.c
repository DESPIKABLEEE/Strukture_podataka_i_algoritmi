//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//typedef struct _Element{
//    char* str;
//    struct _Element* link;
//}Element;
//
//void isprintaj(Element* lst){
//    Element* current = lst;
//    while(current != NULL){
//        printf("%s  ",current->str);
//        current = current->link;
//    }
//}
//
//void dodaj_u_glavu(Element** lst, char* str){
//    Element* novi = malloc(sizeof(Element));
//    novi->str = malloc(sizeof(char) * (strlen(str) + 1));
//    strcpy(novi->str, str);
//    novi->link = (*lst);
//    (*lst)= novi;
//}
//
////Traženje najduže riječi +
////void trazi_najdulji_str(Element* lst){
////    char* najdulji;
////    int duljina = 0;
////    Element* current = lst;
////    while(current != NULL){
////        if(duljina < strlen(current->str)){
////            duljina = strlen(current->str);
////            najdulji = malloc(sizeof(char) * (duljina + 1));
////            strcpy(najdulji, current->str);
////        }
////        current = current->link;
////    }
////    printf("\nNajdulji je %s i duzina je %d\n", najdulji, duljina);
////}
////Ukupan broj riječi  +
//void ukupan_broj_rijeci(Element* lst){
//    int brojac = 0;
//    Element* current = lst;
//    while(current != NULL){
//        brojac++;
//        current = current->link;
//    }
//    printf("\nBrojac rijeci je : %d\n",brojac);
//}
//
////Dodaj na kraj liste
////void dodaj_u_kraj(Element** lst, char* str){
////    Element* novi = malloc(sizeof(Element));
////    novi->str = malloc(sizeof(char) * (strlen(str) + 1));
////    strcpy(novi->str, str);
////    novi->link = NULL;
////    Element* current = (*lst);
////    while(current->link != NULL){
////        current = current->link;
////    }
////    current->link = novi;
////    //(*lst) = current;
////}
////Dodaj na odredeni indeks
////void dodaj_na_indeks(Element** lst, char* str, int indeks){
////    Element* ptr = (*lst);
////    Element* current = ptr;
////    int i = 0;
////    while(current->link != NULL && i < indeks){
////        if(indeks - 1 == i){
////            Element* novi = malloc(sizeof(Element));
////            novi->str = malloc(sizeof(char) * (strlen(str) + 1));
////            strcpy(novi->str, str);
////            
////            novi->link = current->link; //
////            current->link = novi;
////            break;
////        }
////        i++;
////        current = current->link;
////    }
////    (*lst) = ptr;
////}
//
////ukloni s pocetka
////void ukloni_s_glave(Element** lst){
////    Element* ptr = (*lst);
////    Element* current = ptr;
////    Element* tmp = current->link;
//////    free(current->str);
//////    free(current);
//////    tmp = current->link;
////    (*lst) = tmp;
////}
//
////ukloni s kraja
//void ukloni_sa_kraja(Element** lst){
//    Element* ptr = (*lst);
//    Element* current = ptr;
//    while(current->link->link != NULL){
//        current = current->link;
//    }
//    current->link = NULL;
//    (*lst) = ptr;
//}
//
////ukloni odredenu rijec
//void ukloni_trazenu_rijec(Element** lst, char* str){
//    Element* ptr = (*lst);
//    Element* current = ptr;
//    while(current != NULL && (strcmp(str, current->str) != 0)){
//        current = current->link;
//    }
//    current->link = current->link->link;
//    (*lst) = ptr;
//}
//
//int main7(){
//    Element a, b, c, d, e;
//    Element* ptr;
//    ptr = &a;
//    a.link = &b;
//    b.link = &c;
//    c.link = &d;
//    d.link = &e;
//    e.link = NULL;
//    
//    a.str = "Start";
//    b.str = "Suza";
//    c.str = "Gabo";
//    d.str = "Duje";
//    e.str = "End";
//    
//    //char* dodaj_str = "Batonga";
//    
//    //dodaj_u_kraj(&ptr, dodaj_str);
//    //dodaj_u_glavu(&ptr, dodaj_str);
//    //dodaj_na_indeks(&ptr, dodaj_str, 1);
//    //ukloni_s_glave(&ptr);
//    //ukloni_sa_kraja(&ptr);
//    ukloni_trazenu_rijec(ptr, "Gabo");
//    isprintaj(ptr);
//    //ukupan_broj_rijeci(ptr);
//    //trazi_najdulji_str(ptr);
//    
//    return 0;
//}
