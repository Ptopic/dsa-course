
#include <stdio.h>

typedef struct _Element {
	int broj;
	struct _Element* next;
} Element;

// typedef Element* Lista;

void print(Element* lst) {
	Element* tmp = lst;
	while (tmp != NULL) {
		printf("%d-> ", tmp->broj);
		tmp = tmp->next;
	}
	printf(" null\n");
}

void dodaj_u_glavu2(int broj, Element** lst) {
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = broj;
	novi->next = *lst;
	*lst = novi;
}

Element* dodaj_u_glavu(int broj, Element* lst) {
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = broj;
	novi->next = lst;
	return novi;
}

Element* dodaj_na_kraj(int broj, Element* lst) {
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = broj;
	novi->next = NULL;
	if (lst == NULL) {
		return novi;
	}
	Element* tmp = lst;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = novi;
	return lst;
}

Element* dodaj_prije_6(int broj, Element* lst) {
	Element* novi = (Element*)malloc(sizeof(Element));
	novi->broj = broj;
	novi->next = NULL;

	if (lst->broj == 6) {
		novi->next = lst;
		return novi;
	}

	Element* tmp = lst;
	while (tmp->next->broj != 6) {
		tmp = tmp->next;
	}
	novi->next = tmp->next;
	tmp->next = novi;
	return lst;
}

void izbrisi_listu(Element* lst) {
	while (lst != NULL) {
		Element* b = lst;
		lst = lst->next;
		free(b);
	}
}

Element* izbrisi_element(int broj, Element* lst) {
	if (lst->broj == broj) {
		Element* brisi = lst;
		lst = lst->next;
		free(brisi);
		return lst;
	}
	Element* tmp = lst;
	while (tmp->next != NULL) {
		if (tmp->next->broj == broj) {
			Element* brisi = tmp->next;
			tmp->next = tmp->next->next;
			free(brisi);
			return lst;
		}
		tmp = tmp->next;
	}
	return lst;
}


void main() {
	Element* lst = NULL;
	lst = dodaj_u_glavu(10, lst);
	lst = dodaj_u_glavu(3, lst);
	lst = dodaj_u_glavu(9, lst);
	//lst = dodaj_u_glavu(6, lst);
	print(lst);
	lst = izbrisi_element(6, lst);
	print(lst);


}