#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000
#define MUL(a, b) ((a)*(b))

int a;

int broji() {
	static int n = 0;
	n++;
	return n;
}

void main3() {
	/*
	char imena[10][1000] = {
		"ime1",
		"ime2",
		"ime3"
	};

	char* niz = (char*)imena;
	*/

	printf("%d\n", MUL(13, 15)); // 13*15
	printf("%d\n", MUL(10 + 3, 15)); // 10 + 3*15

	printf("%d\n", MUL(13, 15) + 5);

}