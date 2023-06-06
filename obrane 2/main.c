#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
	int broj;
	struct Element* next;
}Element;

typedef Element* Lista;

/*
* - Brisanje liste
o	Brisanje citave liste
*/

Lista brisiListu(Lista lst) {
	while (lst != NULL) {
		Element* brisi = lst;
		lst = lst->next;
		free(brisi);
	}
	return lst;
}

/*
* - Šetanje po listi
o	Traženje najduže riječi
o	Ukupan broj riječi
*/

void print(Lista lst) {
	Element* tmp = lst;
	while (tmp != NULL) {
		printf("%d-> ", tmp->broj);
		tmp = tmp->next;
	}
	printf(" null\n");
}

int maxFromList(Lista lst) {
	int max = lst->broj;
	Lista tmp = lst;
	while (tmp->next != NULL) {
		if (tmp->next->broj > max) {
			max = tmp->next->broj;
		}
		tmp = tmp->next;
	}
	return max;
}



int minFromList(Lista lst) {
	int min = lst->broj;
	Lista tmp = lst;
	while (tmp->next != NULL) {
		if (tmp->next->broj < min) {
			min = tmp->next->broj;
		}
		tmp = tmp->next;
	}
	return min;
}

int ukCount(Lista lst) {
	int count = 0;
	Lista tmp = lst;
	while (tmp != NULL) {
		count++;
		tmp = tmp->next;
	}
	return count;
}


/*
* - Kreiranje i dodavanje novog elementa :
o	Na početak liste
o	Na kraj liste
o	Prije određenog elementa u listi
o	Na određenom indeksu u listi
*/

Lista dodaj_u_glavu(int broj, Lista lst) {
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = broj;
	novi->next = lst;
	return novi;
}

Lista dodajNaKraj(int broj, Lista lst) {
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = broj;
	novi->next = NULL;
	// Prosetat do kraja liste
	Lista tmp = lst;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

	tmp->next = novi;

	return lst;

}

// Nacrtaj
Lista dodajPrijeEl(int broj, Lista lst, int el) {
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = broj;

	Lista tmp = lst;
	while (tmp->next->broj != el) {
		tmp = tmp->next;
	}

	novi->next = tmp->next;
	tmp->next = novi;
	return lst;
}

// Nacrtaj
Lista dodajNaIndeks(int broj, Lista lst, int index) {
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = broj;

	int i = 1;

	Lista tmp = lst;

	// Prosetaj do zeljenog indeksa
	while (tmp->next != NULL) {
		if (i == index) {
			break;
		}
		tmp = tmp->next;
		i++;
	}

	// Dodaj novi element prije elementa na zeljenom indeksu
	// Vezi novi->next na iduci element
	// Stavi trenutni element na novi

	novi->next = tmp->next;
	tmp->next = novi;

	return lst;
}

/*
* - Pronalazak i uklanjanje elementa iz liste :
o	Sa početka liste
o	Sa kraja liste
o	Određenu riječ
o	Od donje do gornje granice indeksa
*/

Lista brisiSaPocetka(Lista lst) {
	if (lst == NULL) {
		return NULL;
	}

	Element* brisi = lst;
	lst = lst->next;
	free(brisi);
	return lst;
}

Lista brisiSaKraja(Lista lst) {
	if (lst == NULL) {
		return lst;
	}

	// Setamo do zadnjeg el i brisemo ga
	Element* tmp = lst;

	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

	Element* brisi = tmp->next;
	tmp->next = NULL;
	free(brisi);
	return lst;
}

Lista ukloniOdrElement(int broj, Lista lst) {
	if (lst == broj) {
		return lst;
	}

	Element* tmp = lst;

	while (tmp->next->broj != broj) {
		tmp = tmp->next;
	}
	tmp->next = tmp->next->next;
	return lst;

}

