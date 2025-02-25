//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj b). Funkcija vraća broj elemenata liste čiji su brojevi jednaki zadnjem broju u listi. Kolika je složenost funkcije O()? (25 bodova)

int f(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna");
        return 0;
    }
    if(lst->next == NULL){
        printf("Lista ima jedan element");
        return 0;
    }
    int brojac = 0;
    Node* current = lst;
    Node* tmp = lst;
    int trazeni = 0;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    trazeni = tmp->data;
    while (current != NULL) {
        if(current->data == trazeni){
            brojac++;
        }
        current = current->next;
    }
    
    
    return brojac;
}

//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj b). Funkcija vraća broj elemenata liste čiji su prethodni i idući element jednaki (brojevi su im jednaki). Kolika je složenost funkcije O()? (25 bodova)

int f(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna");
        return 0;
    }
    if(lst->next == NULL){
        printf("lista ima jedan element");
        return 0;
    }
    int brojac = 0;
    Node* current = lst->next;
    Node* prev = lst;
    while (current->next != NULL) {
        if(prev->data == current->data){
            brojac++;
        }
        prev = current;
        current = current->next;
    }
    
    return brojac;
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija provjerava da li je lista sortirana uzlazno. Funkcija vraća 0 ako nije sortirana ili 1 ako je. Kolika je složenost funkcije O()? (25 bodova)

int f(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna");
        return 0;
    }
    Node* current = lst;
    while (current->next != NULL) {
        if(current->data > current->next->data){
            return 0;
        }
        current = current->next;
    }
    
    return 1;
}



//3.    Napisati funkciju koja prima dvije jednostruko vezane liste (svaki element sadrži broj). Funkcija provjerava da li su obje liste potpuno jednake. Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova)

int f(Node* lst1, Node* lst2){
    if(lst1 == NULL || lst2 == NULL){
        printf("Obe liste su prazne, zato su jednake");
        return 1;
    }
    while (lst1 != NULL && lst2 != NULL) {
        if(lst1->data != lst2->data){
            return 0;
        }
        lst1 = lst1->next;
        lst2 = lst2->next;
    }
    if(lst1 != NULL || lst2 != NULL){
        return 0;
    }
    return 1;
}



//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija provjerava da li je lista sadrži višestruke brojeve. Funkcija vraća 1 ako su svi elementi jedinstveni ili 0 ako nisu. Kolika je složenost funkcije O()? (25 bodova)

int f(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna");
        return 0;
    }
    while (lst != NULL) {
        Node* tmp = lst->next;
        while (tmp != NULL) {
            if(lst->data == tmp->data){
                return 0;
            }
            tmp = tmp->next;
        }
        lst = lst->next;
    }
    return 1;
}



//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija provjerava da li je lista sadrži sve brojeve od 1 do 10. Funkcija vraća 1 ako su svi brojevi u listi ili 0 ako nisu. Kolika je složenost funkcije O()? (25 bodova)

int f(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna");
        return 0;
    }
    int niz[11] = {0};
    Node* tmp = lst;
    while (tmp != NULL) {
        if(tmp->data >= 1 && tmp->data <= 10){
            niz[tmp->data] = 1;
        }
        tmp = tmp->next;
    }
    for(int i = 1; i <= 10; i++){
        if(niz[i] != 1){
            return 0;
        }
    }
    return 1;
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će vratiti pokazivač na element sa najvećim brojem. (25 bodova)

Node* f(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna");
        return NULL;
    }
    Node* najveci = lst;
    lst = lst->next;
    while (lst != NULL) {
        if(najveci->data <= lst->data){
            najveci = lst;
        }
        lst = lst->next;
    }
    return najveci;
}



//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će izbrojati koliko je brojeva liste veće od prethodnog broja u listi. (25 bodova)

int f(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna");
        return 0;
    }
    int brojac = 0;
    Node* tmp = lst;
    while (tmp->next != NULL) {
        if(tmp->data < tmp->next->data){
            brojac++;
        }
        tmp = tmp->next;
    }
    return brojac;
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će između svaka dva parna susjedna broja dodati novi element sa brojem 0. Kolika je složenost funkcije O()? (35 bodova)

