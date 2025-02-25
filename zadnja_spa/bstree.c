#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

BSTree NewBSTree(){
	// Novo prazno stablo
    
	return NULL;
}

void AddNode(BSTree *bst, char *word){
	// Rekurzivno se trazi mjesto za novi cvor u stablu. Ako rijec postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokazivad.
    if (*bst == NULL) {
        Node *new = malloc(sizeof(Node));
        new->word = word;
        new->left = new->right = NULL;
        *bst = new;
        return;
    }
    if (strcmp(word, (*bst)->word) < 0) {
        AddNode(&((*bst)->left), word);
    }
    else if (strcmp(word, (*bst)->word) > 0) {
        AddNode(&((*bst)->right), word);
    } else {
        free(word);
    }
    
}

int BSTHeight(BSTree bst){
	// Rekurzivno se prolazi cijelo stablo da bi se pronasla najduza grana (visina stabla).
    if (bst == NULL) {
        return 0;
    }
    int livo = BSTHeight(bst->left);
    int desno = BSTHeight(bst->right);
    return 1 + (livo > desno ? livo : desno);
}

void PrintBSTree(BSTree bst){
	// Ispisuje rijesi u stablu na ekran po abecednom redu.
	// In-order setnja po stablu (lijevo dijete, cvor, desno dijete)
    if (bst == NULL) {
        return;
    }
    PrintBSTree(bst->left);
    printf("%s ", bst->word);
    PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE *fd){
	// Snima rijec po rijed iz stabla u tekstualnu datoteku. Rijeci su odvojene razmakom.
	// Pre-order setnja po stablu (ttenutni dvor pa djeca)
    if (bst == NULL) {
        return;
    }
    fprintf(fd, "%s ", bst->word);
    SaveBSTree(bst->left, fd);
    SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst){
	// Brise stablo (string word i sam cvor) iz memorije.
	// Post-order setnja po stablu (prvo djeca pa trenutni cvor)
    if (bst == NULL) {
        return;
    }
    DeleteBSTree(bst->left);
    DeleteBSTree(bst->right);
    free(bst->word);
    free(bst);
}

BSTree LoadBSTree(FILE *fd){
	// Ucitava rijec po rijec iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rijec duplicirati sa strdup().
    char buffer[256];
    BSTree bst = NewBSTree();
    while (fscanf(fd, "%s", buffer) != EOF) {
        AddNode(&bst, strdup(buffer));
    }
    return bst;
}
