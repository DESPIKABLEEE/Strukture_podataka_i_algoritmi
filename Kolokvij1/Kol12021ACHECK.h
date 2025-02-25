//  1.
//  T(n) = c1 + n^2 + n * 2 = n^2 * n = n^2
//  O(n) = n^2

//int f(int *niz, int n) {
//    int i = 0, sum = 0;
//    while(i < n * n) {
//        sum += niz[j];
//        i++;
//    }
//    int j = 1;
//    while (j < 2 * n) {
//        sum += niz[j];
//        j++;
//    }
//    return sum;
//}

//  2.
//  Procijeniti složenost O() algoritma koji iz neke datoteke čita elemente (brojeve) u nekakav niz. Za svaki pročitani element algoritam provjerava da li se element već nalazi u nizu. Broj pročitanih elemenata je N. Algoritam se može napisati na dva načina:
//      a)Niz nije sortiran i pri svakom čitanju se provjeravaju svi prethodno pročitani elementi.
//      b)Niz se drži sortiran i pri svakom čitanju se novi element dodaje na odgovarajuće mjesto (pa je to             mjesto potrebno osloboditi pomicanjem elemenata). Pri dodavanju se ujedno i provjeri da li se element        pojavljuje u nizu.
//  Složenost izraziti u N.

//  a) O(N) = N + N * N = N^2
//  b) O(N) = N + N * N

//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i provjerava da li su svi elementi u listi različiti. Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova)

//int funkcija(Node* lst){
//    Node* current = NULL;
//    Node* prev = lst;
//    while(prev != NULL){
//        current = prev->next;
//        while(current != NULL){
//            if(current->data == prev->data){
//                return 0;
//            }
//            current = current->next;
//        }
//        current = prev->next;
//    }
//    return 1;
//}

//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element sa tim brojem nakon najvećeg broja u listi. (35 bodova)

//void funkcija(Node* lst,int dodatni){
//    if(lst == NULL){
//        printf("Greska");
//        return;
//    }
//    Node* current = lst->next;
//    Node* pamti = NULL;
//    int najveci = 0;
//    while(current != NULL){
//        if(najveci < current->data){
//            najveci = current->data;
//            pamti = current;
//        }
//        current = current->next;
//    }
//    Node* new = malloc(sizeof(Node));
//    new->data = dodatni;
//    new->next = pamti->next;
//    pamti->next = new;
//    
//}


//  T(n) = c1 + n * n + c2 + 2 * n = n^2 + n = n^2
//  O(n) = n^2
int f(int *niz, int n) {
    int i = 0, sum = 0;
    while(i < n * n) {
        sum += niz[j];
        i++;
    }
    int j = 1;
    while (j < 2 * n) {
        sum += niz[j];
        j++;
    }
    return sum;
}

//  2.
//  Procijeniti složenost O() algoritma koji iz neke datoteke čita elemente (brojeve) u nekakav niz. Za svaki pročitani element algoritam provjerava da li se element već nalazi u nizu. Broj pročitanih elemenata je N. Algoritam se može napisati na dva načina:
//      a)Niz nije sortiran i pri svakom čitanju se provjeravaju svi prethodno pročitani elementi.
//      b)Niz se drži sortiran i pri svakom čitanju se novi element dodaje na odgovarajuće mjesto (pa je to             mjesto potrebno osloboditi pomicanjem elemenata). Pri dodavanju se ujedno i provjeri da li se element        pojavljuje u nizu.
//  Složenost izraziti u N.

//  a) O(N) = N * N = N^2
//  b) O(N) = N^2


//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i provjerava da li su svi elementi u listi različiti. Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova)

int funkcija(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna");
        return -1;
    }
    Node* tmp;
    while (lst != NULL) {
        tmp = lst->next;
        while (tmp != NULL) {
            if(tmp->data == lst->data){
                return 0;
            }
            tmp = tmp->next;
        }
        lst = lst->next;
    }
    return 1;
}



//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element sa tim brojem nakon najvećeg broja u listi. (35 bodova)

void funkcija(Node** lst, int dodaj){
    if((*lst) == NULL){
        printf("Lista je prazna");
        return;
    }
    Node* current = (*lst)->next;
    Node* prev = (*lst);
    Node* najveci = current;
    while (current != NULL) {
        if(najveci->data < current->data){
            najveci = current;
        }
        prev = current;
        current = current->next;
    }
    Node* tmp = malloc(sizeof(Node));
    tmp->data = dodaj;
    tmp->next = najveci->next;
    najveci->next = tmp;
}
