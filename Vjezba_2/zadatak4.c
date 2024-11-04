// Deklarirati strukturu Tocka koja sadrži dva člana: x i y (oba su float). Deklarirati strukturu Poligon koja se sadrži dva člana: niz vrhova (svaki vrh u nizu je Tocka) i broj vrhova n. Napisati funkcije za rad sa poligonima:
//Poligon* novi_poligon(float *niz_x, float *niz_y, int n) – prima niz x i y koordinata i stvara novi poligon koji će kao vrhove imati parove brojeva iz nizova. Nizovi su dužine n (≥ 3).
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    float x,y;
}Tocka;
typedef struct{
    Tocka* vrhovi;
    int n;
}Poligon;

//5. zadatak
Poligon* novi_poligon(float *niz_x, float *niz_y, int n){
    if (n > 3){
        return NULL;
    }
    Poligon* p = (Poligon*) malloc(sizeof(Poligon));
    p->vrhovi = (Tocka*) malloc(n * sizeof(Tocka));
    p->n = n;

    int i;
    for(i=0;i<n;i++){
        p->vrhovi[i].x = niz_x[i];
        p->vrhovi[i].y = niz_y[i];
    }
    return p;
}

int main(){
    float niz_x[] = {1.0, -2.0, 3.0, 4.0};
    float niz_y[] = {1.0, 2.0, -3.0, 4.0};
    int n = sizeof(niz_x) / sizeof(niz_x[0]);

    Poligon* p = novi_poligon(niz_x,niz_y,n);

    if (p == NULL) {
        printf("Poligon nije validan.\n");
        return 0;
    }
    for (int i = 0; i < p->n; i++) {
        printf("Vrh %d: (%.2f, %.2f)\n", i, p->vrhovi[i].x, p->vrhovi[i].y);
    }
    
    //free(p->vrhovi);
    //free(p);

    return 0;
}