
#include <stdio.h>

typedef struct _Element {
    int broj;
    struct _Element* next;
} Element;

typedef struct {
    struct _Element* lst;
} Lista;

//typedef Element* Lista;

void print(Element* lst) {
    Element* tmp = lst;
    while (tmp != NULL) {
        printf("%d -> ", tmp->broj);
        tmp = tmp->next;
    }
    printf("NULL\n");
}


Element* dodaj_na_kraj(Element* lst, int broj) {
    Element* novi = (Element*)malloc(sizeof(Element));
    novi->broj = broj;
    novi->next = NULL;
    if (lst == NULL) {
        return novi;
    }
    Element* tmp = lst;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = novi;
    return lst;
}

Element* dodaj_po_redu(Element* lst, int broj) {
    Element* novi = (Element*)malloc(sizeof(Element));
    novi->broj = broj;

    if (lst == NULL) {
        novi->next = lst;
        return novi;
    }

    if (lst->broj > broj) {
        novi->next = lst;
        return novi;
    }

    Element* tmp = lst;
    while (tmp->next != NULL && tmp->next->broj < broj) {
        tmp = tmp->next;
    }
    novi->next = tmp->next;
    tmp->next = novi;
    return lst;
}

Element* izbrisi_element(Element* lst, int broj) {

    if (lst == NULL)
        return NULL;

    if (broj == lst->broj) {
        Element* brisi = lst;
        lst = lst->next;
        free(brisi);
        return lst;
    }

    Element* tmp = lst;
    while (tmp->next != NULL) {
        if (tmp->next->broj == broj) {
            Element* brisi = tmp->next;
            tmp->next = tmp->next->next;
            free(brisi);
            return lst;
        }
        tmp = tmp->next;
    }
    return lst;
}

Element* spoji(Element* lsta, Element* lstb) {
    if (lsta == NULL) {
        return lstb;
    }
    if (lstb == NULL) {
        return lsta;
    }
    Element* tmp = lsta;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = lstb;
    return lsta;
}

Element* okreni(Element* lst) {
    Element* olst = NULL;

    while (lst != NULL) {
        Element* tmp = lst;
        lst = lst->next;
        tmp->next = olst;
        olst = tmp;
    }

    return olst;
}

Element* brisi_parne(Element* lst) {
    if (lst == NULL)
        return NULL;
    Element* p = lst;
    Element* t = lst->next;
    while (t != NULL) {
        if (t->broj % 2 == 0) {
            p->next = t->next;
            free(t);
            t = p->next;
        }
        else {
            p = p->next;
            t = t->next;
        }
    }
    if (lst->broj % 2 == 0) {
        t = lst;
        lst = lst->next;
        free(t);
    }
    return lst;
}

void podijeli(Element* lst, Element** prvi, Element** drugi) {
    if (lst == NULL) {
        *prvi = NULL;
        *drugi = NULL;
        return;
    }
    int cnt = 0;
    Element* tmp = lst;
    while (tmp != NULL) {
        cnt++;
        tmp = tmp->next;
    }
    cnt = cnt / 2;
    tmp = lst;
    for (int i = 0; i < cnt - 1; i++) {
        tmp = tmp->next;
    }
    *prvi = lst;
    *drugi = tmp->next;
    tmp->next = NULL;
}

void podijeli_brze(Element* lst, Element** prvi, Element** drugi) {
    if (lst == NULL) {
        *prvi = NULL;
        *drugi = NULL;
        return;
    }
    Element* k = lst;
    Element* z = lst->next;
    while (z != NULL && z->next != NULL) {
        z = z->next->next;
        k = k->next;
    }

    *prvi = lst;
    *drugi = k->next;
    k->next = NULL;
}

void main() {
    Element* lsta = NULL;
    Element* lstb = NULL;
    Element* lstc = NULL;
    lsta = dodaj_po_redu(lsta, 8);
    lsta = dodaj_po_redu(lsta, 4);
    lsta = dodaj_po_redu(lsta, 6);
    lsta = dodaj_po_redu(lsta, 2);
    lsta = dodaj_po_redu(lsta, 9);

    print(lsta);
    podijeli_brze(lsta, &lstb, &lstc);
    print(lstb);
    print(lstc);
    /*
    lstb = dodaj_po_redu(lstb, 50);
    lstb = dodaj_po_redu(lstb, 40);
    lstb = dodaj_po_redu(lstb, 30);
    lstb = dodaj_po_redu(lstb, 20);
    print(lsta);
    print(lstb);
    Element* lstc = spoji(lsta, lstb);
    print(lstc);

    lstc = okreni(lstc);
    print(lstc);

    lstc = brisi_parne(lstc);
    print(lstc);
    */
}

