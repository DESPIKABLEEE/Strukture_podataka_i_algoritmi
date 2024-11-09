//funkcija prima poligon i vraca niz koordinate x
// vrati i x i y
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    float x,y;
}Poligon;

float* funkcija(Poligon* niz, int n){
    int i,j;
    float* niz_x = NULL;
    niz_x = malloc(sizeof(float) * n);
    if(niz_x == NULL){
        printf("Greska");
        return NULL;
    }
    for(i = 0; i < n; i++){
        niz_x[i] = niz[i].x;
    }
    return niz_x;
}

float** i_x_y(Poligon *niz, int n){
    int i,j;
    float** niz_x_y = NULL;
    float* niz_x = NULL;
    float* niz_y = NULL;
    niz_x = malloc(sizeof(float) * n);
    if (niz_x == NULL){
        printf("Greska x");
        return NULL;
    }
    niz_y = malloc(sizeof(float) * n);
    if(niz_y == NULL){
        printf("Greska y");
        return NULL;
    }
    niz_x_y = malloc(sizeof(float*) * 2);
    for(i = 0; i < n; i++){
        niz_x[i] = niz[i].x;
    }
    for(j = 0; j < n; j++){
        niz_y[j] = niz[j].y;
    }
    niz_x_y[0] = niz_x;
    niz_x_y[1] = niz_y;

    return niz_x_y;

}

int main(){
    Poligon niz[] = {
        {4.1,0.2},
        {3.4,0.5},
        {2.1,8.6}
    };
    int n = 3;
    // float *rez = funkcija(niz,n);
    // int i;
    // for(i = 0; i < n; i++){
    //     printf("Tocka %d ima tocku x : %.2f\n",i+1,rez[i]);
    // }
    float** rez1 = i_x_y(niz,n);
    int j,k;
    for(j = 0;j < 2; j++){
        printf("%d niz je : ", j+1);
        for(k = 0; k < n; k++){
            printf("Ima tocke %.2f \n",rez1[j][k]);
        }    
        printf("\n");
    }
    free(rez1[0]);
    free(rez1[1]);
    free(rez1);
    // free(rez);
    return 0;
}