Lista ukloniOdGranica(Lista lst, int donjaGranica, int gornjaGranica) {
	Element* tmp = lst;

	// od 2 do 4
	// 10 2 10
	// Prosetaj do indeksa
	for (int i = 0; i < donjaGranica-1; i++) {
		tmp = tmp->next;
	}
	tmp->next = tmp->next->next;

	printf("\n el %d \n", tmp->broj);
	// Remove (gornja - donja granica)
	for (int i = 0; i < (gornjaGranica - donjaGranica); i++) {
		tmp->next = tmp->next->next;
	}

	return lst;
}


//- Okretanje liste

Lista reverse(Lista lst) {
	struct Element* prev = NULL;
	struct Element* curr = lst;
	struct Element* next;

	while (curr != NULL)
	{
		// Store the next node
		next = curr->next;

		// Reverse the current node
		curr->next = prev;

		// Move pointers one step forward
		prev = curr;
		curr = next;
	}

	// Update the head to point to the new head of the list
	lst = prev;
	return lst;
}

// Prebacivanja
//- Prebacivanje elementa u listi(npr.sa kraja na početak liste)
//- Prebacivanje dijela liste u novu listu po nekom kriteriju(npr.sve riječi duže od 10 znakova)

Lista prebaciSaKrajaNaPocetak(Lista lst) {
	Element* zadnji = NULL;

	Element* tmp = lst;
	while (tmp != NULL) {
		tmp = tmp->next;
	}
	zadnji = tmp->next;

	Element* novi = (Element*)sizeof(Element);
	novi->broj = zadnji->broj;
	novi->next = lst;
	return lst;
}

Lista prebaciPrva3UDruguListu(Lista lst) {
	Lista novaLista = NULL;

	Element* tmp = lst;

	for (int i = 0; i < 3; i++) {
		dodaj_u_glavu(tmp->broj, novaLista);
		tmp = tmp->next;
	}

	return novaLista;
}

Lista prebaciSveVeceOd5UDruguListu(Lista lst) {
	Lista novaLista = NULL;


	Element* tmp = lst;

	while (tmp != NULL) {
		if (tmp->broj > 5) {
			dodaj_u_glavu(tmp->broj, novaLista);
			tmp = tmp->next;
		}
	}

	return novaLista;
}

// Kopiranje
//- Kopiranje jednog ili više elemenata u novu listu
//- Kopiranje jednog ili više elemenata u niz

// !!!!!!!!!!!!!!!!!!!!!!!!!
Lista kopirajUnovuListu(Lista lst) {
	Element* kopija = NULL;
	Element* kraj = NULL;
	while (lst != NULL) {
		Element* novi = (Element*)malloc(sizeof(Element));
		novi->broj = lst->broj;
		novi->next = NULL;

		if (kraj != NULL)
			kraj->next = novi;
		else
			kopija = novi;
		kraj = novi;
		lst = lst->next;
	}
	return kopija;

}

int* kopirajUniz(Lista lst) {
	int count = ukCount(lst);
	int niz[200];
	int i = 0;
	while (lst != NULL) {
		niz[i] = lst->broj;
		i++;
		lst = lst->next;
	}

	return niz;
}

// Zamjena elemenata
//- Zamjena dva elementa u listi(npr.prvi i zadnji)

Lista zamjeniPrviIZadnji(Lista lst) {
	// Provjera jel lista ima samo dva elementa ako ima vrati head
	if (lst == NULL || lst->next == NULL) {
		return lst;
	}

	Element* cur = lst;

	while (cur->next != NULL) {
		cur = cur->next;
	}

	Element* tmp = cur->broj;
	cur->broj = lst->broj;
	lst->broj = tmp;

	return lst;
}

//- Dodavanje elemenata iz niza u listu
Lista dodajElementeIzNizaUlistu(int *niz) {

	int size = sizeof(niz);
	// Kreiraj praznu listu
	Lista newList = NULL;

	// Loopaj kroz niz i dodaj elemente u listu (loopaj kroz nju)
	newList = dodaj_u_glavu(niz[0], newList);
	for (int i = 1; i < size-1; i++) {
		newList = dodajNaKraj(niz[i], newList);
	}
	return newList;
}


