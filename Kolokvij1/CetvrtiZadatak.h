//4.    Napisati funkciju koja prima listu. Funkcija iz liste izdvaja u zasebnu listu sve elemente sa pozitivnim brojevima. Funkcija vraća tu novu listu pozitivnih brojeva. Originalna lista mora i dalje biti ispravna vezana lista preostalih brojeva. Kolika je složenost funkcije O()? (35 bodova) PONOVI
Node* f(Node** lst){
    if((*lst) == NULL){
        printf("Lista je prazna");
        return NULL;
    }
    
    Node* current = (*lst);
    Node* prev = NULL;
    Node* tmp = NULL;
    Node* pozitivna = NULL;
    while (current != NULL) {
        if(current->data > 0){
            Node* novi = malloc(sizeof(Node));
            novi->data = current->data;
            novi->next = pozitivna;
            pozitivna = novi;
            if(prev == NULL){
                (*lst) = current->next;
            } else {
                prev->next = current->next;
            }
            
            tmp = current;
            current = current->next;
            free(tmp);
        } else {
            prev = current;
            current = current->next;
        }
    }
    return pozitivna;
}


//4.    Napisati funkciju koja prima listu i broj. Funkcija u listu dodaje novi element sa brojem 0 ispred svakog elementa sa pozitivnim brojem u listi. Funkcija vraća izmijenjenu listu. Kolika je složenost funkcije O()? (35 bodova) PONOVI

Node* f(Node* lst, int broj){
    if(lst == NULL){
        printf("Lista je prazna");
        return NULL;
    }
    Node* izmjenjena = lst;
    Node* current = lst;
    while (current != NULL) {
        if(current > 0){
            Node* noviNode = malloc(sizeof(Node));
            noviNode->data = 0;
            noviNode->next = current;
            
            if(current == lst){
                lst = noviNode;
            } else {
                Node* tmp = lst;
                while (tmp->next != current) {
                    tmp = tmp->next;
                }
                tmp->next = noviNode
            }
            current = current->next;
        } else {
            current = current->next;
        }
    }
    
    
    
    return izmjenjena;
}


//4.    Napisati funkciju koja prima listu i dva indeksa. Funkcija iz liste briše sve elemente koji nisu između ta dva  indeksa (isključujući same indekse). Funkcija vraća izmijenjenu listu. Može se pretpostaviti da su indeksi legalni (unutar dužine liste).  Kolika je složenost funkcije O()? (35 bodova)

