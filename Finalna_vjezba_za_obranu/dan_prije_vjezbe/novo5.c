// 3. Traženje zajedničkih elemenata
// Zadatak: Napiši funkciju koja prima dva niza brojeva i pronalazi sve zajedničke elemente između njih. Funkcija vraća niz tih zajedničkih elemenata, bez duplikata.
#include <stdio.h>
#include <stdlib.h>

int* funkcija(int* prvi_niz,int* drugi_niz,int prva_duljina, int druga_duljina, int* n){
    int i,j,k;
    int postoji, brojac = 0;
    int* novi_niz = malloc(sizeof(int) * (prva_duljina + druga_duljina));
    for(i = 0; i < prva_duljina; i++){
        postoji = 0;
        for(j = 0; j < druga_duljina; j++){
            if(prvi_niz[i] == drugi_niz[j]){
                postoji = 1;
                break;
            }
        }
        if(postoji){
            for(k = 0; k < brojac; k++){
                if(novi_niz[k] == prvi_niz[i]){
                    postoji = 0;
                    break;
                }
            }
            if(postoji){
                novi_niz[brojac] = prvi_niz[i];
                brojac++;
            }
        }
    }
    novi_niz = realloc(novi_niz,sizeof(int) * brojac);
    *n = brojac;
    return novi_niz;

}

int main(){
    int niz1[] = {1, 2, 3, 4, 3, 6};
    int niz2[] = {3, 4, 5, 2, 3}; // 2,3,4,3
    int duljina1 = sizeof(niz1) / sizeof(niz1[0]);
    int duljina2 = sizeof(niz2) / sizeof(niz2[0]);
    int n;
    int* rez = funkcija(niz1,niz2,duljina1,duljina2,&n);
    int i;
    for(i = 0; i < n; i++){
        printf("%d ",rez[i]);
    }
    free(rez);
    return 0;
}