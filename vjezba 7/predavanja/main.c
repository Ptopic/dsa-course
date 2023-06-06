#include <stdio.h>

typedef struct _Node {
	int b;
	struct _Node* left;
	struct _Node* right;
} Node;

typedef Node* BTree;

void print(Node *tree) {
	if (tree == NULL)
		return;
	printf("%d ", tree->b);
	print(tree->left);
	print(tree->right);
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

void main1() {
	Node a, b, c, d, e, f, g;

	Node* tree = NULL;
	a.b = 5;
	tree = &a;

	b.b = 3;
	a.left = &b;
	c.b = 8;
	a.right = &c;

	d.b = 1;
	b.left = &d;
	e.b = 4;
	b.right = &e;

	d.left = d.right = NULL;
	e.left = e.right = NULL;

	f.b = 7;
	c.left = &f;

	g.b = 10;
	c.right = &g;

	f.left = f.right = NULL;
	g.left = g.right = NULL;

	print(tree);
	najveci(tree);
	najveci_iter(tree);
}