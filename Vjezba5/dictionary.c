#include "dictionary_new.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// kreaira novi prazni rjecnik
Dictionary create(){
    Dictionary glava = malloc(sizeof(Word));
    glava->next = NULL;
    glava->word = NULL;
    glava->count = 0;
    return glava;
    
}

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char *str) {
    Word* nova_ric = malloc(sizeof(Word));
    nova_ric->word = _strdup(str);
    nova_ric->count = 1;
    nova_ric->next = NULL;

    if (dict->next == NULL) {
        dict->next = nova_ric;
        return;
    }
    if (strcmp(str, dict->next->word) < 0) {
        nova_ric->next = dict->next;
        dict->next = nova_ric;
        return;
    }
    Word* current = dict->next;
    while (current->next != NULL && strcmp(str, current->next->word) > 0) {
        current = current->next;
    }
    if (current->next != NULL && strcmp(str, current->next->word) == 0) {
        current->next->count += 1;
        free(nova_ric->word);
        free(nova_ric);
    } else {
        nova_ric->next = current->next;
        current->next = nova_ric;
    }
}


// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict){
    //Word* ric = dict->next;
    dict = dict->next;
    while(dict != NULL){
        printf("%s : %d \n",dict->word,dict->count);
        dict = dict->next;
    }
}

// briöe cijeli rjeËnik
void destroy(Dictionary dict){
    while(dict != NULL){
        Word* brisi = dict;
        dict = dict->next;
        free(brisi->word);
        free(brisi);
    }
}

//Uz opisane funkcije, treba dodati i funkciju za filtriranje liste:
//Funkcija prima rječnik (lista ispunjena sa abecedno poredanim riječima i brojem pojavljivanja u tekstu) i pokazivač na funkciju:
void filterDictionary(Dictionary indict, int (*filter)(Word *w)){
    Word* current = indict->next;
    Word* prev = indict;
    
    while (current != NULL) {
        Word* next = current->next;
        if (filter(current)) {
            prev = current;
        } else {
            prev->next = next;
            free(current->word);
            free(current);
        }

            current = next;
        }
}

//Funkcija filterDictionary() vraća izmijenjenu indict listu koja sadrži samo riječi za koje je filter() funkcija vratila 1 (sve druge riječi se oslobađaju). Funkcija filter() vraća 1 ako je broj pojavljivanja riječi između 5 i 10 i ako je riječ duža od 3 znaka.

void predzadnji_na_glavu(Dictionary dict){
    Word* current = dict->next;
    Word* prev = dict;
    
    while(current->next != NULL){
        current = current->next;
        prev = prev->next;
    }
    
//    Word* tmp = current;
//    tmp->next = prev->next;
//    prev->next = current->next;
//    free(tmp);
//    current = current->next;
    current->next = dict->next;
    dict->next = current;
    
}

int filter(Word *w){
    return w->count >= 5 && w->count <= 10 && strlen(w->word) > 3;
}


//VJEZBA

//char* find_longest_word(Dictionary dict){
//    Word* tmp = NULL;
////    tmp->word = NULL; // OVO NE
//    Word* current = dict->next;
//    while(current != NULL){
//        if(tmp == NULL || strlen(current->word) > strlen(tmp->word)){
//            tmp = current;
//            tmp->word = strdup(current->word);
//        }
//        current = current->next;
//    }
//    
//    return tmp->word;
//}
//
//int number_of_strings_in_dict(Dictionary dict){
//    int brojac = 0;
//    Word* tmp = dict->next;
//    while(tmp != NULL){
//        brojac++;
//        tmp = tmp->next;
//    }
//    
//    return brojac;
//}
//
//
//void add_on_start(Dictionary dict){ // da ne dodamo neku koaj vec postoji nego da samo doda count?
//    Word* new = malloc(sizeof(Word));
//    new->word = strdup("Brat");
//    new->count = 1;
//    new->next = dict->next;
//    dict->next = new;
//}

