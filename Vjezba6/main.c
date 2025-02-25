#include <stdio.h>
#include <stdlib.h>
#define N 10000

typedef struct {
    int broj;
    void* smece;
} Cvor;

typedef struct {
    Cvor gomila[N];
    int velicina;
}Red;

void postaviRed(Red* red){
    red->velicina = 0;
}

void popraviPremaVrhu(Red* red, int indeks){
    if(indeks == 0){
        return;
    }
    
    int roditelj = (indeks - 1) / 2;
    
    if(red->gomila[indeks].broj > red->gomila[roditelj].broj){
        Cvor tmp = red->gomila[roditelj];
        red->gomila[roditelj] = red->gomila[indeks];
        red->gomila[indeks] = tmp;
        
        popraviPremaVrhu(red, roditelj);
    }
    
}

//Operacija dodavanja dodaje novi element na kraj niza. Operacija dodavanja novog elementa će se oslanjati na funkciju koja popravlja gomilu „prema vrhu“. Ta funkcija će za neki element zadan svojim indeksom c provjeriti da li je njegov roditelj na indeksu r manji ili veći. Ako je element na r manji od elementa na c, elementi će se zamijeniti i funkcija će se rekurzivno pozvati za element na indeksu r.
void dodajNaGomilu(Red* red, void* smece, int broj){
    if(red->velicina < N){
        red->gomila[red->velicina].broj = broj;
        red->gomila[red->velicina].smece = smece;
        red->velicina++;
        
        //fun za prema vrhu
        popraviPremaVrhu(red, red->velicina - 1);
    } else {
        printf("Rjeseno");
    }
    
}

void premaDnu(Red* red, int indeks){
    int left = 2 * indeks + 1;
    int right = 2 * indeks + 2;
    int roditelj = indeks;
    
    
    if(left < red->velicina && red->gomila[left].broj > red->gomila[roditelj].broj){
        roditelj = left;
    }
    if(right < red->velicina && red->gomila[right].broj > red->gomila[roditelj].broj){
        roditelj = right;
    }
    if(roditelj != indeks){
        Cvor tmp = red->gomila[indeks];
        red->gomila[indeks] = red->gomila[roditelj];
        red->gomila[roditelj] = tmp;
        
        premaDnu(red, roditelj);
    }
}

//Operacija uklanjanja elementa na vrhu gomile (na indeksu 0) i prebacuje zadnji element niza na indeks 0. Operacija uklanjanja će se oslanjati na funkciju koja popravlja gomilu „prema dnu“. Ta funkcija će za neki element r provjeravati da li je manji od svoje djece na indeksima l i d. Ako je, zamijeniti će se sa većim od njih i funkcija će se rekurzivno pozvati za element na indeksu tog djeteta.
void ukloniSVrha(Red* red){
    if(red->velicina > 0){
        red->gomila[0] = red->gomila[red->velicina - 1];
        red->velicina--;
        
        //prema dnu
        premaDnu(red, 0);
    } else {
        printf("Rjeseno");
    }
}


int main98() {
    Red red;
    postaviRed(&red);
    dodajNaGomilu(&red, NULL, 0);
    dodajNaGomilu(&red, NULL, 4);
    dodajNaGomilu(&red, NULL, 8);
    dodajNaGomilu(&red, NULL, 12);
    dodajNaGomilu(&red, NULL, 2);
//    dodajNaGomilu(&red, NULL, 5);
    
    
    //printam
    printf("\nPRINTAM\n");
    for(int i = 0; i < red.velicina; i++){
        printf("%d ", red.gomila[i].broj);
    }
    
    ukloniSVrha(&red);
    
    printf("\nNakon Vadenja\n");
    for(int i = 0; i < red.velicina; i++){
        printf("%d ", red.gomila[i].broj);
    }
    

    return 0;
}
