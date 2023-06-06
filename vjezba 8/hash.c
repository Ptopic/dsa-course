#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable *NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokazivaèa)

	HashTable* hashTable = (HashTable*) malloc(sizeof(HashTable));

	hashTable->size = size;
	hashTable->load = 0;
	hashTable->table = (Bin**)malloc(sizeof(Bin*) * size);

	for (int i = 0; i < hashTable->size; ++i)
		hashTable->table[i] = NULL;

	return hashTable;
}

unsigned int hash(char *word)
{
	// od kljuca generira hash kod
	unsigned int key = 0;
	while(*word != '\0')
	{
		key = key*HCONST + *word;
		word++;
	}
	return key;
}

Bin* createTempBin(char* word , Bin* nextBin) {
	Bin* tempBin = (Bin*)malloc(sizeof(Bin));
	tempBin->word = word;
	tempBin->next = nextBin;

	return tempBin;
}

void Insert(HashTable *ht, char *word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu

	unsigned int index = hash(word) % ht->size;

	Bin* newBin = createTempBin(word , ht->table[index]);

	ht->table[index] = newBin;
	ht->load++;
}

int Get(HashTable *ht, char *word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici

	unsigned int index = hash(word) % ht->size;

	Bin* tempElement = ht->table[index];

	while (tempElement != NULL) {
		if (strcmp(word, tempElement->word) == 0) return 1;
		tempElement = tempElement->next;
	}

	return 0;
}

void deleteBin(Bin* tempBin) {
	Bin* binForDeleting;

	while (tempBin != NULL) {
		binForDeleting = tempBin;
		tempBin = tempBin->next;
		free(binForDeleting->word);
		free(binForDeleting);
	}
}

void DeleteTable(HashTable *ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)

	for (int i = 0; i < ht->size; i++){
		deleteBin(ht->table[i]);
	}

	free(ht->table);
	free(ht);

}