Node* f(Node* lst, int indeks1, int indeks2){
    if(lst == NULL){
        printf("Lista je prazna");
        return NULL;
    }
    Node* ovuvrati = lst;
    Node* current = lst;
    Node* tmp;
    for(int i = 0; i < indeks1 - 1; i++){
        tmp = current;
        current = current->next;
        free(tmp);
    }
    ovuvrati = current;
    current = current->next;
    for(int i = indeks1; i < indeks2 - 1; i++){
        current = current->next;
    }
    while (current != NULL) {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    return ovuvrati;
}

//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati nove elemente sa tim brojem na početak i na kraj liste. (35 bodova)

void f(Node** lst, int broj){
    if((*lst) == NULL){
        printf("Lista je prazna");
        return;
    }
    Node* current = (*lst);
    Node* novi1 = malloc(sizeof(Node));
    novi1->data = broj;
    novi1->next = current;
    (*lst) = novi1;
    while (current->next != NULL) {
        current = current->next;
    }
    Node* novi2 = malloc(sizeof(Node));
    novi2->next = NULL;
    novi2->data = broj;
    current->next = novi2;
    
}

//4.    Napisati funkciju koja dvije liste. Funkcija na kraj prve liste dodaje kopije svih elemenata iz druge liste. Funkcija vraća izmijenjenu listu. Kolika je složenost funkcije O()? (35 bodova)

Node* f(Node* lst1, Node* lst2){
    if(lst1 == NULL || lst2 == NULL){
        printf("Jedna lista je prazna ili obe");
        return NULL;
    }
    Node* ovuvrati = lst1;
    Node* current = lst1;
    while (current->next != NULL) {
        current = current->next;
    }
    
    while (lst2 != NULL) {
        Node* tmp = malloc(sizeof(Node));
        tmp->data = lst2->data;
        lst2 = lst2->next;
        tmp->next = NULL;
        current->next = tmp;
        current = tmp;
        
    }
    return ovuvrati;
}

//4.    Napisati funkciju koja prima dvije liste. Funkcija na početak prve liste dodaje kopije svih elemenata iz druge liste. Funkcija vraća izmijenjenu listu. Kolika je složenost funkcije O()? (35 bodova)

Node* f(Node* lst1, Node* lst2){
    if(lst1 == NULL || lst2 == NULL){
        printf("Greska");
        return NULL;
    }
    Node* vratiovu = lst1;
    Node* current = lst1;
    
    while(lst2 != NULL){
        Node* tmp = malloc(sizeof(Node));
        tmp->data = lst2->data;
        lst2 = lst2->next;
        tmp->next = NULL;
        tmp->next = vratiovu;
        vratiovu = tmp;
    }
    return vratiovu;
}


//4.    Napisati funkciju koja prima vezanu listu sa barem tri elementa. Funkcija će izbrisati zadnja tri elementa iz liste. (35 bodova)

void f(Node** lst){
    if((*lst) == NULL || (*lst)->next == NULL || (*lst)->next->next == NULL){
        printf("Greska");
        return;
    }
    Node* current = (*lst);
    while (current->next->next->next != NULL) {
        current = current->next;
    }
    Node* tmp = current->next;
    current->next = NULL;
    while (tmp != NULL) {
        Node* brisi = tmp;
        tmp = tmp->next;
        free(brisi);
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------

//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element sa tim brojem ispred prvog broja u listi koji je veći od 100 (ako takav postoji). (35 bodova)

void f(Node** lst, int broj){ // IMA GLAVU
    if((*lst) == NULL || (*lst)->next == NULL){
        printf("Greska");
        return;
    }
    Node* current = (*lst)->next;
    Node* prev = (*lst);
    while (current != NULL) {
        if(current->data > 100){
            Node* tmp = malloc(sizeof(Node));
            tmp->next = current;
            tmp->data = broj;
            prev->next = tmp;
            return;
        }
        current = current->next;
    }
}

//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija vraća pokazivač na zadnji element u listi koji je veći od dodatnog broja ili NULL ako se takav broj ne nalazi u listi. Kolika je složenost funkcije O()? (25 bodova)

Node* f(Node* lst, int broj){
    if(lst == NULL){
        printf("Lista je prazna");
        return NULL;
    }
    Node* tmp = NULL;
    Node* current = lst;
    while (current != NULL) {
        if(current->data > broj){
            tmp = current;
        }
        current = current->next;
    }
    return tmp;
}

//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj). Funkcija će izbrisati prva tri elementa iz liste ili samo ispisati grešku ako lista ima manje od tri elementa. (35 bodova)   PONOVI, MALA GRESKA KOD TMP

void f(Node** lst){
    if((*lst) == NULL || (*lst)->next == NULL || (*lst)->next->next == NULL){
        printf("Greska");
        return;
    }
    Node* tmp = (*lst);
    (*lst) = (*lst)->next->next->next;
    for(int i = 0; i < 3; i++){
        Node* brisi = tmp;
        tmp = tmp->next;
        free(brisi);
    }
}


//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element sa tim brojem prije najvećeg broja u listi. (35 bodova)

void f(Node** lst, int broj){ // IMA GLAVU
    if((*lst) == NULL || (*lst)->next == NULL){
        printf("Lista je prazna");
        return;
    }
    
    int najveciBroj = (*lst)->data;
    Node* current = (*lst)->next;
    Node* pamti;
    Node* prev = (*lst);
    Node* prevpamti;
    while (current != NULL) {
        if(najvecibroj < current->data){
            najvecibroj = current->data;
            pamti = current;
            prevpamti = prev;
        }
        prev = current;
        current = current->next;
    }
    Node* novi = malloc(sizeof(Node));
    novi->next = pamti;
    novi->data = broj;
    prevpamti->next = novi;
    
}


//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj i svi su različiti) i jedan dodatni broj. Funkcija će izbrisati element sa tim brojem. (35 bodova)

void f(Node** lst, int broj){
    if((*lst) == NULL || (*lst)->next == NULL){ // IMA GLAVU
        printf("Lista je prazna");
        return;
    }
    Node* current = (*lst)->next;
    Node* prev = (*lst);
    Node* tmp;
    while (current != NULL) {
        if(current->data == broj){
            tmp = current;
            current = current->next;
            free(tmp);
            prev->next = current
        } else {
            prev = current;
            current = current->next;
        }
    }
}

//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element na predzadnje mjesto ako lista nije prazna, ili na prvo mjesto ako je lista prazna. (35 bodova)

void f(Node** lst, int broj){ // IMA GLAVU
    if((*lst) == NULL){
        printf("Lista je potpuno prazna");
        return;
    }
    Node* novi = malloc(sizeof(Node));
    novi->data = broj;
    if((*lst)->next == NULL){
        (*lst)->next = novi;
    } else {
        Node* current = (*lst)->next;
        Node* prev = (*lst);
        while (current->next->next != NULL) {
            prev = current;
            current = current->next;
        }
        prev->next = novi;
        novi->next = current;
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------

//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element sa tim brojem nakon najvećeg broja u listi. (35 bodova)

void f(Node** lst, int broj){
    if((*lst) == NULL || (*lst)->next == NULL){
        printf("Greska");
        return;
    }
    Node* current = (*lst)->next;
    Node* prev = (*lst);
    Node* tmp = current;
    while (current != NULL) {
        if(current->data > tmp->data){
            tmp = current;
        }
        current = current->next;
    }
    Node* novi = malloc(sizeof(Node));
    novi->data = broj;
    novi->next = tmp->next;
    tmp->next = novi;
}


//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element sa tim brojem na sredinu liste (ili odmah nakon sredine ako je broj elemenata neparan). (35 bodova)

void f(Node** lst, int broj){
    if((*lst) == NULL || (*lst)->next == NULL){
        printf("Greska");
        return;
    }
    
    Node* current = (*lst)->next;
    Node* prev = (*lst);
    int brojac = 0;
    while (current != NULL) {
        brojac++;
        current = current->next;
    }
    brojac = brojac/2;
//    if(brojac % 2 != 0){
//        brojac++;
//    }
    current = (*lst)->next;
    for(int i = 0; i < brojac; i++){
        current = current->next;
    }
    Node* novi = malloc(sizeof(Node));
    novi->data = broj;
    novi->next = current->next;
    current->next = novi;
    
}


//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan indeks. Funkcija će dodati novi element na tom indeksu sa brojem 0. Ako indeks nije legalan (vanka je dužine liste), funkcija ne čini ništa . (35 bodova)

void f(Node** lst, int indeks){
    if((*lst) == NULL || (*lst)->next == NULL){
        printf("Greska");
        return;
    }
    Node* current = (*lst)->next;
    int brojac = 0;
    while (current != NULL) {
        brojac++;
        current = current->next;
    }
    if(indeks > brojac){
        printf("Greska kod indeksa");
        return;
    }
    current = (*lst)->next;
    for(int i = 0; i < indeks - 1; i++){
        current = current->next;
    }
    Node* tmp = malloc(sizeof(Node));
    tmp->data = 0;
    tmp->next = current->next;
    current->next = tmp;
}


//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i dva indeksa. Funkcija će obrisati sve elemente liste između ta dva indeksa. Indeksi su legalni i prvi je manji od drugog. (35 bodova)

void f(Node** lst, int indeks1, int indeks2){
    if((*lst) == NULL || (*lst)->next == NULL){
        printf("Greska");
        return;
    }
    Node* current = (*lst)->next;
    Node* prev = (*lst);
    Node* tmp = NULL;
    
    for(int i = 0; i < indeks1; i++){
        tmp = current;
        current = current->next;
        free(tmp);
    }
    (*lst) = current;
//    current = current->next;
    for(int j = indeks1; j < indeks2; j++){
        current = current->next;
    }
    Node* drugidio = current->next;
    while (drugidio != NULL) {
        tmp = drugidio;
        drugidio = drugidio->next;
        free(tmp);
    }

}



//-----------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------




//4.    Napisati funkciju koja prima listu. Funkcija iz liste izdvaja u zasebnu listu sve elemente sa pozitivnim brojevima. Funkcija vraća tu novu listu pozitivnih brojeva. Originalna lista mora i dalje biti ispravna vezana lista preostalih brojeva. Kolika je složenost funkcije O()? (35 bodova) +

Node* f(Node** lst){
    if((*lst) == NULL || (*lst)->next == NULL){
        printF("Lista je prazna");
        return NULL;
    }
    
    Node* current = (*lst)->next;
    Node* prev = (*lst);
    
    Node* nova = malloc(sizeof(Node));
    nova->next = NULL;
    nova->data = 0;
    Node* kraj = nova;
    Node* tmp = NULL;
    
    while (current != NULL) {
        if(current->data > 0){
            tmp = current;
            current = current->next;
            prev->next = current;
            
            kraj->next = tmp;
            kraj = tmp;
            kraj->next = NULL;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return nova;
}


//4.    Napisati funkciju koja prima listu i broj. Funkcija u listu dodaje novi element sa brojem 0 ispred svakog elementa sa pozitivnim brojem u listi. Funkcija vraća izmijenjenu listu. Kolika je složenost funkcije O()? (35 bodova) +

Node* f(Node* lst, int broj){
    if(lst == NULL || lst->next == NULL){
        printf("Lista je prazna");
        return NULL;
    }
    Node* current = lst->next;
    Node* prev = lst;
    Node* vrati = lst;
    while (current != NULL) {
        if(current->data > 0){
            Node* novi = malloc(sizeof(Node));
            novi->next = current;
            novi->data = 0;
            prev->next = novi;
            prev = novi;
        }
        prev = current;
        current = current->next;
    }
    return vrati;
}



//4.    Napisati funkciju koja prima listu i dva indeksa. Funkcija iz liste briše sve elemente koji nisu između ta dva  indeksa (isključujući same indekse). Funkcija vraća izmijenjenu listu. Može se pretpostaviti da su indeksi legalni (unutar dužine liste).  Kolika je složenost funkcije O()? (35 bodova)    INDEKSI BLJAK

Node* f(Node* lst, int indeks1, int indeks2){
    if(lst == NULL){
        printf("Greska");
        return NULL;
    }
    Node* tmp = NULL;
    Node* current = lst;
    Node* vrati = NULL;
    int i;
    for(i = 0; i < indeks1; i++){
        tmp = current;
        current = current->next;
        free(tmp);
    }
    vrati = current;
    for(i = indeks1; i < indeks2 - 1; i++){
        current = current->next;
    }
    Node* kraj = current->next;
    current->next = NULL;
    while (kraj != NULL) {
        tmp = kraj;
        kraj = kraj->next;
        free(tmp);
    }
    return vrati;
}


//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati nove elemente sa tim brojem na početak i na kraj liste. (35 bodova) +

void f(Node** lst, int broj){
    if((*lst) == NULL){
        printF("Glava je prazna");
        return;
    }
    Node* prev = (*lst);
    Node* tmp1 = malloc(sizeof(Node));
    tmp1->data = broj;
    if(prev->next == NULL){
        tmp1->next = NULL;
        prev->next = tmp1;
    } else {
        tmp1->next = prev->next;
        prev->next = tmp1;
    }
    Node* current = (*lst)->next;
    Node* tmp2 = malloc(sizeof(Node));
    tmp2->data = broj;
    tmp2->next = NULL;
    if(current->next == NULL){
        current->next = tmp2;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = tmp2;
    }
}

//4.    Napisati funkciju koja dvije liste. Funkcija na kraj prve liste dodaje kopije svih elemenata iz druge liste. Funkcija vraća izmijenjenu listu. Kolika je složenost funkcije O()? (35 bodova) +

Node* f(Node* lsta, Node* lstb){
    if(lsta == NULL || lstb == NULL){
        printf("Jedna od listi je prazna");
        return NULL;
    }
    Node* vrati = lsta;
    Node* current = lsta;
    while (current->next != NULL) {
        current = current->next;
    }
    while (lstb != NULL) {
        Node* tmp = malloc(sizeof(Node));
        tmp->data = lstb->data;
        tmp->next = NULL;
        current->next = tmp;
        current = tmp;
        lstb = lstb->next;
    }
    return vrati;
}

//4.    Napisati funkciju koja prima dvije liste. Funkcija na početak prve liste dodaje kopije svih elemenata iz druge liste. Funkcija vraća izmijenjenu listu. Kolika je složenost funkcije O()? (35 bodova) +

Node* f(Node* lsta, Node* lstb){
    if(lsta == NULL || lstb == NULL){
        printF("Liste prazne");
        return NULL;
    }
    Node* vrati = NULL;
    while (lstb != NULL) {
        Node* tmp = malloc(sizeof(Node));
        tmp->data = lstb->data;
        tmp->next = lsta;
        lsta = tmp;
        lstb = lstb->next;
    }
    
    vrati = lsta;
    return vrati;
}


//4.    Napisati funkciju koja prima vezanu listu sa barem tri elementa. Funkcija će izbrisati zadnja tri elementa iz liste. (35 bodova) +

void f(Node** lst){
    if((*lst) == NULL || (*lst)->next == NULL || (*lst)->next->next){
        printf("Nedovoljno elemenata");
        return;
    }
    Node* tmp = NULL;
    Node* current = (*lst);
    while (current->next->next->next != NULL) {
        current = current->next;
    }
    tmp = current->next;
    current->next = NULL;
    while (tmp != NULL) {
        Node* brisi = tmp;
        tmp = tmp->next;
        free(brisi);
    }
}

//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element sa tim brojem ispred prvog broja u listi koji je veći od 100 (ako takav postoji). (35 bodova) +

void f(Node** lst, int broj){
    if((*lst) == NULL || (*lst)->next == NULL){
        printf("Glave nema ili nema elemenata");
        return;
    }
    Node* current = (*lst)->next;
    Node* prev = (*lst);
    Node* tmp = malloc(sizeof(Node));
    tmp->data = broj;
    while (current != NULL) {
        if(current->data > 100){
            tmp->next = current;
            prev->next = tmp;
            return;
        }
        prev = current;
        current = current->next;
    }
}

//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija vraća pokazivač na zadnji element u listi koji je veći od dodatnog broja ili NULL ako se takav broj ne nalazi u listi. Kolika je složenost funkcije O()? (25 bodova)

Node* f(Node* lst, int broj){
    Node* vrati = NULL;
    if(lst == NULL){
        printf("Greska");
        return vrati;
    }
    Node* current = lst;
    while (current != NULL) {
        if (current->data > broj){
            vrati = current;
        }
        current = current->next;
    }
    return vrati;
}

//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj). Funkcija će izbrisati prva tri elementa iz liste ili samo ispisati grešku ako lista ima manje od tri elementa. (35 bodova) +

void f(Node** lst){
    if((*lst) == NULL || (*lst)->next == NULL || (*lst)->next->next == NULL || (*lst)->next->next->next == NULL){
        printf("Manje od 3 elementa");
        return;
    }
    Node* tmp = (*lst)->next;
    (*lst)->next = (*lst)->next->next->next->next;
    
    for(int i = 0; i < 3; i++){
        Node* brisi = tmp;
        tmp = tmp->next;
        free(brisi);
    }
}


//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element sa tim brojem prije najvećeg broja u listi. (35 bodova) +

void f(Node** lst, int broj){
    if((*lst) == NULL || (*lst)->next == NULL){
        printf("Greska");
        return;
    }
    int najveci = (*lst)->next->data;
    Node* current = (*lst)->next;
    Node* prev = (*lst);
    Node* najveciprev = NULL;
    while (current != NULL) {
        if(current->data > najveci){
            najveci = current->data;
            najveciprev = prev;
        }
        prev = current;
        current = current->next;
    }
    Node* novi = malloc(sizeof(Node));
    novi->next = najveciprev->next;
    najveciprev->next = novi;
    novi->data = broj;
}


//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj i svi su različiti) i jedan dodatni broj. Funkcija će izbrisati element sa tim brojem. (35 bodova)

void f(Node** lst, int broj){
    if((*lst) == NULL || (*lst)->next == NULL){
        printf("Greska");
        return;
    }
    Node* current = (*lst)->next;
    Node* prev = (*lst);
    
    while (current != NULL) {
        if(current->data == broj){
            Node* tmp = current;
            prev->next = current->next;
            current = current->next;
            free(tmp);
            return;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element na predzadnje mjesto ako lista nije prazna, ili na prvo mjesto ako je lista prazna. (35 bodova) +

void f(Node** lst, int broj){
    if((*lst) == NULL){
        printf("Greska");
        return;
    }
    if((*lst)->next == NULL){
        Node* tmp1 = malloc(sizeof(Node));
        tmp1->next = NULL;
        tmp1->data = broj;
        (*lst)->next = tmp1;
    } else {
        Node* tmp2 = malloc(sizeof(Node));
        tmp2->data = broj;
        tmp2->next = NULL;
        
        Node* current = (*lst)->next;
        if(current->next == NULL){
            tmp2->next = current;
            (*lst)->next = tmp2;
        } else {
            while (current->next->next != NULL) {
                current  = current->next;
            }
            tmp2->next = current->next;
            current->next = tmp2;
        }
    }
}


//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element sa tim brojem nakon najvećeg broja u listi. (35 bodova) +

void f(Node** lst, int broj){
    if((*lst) == NULL || (*lst)->next == NULL){
        printf("Greska");
        return;
    }
    Node* current = (*lst)->next;
    Node* najveci = current;
    while (current != NULL) {
        if(najveci->data < current->data){
            najveci = current;
        }
        current = current->next;
    }
    Node* tmp1 = malloc(sizeof(Node));
    tmp1->data = broj;
    tmp1->next = najveci->next;
    najveci->next = tmp1;
    
}


//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan dodatni broj. Funkcija će dodati novi element sa tim brojem na sredinu liste (ili odmah nakon sredine ako je broj elemenata neparan). (35 bodova) +

void f(Node** lst, int broj){
    if((*lst) == NULL || (*lst)->next == NULL){
        printf("Greska");
        return;
    }
    
    Node* current = (*lst)->next;
    int brojac = 0;
    int i;
    while (current != NULL) {
        brojac++;
        current = current->next;
    }
    current = (*lst)->next;
    
    brojac = brojac / 2;
    
    for(i = 0; i < brojac; i++){
        current = current->next;
    }
    Node* tmp = malloc(sizeof(Node));
    tmp->next = current->next;
    current->next = tmp;
    tmp->data = broj;
    
}


//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i jedan indeks. Funkcija će dodati novi element na tom indeksu sa brojem 0. Ako indeks nije legalan (vanka je dužine liste), funkcija ne čini ništa . (35 bodova) +

void f(Node** lst, int indeks){
    if((*lst) == NULL){
        printf("Greska");
        return;
    }
    Node* current  = (*lst);
    int brojac = 0;
    int i;
    while (current != NULL) {
        current = current->next;
        brojac++;
    }
    if(brojac <= indeks){
        printf("Ne radi nista");
        return;
    }
    current = (*lst);
    for(i = 0; i < indeks - 1; i++){
        current = current->next;
    }
    Node* tmp = malloc(sizeof(Node));
    tmp->data = broj;
    tmp->next = current->next;
    current->next = tmp;
    
}


//4.    Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i dva indeksa. Funkcija će obrisati sve elemente liste između ta dva indeksa. Indeksi su legalni i prvi je manji od drugog. (35 bodova) +

void f(Node** lst, int indeks1, int indeks2){
    if((*lst) == NULL){
        printf("Greska");
        return;
    }
    Node* start = NULL;
    Node* end = NULL;
    Node* current = (*lst);
    int i;
    if(indeks1 == 0){
        start = (*lst);
    } else {
        for(i = 0; i < indeks1 - 1; i++){
            current = current->next;
        }
        
        start = current->next;
    }
    Node* tmp = current;
    end = start;
    for(i = 0; i < indeks2 - indeks1; i++){
        end = end->next;
    }
    while (start != end->next) {
        Node* brisi = start;
        start = start->next;
        free(brisi);
    }
    
}


void f(Node** lst, int indeks1, int indeks2) {
    if (*lst == NULL) {
        printf("Greska\n");
        return;
    }

    Node* current = *lst;
    Node* start = NULL;
    Node* end = NULL;

    if(indeks1 == 0){
        start = (*lst);
    } else {
        for(int i = 0; i < indeks1 - 1; i++){
            current = current->next;
        }
        start = current->next;
    }
    
    end = start;
    for(int i = 0; i < indeks2 - indeks1; i++){
        end = end->next;
    }
    
    
    if(indeks1 == 0){
        (*lst) = end->next;
    } else {
        current->next = end->next;
    }
    while (start != end->next) {
        Node* tmp = start;
        start = start->next;
        free(tmp);
    }
}

