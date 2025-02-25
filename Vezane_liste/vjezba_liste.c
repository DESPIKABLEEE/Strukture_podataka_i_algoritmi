#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* dodaj_na_kraj(struct Node* head,int broj){
    struct Node* nova = malloc(sizeof(struct Node));
    nova->data = broj;
    nova->link = NULL;
    head->link = nova;
    return nova;
}

int main6(void){
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 10;
    head->link = NULL;
    
    struct Node* ptr;
    ptr = head;
    ptr = dodaj_na_kraj(ptr, 30);
    ptr = dodaj_na_kraj(ptr, 50);
    
    ptr = head;
    while(ptr != NULL){
        printf("Data je %d\n",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}
