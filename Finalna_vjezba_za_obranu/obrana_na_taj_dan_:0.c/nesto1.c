#include <stdio.h>
#include <stdlib.h>

void remove_duplicates(int* niz, int* n) {
    int i,j;
    int k = 0;
    for(i = 0; i < *n; i++){
        for(j = 0; j < k; j++){
            if(niz[j] == niz[i]){
                break;
            }
        }
        if(j == k){
            niz[k++] = niz[i];
        }
    }
    *n = k;
}

int main() {
    int niz[] = {1, 2, 3, 3, 4, 5, 6, 1, 2};
    int n = sizeof(niz) / sizeof(niz[0]);

    printf("Originalni niz: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }
    printf("\n");

    remove_duplicates(niz, &n);

    printf("Niz bez duplikata: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }
    printf("\n");

    return 0;
}