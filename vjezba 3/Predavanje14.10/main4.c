#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main4() {
	/*FILE* fd = fopen("proba.txt", "wt"); // w/r/a ili w+/r+/a+ i jos t/b
	fprintf(fd, "ime1\n");
	fprintf(fd, "ime2\n");
	fprintf(fd, "ime3\n");
	fclose(fd);
	*/
	/*
	FILE* fd = fopen("proba.txt", "rt"); // w/r/a ili w+/r+/a+ i jos t/b
	char buffer[1000];
	fgets(buffer, 999, fd);
	printf("%s", buffer);
	fclose(fd);
	*/
	FILE* fd = fopen("proba.txt", "rt"); // w/r/a ili w+/r+/a+ i jos t/b
	char buffer[1000];
	for (int i = 0; i < 700; i++) {
		fgets(buffer, 999, fd);
	}
	printf("%s", buffer);
	fclose(fd);
}