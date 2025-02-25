//svaki iz prve mora biti veci od svakog iz druge liste
void f(Node** lsta, Node** lstb){
    if((*lsta) == NULL || (*lsta)->next == NULL || (*lstb) == NULL || (*lstb)->next == NULL){
        printf("Greska");
        return;
    }
    Node* currenta = (*lsta)->next;
    Node* currentb = (*lstb)->next;
    Node* preva = (*lsta);
    Node* prevb = (*lstb);
    
    Node* tmpa = NULL;
    
    int flag = 0;
    while (currenta != NULL) {
        currentb = (*lstb)->next;
        while (currentb != NULL) {
            if(currentb->data > currenta->data){
                flag = 1;
                tmpa = currenta;
                currenta = currenta->next;
                preva->next = currenta;
                free(tmpa);
                break;
            }
            currentb = currentb->next;
        }
        if(flag == 0){
            preva = currenta;
            currenta = currenta->next;
        }
        flag = 0;
    }
}



//vrati najmanji od obe liste
Node* f(Node* lsta, Node* lstb){
    if(lsta == NULL || lstb == NULL){
        printf("Greska");
        return NULL;
    }
    Node* najmanji = lsta;
    while (lsta != NULL) {
        if(najmanji->data > lsta->data){
            najmanji = lsta;
        }
        lsta = lsta->next;
    }
    while (lstb != NULL) {
        if(najmanji->data > lstb->data){
            najmanji = lstb;
        }
        lstb = lstb->next;
    }
    
    return najmanji;
}





//svaki iz prve mora biti veci od svakog iz druge liste


void f(Node** lsta, Node** lstb){
    if((*lsta) == NULL || (*lstb) == NULL){
        printf("Greska");
        return;
    }
    
    Node* currenta = (*lsta);
    Node* currentb = (*lstb);
    int flag = 0;
    while (currenta != NULL) {
        currentb = (*lstb);
        flag = 0;
        while (currentb != NULL) {
            if(currenta->data < currentb->data){
                flag = 1;
                break;
            }
            currentb = currentb->next;
        }
        if(flag == 1){
            Node* tmp = currenta;
            currenta = currenta->next;
            free(tmp);
        } else {
            currenta = currenta->next;
        }
    }
}


//vrati najmanji od obe liste

Node* f(Node* lsta, Node* lstb){
    Node* vrati = NULL;
    if(lsta == NULL || lstb == NULL){
        printf("Greska");
        return vrati;
    }
    vrati = lsta;
    Node* currenta = lsta;
    Node* currentb = lstb;
    while (currenta != NULL) {
        if(vrati->data > currenta->data){
            vrati = currenta;
        }
        currenta = currenta->next;
    }
    while (currentb != NULL) {
        if(vrati->data > currentb->data){
            vrati = currentb;
        }
        currentb = currentb->next;
    }
    
    
    return vrati;
}

