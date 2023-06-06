
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BIGRAND (rand()*rand())

void shuffle(int* niz, int n) {
	for (int i = 0; i < n - 1; i++) {
		int j = i + BIGRAND % (n - i);
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

int* generate(int n) {
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = 1 + BIGRAND % 3;
	for (int i = 1; i < n; i++)
		niz[i] = niz[i-1] + BIGRAND % 3 + 1;
	shuffle(niz, n);
	return niz;
}


void main() {
	srand(time(NULL));
	int* niz = generate(10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", niz[i]);
	}
	printf("\n");
	free(niz);
}
