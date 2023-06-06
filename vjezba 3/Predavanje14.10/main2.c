
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main2() {
	char** imena;
	imena = (char**)malloc(10 * sizeof(char*));
	char buffer[1000];
	for (int i = 0; i < 10; i++) {
		scanf("%s", buffer);
		imena[i] = strdup(buffer);

		/*
		imena[i] = (char*)malloc(1000 * sizeof(char));
		scanf("%s", imena[i]);
		imena[i] = realloc(imena[i], (strlen(imena[i]) + 1) * sizeof(char));
		*/
	}

	for (int i = 0; i < 10; i++) {
		free(imena[i]);
	}
	free(imena);
}