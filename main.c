#include <stdio.h>
#include <stdlib.h>
#include "listajk.h"
#define _CRT_SECURE_NO_WARNINGS

int main() {
	lista x = malloc(sizeof(elListy));
	unsigned znal;

	x->klucz = 5;
	x = malloc(sizeof(elListy));
	x->klucz = 6;
	printf("%d", x->klucz);
	x = 0, znal = 0;
	int wybor, klucz, przedza;

	do {
		menu();
		scanf("%d", &wybor);
		switch (wybor)
		{
		case 1:
			printf("Wartosc do dopisania: ");
			scanf("%d", &klucz);
			dnpl(&x, klucz);
			printf("Wykonano\n");
			break;
		case 2:
			printf("Wartosc do dopisania: ");
			scanf("%d", &klucz);
			dnkl(&x, klucz);
			printf("Wykonano\n");
			break;
		case 3:
			usunp(&x);
			printf("Wykonano\n");
			break;
		case 4:
			usunk(&x);
			printf("Wykonano\n");
			break;
		case 5:
			printf("Wartosc do znalezienia: ");
			scanf("%d", &klucz);
			znal = znajdz(x, klucz);
			if (!znal) {
				printf("Nie znaleziono wartosci\n");
			}
			else
				printf("Wykonano\nZapisano wskaznik do zmiennej\n");
			break;
		case 6:
			if (!znal) {
				printf("Najpierw wyszukaj wartosc (opcja 5)");
				break;
			}
			printf("PRZED - 1\nZA - 2\n");
			scanf("%d", &przedza);
			while (przedza != 1 && przedza != 2) {
				printf("PRZED - 1\nZA - 2\n");
				scanf("%d", &przedza);
			}
			printf("Wartosc do dopisania: ");
			scanf("%d", &klucz);
			if (przedza == 1)
				dodajprzedznal(&znal, &x, klucz);
			if (przedza == 2)
				dodajzaznal(&znal, &x, klucz);
			znal = 0;
			printf("Wykonano\nZresetowano wskaznik na szukany element\n");
			break;
		case 7:
			usunwsk(&znal, &x);
			printf("Wykonano\n");
			break;
		case 8:
			if (x)
				druk(x);
			else
				printf("LISTA PUSTA\n");
			break;
		case 9:
			if (x)
				drukodw(x);
			else
				printf("LISTA PUSTA\n");
			break;
		default:
			break;
		}
	} while (wybor);
	system("pause");
	return 0;
}
