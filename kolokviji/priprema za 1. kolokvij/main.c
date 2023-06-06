
// T(n) = c + c * n / 2 + c * log(2n)
// O(f(n)) = O(n + logn) = O(n)

int f(int* niz, int n) {
    int i = 0, sum = 0;
    while (i < n) {
        sum += niz[i];
        i += 2;  // n / 2
    }
    int j = 1;
    while (j < 2 * n) {  // log(2n) == log(n)
        sum += niz[j];
        j = j + j;
    }
    return sum;
}

// 2.	Procijeniti vremensku složenost O() algoritma koji 
// provjerava da li dva skupa (niza brojeva) sadrže iste elemente. 
// Dužina svakog niza je N. Algoritam se može napisati na dva načina: 
// a)	Za svaki broj u prvom nizu se provjerava da li postoji 
// // u drugom nizu.Zatim se za svaki broj u drugom nizu provjerava 
// // da li postoji u prvom nizu.

/*
O(n*n) + O(n * n) = O(n^2)
for i in niz1: O(n)
  for j in niz2: O(n)   === O(n*n) = n^2
    if ...     +
for i in niz2:  === O(n*n) = n^2
    for j in niz1:
    if ...
*/
// O(n^2 + n^2) worst case je n^2

// b)	Oba niza se kopiraju u jedan niz i zatim se taj niz 
// sortira sa mergesortom.Nakon toga se provjerava da svi brojevi 
// imaju jednakog susjeda.

// spajanje O(N)

// Merge sort
// O(NlogN)

// Provjera
// O(N)
// O(N) + O(NlogN) + O(N) = O(NlogN)

// 3.	Napisati funkciju koja prima dvije jednostruko vezane liste 
// (svaki element sadrži broj). Funkcija provjerava da li su obje 
// liste potpuno jednake. 
// Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova)

int provjera(Element* lsta, Element* lsta) {
    while (lsta != NULL && lstb != NULL) {
        if (lsta->broj != lstb->broj)
            return 0;
        lsta = lsta->next;
        lstb = lstb->next;
    }
    if (lsta == NULL && lstb == NULL)
        return 1;
    else
        return 0;
}

// 4.	Napisati funkciju koja prima vezanu listu 
// (svaki element sadrži broj) i jedan dodatni broj. 
// Funkcija će dodati nove elemente sa tim brojem na početak i 
// na kraj liste. (35 bodova)

Element* dodaj(Element* lst, int b) {


    Element* novi = (Element*)malloc(sizeof(Element));
    novi->broj = b;
    novi->next = lst;
    lst = novi;
    
    Element* tmp = lst;
    while (tmp->next != NULL)
        tmp = tmp->next;

    novi = (Element*)malloc(sizeof(Element));
    novi->broj = b;
    novi->next = NULL;
    tmp->next = novi;

    return lst;
}

//          l->l                  d<-d
// { [12], 10, 16, 9, 15, 12, 11, 8, 14 }

//             l->l->l        d <-d
// { [12], 10, 8, 9, 15, 12, 11, 16, 14 }

//             l->l->ld <-d <-d
// { [12], 10, 8, 9, 11, 12, 15, 16, 14 }

//             l->l->ld <-d <-d
// { [12], 10, 8, 9, 11, 12, 15, 16, 14 }

// { 11, 10, 8, 9} [12] { 12, 15, 16, 14 }

//          l->>>>ld             ld <<<- d
// { [11], 10, 8, 9}      {[12], 15, 16, 14 }

//          
// { 9, 10, 8, [11]}      {} [12] { 15, 16, 14 }

//         l  d                           l    d 
// { [9], 10, 8 }  {}             { [15], 16, 14 }

//        ld<-d                           ld <-d
// { [9], 8, 10 }                 { [15], 14, 16 } 

// {8} [9] {10}                   {14} [15] {16}



