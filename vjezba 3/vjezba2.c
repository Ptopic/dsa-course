#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

// vraća novi niz koji je kopija dijela niza od indeksa start do indeksa stop.
int* podniz(int *niz, int start, int stop){
	int size = ((stop - start) + 1);
    int *newArray = malloc(sizeof(int) * size);
    int i;
    int j = 0;
    for(i = start; i <= stop; i++) {
        newArray[j] = niz[i];
        printf("%d", newArray[j]);
        j++;
    }

    return newArray;
}

// vraća novi niz koji sadrži brojeve iz originalnog niza koji su manji od th.
// Originalni niz ima dužinu n. Dužinu novog niza sa brojevima koji su prošli filter treba spremiti u nth.

int* filtriraj(int *niz, int n, int th, int *nth) {
    int brojeviManjiOdTh = 0;
    for (int i = 0; i < n; i++) {
        if (niz[i] < th) {
            brojeviManjiOdTh++;
        }
    }

    int *newArray = malloc(sizeof(int) * brojeviManjiOdTh);  // malloc sa nth prvo prebrojat koliko ih ima pa alocirat
    *nth = 0;
    int i;
    for(i = 0; i < n; i++) {
		if(niz[i] < th) {
			newArray[*nth] = niz[i];
			printf("%d", newArray[*nth]);
			(*nth)++;
		}
    }

    return newArray;
}

// dijeli niz dužine n na dva jednaka dijela i stvara kopije prvog i drugog dijela.
// Funkcija vraća dva pokazivača koji pokazuju na prvi i na drugi dio.
// int**
int** podijeli(int* niz, int n) {
    int** ptr = (int**)malloc(sizeof(int*) * 2);

    int drugiDioIndex = n / 2;

    ptr[0] = &niz[0];
    ptr[1] = &niz[drugiDioIndex];

    return ptr;
}

//Deklarirati strukturu Tocka koja sadrži dva člana: x i y (oba su float).
//Deklarirati strukturu Poligon koja se sadrži dva člana: niz vrhova (svaki vrh u nizu je Tocka) i broj vrhova n.
//Napisati funkcije za rad sa poligonima:

typedef struct{
    float x;
    float y;
}Tocka;

typedef struct{
    Tocka* tocke;
    int n;
}Poligon;

// prima niz x i y koordinata i stvara novi poligon koji će kao vrhove imati parove brojeva iz nizova.
// Nizovi su dužine n (≥ 3).
//

Poligon* novi_poligon(float *niz_x, float *niz_y, int n) {
    int i;
    Poligon* poligon = (Poligon*)malloc(sizeof (Poligon));

    poligon->n = n;

    poligon->tocke = (Tocka*)malloc(sizeof (Tocka) * n);

    for(i = 0; i < n; i++) {
		Tocka t;
        t.x = niz_x[i];
        t.y = niz_y[i];

        poligon->tocke[i] = t;

    }

	return poligon;
};

// Funkcija vraća niz pokazivača na vrhove poligona kojima su obje koordinate pozitivne.
// Broj elemenata u nizu će biti spremljen u np parametar.

Tocka** pozitivni(Poligon *p, int *np) {
    int size = *np;
    int brojPozitivnihTocaka = 0;


    int i,j = 0;

    for (i = 0; i < size; i++) {
        if ((p->tocke[i].x > 0) && (p->tocke[i].y > 0)) {
            brojPozitivnihTocaka++;
        }
    }
    Tocka** pozitivne = (Tocka**)malloc(sizeof(Tocka*) * brojPozitivnihTocaka); // malloc sa brojPozitivnih prvo prebrojat koliko ih ima pa alocirat

    for(i = 0; i < size; i++) {
        if((p->tocke[i].x > 0) && (p->tocke[i].y > 0)) {
            pozitivne[j] = &(p->tocke[i]);
            j++;
        }
    }

    *np = brojPozitivnihTocaka;

    /*printf("vrijednost np %d", *np);*/

    for(i = 0; i < np; i++) {
        printf("(%f ,%f )\n", pozitivne[i]->x, pozitivne[i]->y);
    }
    return pozitivne;
};


int main()
{
    int niz[] = {1,2,3,4,5,6,7};

    int size = sizeof(niz) / sizeof(niz[0]);

// 1 zadatak
//     int *newArray = podniz(niz, 2, 6);
//
//     free(newArray);

// 2 zadatak
     //int *nth = 0;
     //int *newArray = filtriraj(niz, size, 4, &nth);

// 3 zadatak
	int **ptr = podijeli(niz, size);
    int drugidioindex = size / 2;

    // Prebacit u main
    printf("\nprvi dio\n");
    int i;
    for (i = 0; i < drugidioindex; i++) {
        printf("%d ", ptr[0][i]);
    }

    printf("\ndrugi dio\n");
    for (i = 0; i < (size - drugidioindex); i++) {
        printf("%d ", ptr[1][i]);
    }
    printf("\n");
    free(ptr);

// 5 zadatak
    float niz_x[] = {1,7,3,-2,-3,-1};
    float niz_y[] = {4,5,6,-4, -6, 2};
    int n = sizeof(niz_x) / sizeof(niz_x[0]);
//
    Poligon* poligon = novi_poligon(niz_x, niz_y, n);
    // Print tocke poligona
    for (i = 0; i < n; i++) {
        printf("Tocka (%f , %f) \n", poligon->tocke[i].x, poligon->tocke[i].y);
    }

// 6 zadatak
    int *np = n;
    Tocka** pozitivneTocke = pozitivni(poligon, &np);

    free(poligon);
    free(pozitivneTocke);
    //return 0;
}
