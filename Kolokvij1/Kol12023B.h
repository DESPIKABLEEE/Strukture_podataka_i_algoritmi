
//  1.
//  T(n) = c1 + n/2 * (c2 + n/2 * n/4) = n/2 * n/4 = n * n = n^2
//  O(n) = n^2

int f(int *niz, int n) {
    int i = 0, sum = 0; // c1
    while(i <= n / 2) { // n/2
        sum += niz[j];
        int j = 0; // c2
        while (j < n / 2) { // n/2
            sum += niz[j];
            j += 2; // n/2
        }
        i++;
    }
    return sum;
}

//  2.
//  Procijeniti složenost O() algoritma koji računa operaciju za dva niza brojeva dužine N i M. Algoritam provjerava da se nijedan broj prvog niza ne nalazi u drugom nizu. Algoritam se može napisati na tri načina:
//      a)    Za svaki broj u prvom nizu, traži se njegovo pojavljivanje u drugom nizu.
//      b)    Sortira se prvi niz i onda se za svaki broj u prvom nizu traži njegovo pojavljivanje u drugom nizu.
//      c)    Sortira se drugi niz i onda se za svaki broj u prvom nizu traži njegovo pojavljivanje u drugom nizu pomoću binarne pretrage.
//      Složenost za svaki način izraziti u N i M tako da se vidi kako se došlo do konačnog izraza. Možete pretpostaviti da se za             sortiranje koristi quicksort.

//      a) O() = N * M
//      b) O() = N * log(N) + N * M = N * (log(N) + M)
//      c) O() = M * log(M) + N * log(M) = (N + M) * log(M)


//  3.
//  Napisati funkciju koja prima dvije jednostruko vezane liste (svaki element sadrži broj) i vraća listu. Druga lista ima barem jedan element. Funkcija na početak prve liste prebacuje zadnji element druge liste. (25 bodova)

//Node* funkcija(Node* lst1, Node* lst2){
//    if(lst1 == NULL || lst2 == NULL){
//        printf("Greska");
//        return NULL;
//    }
//    Node* current = lst2;
//    Node* prev = NULL;
//    while(current->next != NULL){
//        prev = current;
//        current = current->next;
//    }
//    if(prev != NULL){
//        prev->next = NULL;
//    }
//    
//    current->next = lst1;
//    lst1 = current;
//    
//    return lst1;
//}


//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan indeks. Funkcija će dodati novi element na tom indeksu sa brojem 0. Ako indeks nije legalan (vanka je dužine liste), funkcija ne čini ništa . (35 bodova)

//void funkcija(Node* lst, int indeks){
//    if(lst == NULL || lst->next == NULL){
//        printf("Greska");
//        return;
//    }
//    Node* tmp = lst->next;
//    int i = 0;
//    while(tmp != NULL){
//        i++;
//        tmp = tmp->next;
//    }
//    if(indeks > i){
//        return;
//    }
//    
//    
//    Node* current = lst->next;
//    Node* prev = NULL;
//    for(int j = 0; j < indeks; j++){
//        prev = current;
//        current = current->next;
//    }
//    Node* new = malloc(sizeof(Node));
//    new->next = current;
//    prev->next = new;
//    new->broj = 0;
//    
//}
