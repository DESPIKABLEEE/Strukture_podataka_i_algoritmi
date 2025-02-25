//  1.

//  T(N) = c1 + 2n * (c2 + n/2) = n * n = n^2
//  O(N) = n^2

//int f(int *niz, int n) {
//    int i = 0, sum = 0;
//    while(i < 2 * n) {
//        int j = 0;
//        while (j < n / 2) {
//            sum += niz[j];
//            j++;
//        }
//        i++;
//    }
//    return sum;
//}


//  2.
//  Procijeniti složenost O() algoritma koji računa operaciju za 3 skupa (3 niza brojeva) dužine N, M i K. Algoritam kreira novi skup tako da uzima sve element iz prvog skupa (dužine N) koji se su veći od svih elemenata u drugom skupu (dužine M), ali i manji od svih elemenata u trećem skupu (dužine K). Algoritam se može napisati na dva načina:
//      a)    Nijedan niz nije sortiran. Prolazimo kroz prvi niz i za svaki broj provjerimo da li postoji veći broj u drugom ili manji broj u trećem nizu.
//      b)    Pronađemo najveći i najmanji broj u drugom i trećem nizu. Nakon toga iz prvog niza uzmemo sve brojeve veće od najvećeg iz drugog niza i manje od najmanjeg iz trećeg niza.
//      c)    Sortiramo silazno drugi niz i uzlazno treći niz. Nakon toga iz prvog niza uzmemo sve brojeve veće od prvog broja drugog niza i manje od prvog broja trećeg niza.
//      Složenost izraziti u N, M i K. Možete pretpostaviti da će pretrage u (a) proći pola niza, a da se za sortiranje u (b) koristi quicksort. ****

//      a) O() = N * M * K
//      b) O() = M + K + N = N + M + K
//      c) O() = Mlog(M) + Klog(K) + N * (Mlog(M) + Klog(K))


//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će između svaka dva parna susjedna broja dodati novi element sa brojem 0. Kolika je složenost funkcije O()? (35 bodova)

//void funkcija(Node* lst){
//    if(lst == NULL || lst->next == NULL){
//        printf("Glava je null ili lista ne postoji");
//        return;
//    }
//    Node* current = lst->next;
//    while(current->next != NULL){
//        if(current->data % 2 == 0 && current->next->data % 2 == 0){
//            Node* novi = malloc(sizeof(Node));
//            novi->data = 0;
//            novi->next = current->next;
//            current->next = novi;
//            current = novi;
//        }
//        current = current->next;
//    }
//    
//}


//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija vraća pokazivač na zadnji element u listi koji je veći od dodatnog broja ili NULL ako se takav broj ne nalazi u listi. Kolika je složenost funkcije O()? (25 bodova)

//Node* funkcija(Node* lst, int dodatni){
//    if(lst == NULL){
//        printf("Greska");
//        return NULL;
//    }
//    Node* current = lst;
//    Node* tmp = lst;
//    int postoji = 0;
//    while(current != NULL){
//        if(current->data > dodatni){
//            postoji = 1;
//            tmp = current;
//        }
//        current = current->next;
//    }
//    if(postoji == 0){
//        return NULL;
//    }
//    return tmp;
//}



//  T(n) = c1 + 2 * n * (c2 + n/2) = n * n = n^2
//  O(n) = n^2

int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i < 2 * n) {
        int j = 0;
        while (j < n / 2) {
            sum += niz[j];
            j++;
        }
        i++;
    }
    return sum;
}


//  2.
//  Procijeniti složenost O() algoritma koji računa operaciju za 3 skupa (3 niza brojeva) dužine N, M i K. Algoritam kreira novi skup tako da uzima sve element iz prvog skupa (dužine N) koji se su veći od svih elemenata u drugom skupu (dužine M), ali i manji od svih elemenata u trećem skupu (dužine K). Algoritam se može napisati na dva načina:
//      a)    Nijedan niz nije sortiran. Prolazimo kroz prvi niz i za svaki broj provjerimo da li postoji veći broj u drugom ili manji broj u trećem nizu.
//      b)    Pronađemo najveći i najmanji broj u drugom i trećem nizu. Nakon toga iz prvog niza uzmemo sve brojeve veće od najvećeg iz drugog niza i manje od najmanjeg iz trećeg niza.
//      c)    Sortiramo silazno drugi niz i uzlazno treći niz. Nakon toga iz prvog niza uzmemo sve brojeve veće od prvog broja drugog niza i manje od prvog broja trećeg niza.
//      Složenost izraziti u N, M i K. Možete pretpostaviti da će pretrage u (a) proći pola niza, a da se za sortiranje u (b) koristi quicksort.

//  a) O(N) = N * M + N * K
//  b) O(N) = M + K + K
//  c) O(N) = M * log(M) + K * log(K) + N


//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će između svaka dva parna susjedna broja dodati novi element sa brojem 0. Kolika je složenost funkcije O()? (35 bodova)

void funkcija(Node* lst){
    if(lst == NULL){
        printf("Greska");
        return;
    }
    Node* current = lst->next;
    Node* prev = lst;
    while(current != NULL){
        if(prev->data % 2 == 0 && current->data % 2 == 0){
            Node* novi = malloc(sizeof(Node));
            novi->next = current;
            prev->next = novi;
            novi->data = 0;
            prev = novi;
        }
        current = prev;
        current = current->next;
    }
}



//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija vraća pokazivač na zadnji element u listi koji je veći od dodatnog broja ili NULL ako se takav broj ne nalazi u listi. Kolika je složenost funkcije O()? (25 bodova)

Node* funkcija(Node* lst, int dodatniBroj){
    if(lst == NULL){
        printf("Lista je prazna");
        return NULL;
    }
    Node* pamti = NULL;
    while (lst != NULL) {
        if(lst->data > dodatniBroj){
            pamti = lst;
        }
        lst = lst->next;
    }
    return pamti;
}
