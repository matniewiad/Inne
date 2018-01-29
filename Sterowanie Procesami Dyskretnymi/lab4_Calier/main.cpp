#include <iostream>
#include <fstream>
#include <queue>
#include <conio.h>
using namespace std;

#define MAX 1000

//struktura przechowujaca parametry procesu
struct proces
	{
	int termin_dostepnosci;		//ri
	int czas_obslugi;			//pi
	int czas_dostarczenia;		//qi
	int nr_zadania;
	int czas_max;
	};

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

void wczytaj(proces* wyniki, int &ilosc_procesow);

//algorytm Schrage, zwraca Cmax
int Schrage(proces *harmonogram, int ilosc_procesow);

//algorytm Schrage z podzialem, zwraca Cmax
int PreSchrage(proces* harmonogram, int ilosc_procesow);

//wyznaczanie zadan a, b, c
void blok_abc(proces* permutacje, int ilosc_procesow, int &a, int &b, int &c);

//wyswietlanie permutacji zadan na maszynie wraz z wszystkimi parametrami
void wyswietl_permutacje(proces* permutacje, int ilosc_procesow);

//referencyjny algorytm Caliera
void Calier(proces* harmonogram, int ilosc_zadan, int UB, int &a, int &b, int &c);


int main()
{
	int ilosc_procesow;  //liczba zadan
	proces *harmonogram=new proces[MAX];
	wczytaj(harmonogram, ilosc_procesow);
	
	cout << "harm przed schrage: " << endl;
	wyswietl_permutacje(harmonogram, ilosc_procesow);
	
	int aaa = 0;
	aaa = PreSchrage(harmonogram, ilosc_procesow);
	cout << "Schrage z podzialem: " << aaa << endl;

	int abc = 0;
	abc = Schrage(harmonogram, ilosc_procesow);
	cout << "Schrage: " << abc << endl;

	int a, b, c;
	/*blok_abc(permutacje, ilosc_procesow, a, b, c);
	cout << "A: " << a << "	B: " << b << "	C: " << c << endl;*/

	cout << "harm po schrage: " << endl;
	wyswietl_permutacje(harmonogram, ilosc_procesow);

	int UB = 999999;

	//cout << endl << "Start algorytmu Caliera:" << endl;
	Calier(harmonogram, ilosc_procesow, UB, a, b, c);

	cout << endl;
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
			wyniki[i].nr_zadania = i;
		}
}

int Schrage(proces *harmonogram, int ilosc_procesow)
{
	int licznik =0;
	int max_czas=0;
	int obecna_chwila=0;
	int calkowity_czas=0;
	proces *permutacje = new proces[ilosc_procesow];

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
		
		permutacje[licznik].czas_max = max_czas;
		permutacje[licznik].nr_zadania = kolejka_priorytetowa_gotowych.top().nr_zadania;
		permutacje[licznik].czas_dostarczenia=kolejka_priorytetowa_gotowych.top().czas_dostarczenia;
		permutacje[licznik].czas_obslugi=kolejka_priorytetowa_gotowych.top().czas_obslugi;
		permutacje[licznik].termin_dostepnosci=kolejka_priorytetowa_gotowych.top().termin_dostepnosci;
		licznik++;
		kolejka_priorytetowa_gotowych.pop();
	
		for(int i = 0 ; i < ilosc_procesow ; i++)
		{
			harmonogram[i].nr_zadania = permutacje[i].nr_zadania;
			harmonogram[i].termin_dostepnosci = permutacje[i].termin_dostepnosci;
			harmonogram[i].czas_obslugi = permutacje[i].czas_obslugi;
			harmonogram[i].czas_dostarczenia = permutacje[i].czas_dostarczenia;
			harmonogram[i].czas_max = permutacje[i].czas_max;
		}
	}//!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	delete[] permutacje;
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

