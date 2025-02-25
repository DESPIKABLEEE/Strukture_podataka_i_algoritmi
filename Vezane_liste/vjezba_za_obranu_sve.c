#include <stdio.h>
#include <stdlib.h>
typedef struct _Element{
    int data;
    struct _Element* next;
}Element;
//printaj
void print_lsts(Element* head){
    if(head->next == NULL){
            printf("Error");
            return;
    }
    head = head->next;
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
//-    Šetanje po listi
    //o    Traženje najveceh broja
int find_biggest_number(Element* head){
    if(head->next == NULL){
        printf("head je prazan");
        return 0;
    }
    int najveci = head->next->data;
    head = head->next;
    while(head != NULL){
        if(najveci < head->data){
            najveci = head->data;
        }
        head = head->next;
    }
    return najveci;
}
    //o    Ukupan broj elemenata
int number_of_elements(Element* head){
    if(head == NULL){
        printf("head je prazan");
        return 0;
    }
    int elements = 0;
    head = head->next;
    while(head != NULL){
        elements++;
        head = head->next;
    }
    
    return elements;
}
//-    Kreiranje i dodavanje novog elementa:
    // o    Na početak liste
Element* add_on_start_of_lst(Element* head, int broj){
    if(head == NULL){
        printf("Head je prazan");
        return NULL;
    }
    Element* new = malloc(sizeof(Element));
    new->next = head->next;
    head->next = new;
    new->data = broj;
    
    return head;
}
    // o    Na kraj liste
Element* add_at_the_end_of_lst(Element* head, int broj){
    if(head == NULL){
        printf("Head je prazan");
        return NULL;
    }
    Element* tmp = head->next;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    Element* new = malloc(sizeof(Element));
    new->next = NULL;
    new->data = broj;
    tmp->next = new;
    
    return head;
}
    // o    Prije određenog elementa u listi
Element* add_before_that_data(Element* head, int broj){
    Element* current = head;
    if(head->next == NULL){
        printf("Lista je prazna");
        return head;
    }
    while(current->next->next != NULL){
        if(current->next->data == broj){
            Element* new = malloc(sizeof(Element));
            new->data = 99;
            new->next = current->next;
            current->next = new;
            current = current->next;
        }
        current = current->next;
    }
    
    return head;
}

    // o    Na određenom indeksu u listi
Element* add_on_specifid_index(Element* head, int indeks){
    Element* current = head;
    if(head->next == NULL){
        printf("Head je prazan");
        return NULL;
    }
    int brojac = 0;
    Element* tmp = head->next;
    while(tmp != NULL){
        brojac++;
        tmp = tmp->next;
    }
    if(indeks > brojac){
        printf("Greska");
        return head;
    }
    for(int i = 0; i < indeks; i++){
        current = current->next;
    }
    Element* new = malloc(sizeof(Element));
    new->data = 98;
    new->next = current->next;
    current->next = new;
    return head;
}

//-     Pronalazak i uklanjanje elementa iz liste:
    //o    Sa početka liste
Element* delete_from_start(Element* head){
    if(head == NULL || head->next == NULL){
        printf("Lista ili prvi el su nepostojeci");
        return head;
    }
    Element* tmp = head->next;
    head->next = head->next->next;
    free(tmp);
    return head;
}

    //o    Sa kraja liste
Element* remove_from_end(Element* head){
    if(head == NULL || head->next == NULL){
        printf("lsita ili je prazna ili nema el");
        return head;
    }
    if(head->next->next != NULL){
        Element* current = head->next;
        while(current->next->next != NULL){
            current = current->next;
        }
        Element* tmp = current->next;
        current->next = NULL;
        free(tmp);
    } else {
        Element* tmp = head->next;
        head->next = head->next->next;
        free(tmp);
    }
    
    return head;
}
    //o    Određeni broj  !!! vraca error ako je broj broj broj broj x
Element* remove_specific_number(Element* head, int broj){
    if(head == NULL){
        printf("Lista je prazna");
        return head;
    }
    Element* current = head;
    int postoji = 0;
    while(current->next != NULL){
        if(current->next->data == broj){
            Element* tmp = current->next;
            current->next = current->next->next;
            free(tmp);
            postoji = 1;
        } else {
            current = current->next;
        }
    }
    if(postoji == 0){
        printf("Ne postoji");
        return head;
    }
    return head;
}
// neke random funkcije, ne ukplapaju se u dodavanje/brisanje ali po potrebi brisem/dodam


//-    Uklanjanje više elemenata iz liste po nekom kriteriju (npr. zadnjih 10 elemenata ili sve elemente sa više od 10 znakova)
Element* remove_last_number_of_elements(Element* head, int number_of_elements){
    Element* izbroji_elemente = head->next;
    int brojac = 0;
    while (izbroji_elemente != NULL) {
        brojac++;
        izbroji_elemente = izbroji_elemente->next;
    }
    int range = brojac - number_of_elements;
    Element* current = head->next;
    while(current != NULL && range != 1){
        range--;
        current = current->next;
    }
    Element* tmp = current->next;
    current->next = NULL;
    Element* cuvaj = NULL;
    while(tmp != NULL){
        cuvaj = tmp;
        tmp = cuvaj->next;
        free(cuvaj);
    }
    
    return head;
}

//-    Dodavanje više elemenata u listu (npr. ispred svake riječi duže od 10 znakova)
Element* add_elements_before_number(Element* head, int number){
    Element* prev = head;
    Element* current = head->next;
    while(current != NULL){
        if(current->data == number){
            Element* new = malloc(sizeof(Element));
            new->data = 99;
            new->next = current;
            prev->next = new;
        }
        
        prev = current;
        current = current->next;
    }
    
    
    return head;
}

// -   Zamjena dva elementa u listi (npr. prvi i zadnji)
Element* swap_two_elements(Element* head, int start, int stop){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    int brojac = 0;
    Element* broji = head->next;
    while(broji != NULL){
        brojac++;
        broji = broji->next;
    }
    if(stop > brojac || brojac < start){
        return NULL;
    }
    int i;
    Element* prvi = head->next;
    Element* tmp_prvi = NULL;
    Element* prev1 = NULL;
    for(i = 0; i < start; i++){
        if(i == start - 2){
            prev1 = prvi;
        }
        tmp_prvi = prvi;
        prvi = prvi->next;
    }
    Element* drugi = head->next;
    Element* tmp_drugi = NULL;
    Element* prev_drugi = NULL;
    for(i = 0; i < stop; i++){
        if(i == stop - 2){
            prev_drugi = drugi;
        }
        tmp_drugi = drugi;
        drugi = drugi->next;
    }
    
    int razlika = stop - start;
    if(razlika == 1)
    {
        tmp_prvi->next = tmp_drugi->next;
        prev1->next = tmp_drugi;
        tmp_drugi->next = tmp_prvi;
    }
    else if (razlika > 1)
    {
        Element* tmp = tmp_prvi->next;
        tmp_prvi->next = tmp_drugi->next; // dobro
        tmp_drugi->next = tmp;  // dobro
//        tmp->next = tmp_prvi;
        if(prev1 != NULL){
            prev1->next = tmp_drugi;
        } else {
            head->next = tmp_drugi;
        }
        prev_drugi->next = tmp_prvi;
    }  // pomoc
    
    return head;
}
//-    Prebacivanje elementa u listi
Element* replace_from_one_to_another(Element* head, int pocetak, int kraj){
    if(head == NULL || head->next == NULL){
        printf("Lista je prazna");
        return head;
    }
    int brojac = 0;
    Element* izbroji = head->next;
    while(izbroji != NULL){
        brojac++;
        izbroji = izbroji->next;
    }
    if(brojac < pocetak || brojac < kraj){
        printf("Unesite druge brojeve");
        return head;
    }
    if(pocetak > kraj){
        int temp = pocetak;
        pocetak = kraj;
        kraj = temp;
    }
    int i;
    Element* prvi_pamti = NULL;
    Element* prvi_prodi = head->next;
    for(i = 0; i < pocetak; i++){
        prvi_pamti = prvi_prodi;
        prvi_prodi = prvi_prodi->next;
    }
    
    prvi_pamti->next = prvi_prodi->next;
    
    Element* drugi_pamti = NULL;
    Element* drugi_prodi = head->next;
    for(i = 0; i < kraj; i++){
        drugi_pamti = drugi_prodi;
        drugi_prodi = drugi_prodi->next;
    }
    
    prvi_prodi->next = drugi_prodi;
    drugi_pamti->next = prvi_prodi;
    
    return head;
}

Element* reverse_lst(Element* head){
    Element* okrenuta = NULL;
    Element* current = head->next;
    while(current != NULL){
        Element* tmp = current;
        current = current->next;
        tmp->next = okrenuta;
        okrenuta = tmp;
    }
    
    head->next = okrenuta;
    return head;
}



int main10(){
    Element* head = malloc(sizeof(Element));
    if(head == NULL){
        printf("Head nema memorije");
        return 1;
    }
    head->next = NULL;
    
    Element* a = malloc(sizeof(Element));
    Element* b = malloc(sizeof(Element));
    Element* c = malloc(sizeof(Element));
    Element* d = malloc(sizeof(Element));
    Element* e = malloc(sizeof(Element));
    
    a->data = 2;
    b->data = 4;
    c->data = 8;
    d->data = 16;
    e->data = 32;
    
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = NULL;
    
    printf("Zadaci :\n");
    
//    int najveci_broj = find_biggest_number(head);
//    printf("Najveci broj je : %d\n",najveci_broj);
    
//    int suma = number_of_elements(head);
//    printf("broj el je : %d\n",suma);
    
//    head = add_on_start_of_lst(head, 99);
    
//    head = add_at_the_end_of_lst(head, 99);
    
//    head = add_before_that_data(head, 16);
    
//    head = add_on_specifid_index(head, 3);
    
//    head = delete_from_start(head);
    
//    head = remove_from_end(head);
    
//    head = remove_specific_number(head, 16);
    
//    head = remove_last_number_of_elements(head, 3); //??

//    head = add_elements_before_number(head, 16);
    
//    head = swap_two_elements(head, 2, 5);
    
//    head = replace_from_one_to_another(head, 1, 3);
    
    head = reverse_lst(head);
    
    print_lsts(head);
    
    return 0;
}
