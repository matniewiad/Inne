#pragma once
#include "Modul.h"
#include <list>					//dla funkcji zaprzyjaznionych
class Zadanie
{
public:
	long int index;				//shi oem
	int p;						//czas wykonania
	int q;						//termin dostarczenia - na kiedy zamowione
	int lp;						//numer porzadkowy
	int program;				//program, potrzebne do przezbrojen	
	int p_calkowite;			//p*ilosc
	int ilosc;					//wymagana ilosc

	static int licznik_zadan;			//laczna liczba modulow
	Zadanie(int numer_porzadkowy, long int inx, int prog, int q, int ile, int czas_wykonania=1);
	Zadanie();
	void wyswietl_zadanie();
	void wyswietl_zadanie_less();
	void wyswietl_zadanie_tab();
	~Zadanie();

	bool operator> (const Zadanie&zad1)const
	{
		return (ilosc > zad1.ilosc);
	}

	friend struct sort_zadanie_ilosc_malejaco;
	friend struct sort_zadanie_q_rosnaco;
	friend int zapelnienie_linii(list<Zadanie>lista);
	//friend void wyswietl_zadania_more(vector<Zadanie>zadania);
	//friend void wyswietl_zadania_less(vector<Zadanie>zadania);
	//friend void wyswietl_zadania_tab(vector<Zadanie>zadania);
};

