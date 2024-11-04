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
    int i,brojac=0,j=0;
    for(i=0; i < p->broj_vrhova; i++){
        if(p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0){
            brojac++;
        }
    }
    Tocka** pozitivne_tocke = malloc(brojac * sizeof(Tocka*));
    if(pozitivne_tocke == NULL){
        printf("Greska kod pozitivnih tocaka");
        return NULL;
    }
    for(i=0; i < p->broj_vrhova; i++){
        if(p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0){
            // pozitivne_tocke[i]->x = p->vrhovi[i].x;
            // pozitivne_tocke[i]->y = p->vrhovi[i].y;
            pozitivne_tocke[j] = &p->vrhovi[i];
            j++;
        }
    }
    *np = brojac;
    return pozitivne_tocke;

}

Poligon* novi_poligon(float* niz_x, float* niz_y, int n){
    if (n < 3){
        printf("Pogreska 1");
        return NULL;
    }

    Poligon* p = malloc(sizeof(Poligon));
    if(p == NULL){
        printf("Pogreska 2");
        return NULL;
    }
    p->vrhovi = malloc(n * sizeof(Tocka));
    if(p->vrhovi == NULL){
        printf("Pogreska 3");
        return NULL;
    }
    int i;
    for(i = 0; i < n; i++){
        p->vrhovi[i].x = niz_x[i];
        p->vrhovi[i].y = niz_y[i];
    }
    p->broj_vrhova = n;
    return p;
}

int main(){
    float niz_x[] = {1.0, -2.0, 3.0, 4.0};
    float niz_y[] = {1.0, 2.0, 3.0, 4.0};
    int n = sizeof(niz_x) / sizeof(niz_x[0]);
    int np;

    Poligon* rez = novi_poligon(niz_x,niz_y,n);
    Tocka** rez1 = pozitivni(rez,&np);
    printf("Prvi zadatak : \n");
    int i;
    for(i=0; i < n; i++){
        printf("Za tocku %d u nizu dodjeljene su tocke (%.2f,%.2f)\n",i,rez->vrhovi[i].x,rez->vrhovi[i].y);
    }
    printf("\n");
    printf("Drugi zadatak : \n");
    for(i=0; i < np; i++){
        printf("Poligon s pozitivnim vrhovima ima tocke %d : (%.2f,%.2f)\n",i,rez1[i]->x,rez1[i]->y);
    }
    free(rez->vrhovi);
    free(rez);
    return 0;
}