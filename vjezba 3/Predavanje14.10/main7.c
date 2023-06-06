
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tocke.h"

int cmp(const void* a, const void* b) {
	return *((int*)a) - *((int*)b);
}

int cmpt(const void* a, const void* b) {
	Tocka* pa = a;
	Tocka* pb = b;
	return (pa->x + pa->y) - (pb->x + pb->y);
}

void main7() {
	/*
	int niz[] = { 3, 25, 14, 2, 3, 78, 8 };

	qsort(niz, 7, sizeof(int), cmp);
	for (int i = 0; i < 7; i++)
		printf("%d ", niz[i]);
	int needle = 14;
	int* p = bsearch(&needle, niz, 7, sizeof(int), cmp);
	if (p == NULL)
		printf("nema ga\n");
	else
		printf("%d", *p);
	*/
	Tocka nizt[] = {
		{ 6, 10 },
		{ 5, 11 },
		{ 6, 13 },
		{ 25, 1 },
		{ 6, 16 },
		{ 5, 9 },
		{ 60, 16 }
	};

	qsort(nizt, 7, sizeof(Tocka), cmpt);
	for (int i = 0; i < 7; i++)
		printf("%d %d\n", nizt[i].x, nizt[i].y);

}