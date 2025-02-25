

//  1.

//  T(N) = c1 + c2 + 2 * n + n * n = n + n * n = n^2
//  O(N) = n^2
//int f(int *niz, int n) {
//    int j = 1;
//    int i = 0, sum = 0;
//    while (j < 2 * n) {
//        sum += niz[j];
//        j++;
//    }
//    while(i < n * n) {
//        sum += niz[j];
//        i++;
//    }
//    return sum;
//}


//  2.
//  Procijeniti složenost O() algoritma koji iz neke datoteke čita elemente (brojeve) u jednostruko vezanu listu. Broj pročitanih elemenata je N i ne koriste se nikakvi posebni pokazivači (npr. na kraj liste). Algoritam se može napisati na dva načina:
//      a)    Svaki novi element se dodaje na početak liste.
//      b)    Svaki novi element se dodaje na kraj liste. ****
//  Složenost izraziti u N.

//      a)  O(N) = 1
//      b)  O(N) = N

//  3.
//  Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i provjerava da li se svi elementi sa parnim brojem nalaze između dva elementa sa neparnim brojem. Prvi i zadnji element sadrži neparni broj, a primljena lista ima barem 3 elementa. Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova) ****

//int f(Node* lst){
//    if(lst == NULL){
//        printf("Lista je prazna\n");
//        return 0;
//    }
//    Node* current = lst;
//    Node* prviNeparni = NULL;
//    Node* drugiNeparni = NULL;
//    Node* parni = NULL;
//    int parniPostoji = 0;
//    int neparniPostoji = 0;
//    
//    while(current->next != NULL){
//        if(current->broj % 2 != 0 && current->next->broj % 2 == 0)
//        
//        current = current->next;
//    }
//    return 1;
//}

//  4.
//  Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element sa tim brojem prije najvećeg broja u listi. (35 bodova)

//void funkcija(Node* lst, int dodatni){
//    if(lst == NULL){
//        printf("Greska");
//        return;
//    }
//    
//    Node* current = lst->next;
//    Node* prev = NULL;
//    Node* najvecinode = current;
//    int najvecibroj = current->broj;
//    while(current->next != NULL){
//        if(najvecibroj < current->next->broj){
//            prev = current;
//            najvecibroj = current->next->broj;
//            najvecinode = current->next;
//        }
//        current = current->next;
//    }
//    Node* novi = malloc(sizeof(Node));
//    novi->broj = dodatni;
//    novi->next = najvecinode;
//    if (lst->next == najvecinode){
//        lst->next = novi;
//    } else {
//        prev->next = novi;
//    }
//}