void blok_abc(proces* permutacje, int ilosc_procesow, int &a, int &b, int &c)
{
	//szukamy b
	b = 0;
	for(int i = 0 ; i < ilosc_procesow ; i++)
	{
		if(permutacje[i].czas_max > permutacje[b].czas_max)
		{
			b = i;
		}
	}

	//cout << "B: " << b << endl;
	//cout << "nr zadania: " << permutacje[b].nr_zadania << endl;

	//TAK BYLO
	a = b;		// 'a' ustawiamy na 'b' i sie cofamy, az napotkamy przerwe w bloku
	while(true)
	{
		//a--;
		if(permutacje[a].czas_max - permutacje[a].czas_dostarczenia - permutacje[a].czas_obslugi == permutacje[a].termin_dostepnosci && permutacje[a-1].czas_max-permutacje[a-1].czas_dostarczenia != permutacje[a].termin_dostepnosci)
		{
			break;	//znalezlizmy poczatek bloku, przerywamy petle
		}
		a--;
	}

	/*
	int Cmax = 0;
	for(int i = 0 ; i < ilosc_procesow ; i++)
	{
		if(Cmax < permutacje[i].czas_max)
		{
			Cmax = permutacje[i].czas_max;
		}
	}
	a = 0;
	int p;
	int q = 999999;
	for(int i = 0 ; i < ilosc_procesow ; i++)
	{
		p = 0;
		for(int j = i; j < b; j++)
		{
			p = p + permutacje[j].czas_obslugi;
		} 
		/*if(q > permutacje[i].termin_dostepnosci + p + permutacje[b].czas_dostarczenia)
		{
			q = permutacje[i].termin_dostepnosci + p + permutacje[b].czas_dostarczenia;
			a = i;
		}
		q = permutacje[i].termin_dostepnosci + p + permutacje[b].czas_dostarczenia;
		if(Cmax == q)
		{
			a = i;
			break;
		}
	}
	cout << "tu bylem" << endl;*/

	//cout << "A: " << a << endl;
	//cout << "nr zadania: " << permutacje[a].nr_zadania << endl;

	c = -1;		//'c' na poczatku ustawiamy na pierwszy element po 'a'. 'c' nie moze byc rowne 'a'.
	for(int i = a+1 ; i < b ; i++)
	{
		if(permutacje[i].czas_dostarczenia < permutacje[b].czas_dostarczenia)		//'c' porownujemy czasy dostarczenia. element o najwyzszym czasie dostarczenia to 'c'
		{
			c = i;
		}
	}
	//cout << "C: " << c << endl;
	/*if(a == b)
	{
		a--;
	}*/

	cout << "A= {r: " << permutacje[a] .termin_dostepnosci<< " p: " << permutacje[a].czas_obslugi << " q: " << permutacje[a].czas_dostarczenia << "}, ";
	cout << "B= {r: " << permutacje[b].termin_dostepnosci << " p: " << permutacje[b].czas_obslugi << " q: " << permutacje[b].czas_dostarczenia << "}, ";
	cout << "C= {r: " << permutacje[c].termin_dostepnosci << " p: " << permutacje[c].czas_obslugi << " q: " << permutacje[c].czas_dostarczenia << "}, " << endl;
	/*
	if(c!=-1)
	{
		//cout << "C: " << c << endl;
		//cout << "nr zadania: " << permutacje[c].nr_zadania << endl;
	}
	else
	{
		//cout << "brak C" << endl;
	}
	*/
	/*if(c != -1)
	{
		cout << "nr zadania c: " << permutacje[c].nr_zadania-1 << endl;
	}*/
}

void wyswietl_permutacje(proces* permutacje, int ilosc_procesow)
{
	cout << "Permutacja:" << endl;
	cout << "i	nr_zadania	r	p	q	C+q" << endl;
	for(int i = 0; i < ilosc_procesow ; i++)
	{
		cout << i << "	" << permutacje[i].nr_zadania << "		" << permutacje[i].termin_dostepnosci << "	" << permutacje[i].czas_obslugi << "	" << permutacje[i].czas_dostarczenia << "	" <<permutacje[i].czas_max << endl;
	}
}

