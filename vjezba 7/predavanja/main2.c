#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int b;
	struct _Node* left;
	struct _Node* right;
} Node;

typedef Node* BTree;

void print2(Node* tree) {
	if (tree == NULL)
		return;
	printf("%d ", tree->b);
	print2(tree->left);
	print2(tree->right);
}

void print(Node* tree) {
	if (tree == NULL)
		return;
	printf("%d ", tree->b);
	print(tree->left);
	print(tree->right);
}

int prebroji(Node* tree) {
	if (tree == NULL)
		return 0;
	return 1 + prebroji(tree->left) + prebroji(tree->right);
}


void najveci(Node* tree) {
	if (tree->right == NULL) {
		printf("maks = %d\n", tree->b);
	}
	else {
		najveci(tree->right);
	}
}

void najveci_iter(Node* tree) {
	while (tree->right != NULL) {
		tree = tree->right;
	}
	printf("maks = %d\n", tree->b);
}

Node* dodaj(Node* tree, int b) {
	if (tree == NULL) {
		Node* novi = (Node*)malloc(sizeof(Node));
		novi->b = b;
		novi->left = NULL;
		novi->right = NULL;
		return novi;
	}
	if(b > tree->b)
		tree->right = dodaj(tree->right, b);
	else
		tree->left = dodaj(tree->left, b);
	return tree;
}

int provjeri(Node* tree, int b) {
	if (tree == NULL) {
		return 0;
	}
	if (b < tree->b)
		return provjeri(tree->left, b);
	else if (b > tree->b)
		return provjeri(tree->right, b);
	else
		return 1;
}

void izbrisi_listove(Node** tree) {
	if (*tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL) {
		free(*tree);
		*tree = NULL;
		return;
	}
	izbrisi_listove(&((*tree)->left));
	izbrisi_listove(&((*tree)->right));
}


void main() {
	Node* tree = NULL;
	tree = dodaj(tree, 5);
	tree = dodaj(tree, 7);
	tree = dodaj(tree, 1);
	tree = dodaj(tree, 3);
	tree = dodaj(tree, 4);
	tree = dodaj(tree, 8);
	tree = dodaj(tree, 10);
	
	print(tree);
	printf("%d\n", prebroji(tree));
	//printf("%d %d\n", provjeri(tree, 6), provjeri(tree, 3));
	printf("\n");
	izbrisi_listove(&tree);
	print(tree);
	printf("%d\n", prebroji(tree));

}