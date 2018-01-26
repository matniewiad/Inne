#pragma once
using namespace std;
#include <iostream>

class osoba
{
private:
	int wiek;
	char nazwisko[50];
	static int skladnik_statyczny;
	
public:
	static int skladnik_statyczny_pub;
	osoba(int);
	osoba(int, char*);
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

