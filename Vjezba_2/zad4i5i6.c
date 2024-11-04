#include <stdio.h>
#include <stdlib.h>

//Deklarirati strukturu Tocka koja sadrži dva člana: x i y (oba su float). Deklarirati strukturu Poligon koja se sadrži dva člana: niz vrhova (svaki vrh u nizu je Tocka) i broj vrhova n. Napisati funkcije za rad sa poligonima

typedef struct{
    float x;
    float y;
}Tocka;
typedef struct{
    Tocka* vrhovi;
    int broj_vrhova;
}Poligon;

//Tocka** pozitivni(Poligon *p, int *np) – funkcija vraća niz pokazivača na vrhove poligona kojima su obje koordinate pozitivne. Broj elemenata u nizu će biti spremljen u np parametar.
Tocka** pozitivni_vrhovi(Poligon* p,int *np){
    int i,j=0,brojac=0;
    for(i=0; i < p->broj_vrhova; i++){
        if(p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0){
            brojac++;
        }
    }
    Tocka** pozitivne_tocke = malloc(brojac * sizeof(Tocka*));
    if (pozitivne_tocke == NULL){
        printf("Greska pri pozitivnim tockama");
        *np = 0; //BITNO
        return NULL;
    }
    for(i = 0; i < p->broj_vrhova; i++){
        if(p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0){
            pozitivne_tocke[j] = &p->vrhovi[i];
            j++; 
        }
    }
    *np = brojac; //BITNO
    return pozitivne_tocke;
}

//Poligon* novi_poligon(float *niz_x, float *niz_y, int n) – prima niz x i y koordinata i stvara novi poligon koji će kao vrhove imati parove brojeva iz nizova. Nizovi su dužine n (≥ 3).
Poligon* novi_poligon(float *niz_x, float *niz_y, int n){
    if (n < 3){
        printf("Greska pri vrhovima poligona");
        return NULL;
    }
    Poligon* p = malloc(sizeof(Poligon));
    if (p == NULL){
        printf("Greska pri alociranju memorije za novi poligon");
        return NULL;
    }
    p->vrhovi = malloc(n * sizeof(Tocka));//BITNO
    if (p->vrhovi == NULL){
        printf("Greska pri alociranju memorije za nove tocke");
        return NULL;
    }
    int i;
    for(i=0; i < n; i++){
        p->vrhovi[i].x = niz_x[i];
        p->vrhovi[i].y = niz_y[i];
    }
    p->broj_vrhova = n;//BITNO
    return p;

}

int main(){
    float niz_x[] = {1.3, -2.0, 5.2, 4.0, 9.5};
    float niz_y[] = {1.0, 3.5, 4.8, -0.4, 9.0};
    int n = sizeof(niz_x) / sizeof(niz_x[0]);

    Poligon* rez1 = novi_poligon(niz_x,niz_y,n);
    if (rez1 == NULL){
        printf("Greska kod rez1");
        exit(1);
    }
    printf("ZADATAK 1 : \n");
    int i;
    for(i = 0; i < n; i++){
        printf("Za tocku %d. imamo parove tocaka (%.2f,%.2f)\n",i,rez1->vrhovi[i].x,rez1->vrhovi[i].y);
    }
    printf("\n");
    printf("ZADATAK 2 : \n");
    
    int np;
    Tocka** rez2 = pozitivni_vrhovi(rez1,&np);
    if (rez2 == NULL){
        printf("Greska pri rez2");
        exit(1);
    }
    for(i = 0; i < np; i++){
        printf("Parovi s pozitivnim kordinatama su (%.2f,%.2f)\n",rez2[i]->x,rez2[i]->y);
    }
    free(rez2);
    free(rez1->vrhovi);
    free(rez1);
    return 0;
}