//void add_on_end(Dictionary dict){
//    Word* current = dict;
//    while (current->next != NULL) {
//        current = current->next;
//    }
//    Word* new = malloc(sizeof(Word));
//    current->next = new;
//    new->count = 1;
//    new->word = _strdup("Brat2");
//	new->next = NULL;
//}
//
//void add_before_index(Dictionary dict, int index){
//    Word* tmp = dict->next;
//    for(int i = 0; i < index - 1; i++){
//        tmp = tmp->next;
//    }
//    Word* new = malloc(sizeof(Word));
//    new->count = 1;
//    new->next = tmp->next;
//    tmp->next = new;
//    new->word = strdup("Brat3");
//}
//
//void add_before_element(Dictionary dict, char* string){
//    Word* current = dict->next;
//    Word* prev = dict;
//    while(current != NULL){
//        if(strcmp(current->word, string) == 0){
//            Word* new = malloc(sizeof(Word));
//            new->next = current;
//            prev->next = new;
//            new->count = 1;
//            new->word = strdup("Brat3");
//        }
//        prev = current;
//        current = current->next;
//    }
//}
//
//void remove_from_start(Dictionary dict){
//    Word* current = dict->next;
//    Word* tmp = current;
//    dict->next = current->next;
//    free(tmp);
//}
//
//void remove_from_enndd(Dictionary dict){
//    Word* current = dict->next;
//    Word* tmp = NULL;
//    while(current->next->next != NULL){
//        current = current->next;
//    }
//    
//    tmp = current->next;
//    current->next = NULL;
//    free(tmp);
//}
//
//void remove_specific_word(Dictionary dict, char* string){
//    Word* current = dict->next;
//    while (current->next->next != NULL) {
//        if(strcmp(current->next->word, string) == 0){
//            Word* tmp = current->next;
//            current->next = current->next->next;
//            free(tmp);
//        }
//        current = current->next;
//    }
//    
//}
//
//Dictionary reverse_dict(Dictionary dict){
//    Dictionary glava_okrenuta = NULL;
////    glava_okrenuta->word = NULL;
////    glava_okrenuta->count = 0;
////    glava_okrenuta->next = NULL;
//    Word* current = dict->next;
//    while(current != NULL){
//        Word* tmp = current;
//        current = current->next;
//        tmp->next = glava_okrenuta;
//        glava_okrenuta = tmp;
//    }
//    Dictionary head = malloc(sizeof(Word));
//    head->word = NULL;
//    head->next = glava_okrenuta;
//    return head;
//}
//
//void remove_all_above_10chars(Dictionary dict){
//    Word* current = dict->next;
//    Word* prev = dict;
//    
//    while(current != NULL){
//        if(strlen(current->word) > 4){
//            Word* tmp = current;
//            prev->next = current->next;
//            free(tmp);
//            current = prev->next;
//            
//        } else {
//            prev = prev->next;
//            current = current->next;
//        }
//    }
//}
//
//void remove_last_3_elements(Dictionary dict){
//    Word* current = dict->next;
//    Word* prev = dict;
//    int brojac = 0;
//    while(current != NULL){
//        brojac++;
//        current = current->next;
//    }
//    current = dict->next;
//    for(int i = 0; i < brojac - 3; i++){
//        current = current->next;
//        prev = prev->next;
//    }
//    while(current != NULL){
//        Word* tmp = current;
//        current = current->next;
//        free(tmp);
//    }
//    prev->next = NULL;
//}
//
//void add_elements_in_lst(Dictionary dict){
//    Word* current = dict;
//    while(current->next != NULL){
//        if(strlen(current->next->word) > 6){
//            Word* new = malloc(sizeof(Word));
//            new->word = strdup("Batonga");
//            new->count = 1;
//            new->next = current->next;
//            current->next = new;
//            current = current->next;
//        }
//        current = current->next;
//    }
////    current->next = NULL;
//}
//
//void replace_element_in_lst(Dictionary dict, int start, int end){
//    Word* current = dict->next;
//    Word* tmp = NULL;
//    int i,j;
//    for(i = 0; i < start - 1; i++){
//        current = current->next;
//    }
//    tmp = current->next;
//    current->next = current->next->next;
//    for(j = i; j < end - 2; j++){
//        current = current->next;
//    }
//    tmp->next = current->next;
//    current->next = tmp;
//}
//
//Dictionary add_to_another_lst_longer_words(Dictionary dict, int length){
//    Dictionary glava = malloc(sizeof(Word));
//    glava->count = 0;
//    glava->word = NULL;
//    glava->next = NULL;
//    
//    Word* current = dict->next;
//    Word* prev = dict;
//    while(current != NULL){
//        if (strlen(current->word) > length) {
//            Word* tmp = current;
//            current = current->next;
//            prev->next = current;
//            tmp->next = NULL;
//            if(glava->next == NULL){
//                glava->next = tmp;
//            } else {
//                Word* provjeri = glava->next;
//                    while(provjeri->next != NULL){
//                        provjeri = provjeri->next;
//                    }
//                    provjeri->next = tmp;
//            }
//        } else {
//            current = current->next;
//            prev = prev->next;
//        }
//        
//    }
//    
//    
//    return glava;
//}
//
void swap_two_elementsss(Dictionary dict, int first, int second){
    Word* current = dict->next;
    Word* prev = dict;
    Word* tmp1 = NULL;
    Word* tmp2 = NULL;
    Word* prev1 = NULL;
    Word* prev2 = NULL;
    int i = 0,j;
    while (current != NULL && i <= second) {
        if(i == first-1){
            prev1 = current;
        }
        if(i == first){
            tmp1 = current;
        }
        if(i == second-1){
            prev2 = current;
        }
        if(i == second){
            tmp2 = current;
        }
        i++;
        current = current->next;
    }
    if(tmp1 != NULL && tmp2 != NULL){
        if(prev1 != NULL){
            prev1->next = tmp2;
        }
        if(prev2 != NULL){
            prev2->next = tmp1;
        }
        Word* zamjena = NULL;
        zamjena = tmp1->next;
        tmp1->next = tmp2->next;
        tmp2->next = zamjena;
        
        if(prev1 == NULL){
            dict->next = tmp2;
        } else if (prev2 == NULL){
            dict->next = tmp1;
        }
    }
    
    
}