void f(Node** lst){
    if((*lst) == NULL){
        printf("Lista je prazna");
        return;
    }
    Node* current = (*lst);
    while (current->next != NULL) {
        if(current->data % 2 == 0 && current->next->data % 2 == 0){
            Node* novi = malloc(sizeof(Node));
            novi->next = current->next;
            novi->data = 0;
            current->next = novi;
            current = novi->next;
        } else {
            current = current->next;
        }
    }
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će provjeriti da li se ijedan broj u listi ponavlja. (25 bodova)

void f(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna");
        return;
    }
    while (lst != NULL) {
        Node* tmp = lst->next;
        while (tmp != NULL) {
            if(lst->data == tmp->data){
                printf("Broj se ponavlja");
                return;
            }
            tmp = tmp->next;
        }
        lst = lst->next;
    }
    printf("Brojevi se ne ponavljaju");
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i provjerava da li se svi elementi sa parnim brojem nalaze između dva elementa sa neparnim brojem. Prvi i zadnji element sadrži neparni broj, a primljena lista ima barem 3 elementa. Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova)

int f(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna");
        return 0;
    }
    Node* start = lst;
    Node* end;
    Node* current = lst;
    while (current->next != NULL) {
        current = current->next;
    }
    end = current;
    current = lst->next;
    if(start->data % 2 == 0 || end->data % 2 == 0){
        printf("Pocetak ili kraj nisu neparni");
        return 0;
    }
    while (current->next != NULL) {
        if(current->data % 2 != 0){
            return 0;
        }
        current = current->next;
    }
    return 1;
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i jedan broj. Funkcija će ispisati sve elemente liste veće od tog broja. (25 bodova)

