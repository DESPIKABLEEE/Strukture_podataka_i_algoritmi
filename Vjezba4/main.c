#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "funkcije.h"

//presjek(skupA, skupB) – funkcija računa dužinu presjeka dva skupa
//ne broji se alociranje i oslobadanje, za mjerenje koristi clock()
int presjek(int* niz1, int* niz2, int n){
    int i,j,brojac = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(niz1[i] == niz2[j]){
                brojac++;
                break;
            }
        }
    }
    return brojac;
}

//presjek_jedan_sortiran(skupA, skupB) – funkcija računa dužinu presjeka dva skupa, gdje je skupB sortirani niz tako da se funkcija oslanja na upotrebu upotrebom bsearch() funkcije (iz stdlib.h)

//key − It represents pointer to the element that need to be search.
//base − It represents pointer to the first element of the array.
//nitems − It represents number of element in the array.
//size − It represents size of each element in the array.
//compare − It represent a function that compares two elements.

//int compare(const void * a, const void * b) {
//   return ( *(int*)a - *(int*)b );
//}
int presjek_jedan_sortiran(int* niz1, int* niz2, int n){
    int i,brojac = 0;
    for(i = 0; i < n; i++){
        if(bsearch(&niz1[i], niz2, n, sizeof(int), cmp)){
            brojac++;
        }
    }
    return brojac;
}

//presjek_oba_sortirana(skupA, skupB) – funkcija računa dužinu presjeka dva skupa, gdje je su oba skupa sortirana i moguće je samo ići naprijed sa indeksima po oba skupa
int presjek_oba_sortirana(int* niz1, int* niz2, int n){
    int i = 0, j = 0, brojac = 0;
    while((i < n) && (j < n)){
        if(niz1[i] == niz2[j]){
            brojac++;
            i++;
            j++;
        } else if(niz1[i] < niz2[j]){
            i++;
        } else if(niz2[j] < niz1[i]){
            j++;
        }
    }
    return brojac;
}

//presjek_po_indeksima(skupA, skupB) – funkcija kreira dva nova niza (indexA i indexB) i ispunjava ih sa 0. Dužine nizova su određene najvećim brojem u skupA i skupB. Zatim se za svaki broj iz skupA upiše 1 na njegov indeks u njegovom „indeks“ nizu indexA. Isto se napravi i za skupB. Zatim se broje samo brojevi koji se pojavljuju u oba niza na istom indeksu odnosno imaju 1 u indexA i indexB nizovima.
int presjek_po_indeksima(int* niz1, int* niz2, int n){
    int i, brojac = 0;
    int max1 = niz1[0];
    int max2 = niz2[0];
    int max;
    for(i = 1; i < n; i++){
        if(max1 < niz1[i])
            max1 = niz1[i];
        if(max2 < niz2[i])
            max2 = niz2[i];
    }
    if(max1 < max2)
        max = max2;
    else
        max = max1;
    int* index1 = calloc((1 + max), sizeof(int));
    int* index2 = calloc((1 + max), sizeof(int));
    
    for(i = 0; i < n; i++){
        index1[niz1[i]] = 1;
        index2[niz2[i]] = 1;
    }
    for(i = 0; i < max; i++){
        if(index1[i] && index2[i]){
            brojac++;
        }
    }
    
    free(index1);
    free(index2);
    return brojac;
}

int main(void){
    //clock_t stime = clock();
    //int n = 5;
    for(int n = 10000; n < 100000; n += 10000){
        int rezultat = 0;
        int* skupA = generiraj(n);
        int* skupB = generiraj(n);
        shuffle(skupA, n);
        shuffle(skupB, n);
        
        clock_t start,end;
        double vrijeme;
        //printf(" %d \n",n);
        printf("Zadatak 1 : presjek skupova : \n");
        start = clock();
        rezultat = presjek(skupA, skupB, n);
        end = clock();
        vrijeme = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Brojac presjeka je %d, a vrijeme je : %.4f\n",rezultat,vrijeme);
        printf("\n\n");
        
        printf("Zadatak 2 : presjek_jedan_sortirani : ");
        qsort(skupB, n, sizeof(int), cmp);
        start = clock();
        rezultat = presjek_jedan_sortiran(skupA, skupB, n);
        end = clock();
        vrijeme = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Brojac presjek_jedan_sortirani je : %d, a vrijeme je %.4f\n",rezultat,vrijeme);
        printf("\n\n");
        
        printf("Zadatak 3 : presjek_oba_sortirana : ");
        qsort(skupA, n, sizeof(int), cmp);
        //printf("Test");
        start = clock();
        rezultat = presjek_oba_sortirana(skupA, skupB, n);
        end = clock();
        vrijeme = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Brojac presjek_oba_sortirana je : %d, a vrijeme je %.4f\n",rezultat,vrijeme);
        printf("\n\n");
        
        printf("Zadatak 4 : presjek_po_indeksima : ");
        shuffle(skupA, n);
        shuffle(skupB, n);
        start = clock();
        rezultat = presjek_po_indeksima(skupA, skupB, n);
        end = clock();
        vrijeme = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Brojac presjek_po_indeksima je : %d, a vrijeme je %.4f\n",rezultat,vrijeme);
        printf("\n\n");
        
        
        printf("Kraj");
        free(skupA);
        free(skupB);
    }
    return 0;
}

