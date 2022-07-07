#ifndef listajk_h
#define listajk_h
typedef struct el {
	int klucz;
	struct el* nast;
};
typedef struct el elListy;
typedef elListy* lista;
void menu();
void dnkl(lista* l, int i);
void dnpl(lista* l, int i);
void druk(lista l);
void usunp(lista* l);
void usunk(lista* l);
lista znajdz(lista l, int i);
void dodajzaznal(lista* z, lista* l, int i);
void dodajprzedznal(lista* z, lista* l, int i);
void usunwsk(lista* z, lista* l);
void drukodw(lista l);

#endif



