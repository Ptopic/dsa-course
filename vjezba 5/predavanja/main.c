
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

void main() {
	Element a, b, c;
	a.broj = 10;
	b.broj = 15;
	c.broj = 9;

	Element* lst;
	lst = &a;
	a.next = &b;
	//lst->next = &b;
	b.next = &c;
	c.next = NULL;

	print(lst);
	// izbaciti prvi element iz liste
	// lst = lst->next;
	// print(lst);

	// izbaciti drugi element iz liste
	// lst->next = lst->next->next;
	// print(lst);

	// zamijeniti prvi i drugi element
	/*
	Element* tmp = lst;
	lst = lst->next;
	tmp->next = lst->next;
	lst->next = tmp;
	print(lst);
	*/
	// prebaciti treci element na prvo mjesto
	Element* tmp = lst->next->next;
	lst->next->next = NULL;
	tmp->next = lst;
	lst = tmp;
	print(lst);




}