
#include <stdlib.h>

int* spoji(int* prvi, int* drugi, int dp, int dd) {
	int* novi = (int*)malloc(sizeof(int) * (dp + dd));
	int i;
	for (i = 0; i < dp; i++) {
		novi[i] = prvi[i];
	}
	for (int j=0; j < dd; i++, j++) {
		novi[i] = drugi[j];
	}
	return novi;
}

int* samo_parni_u_novi_niz(int* niz, int n, int *np) {
	int b = 0;
	for (int i = 0; i < n; i++)
		if (niz[i] % 2 == 0)
			b++;
	*np = b;
	int* novi = (int*)malloc(sizeof(int) * b);
	int j = 0;
	for (int i = 0; i < n; i++)
		if (niz[i] % 2 == 0) {
			novi[j] = niz[i];
			j++;
		}
	return novi;
}

int* samo_parni_u_novi_niz(int* niz, int n, int* np) {
	int* novi = (int*)malloc(sizeof(int) * n);
	int j = 0;
	for (int i = 0; i < n; i++)
		if (niz[i] % 2 == 0) {
			novi[j] = niz[i];
			j++;
		}
	*np = j;
	novi = realloc(novi, sizeof(int) * j);
	return novi;
}

int* samo_parni_u_novi_niz(int* niz, int n, int* np) {
	int* novi = NULL;
	int j = 0;
	for (int i = 0; i < n; i++)
		if (niz[i] % 2 == 0) {
			novi = realloc(novi, sizeof(int) * (j+1));
			novi[j] = niz[i];
			j++;
		}
	*np = j;
	return novi;
}

typedef struct {
	float x, y;
} Tocka2D;

typedef struct {
	float x, y, z;
} Tocka3D;

Tocka3D* pretvori_2D_u3D(Tocka2D* niz, int n) {
	Tocka3D* novi = (Tocka3D*)malloc(n * sizeof(Tocka3D));
	for (int i = 0; i < n; i++) {
		novi[i].x = niz[i].x;
		novi[i].y = niz[i].y;
		novi[i].z = niz[i].x + niz[i].y;
	}
	return novi;
}

void izbaci_nti_broj(int* niz, int n, int i) {
	for (int j = i; j < n-1; j++) {
		niz[j] = niz[j + 1];
	}
}

void ubaci_po_redu(int* niz, int n, int b) {
	int j = n - 1;
	while (niz[j] > b && j > 0) {
		niz[j + 1] = niz[j];
		j--;
	}
	niz[j] = b;
}


