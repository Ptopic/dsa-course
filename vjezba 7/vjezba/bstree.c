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

int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se pronašla najduža grana (visina stabla).
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

void SaveBSTree(BSTree bst, FILE *fd)
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

void DeleteBSTree(BSTree* bst)
{
	// Briše stablo (string word i sam èvor) iz memorije.
	// Post-order šetnja po stablu (prvo djeca pa trenutni èvor)

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
