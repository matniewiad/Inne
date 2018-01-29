//#include "StdAfx.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <conio.h>
using namespace std;

#define MAX 50

//struktura przechowujaca parametry procesu
struct proces
	{
		int termin_dostepnosci;		//ri
		int czas_obslugi;			//pi
		int czas_dostarczenia;		//qi
	};

//do ukladania kolejki priorytetowej
struct porownaj_termin_dostepnosci
{
	bool operator()(const proces & proces1, const proces & proces2)
	{
		return proces1.termin_dostepnosci>proces2.termin_dostepnosci;
	}
};

struct porownaj_czas_dostarczenia
{
	bool operator()(const proces & proces1, const proces & proces2)
	{
		return proces1.czas_dostarczenia<proces2.czas_dostarczenia;
	}
};

//wczytywanie parametrow zadan z pliku
void wczytaj(proces* wyniki, int &ilosc_procesow);

//algorytm Schrage, zwraca Cmax
int Schrage(proces *harmonogram, int ilosc_procesow);

//algorytm Schrage z podzialem, zwraca Cmax
int PreSchrage(proces* harmonogram, int ilosc_procesow);

int main()
{
	proces *harmonogram=new proces[MAX];		//tablica procesow

	int ilosc_procesow;		//zeby mozna bylo wczytac
	wczytaj(harmonogram, ilosc_procesow);

	int a = 0;
	a = Schrage(harmonogram, ilosc_procesow);
	cout << "Schrage: " << a << endl;

	int b = 0;
	b = PreSchrage(harmonogram, ilosc_procesow);
	cout << "PreSchrage: " << b << endl;
	
	delete [] harmonogram;
	system ("pause");
	return 0;
}

void wczytaj(proces* wyniki, int &ilosc_procesow)
{
	//otwieranie pliku
	fstream plik; // plik z danymi
	plik.open("SCHRAGE2.DAT", ios::in);

	plik >> ilosc_procesow;

	for(int i=0; i<ilosc_procesow; i++) //wypelnianie
		{
			plik >> wyniki[i].termin_dostepnosci;
			plik >> wyniki[i].czas_obslugi;
			plik >> wyniki[i].czas_dostarczenia;
		}
}

int Schrage(proces *harmonogram, int ilosc_procesow)
{
	int max_czas=0;
	int obecna_chwila=0;
	int calkowity_czas=0;

	//tworzenie kolejki N
	priority_queue <proces, vector<proces>, porownaj_termin_dostepnosci> kolejka_priorytetowa;
	
	//wypelnienie kolejki procesami
	for(int i=0; i<ilosc_procesow;i++)
		{
		kolejka_priorytetowa.push(harmonogram[i]);
		}

	obecna_chwila=kolejka_priorytetowa.top().termin_dostepnosci;
	
	max_czas=0;

	//tworzenie kolejki G
	priority_queue <proces, vector<proces>, porownaj_czas_dostarczenia> kolejka_priorytetowa_gotowych;

	while(!kolejka_priorytetowa_gotowych.empty() || !kolejka_priorytetowa.empty())
	{
		miejsce_skoku:
		while(!kolejka_priorytetowa.empty() && obecna_chwila>= kolejka_priorytetowa.top().termin_dostepnosci)
		{
			kolejka_priorytetowa_gotowych.push(kolejka_priorytetowa.top());
			kolejka_priorytetowa.pop();
		}
		
		if( kolejka_priorytetowa_gotowych.empty() )
		{
			obecna_chwila=kolejka_priorytetowa.top().termin_dostepnosci;
			goto miejsce_skoku;
		}
		obecna_chwila=obecna_chwila+kolejka_priorytetowa_gotowych.top().czas_obslugi;
		max_czas=obecna_chwila+kolejka_priorytetowa_gotowych.top().czas_dostarczenia;
		
		if(max_czas>calkowity_czas)
		{
			calkowity_czas=max_czas;	
		}
		
		kolejka_priorytetowa_gotowych.pop();
	
	}//!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	return calkowity_czas;
}

int PreSchrage(proces* harmonogram, int ilosc_procesow)
{
	//algorytm
	int max_czas=0;			//t+qe
	int obecna_chwila=0;	//t+pecx
	int calkowity_czas=0;	//max(Cmax, t+qe)
	
	//tworzenie kolejki N
	priority_queue <proces, vector<proces>, porownaj_termin_dostepnosci> kolejka_priorytetowa;
	//tworzenie kolejki G
	priority_queue <proces, vector<proces>, porownaj_czas_dostarczenia> kolejka_priorytetowa_gotowych;

	//wypelnienie kolejki N procesami
	for(int i=0; i<ilosc_procesow;i++)
	{
		kolejka_priorytetowa.push(harmonogram[i]);
	}

	obecna_chwila=kolejka_priorytetowa.top().termin_dostepnosci;
	
	max_czas=0;
	proces l;
	l.termin_dostepnosci=0;
	l.czas_obslugi=0;
	l.czas_dostarczenia=32000;

	while(!kolejka_priorytetowa_gotowych.empty() || !kolejka_priorytetowa.empty())
	{
		miejsce_skoku:
		while(!kolejka_priorytetowa.empty() && obecna_chwila>= kolejka_priorytetowa.top().termin_dostepnosci)
		{
			kolejka_priorytetowa_gotowych.push(kolejka_priorytetowa.top());

			if(l.czas_dostarczenia<kolejka_priorytetowa.top().czas_dostarczenia)
			{
				l.czas_obslugi=obecna_chwila-kolejka_priorytetowa.top().termin_dostepnosci;
				obecna_chwila=kolejka_priorytetowa.top().termin_dostepnosci;
				if(l.czas_obslugi>0)
				{
					kolejka_priorytetowa_gotowych.push(l);
				}
			}
			kolejka_priorytetowa.pop();
		}
		
		if( kolejka_priorytetowa_gotowych.empty() )
		{
			obecna_chwila=kolejka_priorytetowa.top().termin_dostepnosci;
			goto miejsce_skoku;
		}
		obecna_chwila=obecna_chwila+kolejka_priorytetowa_gotowych.top().czas_obslugi;
		max_czas=obecna_chwila+kolejka_priorytetowa_gotowych.top().czas_dostarczenia;
		
		if(max_czas>calkowity_czas)
		{
			calkowity_czas=max_czas;	
		}
		l=kolejka_priorytetowa_gotowych.top();
		kolejka_priorytetowa_gotowych.pop();
	}
	return calkowity_czas;
}