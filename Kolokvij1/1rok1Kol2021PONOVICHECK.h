//  1.

//  T(N) = c1 + n * (c2 + n/3) = n * n = n^2
//  O(N) = n^2
//int f(int *niz, int n) {
//    int i = 0, sum = 0;
//    while(i < n) {
//        int j = 1;
//        while (j < n) {
//            sum += niz[j];
//            j = 3*j;
//        }
//        i++;
//    }
//    return sum;
//}


//  2.
//  Procijeniti složenost O() algoritma koji računa operaciju za niz brojeva dužine N. Svi brojevi su cijeli brojevi u rasponu [1, K]. Algoritam traži koji se broj pojavljuje najviše puta u nizu. Algoritam se može napisati na tri načina:
//      a)    Za svaki broj u nizu, broji se njegovo pojavljivanje u cijelom nizu i pamti se broj sa najviše pojavljivanja.
//      b)    Sortiramo niz i brojimo koliko puta se pojavljuje svaki broj bez vraćanja.
//      c)    Za svaki broj od 1 do K, broji se njegovo pojavljivanje u cijelom nizu i pamti se broj sa najviše pojavljivanja.
//  Složenost za svaki način izraziti u N i K. Možete pretpostaviti da se za sortiranje koristi quicksort. ****

//      a)  O(N) = N * N
//      b)  O(N) = N * log(N) + log(N)
//      c)  O(N) = N * K



//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će vratiti pokazivač na element sa najvećim brojem. (25 bodova)

//Node* funkcija(Node* lst){
//    if(lst == NULL){
//        printf("Lista je prazna");
//        return NULL;
//    }
//    Node* current = lst;
//    Node* najveci = lst;
//    int najveciBroj = lst->data;
//    while (current != NULL) {
//        if(current->data > najveciBroj){
//            najveciBroj = current->data;
//            najveci = current;
//        }
//        current = current->next;
//    }
//    return najveci;
//}


//  4.
//  Napisati funkciju koja prima vezanu listu sa barem tri elementa. Funkcija će izbrisati zadnja tri elementa iz liste. (35 bodova) *****

//void funkcija(Node* lst){
//    if(lst == NULL || lst->next == NULL || lst->next->next == NULL){
//        printf("Lista nije legalna");
//        return;
//    }
//    Node* current = lst;
//    Node* tmp = NULL;
//    while(current->next->next->next != NULL){
//        tmp = current;
//        current = current->next;
//    }
//    tmp->next = NULL;
//    for(int i = 0; i < 3; i++){
//        tmp = current;
//        current = current->next;
//        tmp->next = NULL;
//        free(tmp);
//    }
//}








//  T(n) = c1 + n * (log(n)) = n * log(n)
//  O(n) = n * log(n)
int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i < n) {
        int j = 1;
        while (j < n) {
            sum += niz[j];
            j = 3*j;
        }
        i++;
    }
    return sum;
}


//  2.
//  Procijeniti složenost O() algoritma koji računa operaciju za niz brojeva dužine N. Svi brojevi su cijeli brojevi u rasponu [1, K]. Algoritam traži koji se broj pojavljuje najviše puta u nizu. Algoritam se može napisati na tri načina:
//      a)    Za svaki broj u nizu, broji se njegovo pojavljivanje u cijelom nizu i pamti se broj sa najviše pojavljivanja.
//      b)    Sortiramo niz i brojimo koliko puta se pojavljuje svaki broj bez vraćanja.
//      c)    Za svaki broj od 1 do K, broji se njegovo pojavljivanje u cijelom nizu i pamti se broj sa najviše pojavljivanja.
//  Složenost za svaki način izraziti u N i K. Možete pretpostaviti da se za sortiranje koristi quicksort.

//  a)  O(N) = N * N
//  b)  O(N) = N * log(N) + N = N * log(N)
//  c)  O(N) = N + K


//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će vratiti pokazivač na element sa najvećim brojem. (25 bodova)

Node* funkcija(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna");
        return NULL;
    }
    Node* pamti = NULL;
    int najveci = 0;
    while (lst != NULL) {
        if(lst->data > najveci){
            najveci = lst->data;
            pamti = lst;
        }
        lst = lst->next;
    }
    
    return pamti;
}


//  4.
//  Napisati funkciju koja prima vezanu listu sa barem tri elementa. Funkcija će izbrisati zadnja tri elementa iz liste. (35 bodova)

void funkcija(Node** lst){
    if((*lst) == NULL || (*lst)->next == NULL || (*lst)->next->next == NULL){
        printf("Lista je prazna ili nema dovoljno elemenata");
        return;
    }
    Node* current = (*lst);
    while (current->next->next->next != NULL) {
        current = current->next;
    }
    Node* tmp = current->next;;
    current->next = NULL;
    while (tmp != NULL) {
        Node* brisi = tmp;
        tmp = tmp->next;
        free(brisi);
    }
}
