#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BIGRAND (rand()*rand())

void shuffle(int* niz, int n) {
	for (int i = 0; i < n - 1; i++) {
		int j = i + BIGRAND % (n - i);
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

int* generate(int n) {
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = 1 + BIGRAND % 3;
	for (int i = 1; i < n; i++)
		niz[i] = niz[i - 1] + BIGRAND % 3 + 1;
	shuffle(niz, n);
	return niz;
}

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

// funkcija računa dužinu presjeka dva skupa
void presjek(int *skupA, int *skupB, int n) {
	int size1 = 0;
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (skupA[i] == skupB[j]) {
				size1++;
			}

		}
	}

	printf("\n broj ponavljanja %d \n", size1);
}

// funkcija računa dužinu presjeka dva skupa,
// gdje je skupB sortirani niz tako da se funkcija oslanja na upotrebu upotrebom bsearch() funkcije (iz stdlib.h)
void presjekJedanSortiran(int *skupA, int *skupB, int n) {
	int size1 = 0, k = 0;
	qsort(skupA, n, sizeof(int), cmpfunc);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (skupA[i] == skupB[j]) {
				size1++;
			}

		}
	}
	printf("\n broj ponavljanja sortiran jedan %d \n", size1);

}

// funkcija računa dužinu presjeka dva skupa,
// gdje je su oba skupa sortirana i moguće je samo ići naprijed sa indeksima po oba skupa
void presjekObaSortirana(int *skupA, int *skupB, int n) {
	qsort(skupA, n, sizeof(int), cmpfunc);
	qsort(skupB, n, sizeof(int), cmpfunc);

	int size1 = 0, i = 0, j = 0;

	printf("\n start \n");
    while(i < n){
		if (skupA[i] < skupB[j]) {
			i++;
		}
		else if (skupB[j] < skupA[i]) {
			j++;
		}
		else {
			j++;
			i++;
			size1++;
		}
	}
 	printf("\n broj ponavljanja sortirana oba %d \n", size1);
}


int maxBroj(int* niz, int size) {
	int max = niz[0];
	for (int i = 0; i < size; i++) {
		if (niz[i] < niz[i++]) {
			max = niz[i];
		}
		max = niz[i];

	}
	return max;
}

// funkcija kreira dva nova niza(indexA i indexB) i ispunjava ih sa 0.
// Dužine nizova su određene najvećim brojem u skupA i skupB.
// Zatim se za svaki broj iz skupA upiše 1 na njegov indeks u njegovom „indeks“ nizu indexA.
// Isto se napravi i za skupB.
// Zatim se u novi niz(presjek) broje samo brojevi koji se pojavljuju u oba niza na istom indeksu
// odnosno imaju 1 u indexA i indexB nizovima.
void presjekPoIndeksima(int *skupA, int *skupB, int n) {
	int size1 = maxBroj(skupA, n);
	printf("\n max %d\n", size1);
	int size2 = maxBroj(skupB, n);
	printf("\n max %d\n", size2);

	int* indexA = (int*)malloc(sizeof(int) * size1);
	int* indexB = (int*)malloc(sizeof(int) * size2);

	// Ispuni nizove sa nulama
	for (int i = 0; i < size1; i++) {
		indexA[i] = 0;
	}
	
	for (int i = 0; i < size2; i++) {
		indexB[i] = 0;
	}

	// za svaki broj iz skupA i skupaB upiše 1 na njegov indeks u njegovom „indeks“ nizu.
	for (int i = 0; i < n; i++) {
		indexA[i] = 1;
		indexB[i] = 1;
	}

	// Presjek
	// 
	// Zatim se u novi niz(presjek) broje samo brojevi koji se pojavljuju u oba niza na istom indeksu
	// odnosno imaju 1 u indexA i indexB nizovima.

	if (size1 > size2) {
		int* presjek = (int*)malloc(sizeof(int) * size1);
	}
	else {
		int*presjek = (int*)malloc(sizeof(int) * size2);

	}

	int k = 0, j = 0;

	while (k < size1 && j < size2) {
		if (skupA[k] == skupB[j]) {
			printf("%d", skupA[k]);
			k++;
			j++;
		}
		else {
			k++;
			j++;
		}
	}



}
int main() {
	srand(time(NULL));
	clock_t t;
	float total;
	int n = 20;
	int* niz1 = generate(n);
	int* niz2 = generate(n);

	for (int i = 0; i < n; i++) {
		printf("%d ", niz1[i]);
	}
	printf("\n drugi niz \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", niz2[i]);
	}
	t = clock();
	presjek(niz1, niz2, n);
	t = clock() - t;
	total = ((float)t) / CLOCKS_PER_SEC;
	printf("\n Sveukupno vrijeme za prsjek nizova %f", total);

	t = clock();
	presjekJedanSortiran(niz1, niz2, n);
	t = clock() - t;

	total = ((float)t) / CLOCKS_PER_SEC;
	printf("\n Sveukupno vrijeme za presjek s jednim sortiranim nizom %f", total);

	t = clock();
	presjekObaSortirana(niz1, niz2, n);
	t = clock() - t;
	total = ((float)t) / CLOCKS_PER_SEC;
	printf("\n Sveukupno vrijeme za presjek s oba sortirana %f", total);


	t = clock();
	presjekPoIndeksima(niz1, niz2, n);
	t = clock() - t;
	total = ((float)t) / CLOCKS_PER_SEC;
	printf("\n Sveukupno vrijeme za presjek po indeksima %f", total);
	free(niz1);
	free(niz2);
	return 0;
}
