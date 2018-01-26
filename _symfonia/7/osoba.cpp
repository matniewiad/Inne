#include "osoba.h"
#include <iostream>
using namespace std;


osoba::osoba(int a)
{
	cout << endl << "konstruktor dziala" << endl;
	wiek = 0;
	char temp[] = { "Brak" };
	strcpy_s(nazwisko, temp);
}

osoba::osoba(int a, char *b)
{
	cout << endl << "konstruktor 2 dziala" << endl;
	wiek = a;
	//char temp[] = { "Brak" };
	strcpy_s(nazwisko, b);
}


osoba::~osoba()
{
	cout << "haHA! DESTRUKCJA" << endl;
}

void osoba::wypisz()
{
	cout << "wiek: " << wiek << endl;
	cout << "nazwisko: " << nazwisko << endl;
}

void osoba:: zapamietaj()
{
	cout << "podaj wiek: " << endl;
	cin >> wiek;
	cout << "podaj nazwisko: " << endl;
	cin >> nazwisko;
}

void osoba::spiew()
{
	cout << "lalalalal" << endl;
}

void osoba::postarzanie()
{
	wiek += 10;
}

void osoba::funkcja_const() const
{
	cout << "dziala funkcja const" << endl;
}

void osoba::funkcja_volatile() volatile
{
	cout << "dziala funkcja volatile" <<endl;
}

void osoba::funkcja_VC() volatile const
{
	cout << "dziala funkcja volatile i const rownoczenie" << endl;
}

int osoba::skladnik_statyczny = 50;
int osoba::skladnik_statyczny_pub = 50;