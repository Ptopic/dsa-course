int f(int* niz, int n) {
	int j = 1;
	int i = 0, sum = 0;
	while (j < 2 * n) {
		sum += niz[j];
		j++;
	}
	while (i < n * n) {
		sum += niz[j];
		i++;
	}
	return sum;
}

// T(n) = c + c * (2n-1) + c * n * n
// O(f(n)) = O(n^2)

int f(int* niz, int n) {
	int i = 0, sum = 0;
	while (i <= n) {
		int j = 1;
		while (j < 2 * n) {
			sum += niz[j];
			j = j + j;
		}
		i++;
	}
	return sum;
}

// T(n) = c + c*n*(log(2*n)*c) = c + c*n*log(n)
// O(f(n)) = O(n*log(n))

int f(int* niz, int n) {
	int i = n, sum = 0;
	while (i > 0) {
		int j = 0;
		while (j + i < n) {
			sum += niz[j + i];
			j++;
		}
		i--;
	}
	return sum;
}
// T(n) = c + c*n*(c + c*n/2) = c + c*n + c*n*n
// O(f(n)) = O(n^2)

// 2.	Procijeniti složenost O() algoritma koji iz neke datoteke čita elemente 
// (brojeve) u jednostruko vezanu listu. Broj pročitanih elemenata je N i 
// ne koriste se nikakvi posebni pokazivači (npr. na kraj liste). 
// Algoritam se može napisati na dva načina: 
// a)	Svaki novi element se dodaje na početak liste.
// O(1) - dodavanje u glavu * N = O(n)


// b)	Svaki novi element se dodaje na kraj liste.
// O(c + 2*c + 3 + .... + n*c) = O(n^2)

// Složenost izraziti u N.


// 3.	Napisati funkciju koja prima jednostruko vezanu listu (svaki element sadrži broj) i 
// provjerava da li se svi elementi sa parnim brojem nalaze između dva elementa sa neparnim 
// brojem. Prvi i zadnji element sadrži neparni broj, a primljena lista 
// ima barem 3 elementa. Funkcija vraća 1 ako jesu ili 0 ako nisu. (25 bodova)

int provjera(Element* lst) {
	// 3 1 2 1 5 6 7 

	Element* preth = lst;
	Element* tren = lst->next;

	while (tren->next != NULL) {
		if (tren->broj % 2 == 0 && (preth->broj % 2 == 0 || tren->next->broj % 2 == 0))
			return 0;
		tren = tren->next;
		preth = preth->next;
	}
	return 1;
}

// 4.	Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) 
// i jedan dodatni broj. Funkcija će dodati novi element sa tim brojem prije 
// najvećeg broja u listi. (35 bodova)

Element* dodaj(Element* lst, int b) {


	Element* maxp = lst;
	Element* tmp = lst;
	while (tmp->next != NULL) {
		if (tmp->next->broj > maxp->next->broj) {
			maxp = tmp;
		}
		tmp = tmp->next;
	}

	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = b;

	if (lst->broj > maxp->next->broj) {
		novi->next = lst;
		return novi;
	}

	novi->next = maxp->next;
	maxp->next = novi;
	return lst;
}


// T(n) = c + c*n*n * (c + c*2*n) = c + c*n*n + c*n*n*n
// O(n^3)

int f(int* niz, int n) {
	int i = 0, sum = 0;
	while (i < n * n) {
		int j = 0;
		while (j < 2 * n) {
			sum += niz[j];
			j++;
		}
		i++;
	}
	return sum;
}

// 2.	Procijeniti složenost O() algoritma koji računa operaciju za skup (niz) 
// i niz brojeva, dužine N i M. Algoritam iz prvog niza ispisuje element koji se 
// u drugom nizu pojavljuje najviše puta. Algoritam se može napisati na dva načina: 
// a)	Nijedan niz nije sortiran.Prolazimo kroz prvi niz i za svaki broj brojimo 
// koliko puta se pojavljuje u drugom nizu.
// O(N) * O(M) = O(N*M)


// b)	Sortiramo oba niza uzlazno.Zatim za svaki broj prvog niza brojim 
// u drugom nizu koliko puta se pojavljuje bez vraćanja.
/*
O(NlogN)
O(MlogM)
O(N+M)
O(NlogN + MlogM + N + M) = O((N+1)logN + (M+1)*logM) = O(NlogN + MlogM)
*/


//Složenost izraziti u N i M.Možete pretpostaviti da se za sortiranje u(b) koristi quicksort.

// 4.	Napisati funkciju koja prima vezanu listu (svaki element sadrži broj) i 
// jedan dodatni broj. Funkcija će dodati novi element sa tim brojem na sredinu liste 
// (ili odmah nakon sredine ako je broj elemenata neparan). (35 bodova)

Element* usredinu(Element* lst, int b) {

	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = b;

	if (lst == NULL) {
		novi->next = NULL;
		return novi;
	}

	Element* t = lst;
	Element* d = lst;
	while (d != NULL && d->next != NULL) {
		t = t->next;
		d = d->next->next;
	}

	novi->next = t->next;
	t->next = novi;

	return lst;

}