
//  1.
//  T(n) = c1 + n/2 * (c2 + n/2) = n/2 * n/2 = n^2
//  O(n) = n^2

//int f(int *niz, int n) {
//    int i = 0, sum = 0;
//    while(i <= n / 2) {
//      sum += niz[j];
//      int j = 0;
//        while (j < i) {
//            sum += niz[j];
//            j++;
//        }
//        i++;
//    }
//    return sum;
//}

//  2.
//  Procijeniti vremensku složenost O() algoritma koji provjerava da li je prvi skupa podskup drugog i trećeg skupa (skupovi su predstavljeni kao nizovi brojeva). Dužina prvog niza je N, a preostala dva M. Algoritam se može napisati na dva načina:
//      a)Za svaki broj u prvom nizu se provjerava da li postoji u drugom i trećem nizu.
//      b)Quicksortom se sortiraju drugi i treći niz. Zatim se Za svaki broj u prvom nizu se provjerava da li postoji u drugom i              trećem nizu pomoću binarne pretrage.
//      c)Quicksortom sortiramo prvi niz, zatim za svaki broj u prvom nizu provjeravamo da li postoji u drugom i trećem nizu.
//          Složenost izraziti kroz dužine nizova N I M.

//      a) O(n) = (N * M) + (N * M) = N * M
//      b) O(n) = 2 * (M * log(M)) + 2 * (N * log(M)) = M * log(M) + N * log(M) = (M + N) * log(M)
//      c) O(n) = N * log(N) + 2 * (N * M) = N * log(N) + N * M


//  3.
//  Napisati funkciju koja prima dvije jednostruko vezane liste (svaki element sadrži broj) i vraća listu. Druga lista ima barem jedan element. Funkcija na kraj prve liste prebacuje prvi element druge liste. (25 bodova)

//Node* funkcija(Node* lst1, Node* lst2){
//    if(lst1->next == NULL){
//        printf("Greska");
//        return lst1;
//    }
//    Node* current1 = lst1->next;
//    Node* current2 = lst2->next;
//    while(current1->next != NULL){
//        current1 = current1->next;
//    }
//    current2->next = NULL;
//    current1->next = current2;
//    return lst1;
//}

//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i dva indeksa. Funkcija će obrisati sve elemente liste između ta dva indeksa. Indeksi su legalni i prvi je manji od drugog. (35 bodova)

//void funkcija(Node** lst, int indeks1, int indeks2){
//    if((*lst) == NULL){
//        printf("Error");
//        return;
//    }
//    Node* current = (*lst);
//    Node* zapamti = NULL;
//    for(int i = 0; i < indeks1; i++){
//        zapamti = current;
//        current = current->next;
//    }
//    Node* tmp = NULL;
//    for(int j = indeks1; j < indeks2; j++){
//        tmp = current;
//        current = current->next;
//        free(tmp);
//    }
//    zapamti->next = current;
//    
//    (*lst) = zapamti;
//}