//- Uklanjanje više elemenata iz liste po nekom kriteriju(npr.zadnjih 10 elemenata ili sve elemente sa više od 10 znakova)
//- Dodavanje više elemenata u listu(npr.ispred svake riječi duže od 10 znakova)
Lista ukloniZadnja4(Lista lst) {
	Element* tmp = lst;
	int size = ukCount(lst);
	for (int i = 0; i < (size-1) - 4; i++) {
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return lst;
}


Lista ukloniSveVeceOd7(Lista lst) {
	if (lst->broj > 7) {
		Element* brisi = lst;
		lst = lst->next;
		free(brisi);
	}

	Element* tmp = lst;

	while (tmp->next != NULL) {
		if (tmp->next->broj > 7 && tmp->next != NULL) {
			tmp->next = tmp->next->next;
		}

		tmp = tmp->next;
	}

	return lst;

}

// Implementaj posli !!!!!!!!!!!!!!
Lista dodajIspredSvakogParnogBroja(Lista lst) {
	if (lst == NULL) {
		return;
	}
	Element* tmp = lst;
	while (tmp != NULL) {
		// Check if the current node contains an odd number
		if (tmp->broj % 2 == 0) 
		{
			Element* novi = (Element*)malloc(sizeof(Element));
			novi->broj = 11;
			novi->next = tmp;
			tmp = novi;
		}

		tmp = tmp->next;
	}

	return lst;
}






void main() {
	Lista lst = NULL;
	lst = dodaj_u_glavu(10, lst);
	lst = dodaj_u_glavu(3, lst);
	lst = dodaj_u_glavu(9, lst);
	lst = dodajNaKraj(2, lst);
	int max = maxFromList(lst);
	printf("\n %d max \n", max);
	int min = minFromList(lst);
	printf("\n %d min \n", min);
	int count = ukCount(lst);
	printf("\n %d count \n", count);
	dodajPrijeEl(25, lst, 2);

	lst = dodajNaIndeks(7, lst, 3);

	print(lst);

	lst = brisiSaPocetka(lst);

	print(lst);

	lst = ukloniOdrElement(7, lst);

	print(lst);

	lst = zamjeniPrviIZadnji(lst);

	print(lst);

	lst = dodaj_u_glavu(10, lst);
	lst = dodaj_u_glavu(3, lst);
	lst = dodaj_u_glavu(9, lst);

	print(lst);

	lst = ukloniOdGranica(lst, 2, 4);
	print(lst);

	//lst = brisiListu(lst);
	//print(lst);

	int niz[] = { 1,2,3,4,5,6,7 };

	Lista newList = dodajElementeIzNizaUlistu(niz);
	print(newList);

	lst = reverse(lst);
	print(lst);

	lst = dodaj_u_glavu(10, lst);
	lst = dodaj_u_glavu(4, lst);
	lst = dodajNaKraj(3, lst);
	lst = dodajNaKraj(3, lst);
	lst = dodajNaKraj(3, lst);
	lst = dodajNaKraj(3, lst);
	print(lst);

	lst = ukloniZadnja4(lst);
	print(lst);

	lst = dodajNaKraj(2, lst);
	lst = dodaj_u_glavu(8, lst);
	lst = dodajNaIndeks(8, lst, 4);
	print(lst);


	lst = ukloniSveVeceOd7(lst);
	print(lst);

	Lista newList2 = prebaciPrva3UDruguListu(lst);
	print(newList2);

	int *niz2 = kopirajUniz(lst);

	for (int i = 0; i < count; i++) {
		printf("\n %d \n", niz2[i]);
	}

	//Lista novalista3 = prebaciSveVeceOd5UDruguListu(lst);
	//print(novalista3);

	Lista kopijaListe = kopirajUnovuListu(lst);
	print(kopijaListe);

	lst = dodajIspredSvakogParnogBroja(lst);
	print(lst);
	//lst = dodaj_u_glavu(8, lst);
	//lst = dodajNaIndeks(8, lst, 4);
	//lst = dodajIspredSvakogParnogBroja(lst);
	//print(lst);

	// Fix
	//lst = brisiSaKraja(lst);
	//print(lst);


}