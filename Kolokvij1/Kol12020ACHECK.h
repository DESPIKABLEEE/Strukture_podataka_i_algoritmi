//  1.

//  T(N) = c1 + n * (2 * log(n) * (c2))  = n * log(n)
//  O(N) = nlog(n)

//int f(int *niz, int n) {
//    int i = 0, sum = 0;
//    while(i <= n) {
//        int j = 1;
//        while (j < 2*n) {
//            sum += niz[j];
//            j = j + j;
//        }
//        i++;
//    }
//    return sum;
//}

//  2.
//  Procijeniti složenost O() algoritma koji računa operaciju za niz brojeva dužine N. Algoritam provjerava da se nijedan broj u nizu ne ponavlja. Algoritam se može napisati na tri  načina:
//      a)Prolazimo kroz prvi niz i za svaki broj provjeravamo da se ne pojavljuje nigdje drugo u nizu.
//      b)Prolazimo kroz prvi niz i za svaki broj provjeravamo da se ne pojavljuje nigdje drugo u ostatku niza.
//      c)Sortiramo niz uzlazno. Zatim za svaki broj niza provjerimo da je različit od idućeg broja u nizu.
//      Složenost za svaki način izraziti u N. Možete pretpostaviti da se za sortiranje koristi mergesort.

//  a) O(N) = N * N = N^2
//  b) O(N) = N * log(N) = Nlog(N) --
//  c) O(N) = Nlog(N) + N  = (N * log(N))



//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će provjeriti da li je lista sortirana uzlazno. (25 bodova)

//bool funkcija(Node* lst){
//    Node* iduci = lst->next;
//    Node* trenutni = lst;
//    while(iduci != NULL){
//        if(trenutni->data > iduci->data){
//            return false;
//        }
//        trenutni = iduci;
//        iduci = iduci->next;
//    }
//    
//    return true;
//}

//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element na predzadnje mjesto ako lista nije prazna, ili na prvo mjesto ako je lista prazna. (35 bodova)

//void funkcija(Node* lst, int broj){
//    if(lst == NULL){
//        printf("Lista nema glavu");
//        return;
//    }
//    
//    if(lst->next == NULL){
//        Node* new = malloc(sizeof(Node));
//        new->data = broj;
//        new->next = NULL;
//        lst->next = new;
//        return;
//    }
//    
//    Node* current = lst->next;
//    while(current->next->next != NULL){
//        current = current->next;
//    }
//    Node* new = malloc(sizeof(Node));
//    new->next = current->next;
//    new->data = broj;
//    current->next = new;
//    
//}


//  T(n) = c1 + n * (c1 + 2 * log(2n)) = n * log(n)
//  O(n) = n * log(n)

int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i <= n) {
        int j = 1;
        while (j < 2*n) {
            sum += niz[j];
            j = j + j;
        }
        i++;
    }
    return sum;
}

//  2.
//  Procijeniti složenost O() algoritma koji računa operaciju za niz brojeva dužine N. Algoritam provjerava da se nijedan broj u nizu ne ponavlja. Algoritam se može napisati na tri  načina:
//      a)Prolazimo kroz prvi niz i za svaki broj provjeravamo da se ne pojavljuje nigdje drugo u nizu.
//      b)Prolazimo kroz prvi niz i za svaki broj provjeravamo da se ne pojavljuje nigdje drugo u ostatku niza.
//      c)Sortiramo niz uzlazno. Zatim za svaki broj niza provjerimo da je različit od idućeg broja u nizu.
//      Složenost za svaki način izraziti u N. Možete pretpostaviti da se za sortiranje koristi mergesort.


//  a)  O(N) = N * N = N^2
//  b)  O(N) = N * N = N^2
//  c)  O(N) = N * log(N) + N = N * log(N)


//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će provjeriti da li je lista sortirana uzlazno. (25 bodova)

int funkcija(Node* lst){
    if(lst == NULL){
        printf("Greska");
        return -1;
    }
    Node* current = lst->next;
    while (lst->next != NULL) {
        if(lst->data > lst->next->data){
            return 0;
        }
        lst = lst->next;
        current = lst->next;
    }
    return 1;
}


//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element na predzadnje mjesto ako lista nije prazna, ili na prvo mjesto ako je lista prazna. (35 bodova)

void funkcija(Node** lst, int broj){
    if((*lst) == NULL){
        Node* tmp = malloc(sizeof(Node));
        tmp->next = NULL;
        tmp->data = broj;
        (*lst) = tmp;
    } else {
        Node* current = (*lst);
        Node* prev = NULL;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        Node* tmp2 = malloc(sizeof(Node));
        tmp2->data = broj;
        tmp2->next = current;
        if(prev == NULL){
            tmp2->next = (*lst);
            (*lst) = tmp2;
        } else {
            prev->next = tmp2;
        }
    }
}
