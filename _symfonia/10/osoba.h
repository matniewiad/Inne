#pragma once
using namespace std;
#include <iostream>

class osoba
{
private:
	int wiek;
	char nazwisko[50];
	static int skladnik_statyczny;
	static int licznik_priv;
	
public:
	int numer_porzadkowy;
	static int licznik_pub;
	static int skladnik_statyczny_pub;
	osoba();
	osoba(int, char*);
	osoba(const osoba&);			//konstruktor kopiujacy (const - nie moze zmieniac wzorca)
	~osoba();

	void wypisz();
	void zapamietaj();
	void postarzanie();
	static void spiew();
	void funkcja_const() const;
	void funkcja_volatile() volatile;
	void funkcja_VC() volatile const;
	friend void funkcja_zaprzyjazniona(osoba*);
};

