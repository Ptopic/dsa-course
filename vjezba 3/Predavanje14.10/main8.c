
#include <stdio.h>
#include <string.h>

void mystrcpy(char* dest, char* src) {
	int i;
	for (i = 0; i < strlen(src); i++) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
}

void mystrcpy(char* dest, char* src) {
	int i;
	int n = strlen(src);
	for (i = 0; i < n; i++) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
}

void mystrcpy(char* dest, char* src) {
	int i;
	for (i = 0; src[i] != '\0'; i++) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
}

void main() {

}