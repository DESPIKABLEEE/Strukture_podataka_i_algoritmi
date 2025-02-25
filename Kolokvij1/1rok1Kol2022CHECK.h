//  1.
//  t(n) = c1 + n/2 + c2 + 2 * log(n) = n + log(n) = n
//  o(n) = n


//int f(int *niz, int n) {
//    int i = 0, sum = 0;
//    while(i < n) {
//        sum += niz[i];
//        i+=2;
//    }
//    int j = 1;
//    while (j < 2 * n) {
//        sum += niz[j];
//        j= j+j;
//    }
//    return sum;
//}

//  2.
//  Procijeniti vremensku složenost O() algoritma koji provjerava da li dva skupa (niza brojeva) sadrže iste elemente. Dužina svakog niza je N. Algoritam se može napisati na dva načina:
//      a)    Za svaki broj u prvom nizu se provjerava da li postoji u drugom nizu. Zatim se za svaki broj u drugom nizu provjerava da li postoji u prvom nizu.
//      b)    Oba niza se kopiraju u jedan niz i zatim se taj niz sortira sa mergesortom. Nakon toga se provjerava da svi brojevi imaju jednakog susjeda.

//      a) O(N) = N^2 + N^2 = N^2
//      b) O(N) = 2N + 2N * log(2N) + 2N = N * log(N)


//  3.
//  Napisati funkciju koja prima dvije jednostruko vezane liste (svaki element sadrži broj). Funkcija provjerava da li su obje liste potpuno jednake. Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova)

//int funkcija(){
//    if(lst1 == NULL || lst2 == NULL){
//        printf("Lista je prazna");
//        return -1;
//    }
//    while (lst1 != NULL && lst2 != NULL) {
//        if(lst1->data != lst2->data){
//            return 0;
//        }
//        lst2 = lst2->next;
//        lst1 = lst1->next;
//    }
//    return 1;
//}

//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati nove elemente sa tim brojem na početak i na kraj liste.

//void funkcija(Node* lst, int dodatniBroj){
//    if(lst == NULL || lst->next == NULL){
//        printf("Greska, lista ili nema glavu ili prvi element");
//        return;
//    }
//    Node* tmp1 = malloc(sizeof(Node));
//    tmp1->data = dodatniBroj;
//    tmp1->next = lst->next;
//    lst->next = tmp1;
//    Node* current = lst->next;
//    while (current->next != NULL) {
//        current = current->next;
//    }
//    Node* tmp2 = malloc(sizeof(Node));
//    tmp2->data = dodatniBroj;
//    tmp2->next = NULL;
//    current->next = tmp2;
//}


//  T(n) = c1 + n/2 + c2 + 2 * n = n
//  O(n) = n
int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i < n) {
        sum += niz[i];
        i+=2;
    }
    int j = 1;
    while (j < 2 * n) {
        sum += niz[j];
        j= j+j;
    }
    return sum;
}

//  2.
//  Procijeniti vremensku složenost O() algoritma koji provjerava da li dva skupa (niza brojeva) sadrže iste elemente. Dužina svakog niza je N. Algoritam se može napisati na dva načina:
//      a)    Za svaki broj u prvom nizu se provjerava da li postoji u drugom nizu. Zatim se za svaki broj u drugom nizu provjerava da li postoji u prvom nizu.
//      b)    Oba niza se kopiraju u jedan niz i zatim se taj niz sortira sa mergesortom. Nakon toga se provjerava da svi brojevi imaju jednakog susjeda.


//  a) O(N) = N*N + N*N = N^2
//  b) O(N) = 2N + 2N * log(2N) = N * log(N)



//  3.
//  Napisati funkciju koja prima dvije jednostruko vezane liste (svaki element sadrži broj). Funkcija provjerava da li su obje liste potpuno jednake. Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova)

int funkcija(Node* lst1, Node* lst2){
    // Provjeravamo je li obje liste prazne
    if(lst1 == NULL && lst2 == NULL){
        return 1;  // Ako su obje prazne, liste su jednake
    }

    // Ako je jedna lista prazna, a druga nije, nisu jednake
    if(lst1 == NULL || lst2 == NULL){
        return 0;
    }

    // Prolazimo kroz obje liste dok su iste dužine i svi elementi su jednaki
    while (lst1 != NULL && lst2 != NULL) {
        if(lst1->data != lst2->data){
            return 0;  // Ako se brojevi ne podudaraju, liste nisu jednake
        }
        lst1 = lst1->next;
        lst2 = lst2->next;
    }

    // Ako obje liste završavaju istovremeno, to znači da su jednake
    // Ako je jedna lista duža od druge, neće se završiti istovremeno
    if(lst1 == NULL && lst2 == NULL){
        return 1;
    }

    return 0;  // Ako su dužine različite, liste nisu jednake
}



//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati nove elemente sa tim brojem na početak i na kraj liste.

void funkcija(Node** lst, int dodatni){
    if((*lst) == NULL){
        printf("Lista je prazna");
        return;
    }
    Node* tmp = malloc(sizeof(Node));
    tmp->next = (*lst);
    tmp->data = dodatni;
    (*lst) = tmp;
    while((*lst)->next != NULL){
        (*lst) = (*lst)->next;
    }
    Node* tmp2 = malloc(sizeof(Node));
    tmp2->next = NULL;
    tmp2->data = dodatni;
    (*lst)->next = tmp2;
}
