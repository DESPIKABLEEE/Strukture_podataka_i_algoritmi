//  1.

//  T(n) = c1 + n = n
//  O(n) = n

//int f(int *niz, int n) {
//    int i = 0, sum = 0;
//    while(i < n) {
//        sum += niz[i];
//        n--;
//    }
//    return sum;
//}


//  2.
//  Procijeniti složenost O() algoritma koji računa operaciju za skup (niz) i niz brojeva, dužine N i M. Algoritam zbraja sve elemente iz prvog niza koji su manji od svih brojeva u drugom nizu. Algoritam se može napisati na tri načina:
//      a)    Nijedan niz nije sortiran. Prolazimo kroz prvi niz i za svaki broj provjeravamo da je manji od svih elemenata u drugom nizu.
//      b)    Sortiramo drugi niz uzlazno i zatim zbrajamo sve brojeve koji su manji od prvog broja u drugom nizu.
//      c)    Sortiramo oba niza uzlazno. Zatim zbrajamo sve brojeve prvog niza dok ne dođemo do broja koji je veći ili jednak od prvog broja u drugom nizu.
//  Složenost izraziti u N i M. Možete pretpostaviti da se za sortiranje u koristi quicksort.

//      a)  O(N) = N * M
//      b)  O(N) = M * log(M) + N * 1 = Mlog(M)
//      c)  O(N) = N * log(N) + M * log(M) + N + M


//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će izbrojati koliko je brojeva liste veće od prethodnog broja u listi. (25 bodova)

//int funkcija(Node* lst){
//    if(lst == NULL){
//        printf("Lista je prazna");
//        return 0;
//    }
//    int brojac = 0;
//    Node* current = lst->next;
//    Node* prev = lst;
//    while (current != NULL) {
//        if(current->data > prev->data){
//            brojac++;
//        }
//        prev = current;
//        current = current->next;
//    }
//    return brojac;
//}


//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element sa tim brojem ispred prvog broja u listi koji je veći od 100 (ako takav postoji). (35 bodova)

//void funkcija(Node* lst, int dodatni){
//    if(lst == NULL){
//        printf("Greska");
//        return;
//    }
//    Node* current = lst;
//    if(current->data > 100){
//        Node* novi = malloc(sizeof(Node));
//        novi->next = lst;
//        novi->data = current;
//        lst = novi;
//    }
//    while(current->next != NULL){
//        if(current->next->data > 100){
//            Node* novi = malloc(sizeof(Node));
//            novi->next = current->next;
//            novi->data = dodatni;
//            current->next = novi;
//            return;
//        } else {
//            current = current->next;
//        }
//    }
//}



//  T(N) = c1 + n = n
//  O(N) = n
int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i < n) {
        sum += niz[i];
        n--;
    }
    return sum;
}


//  2.
//  Procijeniti složenost O() algoritma koji računa operaciju za skup (niz) i niz brojeva, dužine N i M. Algoritam zbraja sve elemente iz prvog niza koji su manji od svih brojeva u drugom nizu. Algoritam se može napisati na tri načina:
//      a)    Nijedan niz nije sortiran. Prolazimo kroz prvi niz i za svaki broj provjeravamo da je manji od svih elemenata u drugom nizu.
//      b)    Sortiramo drugi niz uzlazno i zatim zbrajamo sve brojeve koji su manji od prvog broja u drugom nizu.
//      c)    Sortiramo oba niza uzlazno. Zatim zbrajamo sve brojeve prvog niza dok ne dođemo do broja koji je veći ili jednak od prvog broja u drugom nizu.
//  Složenost izraziti u N i M. Možete pretpostaviti da se za sortiranje u koristi quicksort.

//  a)  O(N) = N * M
//  b)  O(N) = M * log(M) + N = M * log(M)
//  c)  O(N) = N * log(N) + M * log(M) + N = N * log(N) + M * log(M)


//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će izbrojati koliko je brojeva liste veće od prethodnog broja u listi. (25 bodova)

void funkcija(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna");
        return;
    }
    int brojac = 0;
    Node* current = lst->next;
    int prethodni = lst->data;
    while(current != NULL){
        if(current->data > prethodni){
            brojac++;
        }
        prethodni = current->data;
        current = current->next;
    }
    
    printf("%d",brojac);
}


//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element sa tim brojem ispred prvog broja u listi koji je veći od 100 (ako takav postoji). (35 bodova)

void funkcija(Node* lst, int dodatni){
    if(lst == NULL){
        printf("Lista je prazna");
        return;
    }
    if(lst->data > 100){
        Node* tmp = malloc(sizeof(Node));
        tmp->next = lst;
        tmp->data = dodatni;
        lst = tmp;
        return;
    }
    while (lst->next != NULL) {
        if(lst->next->data > 100){
            Node* tmp = malloc(sizeof(Node));
            tmp->next = lst->next;
            tmp->data = dodatni;
            lst->next = tmp;
            return;
        }
        lst = lst->next;
    }
}

