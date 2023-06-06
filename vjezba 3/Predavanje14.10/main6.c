#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tocke.h"

void main6() {
	/*
	FILE* fd = fopen("proba.bin", "wb"); // w/r/a ili w+/r+/a+ i jos t/b

	Tocka niz[] = {
		{ 6, 10, 1 },
		{ 5, 1, 0 },
		{ 60, 16, 1 }
	};
	for(int i=0; i < 3; i++)
		fwrite(&niz[i], 9, 1, fd);
	fclose(fd);
	*/
	/*
	FILE* fd = fopen("proba.bin", "rb"); // w/r/a ili w+/r+/a+ i jos t/b
	Tocka niz[3];
	for (int i = 0; i < 3; i++)
		fread(&niz[i], 9, 1, fd);
	fclose(fd);
	for (int i = 0; i < 3; i++)
		printf("%d %d\n", niz[i].x, niz[i].y);
	*/

	FILE* fd = fopen("proba.bin", "rb"); // w/r/a ili w+/r+/a+ i jos t/b
	Tocka t;
	printf("%d\n", ftell(fd));
	fseek(fd, 9 * 2, SEEK_SET);
	printf("%d\n", ftell(fd));
	fread(&t, 9, 1, fd);
	printf("%d\n", ftell(fd));
	fclose(fd);
	printf("%d %d\n", t.x, t.y);

	//printf("%d\n", sizeof(Tocka));
}