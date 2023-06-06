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
	// Rekurzivno se tra�i mjesto za novi �vor u stablu. Ako rije� postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokaziva�.
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

int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se prona�la najdu�a grana (visina stabla).
	if (bst == NULL) {
		return 0;
	}
	int left = BSTHeight(bst->left);
	int right = BSTHeight(bst->right);


	if (left > right) {
		// Ako je lijeva veca od desne grane (najveca grana) vracamo tu granu + root (1)
		return left + 1;
	}
	else {
		// Ako je desna veca od lijeve grane (najveca grana) vracamo tu granu + root (1)
		return right + 1;
	}
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rije�i u stablu na ekran po abecednom redu.
	// In-order �etnja po stablu (lijevo dijete, �vor, desno dijete)

	// Base case
	if (bst == NULL) {
		return;
	}

	PrintBSTree(bst->left);
	printf("%s \n", bst->word);
	PrintBSTree(bst->right);


}

void SaveBSTree(BSTree bst, FILE *fd)
{
	// Snima rije� po rije� iz stabla u tekstualnu datoteku. Rije�i su odvojene razmakom.
	// Pre-order �etnja po stablu (ttenutni �vor pa djeca)

	// Base case
	if (bst == NULL) {
		return;
	}

	// Snimi rijec u datoteku
	fprintf(fd, "%s ", bst->word);

	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree* bst)
{
	// Bri�e stablo (string word i sam �vor) iz memorije.
	// Post-order �etnja po stablu (prvo djeca pa trenutni �vor)

		// Base case
	if (*bst == NULL) {
		return;
	}
	if ((*bst)->left == NULL && (*bst)->right == NULL) {
		free(*bst);
		*bst = NULL;
		return;
	}
	DeleteBSTree(&((*bst)->left));
	DeleteBSTree(&((*bst)->right));
}


int loadWord(FILE* fd, char* buffer)
{
	int c;

	do {
		c = fgetc(fd);
		if (c == EOF)
			return 0;
	} while (!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if (c == 146)
			c = '\'';
	} while (isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}

BSTree LoadBSTree(FILE *fd)
{
	// U�itava rije� po rije� iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rije� duplicirati sa strdup().

	BSTree bst = NULL;

	char buffer[1024];

	// Read file word by word
	while (readWord(fd, buffer))
	{
		bst = AddNode(bst, strdup(buffer));
	}
	return bst;
}
