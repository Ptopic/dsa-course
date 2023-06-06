#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	BSTree tree = NULL;
	return tree;
}

BSTree AddNode(BSTree bst, char *word)
{
	// Rekurzivno se traži mjesto za novi èvor u stablu. Ako rijeè postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokazivaè.
	if (bst == NULL) {
		Node* novi = (Node*)malloc(sizeof(Node));
		novi->word = word;
		novi->left = NULL;
		novi->right = NULL;
		//printf("%s \n", novi->word);
		return novi;
	}
	if (strcmp(word, bst->word) == 0) {
		return bst;
	}
	else {
		if (strcmp(word, bst->word) > 0) {
			bst->right = AddNode(bst->right, word);
		}
		else {
			bst->left = AddNode(bst->left, word);
		}
		return bst;
	}

}


void dodajListovima(BSTree* bst, char* str)
{
	if (*bst == NULL)
		return;
	if ((*bst)->left == NULL && (*bst)->right == NULL)
	{
		Node* novi = (Node*)malloc(sizeof(Node));
		novi->word = strdup(str);
		novi->left = novi->right = NULL;
		(*bst)->left = novi;
		novi = (Node*)malloc(sizeof(Node));
		novi->word = strdup(str);
		novi->left = novi->right = NULL;
		(*bst)->right = novi;
		return;
	}
	dodajListovima(&((*bst)->left), str);
	dodajListovima(&((*bst)->right), str);
}

char* najduza(BSTree bst)
{
	if (bst == NULL)
		return "";
	char* nl = najduza(bst->left);
	char* nd = najduza(bst->right);
	if (strlen(bst->word) > strlen(nl) && strlen(bst->word) > strlen(nd))
		return bst->word;
	if (strlen(bst->word) < strlen(nl) && strlen(nl) > strlen(nd))
		return nl;
	return nd;
}


int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se pronašla najduža grana (visina stabla).
	if (bst == NULL) {
		return 0;
	}
	int left = BSTHeight(bst->left);
	int right = BSTHeight(bst->right);

	return 1 + ((left > right) ? left : right);
	
	//if (left > right) {
	//	// Ako je lijeva veca od desne grane (najveca grana) vracamo tu granu + root (1)
	//	return left + 1;
	//}
	//else {
	//	// Ako je desna veca od lijeve grane (najveca grana) vracamo tu granu + root (1)
	//	return right + 1;
	//}
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rijeèi u stablu na ekran po abecednom redu.
	// In-order šetnja po stablu (lijevo dijete, èvor, desno dijete)

	// Base case
	if (bst == NULL) {
		return;
	}

	PrintBSTree(bst->left);
	printf("%s \n", bst->word);
	PrintBSTree(bst->right);
}

// Ispis po kriteriju
// Npr ako je rijec duza od 10

void PrintBSTreePoKriteriju(BSTree bst)
{
	if (bst == NULL)
		return;
	// Ispisi ako je rijec duza od 10
	if (strlen(bst->word) > 10)
		printf("%s ", bst->word);
	printLT(bst->left);
	printLT(bst->right);
}


void PrintLeafs(BSTree bst) {
	if (bst == NULL) {
		return;
	}

	// Ako postoji liva ili desna taj node nije list
	// Za pretragu listova if(!bst->left && !bst->right)
	if (!bst->left && !bst->right) {
		printf("leaf - node %s \n", bst->word);
	}

	if (bst->left) {
		PrintLeafs(bst->left);
	}

	if (bst->right) {
		PrintLeafs(bst->right);
	}

}

void PrintNonLeafs(BSTree bst) {
	if (bst == NULL) {
		return;
	}

	// Ako postoji liva ili desna taj node nije list
	// Za pretragu listova if(!bst->left && !bst->right)
	if (bst->left || bst->right) {
		printf("non leaf - node %s \n", bst->word);
	}

	if (bst->left) {
		PrintNonLeafs(bst->left);
	}

	if (bst->right) {
		PrintNonLeafs(bst->right);
	}

}






void izbrisidesnopodstablo(BSTree* bst) {
	DeleteBSTree((*bst)->right);
	(*bst)->right = NULL;
}

// brisiListove(&bst);
void brisiListove(BSTree* bst)
{
	if (*bst == NULL)
		return;
	if ((*bst)->left == NULL && (*bst)->right == NULL)
	{
		free((*bst)->word);
		free(*bst);
		*bst = NULL;
		return;
	}
	brisiListove(&((*bst)->left));
	brisiListove(&((*bst)->right));
}


void brisiListovePoKriteriju(BSTree* bst)
{
	if (*bst == NULL)
		return;
	if ((*bst)->left == NULL && (*bst)->right == NULL)
	{
		if ((*bst)->word == "a") {
			free((*bst)->word);
			free(*bst);
			*bst = NULL;
		}
		return;
	}
	brisiListove(&((*bst)->left));
	brisiListove(&((*bst)->right));
}

void deleteNode(BSTree* bst) {
	if (*bst == NULL)
		return;
}


void DeleteBSTree(BSTree bst)
{
	// Bri�e stablo (string word i sam �vor) iz memorije.
	// Post-order �etnja po stablu (prvo djeca pa trenutni �vor)
	if (bst == NULL)
		return;
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	free(bst->word);
	free(bst);
}






























//void DeleteBSTree(BSTree* bst)
//{
//	// Briše stablo (string word i sam èvor) iz memorije.
//	// Post-order šetnja po stablu (prvo djeca pa trenutni èvor)
//
//	// Base case
//	if (*bst == NULL) {
//		return;
//	}
//	if ((*bst)->left == NULL && (*bst)->right == NULL) {
//		free(*bst);
//		*bst = NULL;
//		return;
//	}
//	DeleteBSTree(&((*bst)->left));
//	DeleteBSTree(&((*bst)->right));
//}






void SaveBSTree(BSTree bst, FILE* fd)
{
	// Snima rijeè po rijeè iz stabla u tekstualnu datoteku. Rijeèi su odvojene razmakom.
	// Pre-order šetnja po stablu (ttenutni èvor pa djeca)

	// Base case
	if (bst == NULL) {
		return;
	}

	// Snimi rijec u datoteku
	fprintf(fd, "%s ", bst->word);

	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);
}


BSTree LoadBSTree(FILE *fd)
{
	// Uèitava rijeè po rijeè iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rijeè duplicirati sa strdup().

	BSTree bst = NULL;

	char buffer[1024];

	// Read file word by word
	while (readWord(fd, buffer))
	{
		bst = AddNode(bst, strdup(buffer));
	}
	return bst;
}
