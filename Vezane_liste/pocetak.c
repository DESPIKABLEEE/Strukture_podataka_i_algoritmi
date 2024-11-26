#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* link;
};
int main2(void){
    struct Node* glava;
    glava = malloc(sizeof(struct Node));
    glava->data = 45;
    glava->link = NULL;
    
    struct Node* iduca = malloc(sizeof(struct Node));
    iduca->data = 90;
    iduca->link = NULL;
    glava->link = iduca;
    printf("Data glava je %d\n", glava->data);
    printf("Data iduca je %d\n",iduca->data);
//    int n = glava->link->data;
//    printf("\n%d\n", n);
    struct Node* iduca2 = malloc(sizeof(struct Node));
    iduca2->data = 120;
    iduca2->link = NULL;
    iduca->link = iduca2;
    printf("Data iduca2 je %d\n",iduca2->data);
    int n = glava->link->link->data;
    printf("Vrijednost od glava->link->link->data je %d\n",n);
    return 0;
}
