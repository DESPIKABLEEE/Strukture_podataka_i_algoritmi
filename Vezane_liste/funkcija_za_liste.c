#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

int brojac_lista(struct Node* head){
    int brojac = 0;
    if(head == NULL){
        printf("Head je null");
        return 1;
    }
    struct Node* ptr = head;
    while(ptr != NULL){
        brojac++;
        ptr = ptr->link;
    }
    return brojac;
}

void printaj_liste(struct Node* head){
    if(head == NULL){
        printf("Head je null");
        return;
    }
    struct Node* ptr = head;
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }
    printf("\nkraj\n");
}

void dodaj_na_kraj_liste(struct Node* head, int broj){
    if(head == NULL){
        printf("Head je null");
        return;
    }
    struct Node* ptr = head;
    struct Node* nova = malloc(sizeof(sizeof(struct Node)));
    nova->data = broj;
    nova->link = NULL;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = nova;
}

int main3(void){
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 45;
    head->link = NULL;
    
    struct Node* current1 = malloc(sizeof(struct Node));
    current1->data = 90;
    current1->link = NULL;
    head->link = current1;
    
    struct Node* current2 = malloc(sizeof(struct Node));
    current2->data = 135;
    current2->link = NULL;
    current1->link = current2;
    
    int rezultat = brojac_lista(head);
    printf("Brojac lista je %d\n",rezultat);
    
    printaj_liste(head);
    dodaj_na_kraj_liste(head, 180);
    printaj_liste(head);
    
    
    return 0;
}
