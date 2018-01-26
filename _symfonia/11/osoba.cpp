#include "osoba.h"
#include <iostream>
using namespace std;


osoba::osoba()
{
	licznik_priv++;
	licznik_pub++;
	numer_porzadkowy = licznik_priv;
	cout << "konstruktor obiektu " << licznik_priv << " dziala" << endl << endl;
	wiek = 0;
	char temp[] = { "Brak" };
	strcpy_s(nazwisko, temp);
}

osoba::osoba(int a, char *b)
{
	licznik_priv++;
	licznik_pub++;
	numer_porzadkowy = licznik_priv;
	cout << "konstruktor 2 obiektu " << licznik_priv << " dziala" << endl << endl;
	wiek = a;
	//char temp[] = { "Brak" };
	strcpy_s(nazwisko, b);
}

//konstruktor kopiujacy
osoba::osoba(const osoba& wzor)
{
	licznik_priv++;
	licznik_pub++;
	numer_porzadkowy = licznik_priv;
	cout << "konstruktor kopiujacy obiektu " << licznik_priv << " dziala" << endl << endl;
	wiek = wzor.wiek;
	strcpy_s(nazwisko, wzor.nazwisko);
}

osoba::~osoba()
{
	cout << "destruktor " << licznik_priv << " dziala" << endl;
	licznik_priv--;
	licznik_pub--;
	//cout << "haHA! DESTRUKCJA" << endl;
}

void osoba::wypisz()
{
	cout << "wiek: " << wiek << endl;
	cout << "nazwisko: " << nazwisko << endl << endl;
}

void osoba:: zapamietaj()
{
	cout << "podaj wiek: ";
	cin >> wiek;
	cout << "podaj nazwisko: ";
	cin >> nazwisko;
	cout << endl;
}

void osoba::spiew()
{
	cout << "lalalalal" << endl << endl;
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
int osoba::licznik_priv = 0;
int osoba::licznik_pub = 0;