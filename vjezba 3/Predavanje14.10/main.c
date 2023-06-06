
#include <stdio.h>
#include "tocke.h"
/*
typedef struct {
	int x;
	int y;
} Tocka;
*/
typedef struct {
	int n;
	int *niz;
} NizSaVelicinom;

Tocka ispuni(int x, int y) {
	Tocka t;
	t.x = x;
	t.y = y;
	return t;
}

Tocka* ispuni2(int x, int y) {
	Tocka t;
	t.x = x;
	t.y = y;
	return &t; // greška
}

void main1() {
	int x = 45;
	char* p = (char*)&x;

	printf("%d %d %d %d", p[0], p[1], p[2], p[3]);
	Tocka a, b;

	// a = b;

	Tocka* pa = &a;
	pa->x = 1;
	(*pa).x = 1;




}