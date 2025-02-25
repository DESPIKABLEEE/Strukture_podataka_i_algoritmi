//  1.
//  t(n) = c1 + n + n = n + n = n
//  o(n) = n

//int f(int *niz, int n) {
//    int i = n, sum = 0;
//    while(i > 0) {
//        sum += niz[i/2];
//        i--;
//    }
//    while(i < n) {
//        sum += niz[i/2];
//        i++;
//    }
//    return sum;
//}


//  2.
//  Procijeniti klasu složenosti O() algoritma koji računa razliku dva skupa (dva niza dužine N i M sa svim različitim brojevima). Razlika skupova je niz brojeva koji sadrži sve brojeve iz prvog niza koji se ne nalazi u drugom nizu. Algoritam se može napisati na tri načina:
//      a)    Nijedan niz nije sortiran. Svaki broj u prvom nizu uspoređujemo sa svim brojevima drugog niza.
//      b)    Drugi niz je sortiran. Svaki broj u prvom nizu tražimo među brojevima drugog niza upotrebom binarne pretrage.
//      c)    Oba niza su sortirana. Postavimo indeks j na početak drugog niza. Za svaki broj u prvom nizu provjeravamo redom sve brojeve u drugom nizu koji su manji ili jednaki od traženog broja uvećavajući indeks j. Indeks j se nikada ne vraća na početak drugog niza.

//      a)  O(N) = N * M
//      b)  O(N) = M * log(M) + N * log(M) = (N + M) * log(M)
//      c)  O(N) = N * log(N) + M * log(M) + N + M = N * log(N) + M * log(M)


//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija provjerava da li je lista sadrži višestruke brojeve. Funkcija vraća 1 ako su svi elementi jedinstveni ili 0 ako nisu. Kolika je složenost funkcije O()? (25 bodova)

//int funkcija(Node* lst){
//    if(lst == NULL){
//        printf("Greska");
//        return -1;
//    }
//    Node* current = lst;
//    while (current->next != NULL) {
//        Node* tmp = current->next;
//        while (tmp != NULL) {
//            if(tmp->data == current->data){
//                return 0;
//            }
//            tmp = tmp->next;
//        }
//        current = current->next;
//    }
//    return 1;
//}

//  4.
//  Napisati funkciju koja dvije liste. Funkcija na kraj prve liste dodaje kopije svih elemenata iz druge liste. Funkcija vraća izmijenjenu listu. Kolika je složenost funkcije O()? (35 bodova)

//Node* funkcija(Node* lst1, Node* lst2){
//    if(lst1 == NULL || lst2 == NULL){
//        printf("Greska");
//        return NULL;
//    }
//    Node* current1 = lst1;
//    Node* current2 = lst2;
//    while (current1->next != NULL) {
//        current1 = current1->next;
//    }
//    while(current2 != NULL){
//        Node* tmp = malloc(sizeof(Node));
//        tmp->data = current2->data;
//        current1->next = tmp;
//        tmp->next = NULL;
//        current1 = tmp;
//        current2 = current2->next;
//    }
//    return lst1;
//}





// T(n) = c1 + n + n = n
// O(n) = n

int f(int *niz, int n) {
    int i = n, sum = 0;
    while(i > 0) {
        sum += niz[i/2];
        i--;
    }
    while(i < n) {
        sum += niz[i/2];
        i++;
    }
    return sum;
}

//  2.
//  Procijeniti klasu složenosti O() algoritma koji računa razliku dva skupa (dva niza dužine N i M sa svim različitim brojevima). Razlika skupova je niz brojeva koji sadrži sve brojeve iz prvog niza koji se ne nalazi u drugom nizu. Algoritam se može napisati na tri načina:
//      a)    Nijedan niz nije sortiran. Svaki broj u prvom nizu uspoređujemo sa svim brojevima drugog niza.
//      b)    Drugi niz je sortiran. Svaki broj u prvom nizu tražimo među brojevima drugog niza upotrebom binarne pretrage.
//      c)    Oba niza su sortirana. Postavimo indeks j na početak drugog niza. Za svaki broj u prvom nizu provjeravamo redom sve brojeve u drugom nizu koji su manji ili jednaki od traženog broja uvećavajući indeks j. Indeks j se nikada ne vraća na početak drugog niza.

//  a) O(N) = N * M
//  b) O(N) = M * log(M) + N * log(M) = (N + M) * log(M)
//  c) O(N) = N * log(N) + M * log(M) + N + M = N * log(N) + M * log(M)


//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija provjerava da li je lista sadrži višestruke brojeve. Funkcija vraća 1 ako su svi elementi jedinstveni ili 0 ako nisu. Kolika je složenost funkcije O()? (25 bodova)

int funkcija(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna")
        return -1;
    }
    while(lst->next != NULL){
        Node* tmp = lst->next;
        while(tmp != NULL){
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
//  Napisati funkciju koja dvije liste. Funkcija na kraj prve liste dodaje kopije svih elemenata iz druge liste. Funkcija vraća izmijenjenu listu. Kolika je složenost funkcije O()? (35 bodova)

Node* funkcija(Node* lst1, Node* lst2){
    if(lst1 == NULL || lst2 == NULL){
        printf("Greska");
        return NULL;
    }
    Node* current1 = lst;
    Node* current2 = lst2;
    while (current1->next != NULL) {
        current1 = current1->next;
    }
    
    while (current2 != NULL) {
        Node* tmp = malloc(sizeof(Node));
        tmp->data = current2->data;
        current2 = current2->next;
        tmp->next = NULL;
        current1->next = tmp;
        current1 = tmp;
    }
    return lst1;
}
