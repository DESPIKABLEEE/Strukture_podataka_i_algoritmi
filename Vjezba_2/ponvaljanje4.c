// Deklarirati strukturu Tocka koja sadrži dva člana: x i y (oba su float). Deklarirati strukturu Poligon koja se sadrži dva člana: niz vrhova (svaki vrh u nizu je Tocka) i broj vrhova n. Napisati funkcije za rad sa poligonima:

//Poligon* novi_poligon(float *niz_x, float *niz_y, int n) – prima niz x i y koordinata i stvara novi poligon koji će kao vrhove imati parove brojeva iz nizova. Nizovi su dužine n (≥ 3).

//Tocka** pozitivni(Poligon *p, int *np) – funkcija vraća niz pokazivača na vrhove poligona kojima su obje koordinate pozitivne. Broj elemenata u nizu će biti spremljen u np parametar. 
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    float x;
    float y;
}Tocka;
typedef struct{
    Tocka* vrhovi;
    int broj_vrhova;
}Poligon;

Tocka** pozitivni(Poligon *p, int *np){
    int i,j=0,brojac=0;
    for(i = 0; i < p->broj_vrhova; i++){
        if(p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0){
            brojac++;
        }
    }
    *np = brojac;
    Tocka** pozitivne_tocke = malloc(sizeof(Tocka*) * brojac);
    for(i = 0; i < p->broj_vrhova; i++){
        if(p->vrhovi[i].x > 0 && p->vrhovi[i].y){
            pozitivne_tocke[j] = &p->vrhovi[i];
            j++;
        }
    }
    return pozitivne_tocke;

}

Poligon* novi_poligon(float *niz_x, float *niz_y, int n){
    if (n < 3){
        printf("Greska kod broja vrhova");
        return 0;
    }
    Poligon* p = malloc(sizeof(Poligon));
    if ( p == NULL)
        return NULL;
    p->vrhovi = malloc(sizeof(Tocka) * n);
    if (p->vrhovi == NULL)
        return NULL;
    p->broj_vrhova = n;
    int i;
    for(i = 0; i < p->broj_vrhova; i++){
        p->vrhovi[i].x = niz_x[i];
        p->vrhovi[i].y = niz_y[i];
    }
    return p;

}
int main(){
    float niz_x[] = {1.0, 2.3, 4.8, 3.0};
    float niz_y[] = {0.8, 1.6, 4.0, 5.3};
    int n = sizeof(niz_x) / sizeof(niz_x[0]);
    printf("PRVI ZADATAK\n");
    Poligon* rez1 = novi_poligon(niz_x,niz_y,n);
    printf("Tocke poligona su : ");
    int i;
    for(i = 0; i < n; i++){
        printf("(%.1f,%.1f)",rez1->vrhovi[i].x,rez1->vrhovi[i].y);
    }
    printf("\n");
    printf("DRUGI ZADATAK");
    int np;
    Tocka** rez2 = pozitivni(rez1,&np);
    for(i = 0; i < np; i++){
        printf("(%.1f,%.1f)", rez2[i]->x,rez2[i]->y);
    }
    free(rez2);
    free(rez1->vrhovi);
    free(rez1);

    return 0;
}