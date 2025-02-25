//  1.

//  T(N) = c1 + n + log(n) = n
//  O(N) = n

//int f(int *niz, int n) {
//    int i = n, sum = 0;
//    while(i > 0) {
//        sum += niz[i/2];
//        i--;
//    }
//    while(i < n) {
//        sum += niz[i/2];
//        i*=2;
//    }
//    return sum;
//}


//  2.
//  Procijeniti klasu složenosti O() algoritma koji računa razliku dva skupa (dva niza jednake dužine N, sa svim različitim brojevima). Razlika skupova je niz brojeva koji sadrži sve brojeve iz prvog niza koji se ne nalazi u drugom nizu. Algoritam se može napisati na tri načina:
//      a)    Nijedan niz nije sortiran. Svaki broj u prvom nizu uspoređujemo sa svim brojevima drugog niza.
//      b)    Drugi niz je sortiran. Svaki broj u prvom nizu tražimo među brojevima drugog niza upotrebom binarne pretrage.
//      c)    Oba niza su sortirana. Postavimo indeks j na početak drugog niza. Za svaki broj u prvom nizu provjeravamo redom sve brojeve u drugom nizu koji su manji ili jednaki od traženog broja uvećavajući indeks j. Indeks j se nikada ne vraća na početak drugog niza.

//      a)  O(N) = N * N = N^2
//      b)  O(N) = N * log(N*log(N)) = N * log(N) // N * log(N) + log(N)
//      b)  O(N) = N * log(N) + N * log(N) + N * N = N^2


//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija provjerava da li je lista sadrži sve brojeve od 1 do 10. Funkcija vraća 1 ako su svi brojevi u listi ili 0 ako nisu. Kolika je složenost funkcije O()? (25 bodova)

//int funkcija(Node* lst){
//    if(lst == NULL){
//        printf("Lista je prazna");
//        return 0;
//    }
//    int niz[10] = {0}
//    Node* current = lst;
//    
//    while(current != NULL){
//        if(current->data > 0 && current->data <= 10){
//            niz[current->data] = 1;
//        }
//        current = current->next;
//    }
//    for(int i = 0; i < 10; i++){
//        if(niz[i] == 0){
//            return 0;
//        }
//    }
//    
//    return 1;
//}

//  4.
//  Napisati funkciju koja prima dvije liste. Funkcija na početak prve liste dodaje kopije svih elemenata iz druge liste. Funkcija vraća izmijenjenu listu. Kolika je složenost funkcije O()? (35 bodova)

//Node* funkcija(Node* lst1, Node* lst2){
//    
//    Node* current = lst1;
//    Node* elementDruge = lst2;
//    Node* tmp = NULL;
//    while(elementDruge != NULL){
//        tmp = elementDruge;
//        elementDruge = elementDruge->next;
//        tmp->next = current;
//        current = tmp;
//    }
//    
//    lst1 = current;
//    return lst1;
//}


//  T(n) = c1 + n + log(n) = n
//  O(n) = n


int f(int *niz, int n) {
    int i = n, sum = 0;
    while(i > 0) {
        sum += niz[i/2];
        i--;
    }
    while(i < n) {
        sum += niz[i/2];
        i*=2;
    }
    return sum;
}


//  2.
//  Procijeniti klasu složenosti O() algoritma koji računa razliku dva skupa (dva niza jednake dužine N, sa svim različitim brojevima). Razlika skupova je niz brojeva koji sadrži sve brojeve iz prvog niza koji se ne nalazi u drugom nizu. Algoritam se može napisati na tri načina:
//      a)    Nijedan niz nije sortiran. Svaki broj u prvom nizu uspoređujemo sa svim brojevima drugog niza.
//      b)    Drugi niz je sortiran. Svaki broj u prvom nizu tražimo među brojevima drugog niza upotrebom binarne pretrage.
//      c)    Oba niza su sortirana. Postavimo indeks j na početak drugog niza. Za svaki broj u prvom nizu provjeravamo redom sve brojeve u drugom nizu koji su manji ili jednaki od traženog broja uvećavajući indeks j. Indeks j se nikada ne vraća na početak drugog niza. ******

//  a) O(N) = N * N = N^2
//  b) O(N) = N * log(N) + N * log(N) = N * log(N)
//  c) O(N) = 2N * log(2N) + N + N = N * log(N)


//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija provjerava da li je lista sadrži sve brojeve od 1 do 10. Funkcija vraća 1 ako su svi brojevi u listi ili 0 ako nisu. Kolika je složenost funkcije O()? (25 bodova)

int funkcija(Node* lst){
    if(lst == NULL){
        printf("Greska");
        return -1;
    }
    int niz[11] = {0};
    while (lst != NULL) {
        if(lst->data > 0 && lst->data <= 10){
            niz[lst->data] = 1;
        }
        lst = lst->next
    }
    for(int i = 1; i < 11; i++){
        if(niz[i] == 0){
            return 0;
        }
    }
    return 1;
}


//  4.
//  Napisati funkciju koja prima dvije liste. Funkcija na početak prve liste dodaje kopije svih elemenata iz druge liste. Funkcija vraća izmijenjenu listu. Kolika je složenost funkcije O()? (35 bodova)

Node* funkcija(Node* lst1, Node* lst2){
    if(lst1 == NULL || lst2 == NULL){
        printf("Greska");
        return NULL;
    }
    while(lst2 != NULL){
        Node* tmp = malloc(sizeof(Node));
        tmp->data = lst2->data;
        lst2 = lst2->next;
        tmp->next = lst1;
        lst1 = tmp;
    }
    return lst1;
}

