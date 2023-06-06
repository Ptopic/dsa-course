#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

// vraća novi niz koji je kopija dijela niza od indeksa start do indeksa stop.
int* podniz(int* niz, int start, int stop) {
    int size = ((stop - start) + 1);
    int* newArray = malloc(sizeof(int) * size);
    int i;
    int j = 0;
    for (i = start; i <= stop; i++) {
        newArray[j] = niz[i];
        printf("%d", newArray[j]);
        j++;
    }

    return newArray;
}

// vraća novi niz koji sadrži brojeve iz originalnog niza koji su manji od th.
// Originalni niz ima dužinu n. 
// Dužinu novog niza sa brojevima koji su prošli filter treba spremiti u nth.

int* filtriraj(int* niz, int n, int th, int* nth) {
    int brojeviManjiOdTh = 0;
    for (int i = 0; i < n; i++) {
        if (niz[i] < th) {
            brojeviManjiOdTh++;
        }
    }

    int* newArray = malloc(sizeof(int) * brojeviManjiOdTh);  // malloc sa nth prvo prebrojat koliko ih ima pa alocirat
    *nth = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (niz[i] < th) {
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
    int size1 = n / 2;
    int size2 = n - size1;
    int** ptr = (int**)malloc(sizeof(int*) * 2);
    int* prviNiz = malloc(sizeof(int) * size1);
    int* drugiNiz = malloc(sizeof(int) * size2);

    // Prvi niz podjela
    int i;
    printf("print niz\n");
    for (i = 0; i < size1; i++) {
        prviNiz[i] = niz[i];
    }

    // Drugi niz podjela
    printf("drugi niz \n");
    int k = 0;
    for (int j = i; j < n; j++) {
        drugiNiz[k] = niz[j];
        k++;
    }

    ptr[0] = prviNiz;
    ptr[1] = drugiNiz;

    return ptr;
}

//Deklarirati strukturu Tocka koja sadrži dva člana: x i y (oba su float).
//Deklarirati strukturu Poligon koja se sadrži dva člana: niz vrhova (svaki vrh u nizu je Tocka) i broj vrhova n.
//Napisati funkcije za rad sa poligonima:

typedef struct {
    float x;
    float y;
}Tocka;

typedef struct {
    int x;
    int y;
    int z;
}Tocka3D;

typedef struct {
    Tocka* tocke;
    int n;
}Poligon;

// prima niz x i y koordinata i stvara novi poligon koji će kao vrhove imati parove brojeva iz nizova.
// Nizovi su dužine n (≥ 3).
//

Poligon* novi_poligon(float* niz_x, float* niz_y, int n) {
    int i;
    Poligon* poligon = (Poligon*)malloc(sizeof(Poligon));

    poligon->n = n;

    poligon->tocke = (Tocka*)malloc(sizeof(Tocka) * n);

    for (i = 0; i < n; i++) {
        Tocka t;
        t.x = niz_x[i];
        t.y = niz_y[i];

        poligon->tocke[i] = t;

    }

    return poligon;
};

// Funkcija vraća niz pokazivača na vrhove poligona kojima su obje koordinate pozitivne.
// Broj elemenata u nizu će biti spremljen u np parametar.

Tocka** pozitivni(Poligon* p, int* np) {
    // Popravit sa sizeom sve
    int size = p->n;
    int brojPozitivnihTocaka = 0;

    int i, j = 0;

    for (i = 0; i < size; i++) {
        if ((p->tocke[i].x > 0) && (p->tocke[i].y > 0)) {
            brojPozitivnihTocaka++;
        }
    }
    Tocka** pozitivne = (Tocka**)malloc(sizeof(Tocka*) * brojPozitivnihTocaka); // malloc sa brojPozitivnih prvo prebrojat koliko ih ima pa alocirat

    for (i = 0; i < size; i++) {
        if ((p->tocke[i].x > 0) && (p->tocke[i].y > 0)) {
            pozitivne[j] = &(p->tocke[i]);
            j++;
        }
    }

    *np = brojPozitivnihTocaka;
    return pozitivne;
};

// Spoji 2 dijela niza iz vjezbe 2 u jedan niz
int* obrana1(int* niz1, int* niz2) {
    int size = sizeof(niz1);
    int size1 = size / 2;
    int size2 = size - size1;

    int* noviNiz = (int*)malloc(sizeof(int) * (size));
    
    int i, j, k;
    for (i = 0; i < size1; i++) {
        noviNiz[i] = niz1[i];
    }
    
    k = 0;
    for (j = i; j < size; j++, k++) {
        noviNiz[j] = niz2[k];
    }

    return noviNiz;
}




// Izbaci parne brojeve iz niza
void obrana2(int *niz, int n, int *ptr) {
    int i, j = 0;
    int brojParnih = 0;

    // Prebrojat parne
    for (i = 0; i < n; i++) {
        if (niz[i] % 2 == 0) {
            brojParnih++;
        }
    }

    //printf("%d", brojParnih);
    for (j = 0, i = 0; j < brojParnih; i++) {
        if (niz[i] % 2 != 0) {
            niz[j] = niz[i];
            j++;
        }
    }

    *ptr = brojParnih;
}





// Pretvori niz 2d tocaka u 3d tocke tako da z kordinata bude zbroj x i y kordinata
void obrana3(Tocka3D tocke, int n) {
    Tocka3D *noviNiz = (Tocka3D*)malloc(sizeof(Tocka3D*) * n);

    int sum;
    for (int i = 0; i < n; i++) {
        sum = tocke.x + tocke.y;
        noviNiz[i].z = sum;
        printf("%d\n", sum);
    }
}






// Izbaci nti broj iz niza
void obrana4(int *niz, int n, int nti) {
    int i = 0;

    for (i = 0; i < n; i++) {
        if (i = nti) {
            i++;
            niz[i] = niz[i+1];
        }
        niz[i] = niz[i];
        printf("%d\n", niz[i]);
    }
}





// Ubaci broj po redu u niz (sortiran niz)
void obrana5() {

}





// Ubaci po redu
void obrana6() {

}




// Funkcija koja prima 2 niza, 2 indeksa i n
// Funkcija radi novi niz koji ce biti spojen od 2 dijela
// od 1 indeksa do 2 indeksa
// {6,10,2,8,7,4}
// {2,4,6,10,7,4}
void obrana7(int *niz, int start, int stop) {
    int size = start - stop;
    int *noviNiz = malloc(sizeof(int) * (size));

    int i, j = 0;
    for (i = start; i < stop; i++, j++)
    {
        noviNiz[j] = niz[i];
        printf("\n %d \n", niz[i]);
    }


}




int main()
{
    int niz[] = { 1,2,3,4,8,9,4,3 };

    int size = sizeof(niz) / sizeof(niz[0]);

    // 1 zadatak
    //     int *newArray = podniz(niz, 2, 6);
    //
    //     free(newArray);

    // 2 zadatak
         //int *nth = 0;
         //int *newArray = filtriraj(niz, size, 4, &nth);

    // 3 zadatak
    //int** ptr = podijeli(niz, size);
    //int drugidioindex = size / 2;

    //printf("\nprvi dio\n");
    //int i;
    //for (i = 0; i < drugidioindex; i++) {
    //    printf("%d ", ptr[0][i]);
    //}

    //printf("\ndrugi dio\n");
    //for (i = 0; i < (size - drugidioindex); i++) {
    //    printf("%d ", ptr[1][i]);
    //}
    //printf("\n");


    // 5 zadatak
    //float niz_x[] = { 1,7,3,-2,-3,-1 };
    //float niz_y[] = { 4,5,6,-4, -6, 2 };
    //int n = sizeof(niz_x) / sizeof(niz_x[0]);
    ////
    //Poligon* poligon = novi_poligon(niz_x, niz_y, n);
    //// Print tocke poligona
    //for (i = 0; i < n; i++) {
    //    printf("Tocka (%f , %f) \n", poligon->tocke[i].x, poligon->tocke[i].y);
    //}

    // 6 zadatak
    //int* np = n;
    //Tocka** pozitivneTocke = pozitivni(poligon, &np);

    //printf("broj pozivinih tocaka %d \n", np);
    //for (i = 0; i < np; i++) {
    //    printf("(%f ,%f )\n", pozitivneTocke[i]->x, pozitivneTocke[i]->y);
    //}
    //free(poligon);
    //free(pozitivneTocke);


    // Obrana zadatak 1
    //int* noviNiz = obrana1(ptr[0], ptr[1]);
    //int sizeNew = sizeof(noviNiz);
    //int sizeNew1 = sizeNew / 2;
    //int sizeNew2 = sizeNew - sizeNew1;

    //// Print novog niza
    //int j,k;
    //for (j = 0; j < sizeNew1; j++) {
    //    printf("\n %d \n", noviNiz[j]);
    //}

    //for (k = j; k < sizeNew; j++, k++) {
    //    printf("\n %d \n", noviNiz[k]);
    //}


    //printf("\n %d \n", sizeNew1);

    //free(ptr);


    // Obrana zadatak 2
    int i = 0;
    int size2 = 0;
    obrana2(niz, size, &size2);
    printf("\n new size %d\n", size2);
    for (i = 0; i < size2; i++) {
        printf("%d ", niz[i]);
    }




    // Obrana zadatak 3




    // Obrana zadatak 4
    //obrana4(niz, size, 2);



    // Obrana zadatak 5



    // Obrana zadatak 6
    int nizA[] = { 6,10,2,8,7,4 };
    int start = 1;
    int stop = 4;
    obrana7(nizA, start, stop);

    return 0;
}
