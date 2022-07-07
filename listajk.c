#include <stdio.h>
#include <stdlib.h>
#include "listajk.h"

void menu() {
	printf("\n");
	printf("1 - dodaj element na poczatku listy\n");
	printf("2 - dodaj element na koncu listy\n");
	printf("3 - usun pierwszy element listy\n");
	printf("4 - usun ostatni element listy\n");
	printf("5 - odszukaj zadany element\n");
	printf("6 - dodaj nowy element przed lub za wskazanym elementem\n");
	printf("7 - usun zadany element\n");
	printf("8 - wyswietl zawartosc listy\n");
	printf("9 - wyswietl ODWROTNIE zawartosc listy\n");
	printf("Nastepna operacja: ");
}

void dnkl(lista* l, int i) {
	lista p = 0;
	lista kopia = *l;
	p = (lista)malloc(sizeof(elListy));
	p->klucz = i;
	p->nast = 0;
	if (kopia) {
		while (kopia->nast)
			kopia = kopia->nast;
		kopia->nast = p;
	}
	else
		*l = p;
}

void dnpl(lista* l, int i) {
	lista p = 0;
	p = malloc(sizeof(elListy));
	p->nast = *l;
	p->klucz = i;
	*l = p;
}

void druk(lista l) {
	if (l == NULL) {
		return;
	}
	printf("%d -> ", l->klucz);
	druk(l->nast);
}

void drukodw(lista l) {
	lista k = l;
	lista p = 0;
	while (k) {
		dnpl(&p, k->klucz);
		k = k->nast;
	}
	druk(p);
}

void usunp(lista* l) {
	lista p = *l;
	if (p) {
		*l = (*l)->nast;
		free(p);
	}
}

void usunk(lista* l) {
	lista p = *l;
	while (p->nast->nast)
		p = p->nast;
	p->nast = 0;
	free(p->nast);
}

lista znajdz(lista l, int i) {///zwraca element poprzedzajacy
	lista p = l;
	if (p == 0)
		return 0;
	if (p->klucz == i)
		return INT_MAX; //szukany jest 1 el
	while (p->nast) {
		if (p->nast->klucz == i)
			return p;
		else
			p = p->nast;
	}
	return 0;
}

void dodajzaznal(lista* z, lista* l, int i) {
	lista p = 0;
	lista w = (lista)malloc(sizeof(elListy));
	w->klucz = i;
	if (*z == INT_MAX) {//oznacza ¿e znaleziony el jest 1 el listy
		if ((*l)->nast) {
			p = *l;
			w->nast = p->nast;
			p->nast = w;
		}
		else
			dnkl(&(*l), i);
	}
	else {
		p = *z;
		w->nast = p->nast->nast;
		p->nast->nast = w;
	}
}

void dodajprzedznal(lista* z, lista* l, int i) {
	if (*z == INT_MAX) {
		dnpl(&(*l), i);
		return;
	}
	lista p = *z;
	lista w = (lista)malloc(sizeof(elListy));
	w->klucz = i;
	w->nast = p->nast;
	p->nast = w;
}

void usunwsk(lista* z, lista* l) {
	if (*z == INT_MAX) {
		usunp(&(*l));
		/*if ((*l)->nast) {
			lista p = *l;
			*l = (*l)->nast;
			p->nast = 0;
			free(p);
			return;
		}
		else
			free(*l);*/
		return;
	}
	if (*z == 0)
		return;
	if ((*z)->nast->nast == 0) {
		free((*z)->nast);
		return;
	}
	else {
		lista p;
		p = (*z)->nast;
		(*z)->nast = (*z)->nast->nast;
		free(p);
	}
}