void f(Node* lst, int broj){
    if(lst == NULL){
        printf("Lista je prazna");
        return;
    }
    while (lst != NULL) {
        if(lst->data > broj){
            printf("%d ", lst->data);
        }
        lst = lst->next;
    }
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će provjeriti da li je lista sortirana uzlazno. (25 bodova)

void f(Node* lst){
    if(lst == NULL){
        printf("Greska");
        return;
    }
    while (lst->next != NULL) {
        if(lst->data > lst->next->data){
            printf("Lista nije sortirana");
            return;
        }
        lst = lst->next;
    }
    
    printf("Sortirana je uzlazno");
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i provjerava da li su svi elementi u listi različiti. Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova)

int f(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna");
        return 0;
    }
    while (lst != NULL) {
        Node* tmp = lst->next;
        while (tmp != NULL) {
            if(tmp->data == lst->data){
                return 0;
            }
            tmp = tmp->next;
        }
        lst = lst->next;
    }
    
    
    return 1;
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i jedan broj. Funkcija će izbrojati koliko je elemenata liste veće od tog broja. (25 bodova)

void f(Node* lst, int broj){
    if(lst == NULL){
        printf("Lista je prazna");
        return;
    }
    int brojac = 0;
    while (lst != NULL) {
        if(lst->data > broj){
            brojac++;
        }
        lst = lst->next;
    }
    
    
    printf("%d ", brojac);
}


//3.    Napisati funkciju koja prima dvije jednostruko vezane liste (svaki element sadrži broj) i vraća listu. Druga lista ima barem jedan element. Funkcija na početak prve liste prebacuje zadnji element druge liste. (25 bodova)

Node* f(Node** lst1, Node** lst2){
    if((*lst1) == NULL || (*lst2) == NULL){
        printf("Jedna lista je prazna");
        return;
    }
    Node* current2 = (*lst2);
    Node* tmp = NULL;
    while (current2->next != NULL) {
        tmp = current2;
        current2 = current2->next;
    }
    if(tmp == NULL){
        (*lst2)->next = (*lst1);
        (*lst1) = (*lst2);
    } else if (tmp != NULL){
        tmp->next = NULL;
        current2->next = (*lst1);
        (*lst1) = current2;
    }
    
    return *lst1;
}


//3.    Napisati funkciju koja prima dvije jednostruko vezane liste (svaki element sadrži broj) i vraća listu. Druga lista ima barem jedan element. Funkcija na kraj prve liste prebacuje prvi element druge liste. (25 bodova)

Node* f(Node** lst1, Node** lst2){
    if((*lst1) == NULL || (*lst2) == NULL){
        printf("lista je prazna, barem jedna");
        return NULL;
    }
    Node* current2 = (*lst2);
    (*lst2) = (*lst2)->next;
    
    while (current1->next != NULL) {
        current1 = current1->next;
    }
    current1->next = current2;
    return *lst1;
}

















//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj b). Funkcija vraća broj elemenata liste čiji su brojevi jednaki zadnjem broju u listi. Kolika je složenost funkcije O()? (25 bodova) +

int f(Node* lst){
    if(lst == NULL){
        printf("Prazna lista");
        return 0;
    }
    int najveci;
    int brojac = 0;
    Node* current = lst;
    while (current->next != NULL) {
        current = current->next;
    }
    najveci = current->data;
    current = lst;
    while (current != NULL) {
        if(current->data == najveci){
            brojac++;
        }
        current = current->next;
    }
    return brojac;
}

//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj b). Funkcija vraća broj elemenata liste čiji su prethodni i idući element jednaki (brojevi su im jednaki). Kolika je složenost funkcije O()? (25 bodova) +

int f(Node* lst){
    if(lst == NULL){
        printf("Greska");
        return 0;
    }
    int brojac = 0;
    Node* current = lst;
    while (current->next->next != NULL) {
        if(current->data == current->next->next->data){
            brojac++;
        }
        current = current->next;
    }
    return brojac;
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija provjerava da li je lista sortirana uzlazno. Funkcija vraća 0 ako nije sortirana ili 1 ako je. Kolika je složenost funkcije O()? (25 bodova) +

int f(Node* lst){
    if(lst == NULL){
        printf("Greska");
        return 0;
    }
    while (lst->next != NULL) {
        if(lst->data > lst->next->data){
            return 0;
        }
        lst = lst->next;
    }
    return 1;
}

//3.    Napisati funkciju koja prima dvije jednostruko vezane liste (svaki element sadrži broj). Funkcija provjerava da li su obje liste potpuno jednake. Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova) +

int f(Node* lsta, Node* lstb){
    if(lsta == NULL && lstb == NULL){
        return 1;
    }
    if(lsta == NULL || lstb == NULL){
        return 0;
    }
    while (lsta != NULL && lstb != NULL) {
        if(lsta->data != lstb->data){
            return 0;
        }
        lsta = lsta->next;
        lstb = lstb->next;
    }
    if(lsta != lstb){
        return 0;
    }
    return 1;
}

//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija provjerava da li je lista sadrži višestruke brojeve. Funkcija vraća 1 ako su svi elementi jedinstveni ili 0 ako nisu. Kolika je složenost funkcije O()? (25 bodova) +

int f(Node* lst){
    if(lst == NULL){
        printf("Greska");
        return 0;
    }
    Node* current = lst;
    Node* tmp = NULL;
    while (current->next != NULL) {
        tmp = current->next;
        while (tmp != NULL) {
            if(current->data == tmp->data){
                return 0;
            }
            tmp = tmp->next;
        }
        current = current->next;
    }
    return 1;
}



//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija provjerava da li je lista sadrži sve brojeve od 1 do 10. Funkcija vraća 1 ako su svi brojevi u listi ili 0 ako nisu. Kolika je složenost funkcije O()? (25 bodova) +

int f(Node* lst){
    if(lst == NULL){
        printf("greska");
        return 0;
    }
    int niz[11] = {0};
    Node* current = lst;
    
    while (current != NULL) {
        if(current->data >= 1 && current->data <= 10){
            niz[current->data] = 1;
        }
        current = current->next;
    }
    for(int i = 1; i <= 10; i++){
        if(niz[i] == 0){
            return 0;
        }
    }
    
    return 1;
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će vratiti pokazivač na element sa najvećim brojem. (25 bodova) +

Node* f(Node* lst){
    if (lst == NULL){
        printf("greska");
        return NULL;
    }
    Node* vrati = lst;
    Node* current = lst;
    while (current != NULL) {
        if(current->data > vrati->data){
            vrati = current;
        }
        current = current->next;
    }
    return vrati;
}



//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će izbrojati koliko je brojeva liste veće od prethodnog broja u listi. (25 bodova) +

int f(Node* lst){
    if(lst == NULL){
        printf("Greska");
        return 0;
    }
    int brojac = 0;
    Node* current = lst;
    while (current->next != NULL) {
        if(current->next->data > current->data){
            brojac++;
        }
        current = current->next;
    }
    
    return brojac;
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će između svaka dva parna susjedna broja dodati novi element sa brojem 0. Kolika je složenost funkcije O()? (35 bodova) +

void f(Node** lst){
    if((*lst) == NULL){
        printf("Greska");
        return;
    }
    Node* current = (*lst);
    while (current->next != NULL) {
        if(current->data % 2 == 0 && current->next->data % 2 == 0){
            Node* tmp = malloc(sizeof(Node));
            tmp->next = current->next;
            current->next = tmp;
            tmp->data = 0;
            current = tmp;
        }
        current = current->next;
    }
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će provjeriti da li se ijedan broj u listi ponavlja. (25 bodova) +

void f(Node* lst){
    if(lst == NULL){
        printf("Greska");
        return;
    }
    Node* tmp;
    while (lst != NULL) {
        tmp = lst->next;
        while (tmp != NULL) {
            if(lst->data == tmp->data){
                printf("Ponavlja se");
                return;
            }
            tmp = tmp->next;
        }
        lst = lst->next;
    }
    printf("Nijedan se ne ponavlja");
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i provjerava da li se svi elementi sa parnim brojem nalaze između dva elementa sa neparnim brojem. Prvi i zadnji element sadrži neparni broj, a primljena lista ima barem 3 elementa. Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova) +

int f(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna");
        return 0;
    }
    if(lst->data % 2 == 0){
        printf("prvi je paran");
        return 0;
    }
    Node* kraj = lst;
    Node* current = lst;
    while (kraj->next != NULL) {
        kraj = kraj->next;
    }
    if(kraj->data % 2 == 0){
        printf("Zadnji je paran");
        return 0;
    }
    current = current->next;
    while (current->next != NULL) {
        if (current->data % 2 != 0) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i jedan broj. Funkcija će ispisati sve elemente liste veće od tog broja. (25 bodova) +

void f(Node* lst, int broj){
    if(lst == NULL){
        printf("Greska");
        return;
    }
    while (lst != NULL) {
        if(lst->data > broj){
            printf("%d ", lst->data);
        }
        lst = lst->next;
    }
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj). Funkcija će provjeriti da li je lista sortirana uzlazno. (25 bodova)

int f(Node* lst){
    if(lst == 0){
        printf("Greska");
        return 0;
    }
    while (lst->next != NULL) {
        if(lst->data > lst->next->data){
            return 0;
        }
        lst = lst->next;
    }
    return 1;
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i provjerava da li su svi elementi u listi različiti. Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova) +

int f(Node* lst){
    if(lst == NULL){
        printf("Lista je prazna");
        return 0;
    }
    
    Node* tmp = NULL;
    while (lst != NULL) {
        tmp = lst->next;
        while (tmp != NULL) {
            if(tmp->data == lst->data){
                return 0;
            }
            tmp = tmp->next;
        }
        lst = lst->next;
    }
    return 1;
}


//3.    Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i jedan broj. Funkcija će izbrojati koliko je elemenata liste veće od tog broja. (25 bodova) +

int f(Node* lst, int broj){
    if(lst == NULL){
        printf("Greska");
        return 0;
    }
    int brojac = 0;
    while (lst != NULL) {
        if(lst->data > broj){
            brojac++;
        }
        lst = lst->next;
    }
    return brojac;
}


//3.    Napisati funkciju koja prima dvije jednostruko vezane liste (svaki element sadrži broj) i vraća listu. Druga lista ima barem jedan element. Funkcija na početak prve liste prebacuje zadnji element druge liste. (25 bodova) +/-

Node* f(Node* lsta, Node* lstb){
    if(lsta == NULL && lstb == NULL){
        printf("Greska");
        return NULL;
    }
    Node* currentb = lstb;
    Node* tmp;
    if(lstb->next == NULL){
        lstb->next = lsta;
        lsta = lstb;
        return lsta;
    } else if (lstb->next->next == NULL){
        tmp = lstb->next;
        lstb->next = NULL;
        tmp->next = lsta;
        lsta = tmp;
        return lsta;
    } else {
        while (currentb->next != NULL && currentb->next->next != NULL) {
            currentb = currentb->next;
        }
        tmp = currentb->next;
        currentb->next = NULL;
        tmp->next = lsta;
        lsta = tmp;
        return lsta;
    }
}



//3.    Napisati funkciju koja prima dvije jednostruko vezane liste (svaki element sadrži broj) i vraća listu. Druga lista ima barem jedan element. Funkcija na kraj prve liste prebacuje prvi element druge liste. (25 bodova)

Node* f(Node* lsta, Node* lstb){
    if(lsta == NULL || lstb == NULL){
        printF("Greska");
        return NULL;
    }
    Node* currenta = lsta;
    while (currenta->next != NULL) {
        currenta = currenta->next;
    }
    Node* tmp;
    tmp = lstb;
    lstb = lstb->next;
    tmp->next = NULL;
    currenta->next = tmp;
    return lsta;
}

