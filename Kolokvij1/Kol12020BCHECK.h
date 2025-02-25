//  1.

//  T(N) = c1 + n * (c2 + n) = n * n = n^2
//  O(N) = n^2

//int f(int *niz, int n) {
//    int i = 0, sum = 0;
//    while(i <= n) {
//        int j = 0;
//        while (j < i) {
//            sum += niz[j];
//            j++;
//        }
//        i++;
//    }
//    return sum;
//}


//  2.
//  Procijeniti složenost O() algoritma koji računa operaciju za dva niza brojeva dužine N. Algoritam spaja ta dva niza u novi sortirani niz. Algoritam se može napisati na dva  načina:
//      a)Kopiramo oba niza u novi niz i zatim sortiramo novi niz.
//      b)Sortiramo svaki niz zasebno i zatim sa merge algoritmom konstruiramo novi sortirani niz. N * log(N)
//      Složenost za svaki način izraziti u N. Možete pretpostaviti da se za sortiranje koristi quicksort. N * log(N)

//      a)  O(N) = 2 * (N * N) + 2N * log(2N) = Nlog(N)
//      b)  O(N) = 2 * (N * log(N)) + Nlog(N) = Nlog(N)


//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će provjeriti da li se ijedan broj u listi ponavlja. (25 bodova)

//int funkcija(Node* lst){
//    Node* current = lst;
//    Node* unutarnja = lst;
//    while(current->next != NULL){
//        unutarnja = current->next;
//        while(unutarnja != NULL){
//            if(unutarnja->data == current->data){
//                return 1;
//            }
//            unutarnja = unutarnja->next;
//        }
//        current = current->next;
//    }
//    
//    return 0;
//}

//  4.

//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj). Funkcija će izbrisati prva tri elementa iz liste ili samo ispisati grešku ako lista ima manje od tri elementa. (35 bodova)

//void funkcija(Node* lst){
//    if(lst->next == NULL || lst->next->next == NULL || lst->next->next->next == NULL){
//        printf("Lista nema 3 elementa");
//        return;
//    }
//    Node* current = lst->next;
//    lst->next = lst->next->next->next->next;
//    Node* tmp = NULL;
//    int i = 0;
//    while(current != NULL && i < 3){
//        tmp = current;
//        current = current->next;
//        free(tmp);
//        i++;
//    }
//    
//}











//  T(n) = c1 + n * (c2 + n) = n * n = n^2
//  O(n) = n^2

int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i <= n) {
        int j = 0;
        while (j < i) {
            sum += niz[j];
            j++;
        }
        i++;
    }
    return sum;
}


//  2.
//  Procijeniti složenost O() algoritma koji računa operaciju za dva niza brojeva dužine N. Algoritam spaja ta dva niza u novi sortirani niz. Algoritam se može napisati na dva  načina:
//      a)Kopiramo oba niza u novi niz i zatim sortiramo novi niz.
//      b)Sortiramo svaki niz zasebno i zatim sa merge algoritmom konstruiramo novi sortirani niz. N * log(N)
//      Složenost za svaki način izraziti u N. Možete pretpostaviti da se za sortiranje koristi quicksort. N * log(N)

//  a) O(N) = N + N + 2N * log(2N) = N * log(N)
//  b) O(N) = N * log(N) + N * log(N) + 2N * log(2N) = N * log(N)



//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će provjeriti da li se ijedan broj u listi ponavlja. (25 bodova)

int funckija(Node* lst){
    if(lst == NULL){
        printf("Greska");
        return -1;
    }
    Node* current = lst;
    Node* tmp = NULL;
    while (current != NULL) {
        tmp = current->next;
        while (tmp != NULL) {
            if(tmp->data == current->data){
                return 0;
            }
            tmp = tmp->next;
        }
        current = current->next;
    }
    return 1;
}


//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj). Funkcija će izbrisati prva tri elementa iz liste ili samo ispisati grešku ako lista ima manje od tri elementa. (35 bodova)

void funkcija(Node** lst){
    if((*lst) == NULL || (*lst)->next == NULL || (*lst)->next->next == NULL){
        printf("Lista nije legalna");
        return;
    }
    Node* tmp = (*lst);
    (*lst) = (*lst)->next->next->next;
    
    for(int i = 0; i < 3; i++){
        Node* brisi = tmp;
        tmp = tmp->next;
        free(brisi);
    }
    
}
