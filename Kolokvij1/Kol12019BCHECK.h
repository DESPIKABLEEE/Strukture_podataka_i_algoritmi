//  1.

//  T(N) = c1 + 2 * n + c2 + n * n = n + n * n
//  O(N) = N^2
//int f(int *niz, int n) {
//    int i = 0, sum = 0;
//    while(i < 2 * n) {
//        sum += niz[i];
//        i++;
//    }
//    int j = 0;
//    while (j < n * n) {
//        sum += niz[j];
//        j++;
//    }
//  return sum;
//}

//  2.
//  Procijeniti složenost O() algoritma koji računa operaciju za jedan skup i još N skupova dužine. Prvi skup je niz dužine M, a ostalih N skupova su nizovi dužine K. Algoritam iz prvog skupa ispisuje sve elemente koji se pojavljuju u ostalih N skupova. Algoritam se može napisati na dva načina:
//      a)    Nijedan niz nije sortiran. Prolazimo kroz prvi niz i za svaki broj provjeravamo da se pojavljuje u N preostalih nizova.
//      b)    Sortiramo N nizova. Zatim prolazimo kroz prvi niz i za svaki broj provjeravamo da se pojavljuje u N preostalih nizova binarnom pretragom.
//      Složenost izraziti u N, M i K. Možete pretpostaviti da se za sortiranje u (b) koristi quicksort.

//      a) O(N) = N * (M * K)
//      b) O(N) = N * (K * log(K)) + M * (N * log(K)) = N * log(K) * (K + M) = Nlog(K)


//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i jedan broj. Funkcija će ispisati sve elemente liste veće od tog broja. (25 bodova)

//void f(Node* lst, int broj){
//    if(lst == NULL){
//        printf("Greska");
//        return;
//    }
//    Node* current = lst;
//    while(current != NULL){
//        if(broj < current->data){
//            printf("%d ", current->data);
//        }
//        current = current->next;
//    }
//}


//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj i svi su različiti) i jedan dodatni broj. Funkcija će izbrisati element sa tim brojem. (35 bodova)

//void f(Node* lst, int broj){
//    if(lst == NULL){
//        printf("Greska\n");
//        return;
//    }
//    Node* tmp = NULL;
//    Node* current = lst->next;
//    Node* prev = lst;
//    while(current != NULL){
//        if(current->data == broj){
//            tmp = current;
//            current = current->next;
//            prev->next = current
//            free(tmp);
//            
//        } else {
//            prev = current;
//            current = current->next;
//        }
//    }
//    if (lst->data == broj) {
//        tmp = lst;
//        lst = lst->next;
//        free(tmp);
//    }
//}







//  T(n) = c1 + 2 * n + n^2 = n + n^2
//  O(n) = n^2

int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i < 2 * n) {
        sum += niz[i];
        i++;
    }
    int j = 0;
    while (j < n * n) {
        sum += niz[j];
        j++;
    }
  return sum;
}

//  2.
//  Procijeniti složenost O() algoritma koji računa operaciju za jedan skup i još N skupova dužine. Prvi skup je niz dužine M, a ostalih N skupova su nizovi dužine K. Algoritam iz prvog skupa ispisuje sve elemente koji se pojavljuju u ostalih N skupova. Algoritam se može napisati na dva načina:
//      a)    Nijedan niz nije sortiran. Prolazimo kroz prvi niz i za svaki broj provjeravamo da se pojavljuje u N preostalih nizova.
//      b)    Sortiramo N nizova. Zatim prolazimo kroz prvi niz i za svaki broj provjeravamo da se pojavljuje u N preostalih nizova binarnom pretragom.
//      Složenost izraziti u N, M i K. Možete pretpostaviti da se za sortiranje u (b) koristi quicksort.

//  a) O(N) = M * N * K
//  b) O(N) = N * (K * log(K)) + M * (N * log(K)) =


//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i jedan broj. Funkcija će ispisati sve elemente liste veće od tog broja. (25 bodova)

void funkcija(Node* lst, int broj){
    if(lst == NULL){
        printf("Greska");
        return;
    }
    while(lst != NULL){
        if(lst->data > broj){
            printf("%d ", lst->data);
        }
        lst = lst->next;
    }
}

//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj i svi su različiti) i jedan dodatni broj. Funkcija će izbrisati element sa tim brojem. (35 bodova)

void funkcija(Node** lst, int broj){
    if((*lst) == NULL){
        printf("Greska");
        return;
    }
    Node* current = (*lst)->next;
    Node* prev = (*lst);
    if(current->data == broj){
        Node* tmp1 = current;
        current = current->next;
        prev->next = current;
        free(tmp1);
    }
    while (current != NULL) {
        if(current->data == broj){
            Node* tmp = current;
            current = current->next;
            prev->next = current;
            free(tmp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}
