#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	return NULL;
}

void AddNode(BSTree *bst, char *word)
{
	// Rekurzivno se tra�i mjesto za novi �vor u stablu. Ako rije� postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokaziva�.
	if (*bst == NULL)
	{
		Node *novi = (Node *)malloc(sizeof(Node));
		novi->word = word;
		novi->left = novi->right = NULL;
		*bst = novi;
	}
	else if (strcmp(word, (*bst)->word) > 0)
	{
		AddNode(&((*bst)->left), word);
	}
	else if (strcmp(word, (*bst)->word) < 0)
	{
		AddNode(&((*bst)->right), word);
	}
	else
	{
		free(word);
	}
}

// int BSTHeight(BSTree bst)
// {
// 	// Rekurzivno se prolazi cijelo stablo da bi se prona�la najdu�a grana (visina stabla).
// 	if (bst == NULL)
// 		return 0;
// 	int hl = BSTHeight(bst->left);
// 	int hr = BSTHeight(bst->right);
// 	return 1 + ((hl > hr) ? hl : hr);
// }

// void printLT(BSTree bst) {
// 	// ispisi sve rijeci iz stabla duze od 10 znakova
// 	if (bst == NULL)
// 		return;
// 	if (strlen(bst->word) > 10)
// 		printf("%s ", bst->word);
// 	printLT(bst->left);
// 	printLT(bst->right);
// }

/* bolje ne
void printLT(BSTree bst) {
	// ispisi sve rijeci iz stabla duze od 10 znakova
	if (bst == NULL)
		return;
	if (strlen(bst->word) > 10)
		printf("%s ", bst->word);
	if (bst->left)
		printLT(bst->left);
	if (bst->right)
		printLT(bst->right);
}
*/

void brisiListove(BSTree *bst)
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

BSTree brisiListove2(BSTree bst)
{
	if (bst == NULL)
		return NULL;
	if (bst->left == NULL && bst->right == NULL)
	{
		free(bst->word);
		free(bst);
		return NULL;
	}
	bst->left = brisiListove2(bst->left);
	bst->right = brisiListove2(bst->right);
	return bst;
}

// !!!!!!!!
void dodajListovima(BSTree *bst, char *str)
{
	if (*bst == NULL)
		return;
	if ((*bst)->left == NULL && (*bst)->right == NULL)
	{
		Node *novi = (Node *)malloc(sizeof(Node));
		novi->word = strdup(str);
		novi->left = novi->right = NULL;
		(*bst)->left = novi;
		novi = (Node *)malloc(sizeof(Node));
		novi->word = strdup(str);
		novi->left = novi->right = NULL;
		(*bst)->right = novi;
		return;
	}
	dodajListovima(&((*bst)->left), str);
	dodajListovima(&((*bst)->right), str);
}

// !!!!!!!!!
char *najduza(BSTree bst)
{
	if (bst == NULL)
		return "";
	char *nl = najduza(bst->left);
	char *nd = najduza(bst->right);
	if (strlen(bst->word) > strlen(nl) && strlen(bst->word) > strlen(nd))
		return bst->word;
	if (strlen(bst->word) < strlen(nl) && strlen(nl) > strlen(nd))
		return nl;
	return nd;
}

// void izbrisidesnopodstablo(BSTree *bst) {
// 	DeleteBSTree((*bst)->right);
// 	(*bst)->right = NULL;
// }

// !!!!!!
void izbrisinajdesniji(BSTree *bst)
{
	if (*bst == NULL)
		return NULL;

	if ((*bst)->right == NULL)
	{
		BSTree left = (*bst)->left;
		free((*bst)->word);
		free(*bst);
		*bst = left;
		return;
	}
	izbrisinajdesniji(&((*bst)->right));
}

// void PrintBSTree(BSTree bst)
// {
// 	// Ispisuje rije�i u stablu na ekran po abecednom redu.
// 	// In-order �etnja po stablu (lijevo dijete, �vor, desno dijete)
// 	if (bst == NULL)
// 		return;
// 	PrintBSTree(bst->left);
// 	printf("%s\n", bst->word);
// 	PrintBSTree(bst->right);
// }

// void SaveBSTree(BSTree bst, FILE *fd)
// {
// 	// Snima rije� po rije� iz stabla u tekstualnu datoteku. Rije�i su odvojene razmakom.
// 	// Pre-order �etnja po stablu (ttenutni �vor pa djeca)
// 	if (bst == NULL)
// 		return;
// 	fprintf(fd, "%s\n", bst->word);
// 	SaveBSTree(bst->left, fd);
// 	SaveBSTree(bst->right, fd);
// }

// void DeleteBSTree(BSTree bst)
// {
// 	// Bri�e stablo (string word i sam �vor) iz memorije.
// 	// Post-order �etnja po stablu (prvo djeca pa trenutni �vor)
// 	if (bst == NULL)
// 		return;
// 	DeleteBSTree(bst->left);
// 	DeleteBSTree(bst->right);
// 	free(bst->word);
// 	free(bst);
// }

// BSTree LoadBSTree(FILE *fd)
// {
// 	// U�itava rije� po rije� iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
// 	// Rije� duplicirati sa strdup().
// 	BSTree t = NewBSTree();
// 	char buffer[1000];
// 	while (!feof(fd))
// 	{
// 		fgets(buffer, 999, fd);
// 		AddNode(&t, strdup(buffer));
// 	}
// 	return t;
// }
