#include <stdio.h>
#include <ctype.h>
#include "bstree.h"

int readWord(FILE *fd, char *buffer)
{
	int c;
	
	do {
		c = fgetc(fd);				
		if(c == EOF)
			return 0;
	} while(!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if(c == 146)
			c = '\'';
	} while(isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}

void main()
{
	int wc;
	FILE *fd;
	char buffer[1024];
	BSTree bst;
	bst = NewBSTree();

	//// Kreiraj stablo
	//fd = fopen("D:/FAKULTET/--- 2 GODINA ---/1 SEMESTAR/spa/vjezba7/liar.txt", "rt");
	//if(fd == NULL)
	//{
	//	printf("Error opening file.\n");
	//	return;
	//}

	//wc = 0;
	//while(readWord(fd, buffer))
	//{
	//	//printf("%s\n", buffer);
	//	bst = AddNode(bst, strdup(buffer));
	//	wc++;
	//}

	//fclose(fd);

	//// Ispi�i stablo, visinu i broj �vorova
	//PrintBSTree(bst);
	//printf("\nH = %d, N = %d\n", BSTHeight(bst), wc);
	//

	////// Snimi i izbri�i
	//if((fd = fopen("D:/FAKULTET/--- 2 GODINA ---/1 SEMESTAR/spa/vjezba7/stablo.txt", "wt")) == NULL)
	//{
	//	printf("Error opening file for writing.\n");
	//	return;
	//}

	//SaveBSTree(bst, fd);
	//fclose(fd);

	//DeleteBSTree(bst);

	//printf("\n Load new tree \n");


	// U�itaj stablo
	if((fd = fopen("D:/FAKULTET/--- 2 GODINA ---/1 SEMESTAR/spa/vjezba7/liar.txt", "rt")) == NULL)
	{
		printf("Error opening file for reading.\n");
		return;
	}

	bst = LoadBSTree(fd);
	bst = AddNode(bst, "aaaaaaaaaaaaaaaaaaaaa");
	fclose(fd);

	//PrintBSTree(bst);

	PrintLeafs(bst);
	PrintNonLeafs(bst);

	// Ispi�i visinu i izbri�i
	printf("\nH = %d\n", BSTHeight(bst));
	DeleteBSTree(bst);
}