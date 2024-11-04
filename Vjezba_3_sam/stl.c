#include "stl.h"
#include <stdio.h>
#include <string.h>

OBJEKT3D ucitaj_binarnu_stl(const char* file){
    FILE* datoteka = fopen(file,"rb");
    OBJEKT3D obj; // obj?
    obj.trokuti = NULL;
    obj.broj_trokuta = 0;
    if(!datoteka){
        printf("Greska s datotekom");
        return obj;
    }
    fseek(datoteka,80,SEEK_SET);
    fread(&obj.broj_trokuta,sizeof(int),1,datoteka);
    obj.trokuti = (TROKUT*) malloc(obj.broj_trokuta * sizeof(TROKUT));
    int i,j;
    for(i = 0; i < obj.broj_trokuta; i++){
        fread(&obj.trokuti[i].normala,sizeof(float),3,datoteka);
        for(j = 0; j < 3; j++){
            fread(&obj.trokuti[i].vrhovi[j],sizeof(VRH),1,datoteka);
        }
        fread(&obj.trokuti[i].boja,sizeof(unsigned short),1,datoteka);
    }
    fclose(datoteka);
    return obj;
}
void ispisi_binarnu_stl(const char* file, OBJEKT3D obj){
    FILE* datoteka = fopen(file,"wb");
    if(!datoteka){
        printf("Greska s datotekom");
        return;
    }
    char header[80] = {0};
    fwrite(header,sizeof(char),80,datoteka);
    fwrite(&obj.broj_trokuta,sizeof(int),1,datoteka);
    int i,j;
    for(i = 0; i < obj.broj_trokuta; i++){
        TROKUT p = obj.trokuti[i];
        printf("Redni broj trokuta : %d -- (%f,%f,%f)\n",i,p.normala[0],p.normala[1],p.normala[2]);
        printf("Vrhovi trokuta su A(%f,%f,%f), B(%f,%f,%f), C(%f,%f,%f)\n",
                p.vrhovi[0].x, p.vrhovi[0].y, p.vrhovi[0].z,
                p.vrhovi[1].x,p.vrhovi[1].y,p.vrhovi[1].z,
                p.vrhovi[2].x,p.vrhovi[2].y,p.vrhovi[2].z);
        fwrite(&p.normala,sizeof(float),3,datoteka);
        for(j = 0; j < 3; j++){
            fwrite(&p.vrhovi[i].x,sizeof(VRH),1,datoteka);
        }
        fwrite(&p.boja,sizeof(unsigned short),1,datoteka);
    }
    fclose(datoteka);
}
OBJEKT3D ucitaj_tekstualnu_stl(const char* file){
    FILE* datoteka = fopen(file,"r");
    OBJEKT3D obj;
    obj.broj_trokuta = 0;
    obj.trokuti = NULL;
    if (!datoteka){
        printf("Greska kod otvaranja datoteke");
        return obj;
    }
    char citanje[100]; // zasto ovo
    TROKUT t;
    int kapacitet = 10;
    obj.trokuti = (TROKUT*) malloc(kapacitet * sizeof(TROKUT));
    while(fgets(citanje, sizeof(citanje), datoteka)){
        if(strstr(citanje,"facet normal")){
            sscanf(citanje, "facet normal %f %f %f", &t.normala[0],&t.normala[1],&t.normala[2]);
        } else if (strstr(citanje,"vertex")){
            static int vrh_broj = 0; // sta je static
            sscanf(citanje, " vertex %f %f %f", &t.vrhovi[vrh_broj].x,&t.vrhovi[vrh_broj].y,&t.vrhovi[vrh_broj].z);
            vrh_broj++;
            if(vrh_broj == 3){
                vrh_broj = 0;
            }
        } else if (strstr(citanje,"endfacet")){
            t.boja = 0;
            if(obj.broj_trokuta >= kapacitet){
                kapacitet *= 2;
                obj.trokuti = (TROKUT*) realloc(obj.trokuti, kapacitet * sizeof(TROKUT));
            }
            obj.trokuti[obj.broj_trokuta++] = t;
        }
    }
    fclose(datoteka);
    return obj;
}
void zapisi_tekstualnu_stl(const char* file, OBJEKT3D obj){
    FILE* datoteka = fopen(file,"w");
    if(!datoteka){
        printf("Greska kod datoteke");
        return ;
    }
    fprintf(datoteka, "solid objekt\n");
    int i,j;
    for(i = 0; i < obj.broj_trokuta; i++){
        TROKUT t = obj.trokuti[i];
        fprintf(datoteka, " facet normal %f %f %f\n",t.normala[0],t.normala[1],t.normala[2]);
        fprintf(datoteka,"    outer loop\n");
        for(j = 0; j < 3; j++){
            fprintf(datoteka,"     vertex %f %f %f\n", t.vrhovi[j].x,t.vrhovi[j].y,t.vrhovi[j].z);
        }
        fprintf(datoteka, "   endloop\n");
        fprintf(datoteka, "  endfacet\n");
    }
    fprintf(datoteka, "endsolid objekt\n");
    fclose(datoteka);
}
void obrisi_objekt_3d(OBJEKT3D* obj){
    if (obj->trokuti != NULL){
        free(obj->trokuti);
        obj->trokuti = NULL;
    }
    obj -> broj_trokuta = 0;
}
int main() {
    // Učitaj binarnu STL datoteku
    OBJEKT3D obj = ucitaj_binarnu_stl("primjerbin.stl");
    if (obj.trokuti == NULL) {
        printf("Greska kod ucitavanja binarne STL datoteke\n");
        return 1;
    }

    // Zapiši objekat u tekstualnu STL datoteku
    zapisi_tekstualnu_stl("output_textual.stl", obj);

    // Oslobodi memoriju za objekat
    obrisi_objekt_3d(&obj);

    // Učitaj tekstualnu STL datoteku
    obj = ucitaj_tekstualnu_stl("primjertxt.stl");
    if (obj.trokuti == NULL) {
        printf("Greska kod ucitavanja tekstualne STL datoteke\n");
        return 1;
    }

    // Zapiši objekat nazad u binarnu STL datoteku
    ispisi_binarnu_stl("output_binary.stl", obj);

    // Oslobodi memoriju za objekat
    obrisi_objekt_3d(&obj);

    printf("Testiranje zavrseno uspesno\n");
    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// #include "stl.h"
// #include <string.h>
// OBJEKT3D citanje_binarne_stl(const char* naziv_datoteke){
//     FILE* datoteka = fopen(naziv_datoteke,"rb");
//     if (datoteka == NULL){
//         OBJEKT3D prazan_objekt = {NULL,0};
//         return prazan_objekt;
//     }
//     char zaglavlje[80];
//     fread(zaglavlje,sizeof(char),80,datoteka);
//     unsigned int broj_trokutova;
//     fread(&broj_trokutova,sizeof(unsigned int),1,datoteka);
//     TROKUT* niz_trokutova = malloc(broj_trokutova * sizeof(TROKUT));
//     if (niz_trokutova == NULL){
//         fclose(datoteka);
//         OBJEKT3D prazan_objekt = {NULL,0};
//         return prazan_objekt;
//     }
//     int i;
//     for(i = 0; i < broj_trokutova; i++){
//         fread(&niz_trokutova[i],sizeof(TROKUT),1,datoteka);
//     }
//     fclose(datoteka);
//     OBJEKT3D popunjeni_objekt = {niz_trokutova,broj_trokutova};
//     return popunjeni_objekt;
// }
// void ispisi_binarnu_stl(const char* file, OBJEKT3D obj){
//     FILE* datoteka = fopen(file,"wb");
//     if (datoteka == NULL){
//         printf("Greska kod otvaranja datoteke");
//         return;
//     }
//     char zaglavlje[80];
//     fwrite(zaglavlje,sizeof(char),80,datoteka);
//     fwrite(&obj.broj_trokuta,sizeof(unsigned int),1,datoteka);
//     int i,j;
//     for(i = 0; i < obj.broj_trokuta; i++){
//         TROKUT p = obj.trokuti[i];
//         fwrite(&p.normal,sizeof(float),3,datoteka);
//         for(j = 0; j < 3; j++){
//             fwrite(&p.vrhovi[j],sizeof(VRH),1,datoteka);
//         }
//         fwrite(&p.dodatni_broj,sizeof(unsigned short),1,datoteka);
//     }
//     fclose(datoteka);
// }
// void ispisi_tekstualnu_stl(const char* naziv_datoteke, OBJEKT3D obj){
//     FILE* file = fopen(naziv_datoteke, "w");
//     if (file == NULL){
//         printf("Greska kod otvaranje datoteke");
//         return;
//     }
//     fprintf(file,"solid model\n");
//     int i,j;
//     for(i = 0; i < obj.broj_trokuta; i++){
//         TROKUT p = obj.trokuti[i];
//         fprintf(file,"  facet normal %f %f %f\n",p.normal[0],p.normal[1],p.normal[2]);
//         fprintf(file,"    outer loop\n");
//         for(j = 0; j < 3; j++){
//             fprintf(file,"      vertex %f %f %f\n",p.vrhovi[j].x,p.vrhovi[j].y,p.vrhovi[j].y);
//         }
//         fprintf(file,"    endloop\n");
//         fprintf(file,"  endfacet\n");
//         fprintf(file,"endsolid model\n");
//         fclose(file);
//     }
// }
// void brisanje_objekta(OBJEKT3D* obj){
//     if(obj->trokuti != NULL){
//         free(obj->trokuti);
//         obj->trokuti = NULL;
//     }
//     obj->broj_trokuta = 0;
// }
// //
// //
// //
// //
// //
// OBJEKT3D citanje_tekstualne_stl(const char* naziv_datoteke){
//     FILE* file = fopen(naziv_datoteke,"r");
//     OBJEKT3D obj;
//     obj.broj_trokuta = 0;
//     obj.trokuti = NULL;
//     if(file == NULL){
//         printf("Greska");
//         return obj;
//     }
//     char zaglavlje[256];
//     fgets(zaglavlje,sizeof(zaglavlje),file);
//     while(fgets(zaglavlje,sizeof(zaglavlje),file)){
//         if(strstr(zaglavlje,"facet normal")){
//             obj.broj_trokuta++;
//         }
//     }
//     rewind(file);
//     fgets(zaglavlje,sizeof(zaglavlje),file);
//     obj.trokuti = (TROKUT*)malloc(sizeof(TROKUT) * obj.broj_trokuta);
//     if(obj.trokuti == NULL){
//         printf("Greska kod alokacije");
//         fclose(file);
//         obj.broj_trokuta = 0;
//         return obj;
//     }
//     int i,j;
//     for(i = 0; i < obj.broj_trokuta; i++){
//         fgets(zaglavlje,sizeof(zaglavlje),file);
//         sscanf(zaglavlje," facet normal %f %f %f",&obj.trokuti[i].normal[0],&obj.trokuti[i].normal[1],&obj.trokuti[i].normal[2]);
//         fgets(zaglavlje,sizeof(zaglavlje),file);
//         for(j = 0; j < 3; j++){
//             fgets(zaglavlje,sizeof(zaglavlje),file);
//             sscanf(zaglavlje," vertex %f %f %f",&obj.trokuti[i].vrhovi[j].x, &obj.trokuti[i].vrhovi[j].y, &obj.trokuti[i].vrhovi[j].z);
//         }
//         fgets(zaglavlje,sizeof(zaglavlje),file);
//         fgets(zaglavlje, sizeof(zaglavlje), file);
//     }
//     fclose(file);
//     return obj;
// }
// int main(){
//     OBJEKT3D obj = citanje_binarne_stl("primjerbin.stl");
//     if (obj.trokuti == NULL) {
//         printf("Greska kod ucitavanja binarne STL datoteke\n");
//         return 1;
//     }

//     ispisi_tekstualnu_stl("output_textual.stl", obj);

//     brisanje_objekta(&obj);

//     obj = citanje_tekstualne_stl("primjertxt.stl");
//     if (obj.trokuti == NULL) {
//         printf("Greska kod ucitavanja tekstualne STL datoteke\n");
//         return 1;
//     }

//     ispisi_binarnu_stl("output_binary.stl", obj);

//     brisanje_objekta(&obj);

//     printf("Testiranje zavrseno uspesno\n");
//     return 0;
// }
