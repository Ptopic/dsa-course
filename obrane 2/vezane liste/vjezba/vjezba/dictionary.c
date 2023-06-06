#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>

Dictionary create() {
	Dictionary d = (Dictionary)malloc(sizeof(Word));
	Dictionary d = NULL;
	d->count = 0;
	d->next = NULL;
	d->word = NULL;
	return d;
}

void add(Dictionary dict, char* str) {
	Dictionary t = dict;
	Dictionary n = dict->next;

	Dictionary novi = (Dictionary)malloc(sizeof(Word));

	novi->word = (char*)malloc(sizeof(char) * (strlen(str) + 1));
	strcpy(novi->word, str);
	novi->count = 1;

	while (n != NULL) {
		// Ako su rijeci iste counter +1
		if (strcmp(n->word, str) == 0) {
			n->count++;
			free(novi->word);
			free(novi);
			return;
		}
		// Ako nisu stavljamo abecedno u listu
		else if (strcmp(n->word, str) > 0) {
			novi->next = n;
			t->next = novi;
			return;
		}
		n = n->next;
		t = t->next;
	}

	// Stavi novi element na kraj
	t->next = novi;
	novi->next = NULL;
}

void print(Dictionary dict) {
	dict = dict->next;
	// Print dok ne dodemo do kraja liste
	while (dict != NULL) {
		printf("%s count :%d \n", dict->word, dict->count);
		dict = dict->next;
	}
}

void destroy(Dictionary dict) {
	while (dict != NULL) {
		Dictionary tmp = dict;
		dict = dict->next;
		free(tmp->word);
		free(tmp);
	}
}

int filter(Word* w) {
	// Broj ponavljanja 5-10 i velicina rijeci veca od 3
	if ((w->count > 5 && w->count < 10) && strlen(w->word) > 3) {
		return 1;
	}
	else {
		return 0;
	}
}

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w)) {
	Dictionary t = indict;
	Dictionary n = indict->next;

	while (n != NULL) {
		// Ako je funkcija filter zadovoljena idemo na sljedeci
		if (filter(n) == 1) {
			t = t->next;
			n = n->next;
		}
		// Ako filter nije zadovoljen prosli pokazuje na sljedeci i oslobada se element liste
		else {
			t->next = n->next;
			free(n->word);
			free(n);
			n = t->next; // n na sljedeci
		}
	}
	return indict;
}
