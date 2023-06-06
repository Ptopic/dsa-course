#include "dictionary.h"
#include <stdio.h>

Dictionary create() {
	Dictionary d = NULL;
	return d;
}

Dictionary addHead(Dictionary* dict, char* str) {
	Word* newWord = (Word*)malloc(sizeof(Word));
	Dictionary newDictionary = dict;
	newWord->word = str;
	newWord->next = &dict;
	newDictionary->word = newWord;
	return newDictionary;
}

Dictionary* addEnd(Dictionary* dict, char* str) {
	Word* newWord = (Word*)malloc(sizeof(Word));

	newWord->word = str;
	newWord->next = NULL;
	printf("%s", newWord->word);

	if (dict == NULL) {
		dict = &newWord;
		return dict;
	}
	Dictionary tmp = dict;

	// Prosetat do kraja liste
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = newWord;
	return dict;
}

void print(Dictionary* dict) {
	Dictionary tmp = dict;
	while (tmp != NULL) {
		printf("%s-> ", tmp->word);
		tmp = tmp->next;
	}
}

void destroy(Dictionary dict) {
	while (dict != NULL) {
		Dictionary* tmp = dict;
		dict = dict->next;
		free(tmp);
	}
}

int filter(Word* w) {

}

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w));