void Calier(proces* harmonogram, int ilosc_procesow, int UB, int &a, int &b, int &c)
{
	if(c == -1)
	{
		//cout << "Wynik: " << U << endl;
		return;
	}

	cout <<"Carlier wywolany z permutacja:" << endl;
	for(int i = 0 ; i < ilosc_procesow ; i++)
	{
		cout << "r: " << harmonogram[i].termin_dostepnosci << " p: " << harmonogram[i].czas_obslugi << " q: " << harmonogram[i].czas_dostarczenia << " Cmax: " << harmonogram[i].czas_max << endl;
	}
	cout << endl;
	
	int U;

	U = Schrage(harmonogram, ilosc_procesow);		//krok 1 pseudokodu
	cout <<"Permutacja ze Schrage:" << endl;
	for(int i = 0 ; i < ilosc_procesow ; i++)
	{
		cout << "r: " << harmonogram[i].termin_dostepnosci << " p: " << harmonogram[i].czas_obslugi << " q: " << harmonogram[i].czas_dostarczenia << " Cmax: " << harmonogram[i].czas_max << endl;
	}
	cout << endl;


	if(U < UB)													//krok 2
	{
		UB = U;
	}

	cout << "blok abc: " << endl;
	blok_abc(harmonogram, ilosc_procesow, a, b, c);				//krok 3

	if(c == -1)													//krok 4
	{
		cout << "----------------------------" << endl;
		cout << "----------------------------" << endl;
		cout << "----------------------------" << endl;
		cout << "wynik Caliera: " << U << endl;
		cout << "----------------------------" << endl;
		cout << "----------------------------" << endl;
		cout << "----------------------------" << endl;
		return;
	}

	int r_prim = 99999;											//krok 5
	int p_prim = 0;
	int q_prim = 99999;									

	for(int i = c+1; i <= b; i++)
	{
		if(harmonogram[i].termin_dostepnosci < r_prim)
		{
			r_prim = harmonogram[i].termin_dostepnosci;
		}
	}

	for(int i = c+1; i <= b; i++)
	{
		if(harmonogram[i].czas_dostarczenia < q_prim)
		{
			q_prim = harmonogram[i].czas_dostarczenia;
		}
	}

	for(int i = c+1; i <= b; i++)
	{
		p_prim = p_prim + harmonogram[i].czas_obslugi;
	}

	int LB;
	//c = permutacje[c].nr_zadania-1;	//-1, bo iteracja od 1 a nie od 0

	int temp_r = harmonogram[c].termin_dostepnosci;				//krok 6
	if(r_prim + p_prim > harmonogram[c].termin_dostepnosci)
	{
		cout << "przenosze C na koniec" << endl;
		harmonogram[c].termin_dostepnosci = r_prim + p_prim;
	}

	LB = PreSchrage(harmonogram, ilosc_procesow);				//krok 7
	cout << "Schrage z podzialem dalo LB= " << LB << " a UB= " << UB << endl;
	if(LB < UB)													//krok 8
	{
		cout << "wywoluje Carliera rekurencyjnie" << endl;
		Calier(harmonogram, ilosc_procesow, UB, a, b, c);	//krok 9
	}

	harmonogram[c].termin_dostepnosci = temp_r;					//krok 10

	int temp_q = harmonogram[c].czas_dostarczenia;				//krok 11
	if(q_prim + p_prim > harmonogram[c].czas_dostarczenia)
	{
		cout << "przenosze C na poczatek" << endl;
		harmonogram[c].czas_dostarczenia = q_prim + p_prim;
	}

	LB = PreSchrage(harmonogram, ilosc_procesow);				//krok 12
	cout << "Schrage z podzialem dalo LB= " << LB << " a UB= " << UB << endl;

	if(LB < UB)													//krok 13
	{
		cout << "wywoluje Carliera rekurencyjnie" << endl;
		Calier(harmonogram, ilosc_procesow, UB, a, b, c);	//krok 14
	}
	harmonogram[c].czas_dostarczenia = temp_q;
	if(LB == UB)
	{
		cout << "Wynik: " << LB << endl;
	}
	cout << "Wracam..." << endl;
}