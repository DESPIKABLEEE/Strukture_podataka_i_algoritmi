#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#include <time.h>

// pomocne funkcije
int* generiraj(int n) {
    int *niz = (int*)malloc(sizeof(int) * n);
    niz[0] = rand() % 5;
    for (int i = 1; i < n; i++) {
        niz[i] = niz[i - 1] + rand() % 5;
    }
    return niz;
}

void shuffle(int *niz, int n) {
    for (int i = 0; i < n; i++) {
        int k1 = abs(rand()) % n;
        int tmp = niz[i];
        niz[i] = niz[k1];
        niz[k1] = tmp;
    }
}

void print(int *niz, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }
    printf("\n");
}

int cmp(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);
}

// selection sort
void selectionsort(int *niz, int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        int j, tmp, maxi = i;
        for (j = i + 1; j < n; j++) {
            if (niz[j] < niz[maxi])
                maxi = j;
        }

        tmp = niz[maxi];
        niz[maxi] = niz[i];
        niz[i] = tmp;
    }
}

// insertion sort
void insertionsort(int *niz, int n) {
    int i;
    for (i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && niz[j - 1] > niz[j]) {
            int tmp;
            tmp = niz[j-1];
            niz[j - 1] = niz[j];
            niz[j] = tmp;
            j--;
        }
    }
}

// quick sort
int partition(int *niz, int n) {
    int l, r;
    l = 1;
    r = n - 1;
    while (l < r) {
        if (niz[r] >= niz[0]) {
            r--;
        }
        else if (niz[l] < niz[0]) {
            l++;
        }
        else {
            int tmp = niz[l];
            niz[l] = niz[r];
            niz[r] = tmp;
        }
    }
    if (niz[0] < niz[r]) { // 1
        return 0;
    }
    else { // 3
        int tmp = niz[r];
        niz[r] = niz[0];
        niz[0] = tmp;
        return r;
    }
}

void quicksort(int *niz, int n) {
    if (n < 2)
        return;
    int pi = partition(niz, n);
    quicksort(niz, pi);
    quicksort(niz + pi + 1, n - pi - 1);
}

// merge sort
void merge(int *niz, int *niza, int na, int *nizb, int nb) {
    // implemntirati merge funkciju
}

// alocira i vraÊa kopiju niza
int* duplicate(int *niz, int n) {
    int i;
    int *novi = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) {
        novi[i] = niz[i];
    }
    return novi;
}

//void mergesort(int *niz, int n) {
//    // implementirati
//}

// mjerenje vremena izvodenja funkcije sortiranja
//double measure(void(*sort)(int *niz, int n), int *niz, int n) {
//    int start_time = clock();
//    sort(niz, n);
//    int end_time = clock();
//    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
//}

//clock_t stime = clock();
