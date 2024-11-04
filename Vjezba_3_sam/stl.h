#ifndef STL_H
#define STL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x, y, z; // 12 BAJTOVA
} VRH;

typedef struct {
    float normala[3]; // 12 BAJTOVA
    VRH vrhovi[3]; // 36 BAJTOVA
    unsigned short boja; // 2 BAJTA
} TROKUT;

typedef struct {
    TROKUT* trokuti; // 8 BAJTOVA
    unsigned int broj_trokuta; // 4 BAJTA
} OBJEKT3D;

// Deklaracije funkcija
OBJEKT3D citanje_binarne_stl(const char* naziv_datoteke);
void ispisi_binarnu_stl(const char* naziv_datoteke, OBJEKT3D obj);
OBJEKT3D citanje_tekstualne_stl(const char* naziv_datoteke);
void ispisi_tekstualnu_stl(const char* naziv_datoteke, OBJEKT3D obj);
void obrisi_objekt3d(OBJEKT3D* obj);

#endif // STL_H