#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tocke.h"

void main5() {
	/*
	FILE* fd = fopen("proba.bin", "wb"); // w/r/a ili w+/r+/a+ i jos t/b
	int x = 67789;
	fwrite(&x, sizeof(int), 1, fd);
	fclose(fd);
	*/
	/*
	FILE* fd = fopen("proba.bin", "rb"); // w/r/a ili w+/r+/a+ i jos t/b
	int x;
	fread(&x, sizeof(int), 1, fd);
	printf("%d\n", x);
	fclose(fd);
	*/
	/*
	FILE* fd = fopen("proba.bin", "wb"); // w/r/a ili w+/r+/a+ i jos t/b
	Tocka niz[] = {
		{ 6, 10 },
		{ 5, 1 },
		{ 60, 16 }
	};
	fwrite(niz, sizeof(Tocka), 3, fd);
	fclose(fd);
	*/
	/*
	FILE* fd = fopen("proba.bin", "rb"); // w/r/a ili w+/r+/a+ i jos t/b
	Tocka niz[3];
	fread(niz, sizeof(Tocka), 3, fd);
	for (int i = 0; i < 3; i++)
		printf("%d %d\n", niz[i].x, niz[i].y);
	fclose(fd);
	*/
	printf("%d\n", sizeof(Tocka));
}