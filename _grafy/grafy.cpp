#include "grafy.h"
#include <iostream>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;

//************************************************
//macierz sasiedztwa - funkcje glowne

int** stworz_macierz_nxn(int n)
{
	int **tab = new int*[n];

	for (int i = 0; i < n; i++)
		tab[i] = new int[n];

	return tab;
}

void usun_macierz_nxn(int ** tab, int n)
{
	for (int i = 0; i < n; i++)
		delete[]tab[i];
	delete[]tab;
}

void zeruj_macierz_nxn(int ** tab, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tab[i][j] = 0;
		}
	}
}

void wyswietl_macierz_nxn(int ** tab, int n)
{
	cout << "   ";
	for (int i = 0; i < n; i++) cout << setw(2) << i;
	cout << endl << endl;

	for (int i = 0; i < n; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < n; j++)
		{
			cout << setw(2) << tab[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void wypelnij_macierz_sasiedztwa_nxn_DG(int ** tab, int n, int E)
{
	int pocz, konc;

	cout << "podaj kolejne krawedzie" << endl;
	for (int i = 0; i < E; i++)
	{
		cin >> pocz >> konc;
		if (pocz < n && konc < n && pocz >= 0 && konc >= 0)
		{
			tab[pocz][konc] = 1;
		}
		else
		{
			cout << "bledne wspolrzedne wierzcholka! Podaj wspolrzedne raz jeszcze" << endl;
			i--;
		}
	}
}

void wypelnij_macierz_sasiedztwa_nxn_NDG(int ** tab, int n, int E)
{
	int pocz, konc;

	cout << "podaj kolejne krawedzie" << endl;
	for (int i = 0; i < E; i++)
	{
		cin >> pocz >> konc;
		if (pocz < n && konc < n && pocz >= 0 && konc >= 0)
		{
			tab[pocz][konc] = 1;
			tab[konc][pocz] = 1;
		}
		else
		{
			cout << "bledne wspolrzedne wierzcholka! Podaj wspolrzedne raz jeszcze" << endl;
			i--;
		}
	}
}

void wczytaj_macierz_sasiedztwa_nxn_DG_z_pliku(int**graf, string nazwa, int E)
{
	fstream plik;
	plik.open(nazwa, ios::in);
	int p, k;
	if (plik.good() == true)
	{
		//cout << "otworzono" << endl;
		for (int i = 0; i < E; i++)
		{
			plik >> p >> k;
			graf[p][k] = 1;
		}
		cout << "prawdopodobnie wczytano!" << endl;
	}
	else
	{
		cout << "nie udalo sie otworzyc pliku" << endl;
	}
	plik.close();
}

void wczytaj_macierz_sasiedztwa_nxn_NDG_z_pliku(int**graf, string nazwa, int E)
{
	fstream plik;
	plik.open(nazwa, ios::in);
	int p, k;
	if (plik.good() == true)
	{
		//cout << "otworzono" << endl;
		for (int i = 0; i < E; i++)
		{
			plik >> p >> k;
			graf[p][k] = 1;
			graf[k][p] = 1;
		}
		cout << "prawdopodobnie wczytano!" << endl;
	}
	else
	{
		cout << "nie udalo sie otworzyc pliku" << endl;
	}
	plik.close();
}


//***************************************************************
//macierz sasiedztwa - funckje poboczne

void przepisz_nxn(int**cel, int**zrodlo, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cel[i][j] = zrodlo[i][j];
}

void wypisz_sasiadow_wierzcholka_nxn(int ** tab, int n, int ktory)
{
	cout << "sasiedzi wierzcholka " << ktory << " to: " << endl;

	for (int i = 0; i < n; i++)
	{
		if (tab[ktory][i] == 1)
			cout << i << "  ";
	}
	cout << endl;
}

void dla_kogo_sasiadem_nxn(int ** tab, int n, int ktory)
{
	cout << "wierzcholek " << ktory << " jest sasiadem dla: " << endl;

	for (int i = 0; i < n; i++)
	{
		if (tab[i][ktory] == 1)
			cout << i << "  ";
	}
	cout << endl;
}

void stopnie_nxn_NDG(int ** tab, int n)
{
	int stopien = 0;
	cout << "stopnie grafu nieskierowanego" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tab[i][j] == 1)
			{
				stopien++;
				if (i == j)
					stopien++;
			}
		}
		cout << "deg(v" << i << ") = " << stopien << endl;
		stopien = 0;
	}
}

void stopnie_wchodzace_nxn(int ** tab, int n)
{
	int stopien = 0;
	cout << "stopnie wchodzace grafu" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tab[j][i] == 1 && i != j)
			{
				stopien++;
			}
		}
		cout << "deg_in(v" << i << ") = " << stopien << endl;
		stopien = 0;
	}
}

void stopnie_wychodzace_nxn(int ** tab, int n)
{
	int stopien = 0;
	cout << "stopnie wychodzace grafu" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tab[i][j] == 1)
			{
				stopien++;
			}
		}
		cout << "deg_out(v" << i << ") = " << stopien << endl;
		stopien = 0;
	}
}

void krawedzie_dwukierunkowe_nxn_DG(int ** tab, int n)
{
	cout << "krawedzie dwukierunkowe w grafie skierowanym: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)		//sprawdzamy poloe macierzy
		{
			if (tab[i][j] == 1 && tab[j][i] == 1 && i != j)
			{
				cout << "(" << i << ", " << j << ")" << endl;
			}
		}
	}
}

void wierzcholki_izolowane_nxn(int ** tab, int n)
{
	bool izolowany = true;
	int ile_izolowanych = 0;
	cout << "wierzcholki izolowane:" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tab[i][j] == 1 && i != j)
			{
				izolowany = false;
				break;
			}
		}
		if (izolowany == true)
		{
			cout << "v" << i << endl;
			ile_izolowanych++;
		}
		izolowany = true;
	}

	if (ile_izolowanych == 0)
		cout << "brak wierzcholkow izolowanych" << endl;
}

void petle_nxn(int ** tab, int n)
{
	cout << "petle w grafie:" << endl;
	int ile_petli = 0;
	for (int i = 0; i < n; i++)
	{
		if (tab[i][i] == 1)
		{
			cout << "v" << i << endl;
			ile_petli++;
		}
	}
	if (ile_petli == 0)
		cout << "brak petli w grafie" << endl;
}


//***************************************************************
//macierz incydencji

int ** stworz_macierz_nxm(int n, int m)
{
	int **tab = new int*[n];

	for (int i = 0; i < n; i++)
		tab[i] = new int[m];

	return tab;
}

void usun_macierz_nxm(int ** tab, int n)
{
	for (int i = 0; i < n; i++)
		delete[]tab[i];
	delete[]tab;
}

void zeruj_macierz_nxm(int ** tab, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tab[i][j] = 0;
		}
	}
}

void wyswietl_macierz_nxm(int ** tab, int n, int m)
{
	cout << "   ";
	for (int i = 0; i < m; i++) cout << setw(2) << i;
	cout << endl << endl;

	for (int i = 0; i < n; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < m; j++)
		{
			cout << setw(2) << tab[i][j];
		}
		cout << endl;
	}
}

void wypelnij_macierz_incydencji_nxm_DG(int ** tab, int n, int E)
{
	int pocz, konc;
	int ktora_krawedz = 0;

	cout << "podaj kolejne krawedzie" << endl;
	for (int i = 0; i < E; i++)
	{
		cin >> pocz >> konc;
		if (pocz < n && konc < n && pocz >= 0 && konc >= 0)
		{
			tab[pocz][ktora_krawedz] = 1;
			tab[konc][ktora_krawedz] = -1;
			ktora_krawedz++;
		}
		else
		{
			cout << "bledne wspolrzedne wierzcholka! Podaj wspolrzedne raz jeszcze" << endl;
			i--;
		}
	}
}

void wypelnij_macierz_incydencji_nxm_NDG(int ** tab, int n, int E)
{
	int pocz, konc;
	int ktora_krawedz = 0;

	cout << "podaj kolejne krawedzie" << endl;
	for (int i = 0; i < E; i++)
	{
		cin >> pocz >> konc;
		if (pocz < n && konc < n && pocz >= 0 && konc >= 0)
		{
			tab[pocz][ktora_krawedz] = 1;
			tab[konc][ktora_krawedz] = 1;
			ktora_krawedz++;
		}
		else
		{
			cout << "bledne wspolrzedne wierzcholka! Podaj wspolrzedne raz jeszcze" << endl;
			i--;
		}
	}
}

void wierzcholki_izolowane_nxm(int ** tab, int n, int E)
{
	bool izolowany = true;
	int ile_izolowanych = 0;
	cout << "wierzcholki izolowane:" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < E; j++)
		{
			if (tab[i][j] == 1 || tab[i][j] == -1)
			{
				izolowany = false;
				break;
			}
		}
		if (izolowany == true)
		{
			cout << "v" << i << endl;
			ile_izolowanych++;
		}
		izolowany = true;
	}

	if (ile_izolowanych == 0)
		cout << "brak wierzcholkow izolowanych" << endl;
}

void usun_krawedz_lista_sasiedztwa(list<int>*graf, int pocz, int konc, bool is_DG)
{
	graf[pocz].remove(konc);
	if (!is_DG)
		graf[konc].remove(pocz);
}


//*********************************************************
//lista sasiedztwa - funckje glowne
list<int>* stworz_liste_sasiedztwa(int n)
{
	list<int> * graf = new list<int>[n];
	return graf;
}

void usun_liste_sasiedztwa(list<int>*graf)
{
	delete[] graf;
}

void wczytaj_liste_sasiedztwa_DG_z_pliku(list<int>*graf, string nazwa, int E)
{
	fstream plik;
	plik.open(nazwa, ios::in);
	int p, k;
	if (plik.good() == true)
	{
		//cout << "otworzono" << endl;
		for (int i = 0; i < E; i++)
		{
			plik >> p >> k;
			graf[p].push_back(k);
		}
		cout << "prawdopodobnie wczytano!" << endl;
	}
	else
	{
		cout << "nie udalo sie otworzyc pliku" << endl;
	}
	plik.close();
}

void wczytaj_liste_sasiedztwa_NDG_z_pliku(list<int>*graf, string nazwa, int E)
{
	fstream plik;
	plik.open(nazwa, ios::in);
	int p, k;
	if (plik.good() == true)
	{
		//cout << "otworzono" << endl;
		for (int i = 0; i < E; i++)
		{
			plik >> p >> k;
			graf[p].push_back(k);
			if (p != k)
				graf[k].push_back(p);
		}
		cout << "prawdopodobnie wczytano!" << endl;
	}
	else
	{
		cout << "nie udalo sie otworzyc pliku" << endl;
	}
	plik.close();
}

void wypelnij_liste_sasiedztwa_NDG(list<int> *graf, int n, int E)
{
	int pocz, konc;		//wierzcholek poczatkowy i koncowy krawedzi

	cout << "podaj kolejne krawedzie:" << endl;
	for (int i = 0; i < E; i++)
	{
		cin >> pocz >> konc;
	
		if (pocz >= 0 && konc >= 0 && pocz < n && konc < n)
		{
			graf[pocz].push_back(konc);
			if (pocz != konc)
				graf[konc].push_back(pocz);
		}
		else
		{
			cout << "zle wspolrzedne wierzcholkow, podaj jeszcze raz" << endl;
			i--;
		}
	}
	cout << endl;
}

void wypelnij_liste_sasiedztwa_DG(list<int> *graf, int n, int E)
{
	int pocz, konc;		//wierzcholek poczatkowy i koncowy krawedzi
	cout << "podaj kolejne krawedzie:" << endl;
	for (int i = 0; i < E; i++)
	{
		cin >> pocz >> konc;

		if (pocz >= 0 && konc >= 0 && pocz < n && konc < n)
		{
			graf[pocz].push_back(konc);
		}
		else
		{
			cout << "zle wspolrzedne wierzcholkow, podaj jeszcze raz" << endl;
			i--;
		}
	}
	cout << endl;
}

void wyswietl_liste_sasiedztwa(list<int>*graf, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "] =  ";

		for (list<int>::iterator j = graf[i].begin(); j != graf[i].end(); j++)
		{
			cout << *j << "  ";
		}
		cout << endl;
	}
	cout << endl;
}


//*********************************************************
//lista sasiedztwa - funkcje poboczne

list<pair<int, int>>*stworz_wazona_liste_sasiedztwa(int n)
{
	list<pair<int, int>> * graf = new list<pair<int, int>>[n];
	return graf;
}

void usun_liste_sasiedztwa(list<pair<int, int>>*graf)
{
	delete[] graf;
}

void wypelnij_wazona_liste_sasiedztwa_DG(list<pair<int, int>> *graf, int n, int E)
{
	int pocz, konc, w;		//wierzcholek poczatkowy i koncowy krawedzi
	cout << "podaj kolejne krawedzie:" << endl;
	for (int i = 0; i < E; i++)
	{
		cin >> pocz >> konc >> w;

		if (pocz >= 0 && konc >= 0 && pocz < n && konc < n)
		{
			graf[pocz].push_back(make_pair(konc, w));
		}
		else
		{
			cout << "zle wspolrzedne wierzcholkow, podaj jeszcze raz" << endl;
			i--;
		}
	}
	cout << endl;
}

void wypelnij_wazona_liste_sasiedztwa_NDG(list<pair<int, int>> *graf, int n, int E)
{
	int pocz, konc, w;		//wierzcholek poczatkowy i koncowy krawedzi
	cout << "podaj kolejne krawedzie:" << endl;
	for (int i = 0; i < E; i++)
	{
		cin >> pocz >> konc >> w;

		if (pocz >= 0 && konc >= 0 && pocz < n && konc < n)
		{
			graf[pocz].push_back(make_pair(konc, w));
			if(pocz != konc)	//zeby nie dublowac petli
				graf[konc].push_back(make_pair(pocz, w));
		}
		else
		{
			cout << "zle wspolrzedne wierzcholkow, podaj jeszcze raz" << endl;
			i--;
		}
	}
	cout << endl;
}

void wyswietl_wazona_liste_sasiedztwa(list<pair<int, int>> *graf, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "] =  ";

		for (list<pair<int, int>>::iterator j = graf[i].begin(); j != graf[i].end(); j++)
		{
			cout << (*j).first << "(" << (*j).second << ")" << "  ";
		}
		cout << endl;
	}
	cout << endl;
}


//*********************************************************
//lista sasiedztwa - funkcje poboczne

void przepisz_liste_sasiedztwa(list<int>*cel, list<int>*zrodlo, int n)
{
	for (int i = 0; i < n; i++)
		for (list<int>::iterator iter = zrodlo[i].begin(); iter != zrodlo[i].end(); iter++)
			cel[i].push_back(*iter);
}

void wyczysc_liste_sasiadow(list<int>* graf, int n)
{
	for (int i = 0; i < n; i++)
	{
		graf[i].clear();
	}
	//cout << "lista sasiedztwa wyczyszczona!" << endl;
}

void sortuj_liste_sasiedztwa(list<int>* graf, int n)
{
	for (int i = 0; i < n; i++)
	{
		graf[i].sort();
	}
}

void wierzcholki_izolowane_lista_sasiedztwa(list<int>* graf, int n)
{
	int ile_pustych = 0;
	cout << "wierzcholki izolowane:" << endl;
	for (int i = 0; i < n; i++)
	{
		if (graf[i].empty())
		{
			cout << "v" << i << endl;
			ile_pustych++;
		}
	}
	if (ile_pustych == 0)
	{
		cout << "brak wierzcholkow izolowanych" << endl;
	}
	cout << endl;
}

void petle_lista_sasiedztwa(list<int>* graf, int n)
{
	bool jest_petla = false;
	int ile_petli = 0;

	cout << "petle w liscie sasiedztwa:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (list<int>::iterator iter = graf[i].begin(); iter != graf[i].end(); iter++)
		{
			if(*iter == i)
			{
				cout << "v" << i << endl;
				ile_petli++;
				break;
			}
		}
	}
	if (ile_petli == 0)
	{
		cout << "brak petli" << endl;
	}
	cout << endl;
}

void krawedzie_dwukierunkowe_lista_sasiedztwa(list<int>*graf, int n)
{
	sortuj_liste_sasiedztwa(graf, n);
	cout << "krawedzie dwukierunkowe w grafie:" << endl;
	int ile_dwukierunkowych = 0;

	for (int i = 0; i < n; i++)
	{
		for (list<int>::iterator iter = graf[i].begin(); iter != graf[i].end(); iter++)
		{
			if (i != *iter  && i < *iter)		//wyklucza petle
			{
				for (list<int>::iterator iter2 = graf[*iter].begin(); iter2 != graf[*iter].end(); iter2++)
				{
					if (*iter2 == i)
					{
						cout << i << " <-> " << *iter << endl;
						ile_dwukierunkowych++;
					}
				}
			}
		}
	}
	if (ile_dwukierunkowych == 0)
	{
		cout << "brak krawedzi dwukierunkowych" << endl;
	}
	cout << endl;
}

void stopnie_lista_sasiedztwa_NDG(list<int>*graf, int n)
{
	bool jest_petla = false;
	int ile_petli = 0;

	for (int i = 0; i < n; i++)
	{
		for (list<int>::iterator iter = graf[i].begin(); iter != graf[i].end(); iter++)
		{
			if (i == *iter)
			{
				ile_petli++;
				jest_petla = true;
			}
		}

		if (jest_petla == false)
		{
			cout << "deg v" << i << " = " << graf[i].size() << endl;
		}
		else
		{
			cout << "deg v" << i << " = " << graf[i].size()+ile_petli << endl;
		}

		jest_petla = false;
		ile_petli = 0;
	}
	cout << endl;
}

void stopnie_wychodzace_lista_sasiedztwa_DG(list<int>*graf, int n)
{
	cout << "stopnie wychodzace:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "deg_out v" << i << " = " << graf[i].size() << endl;
	}
	cout << endl;
}

void stopnie_wchodzace_lista_sasiedztwa_DG(list<int>*graf, int n)
{
	int ile_stopni = 0;
	cout << "stopnie wchodzace: " << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (list<int>::iterator iter = graf[j].begin(); iter != graf[j].end(); iter++)
			{
				if (*iter == i)
					ile_stopni++;
			}
		}
		cout << "deg_in v" << i << " = " << ile_stopni << endl;
		ile_stopni = 0;
	}
	cout << endl;
}

void dla_kogo_sasiadem_lista_sasiedztwa(list<int>*graf, int n)
{
	cout << "dla kogo sasiadem jest dany wierzcholek:" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "] =  ";
		for (int j = 0; j < n; j++)
		{
			for (list<int>::iterator iter = graf[j].begin(); iter != graf[j].end(); iter++)
			{
				if (*iter == i)
				{
					cout << j << "  ";
				}
			}
		}
		cout << endl;
	}
	cout << endl;
}


//*********************************************************
// DFS
void DFS_nxn(int**graf, int startowy, int n)
{
	//tablica visited
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	cout << "algorytm DFS dla macierzy sasiedztwa: " << endl;
	DFS_nxn_rek(graf, visited, startowy, n);

	//sprawdzenie i ewentualne wypisanie wierzcholkow nieodwiedzonych
	bool sa_nieodwiedzone = false;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			sa_nieodwiedzone = true;
			break;
		}
	}
	if (sa_nieodwiedzone)
	{
		cout << endl << "wierzcholki nieodwiedzone: " << endl;
		for (int i = 0; i < n; i++)
			if (visited[i] == false) cout << i << "  ";
	}

	cout << endl << endl;
	//zwalnianie pamieci
	delete[]visited;
}

void DFS_nxn_rek(int**graf, bool*visited, int startowy, int n)
{
	visited[startowy] = true;

	cout << startowy << "  ";

	for (int i = 0; i < n; i++)
	{
		if (graf[startowy][i] == 1 && visited[i] == false)
		{
			DFS_nxn_rek(graf, visited, i, n);
		}
	}
}

void DFS_lista_sasiedztwa(list<int>*graf, int startowy, int n)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	cout << "algorytm DFS dla listy sasiedztwa: " << endl;
	DFS_lista_sasiedztwa_rek(graf, visited, startowy, n);

	//sprawdzenie i ewentualne wypisanie wierzcholkow nieodwiedzonych
	bool sa_nieodwiedzone = false;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			sa_nieodwiedzone = true;
			break;
		}
	}
	if (sa_nieodwiedzone)
	{
		cout << endl << "wierzcholki nieodwiedzone: " << endl;
		for (int i = 0; i < n; i++)
			if (visited[i] == false) cout << i << "  ";
	}

	cout << endl << endl;

	delete[]visited;
}

void DFS_lista_sasiedztwa_rek(list<int>*graf, bool *visited, int startowy, int n)
{
	visited[startowy] = true;

	cout << startowy << "  ";

	list<int>::iterator iter = graf[startowy].begin();

	for (iter = graf[startowy].begin(); iter != graf[startowy].end(); iter++)
	{
		if (visited[*iter] == false)
		{
			DFS_lista_sasiedztwa_rek(graf, visited, *iter, n);
		}
	}
}

void DFS_stos_lista_sasiedztwa(list<int>* graf, int startowy, int n)
{
	stack<int> Stos;
	list<int>::iterator iter;

	//tablica odwiedzonych wierzcholkow
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	cout << "algorytm DFS dla listy sasiedztwa z wykorzystaniem stosu: " << endl;

	Stos.push(startowy);
	visited[startowy] = true;

	while (Stos.empty() == false)
	{
		startowy = Stos.top();
		Stos.pop();
		cout << startowy << "  ";

		for (iter = graf[startowy].begin(); iter != graf[startowy].end(); iter++)
		{
			if (visited[*iter] == false)
			{
				Stos.push(*iter);
				visited[*iter] = true;
			}
		}
	}

	cout << endl;

	//sprawdzenie i ewentualne wypisanie wierzcholkow nieodwiedzonych
	bool sa_nieodwiedzone = false;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			sa_nieodwiedzone = true;
			break;
		}
	}
	if (sa_nieodwiedzone)
	{
		cout << "wierzcholki nieodwiedzone: " << endl;
		for (int i = 0; i < n; i++)
			if (visited[i] == false) cout << i << "  ";
	}
	cout << endl << endl;

	delete[]visited;
}


//*********************************************************
// BFS
void BFS_nxn(int ** graf, int startowy, int n)
{
	queue<int> Kolejka;

	//tablica odwiedzonych wierzcholkow
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	Kolejka.push(startowy);
	visited[startowy] = true;

	cout << "algorytm BFS dla macierzy sasiedztwa" << endl;
	while (!Kolejka.empty())
	{
		startowy = Kolejka.front();
		Kolejka.pop();
		cout << startowy << "  ";
		for (int i = 0; i < n; i++)
		{
			if (graf[startowy][i] == 1 && visited[i] == false)
			{
				Kolejka.push(i);
				visited[i] = true;
			}
		}
	}

	//sprawdzenie i ewentualne wypisanie wierzcholkow nieodwiedzonych
	bool sa_nieodwiedzone = false;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			sa_nieodwiedzone = true;
			break;
		}
	}
	if (sa_nieodwiedzone)
	{
		cout << endl << "wierzcholki nieodwiedzone: " << endl;
		for (int i = 0; i < n; i++)
			if (visited[i] == false) cout << i << "  ";
	}

	cout << endl << endl;
	delete[]visited;
}

void BFS_lista_sasiedztwa(list<int>* graf, int startowy, int n)
{
	queue<int> Kolejka;
	list<int>::iterator iter;

	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	//---
	Kolejka.push(startowy);
	visited[startowy] = true;

	cout << "algorytm BFS dla listy sasiedztwa" << endl;
	while (!Kolejka.empty())
	{
		startowy = Kolejka.front();
		Kolejka.pop();
		cout << startowy << "  ";
		for (iter = graf[startowy].begin(); iter != graf[startowy].end(); iter++)
		{
			if (visited[*iter] == false)
			{
				Kolejka.push(*iter);
				visited[*iter] = true;
				//iter--;
			}
		}
	}

	//sprawdzenie i ewentualne wypisanie wierzcholkow nieodwiedzonych
	bool sa_nieodwiedzone = false;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			sa_nieodwiedzone = true;
			break;
		}
	}
	if (sa_nieodwiedzone)
	{
		cout << endl << "wierzcholki nieodwiedzone: " << endl;
		for (int i = 0; i < n; i++)
			if (visited[i] == false) cout << i << "  ";
	}

	cout << endl << endl;
	delete[]visited;
}


//*********************************************************
// transpozycja, kwadrat

void transponuj_nxn(int**graf, int n)
{
	int temp;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			temp = graf[i][j];
			graf[i][j] = graf[j][i];
			graf[j][i] = temp;
		}
	}
}

void transponuj_liste_sasiedztwa(list<int>*graf, int n)
{
	list<int> *grafT = stworz_liste_sasiedztwa(n);		//pomocniczy graf
	list<int>::iterator iter;

	for (int i = 0; i < n; i++)
	{
		for (iter = graf[i].begin(); iter != graf[i].end(); iter++)
		{
			grafT[*iter].push_back(i);
		}
	}

	wyczysc_liste_sasiadow(graf, n);		//czyszczenie grafu wyjsciowego

											//przepisanie do grafu pierwotnego grafu transponowanego
	for (int i = 0; i < n; i++)
	{
		for (iter = grafT[i].begin(); iter != grafT[i].end(); iter++)
		{
			graf[i].push_back(*iter);
		}
	}

	usun_liste_sasiedztwa(grafT);			//usuniecie grafu pomocniczego, zwalnianie pamieci
}

void kwadrat_grafu_nxn(int**graf, int n)
{
	int **grafK = stworz_macierz_nxn(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			grafK[i][j] = graf[i][j];

		}
		for (int j = 0; j < n; j++)
		{
			if (i != j && graf[i][j] == 1)
			{
				for (int k = 0; k < n; k++)
				{
					if (graf[j][k] == 1)
						grafK[i][k] = 1;
				}
			}
		}
	}
	
	zeruj_macierz_nxn(graf, n);
	przepisz_nxn(graf, grafK, n);
	usun_macierz_nxn(grafK, n);
}

void kwadrat_grafu_lista_sasiedztwa(list<int>*graf, int n)
{
	list<int>*grafK = stworz_liste_sasiedztwa(n);			//lista pomocnicza
	list<int>::iterator iter;
	list<int>::iterator iter2;
	list<int>::iterator iter3;

	//glowna czesc algorytmu, wypelnianie listy grafK
	for (int i = 0; i < n; i++)
	{
		//wypelnienie listy pomocniczej wartosciami z listy glownej
		for (iter = graf[i].begin(); iter != graf[i].end(); iter++)
		{
			grafK[i].push_back(*iter);
		}

		//przegladanie listy sasiedztwa raz jeszcze
		for (iter = graf[i].begin(); iter != graf[i].end(); iter++)
		{
			//listy sasiedztwa sasiada
			for (iter2 = graf[*iter].begin(); iter2 != graf[*iter].end(); iter2++)
			{
				for (iter3 = grafK[i].begin(); iter3 != grafK[i].end(); iter3++)
				{
					if (*iter3 == *iter2)
					{
						break;
					}
				}
				if (iter3 == grafK[i].end())
				{
					grafK[i].push_back(*iter2);
				}
			}
		}
	}


	wyczysc_liste_sasiadow(graf, n);
	przepisz_liste_sasiedztwa(graf, grafK, n);
	usun_liste_sasiedztwa(grafK);
}


//*********************************************************
// stopien grafu

void stopien_grafu_nxn_NDG(int**graf, int n)
{
	int stopien_grafu = 0;
	int stopien_wierzcholka = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			stopien_wierzcholka += graf[i][j];
			if (i == j)
				stopien_wierzcholka += graf[i][j];
		}
		if (stopien_wierzcholka > stopien_grafu)
			stopien_grafu = stopien_wierzcholka;

		stopien_wierzcholka = 0;
	}
	cout << "stopien grafu: " << stopien_grafu << endl;
}

void stopien_grafu_nxn_DG(int**graf, int n)
{
	int stopien_grafu = 0;
	int stopien_wierzcholka = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			stopien_wierzcholka += graf[i][j];
			stopien_wierzcholka += graf[j][i];
		}
		if (stopien_wierzcholka > stopien_grafu)
			stopien_grafu = stopien_wierzcholka;

		stopien_wierzcholka = 0;
	}
	cout << "stopien grafu: " << stopien_grafu << endl;
}

void stopien_grafu_lista_sasiedztwa_NDG(list<int>*graf, int n)
{
	int stopien_grafu = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		stopien_grafu = graf[i].size();
		for (list<int>::iterator iter = graf[i].begin(); iter != graf[i].end(); iter++)
		{
			if (i == *iter)
			{
				stopien_grafu++;
				break;
			}
		}
		if (stopien_grafu > max)
			max = stopien_grafu;

		stopien_grafu = 0;
	}
	cout << "stopien grafu: " << max << endl;
}

void stopien_grafu_lista_sasiedztwa_DG(list<int>*graf, int n)
{
	int stopien_grafu = 0;
	int max = 0;
	int ile_stopni = 0;

	for (int i = 0; i < n; i++)
	{
		stopien_grafu += graf[i].size();
		//sprawdzenie, czy jest petla
		for (list<int>::iterator iter = graf[i].begin(); iter != graf[i].end(); iter++)
		{
			if (i == *iter)
			{
				stopien_grafu++;
				break;
			}
		}

		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				for (list<int>::iterator iter = graf[j].begin(); iter != graf[j].end(); iter++)
				{
					if (*iter == i)
						ile_stopni++;
				}
			}
		}
		stopien_grafu += ile_stopni;

		if (stopien_grafu > max)
			max = stopien_grafu;

		ile_stopni = 0;
		stopien_grafu = 0;
	}
	cout << "stopien grafu: " << max << endl;
}


//*********************************************************
// sciezka w grafie

void sciezka_z_przejsciem_DFS_lista_sasiedztwa_1(list<int>*graf, int startowy, int koncowy, int n)
{
	//elementy pomocnicze
	bool *visited = new bool[n];		//wierzcholki odwiedzone
	for (int i = 0; i < n; i++)
		visited[i] = false;

	int *path = new int[n];				//sciezka
	for (int i = 0; i < n; i++)
		path[i] = -2;					//-2 - wartosc neutralna, 0+ - numery wierzcholkow, -1 - wierzcholek startowy

	stack<int> S;						//stos do DFS

	int v;								//wierzcholek biezacy
	list<int>::iterator iter;

	//algorytm
	path[startowy] = -1;
	visited[startowy] = true;
	S.push(startowy);

	cout << "sciezka: " << endl;
	while (S.empty() == false)
	{
		v = S.top();
		S.pop();

		if (v == koncowy)				//jesli to juz koniec
		{
			while (v > -1)				//wypisywanie sciezki
			{
				cout << v << " ";
				v = path[v];			//ruch po sciezce
			}
			cout << endl;
			//zwalnianie pamieci
			delete[]visited;
			delete[]path;
			return;						//koniec funkcji
		}

		for (iter = graf[v].begin(); iter != graf[v].end(); iter++)
		{
			if (visited[*iter] == false)		//*iter to kolejni sasiedzi wierzcholka v
			{
				path[*iter] = v;
				S.push(*iter);
				visited[*iter] = true;
			}
		}
	}

	cout << "brak sciezki miedzy " << startowy << " a " << koncowy << endl;

	//zwalnianie pamieci
	delete[]visited;
	delete[]path;
}

void sciezka_z_przejsciem_DFS_macierz_sasiedztwa_1(int**graf, int startowy, int koncowy, int n)
{
	//elementy pomocnicze
	bool *visited = new bool[n];		//wierzcholki odwiedzone
	for (int i = 0; i < n; i++)
		visited[i] = false;

	int *path = new int[n];				//sciezka
	for (int i = 0; i < n; i++)
		path[i] = -2;					//-2 - wartosc neutralna, 0+ - numery wierzcholkow, -1 - wierzcholek startowy

	stack<int> S;						//stos do DFS

	int v;								//wierzcholek biezacy
	int i;

	//algorytm
	path[startowy] = -1;
	visited[startowy] = true;
	S.push(startowy);

	cout << "sciezka: " << endl;
	while (S.empty() == false)
	{
		v = S.top();
		S.pop();

		if (v == koncowy)				//jesli to juz koniec
		{
			while (v > -1)				//wypisywanie sciezki
			{
				cout << v << " ";
				v = path[v];			//ruch po sciezce
			}
			cout << endl;
			//zwalnianie pamieci
			delete[]visited;
			delete[]path;
			return;						//koniec funkcji
		}

		for (i = 0; i < n; i++)
		{
			if (visited[i] == false && graf[v][i] == 1)		//*iter to kolejni sasiedzi wierzcholka v
			{
				path[i] = v;
				S.push(i);
				visited[i] = true;
			}
		}
	}

	cout << "brak sciezki miedzy " << startowy << " a " << koncowy << endl;

	//zwalnianie pamieci
	delete[]visited;
	delete[]path;
}

void sciezka_z_przejsciem_DFS_lista_sasiedztwa_2(list<int>*graf, int startowy, int koncowy, int n)
{
	stack<int> *S = new stack<int>;				//stos dynamiczny, zeby mozna przesylac do funkcji bez wiekszych problemow

	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	if (DFS_sciezka_lista_sasiedztwa_rek(graf, S, visited, startowy, koncowy) == false)
	{
		cout << "brak sciezki" << endl;
		delete[]visited;
		delete S;
		return;
	}

	cout << "sciezka: " << endl;
	while ((*S).empty() == false)
	{
		cout << (*S).top() << " ";
		(*S).pop();
	}
	cout << endl;

	delete[]visited;
	delete S;
}

bool DFS_sciezka_lista_sasiedztwa_rek(list<int>*graf, stack<int> *S, bool*visited, int biezacy, int koncowy)
{
	visited[biezacy] = true;
	(*S).push(biezacy);

	if (biezacy == koncowy)
		return true;

	for (list<int>::iterator iter = graf[biezacy].begin(); iter != graf[biezacy].end(); iter++)			//przeszukiwanie sasiadow biezacego wierzcholka
	{
		if (visited[*iter] == false)	//*iter - sasiad wierzcholka biezacego
		{
			if (DFS_sciezka_lista_sasiedztwa_rek(graf, S, visited, *iter, koncowy) == true)
				return true;
		}
	}

	(*S).pop();
	return false;
}

void sciezka_z_przejsciem_DFS_macierz_sasiedztwa_2(int**graf, int startowy, int koncowy, int n)
{
	stack<int> *S = new stack<int>;				//stos dynamiczny, zeby mozna przesylac do funkcji bez wiekszych problemow

	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	if (DFS_sciezka_macierz_sasiedztwa_rek(graf, S, visited, startowy, koncowy, n) == false)
	{
		cout << "brak sciezki" << endl;
		delete[]visited;
		delete S;
		return;
	}

	cout << "sciezka: " << endl;
	while ((*S).empty() == false)
	{
		cout << (*S).top() << " ";
		(*S).pop();
	}
	cout << endl;

	//zwalnianie pamieci
	delete[]visited;
	delete S;
}

bool DFS_sciezka_macierz_sasiedztwa_rek(int**graf, stack<int> *S, bool*visited, int biezacy, int koncowy, int n)
{
	visited[biezacy] = true;
	(*S).push(biezacy);

	if (biezacy == koncowy)
		return true;

	for (int i = 0; i < n; i++)			//przeszukiwanie sasiadow biezacego wierzcholka
	{
		if (visited[i] == false && graf[biezacy][i] == 1)	//*iter - sasiad wierzcholka biezacego
		{
			if (DFS_sciezka_macierz_sasiedztwa_rek(graf, S, visited, i, koncowy, n) == true)
				return true;
		}
	}

	(*S).pop();
	return false;
}

void najkrotsza_sciezka_lista_sasiedztwa(list<int>*graf, int startowy, int koncowy, int n)
{
	queue<int> Q;							//kolejka dla BFS

	bool *visited = new bool[n];			//wierzcholki odwiedzone
	for (int i = 0; i < n; i++)
		visited[i] = false;

	int *path = new int[n];
	for (int i = 0; i < n; i++)
		path[i] = -2;						//-2 - wartosc neutralna, 0+ - numery wierzcholkow, -1 - wierzcholek startowy

	int v;

	//algorytm
	path[startowy] = -1;
	visited[startowy] = true;
	Q.push(startowy);

	cout << "najkrotsza sciezka miedzy v" << startowy << " a v" << koncowy << ": " << endl;
	while (Q.empty() == false)
	{
		v = Q.front();
		Q.pop();

		if (v == koncowy)
		{
			while (v > -1)
			{
				cout << v << " ";
				v = path[v];
			}
			while (Q.empty() == false)
				Q.pop();
			cout << endl;
			//zwalnianie pamieci
			delete[]visited;
			delete[]path;
			return;
		}

		for (list<int>::iterator iter = graf[v].begin(); iter != graf[v].end(); iter++)		//dla kazdego sasiada wierzcholka biezacego
		{
			if (visited[*iter] == false)				//*iter - sasiad wierzcholka bierzacego
			{
				path[*iter] = v;
				visited[*iter] = true;
				Q.push(*iter);
			}
		}
	}

	cout << "brak sciezki" << endl;

	//zwalnianie pamieci
	delete[]visited;
	delete[]path;
}

void najkrotsza_sciezka_macierz_sasiedztwa(int**graf, int startowy, int koncowy, int n)
{
	queue<int> Q;							//kolejka dla BFS

	bool *visited = new bool[n];			//wierzcholki odwiedzone
	for (int i = 0; i < n; i++)
		visited[i] = false;

	int *path = new int[n];
	for (int i = 0; i < n; i++)
		path[i] = -2;						//-2 - wartosc neutralna, 0+ - numery wierzcholkow, -1 - wierzcholek startowy

	int v;

	//algorytm
	path[startowy] = -1;
	visited[startowy] = true;
	Q.push(startowy);

	cout << "najkrotsza sciezka miedzy v" << startowy << " a v" << koncowy << ": " << endl;
	while (Q.empty() == false)
	{
		v = Q.front();
		Q.pop();

		if (v == koncowy)
		{
			while (v > -1)
			{
				cout << v << " ";
				v = path[v];
			}
			while (Q.empty() == false)
				Q.pop();
			cout << endl;
			//zwalnianie pamieci
			delete[]visited;
			delete[]path;
			return;
		}

		for (int i = 0; i < n; i++)		//dla kazdego sasiada wierzcholka biezacego
		{
			if (visited[i] == false && graf[v][i] == 1)				//*iter - sasiad wierzcholka bierzacego
			{
				path[i] = v;
				visited[i] = true;
				Q.push(i);
			}
		}
	}

	cout << "brak sciezki" << endl;

	//zwalnianie pamieci
	delete[]visited;
	delete[]path;
}


//*********************************************************
// drzewa rozpinajace

void drzewo_rozpinajace_DFS_lista_sasiedztwa(list<int>*graf, list<int>*drzewo, int startowy, int n, bool czy_skierowane)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	DFS_Tree_lista_sasiedztwa(graf, drzewo, visited, startowy, n, czy_skierowane);

	delete[]visited;
}

void DFS_Tree_lista_sasiedztwa(list<int>*graf, list<int>*drzewo, bool *visited, int biezacy, int n, bool czy_skierowane)
{
	visited[biezacy] = true;

	for (list<int>::iterator iter = graf[biezacy].begin(); iter != graf[biezacy].end(); iter++)
	{
		if (visited[*iter] == false)
		{
			drzewo[biezacy].push_back(*iter);
			if (czy_skierowane == false)
				drzewo[*iter].push_back(biezacy);
			DFS_Tree_lista_sasiedztwa(graf, drzewo, visited, *iter, n, czy_skierowane);
		}
	}
}

void drzewo_rozpinajace_DFS_macierz_sasiedztwa(int**graf, int**drzewo, int startowy, int n, bool czy_skierowane)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	DFS_Tree_macierz_sasiedztwa(graf, drzewo, visited, startowy, n, czy_skierowane);

	delete[]visited;
}

void DFS_Tree_macierz_sasiedztwa(int**graf, int**drzewo, bool *visited, int biezacy, int n, bool czy_skierowane)
{
	visited[biezacy] = true;

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false && graf[biezacy][i] == 1)
		{
			drzewo[biezacy][i] = 1;
			if (czy_skierowane == false)
				drzewo[i][biezacy] = 1;
			DFS_Tree_macierz_sasiedztwa(graf, drzewo, visited, i, n, czy_skierowane);
		}
	}
}

void drzewo_rozpinajace_BFS_lista_sasiedztwa(list<int>*graf, list<int>*drzewo, int startowy, int n, bool czy_skierowane)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	queue<int> Q;
	int w;

	//algorytm
	Q.push(-1);
	Q.push(startowy);
	visited[startowy] = true;

	while (Q.empty() == false)
	{
		startowy = Q.front();
		Q.pop();
		w = Q.front();
		Q.pop();

		if (startowy > -1)
		{
			drzewo[startowy].push_back(w);
			if (czy_skierowane == false)
				drzewo[w].push_back(startowy);
		}

		for (list<int>::iterator iter = graf[w].begin(); iter != graf[w].end(); iter++)
		{
			if (visited[*iter] == false)
			{
				visited[*iter] = true;
				Q.push(w);
				Q.push(*iter);
			}
		}
	}

	delete[]visited;
}

void drzewo_rozpinajace_BFS_macierz_sasiedztwa(int**graf, int**drzewo, int startowy, int n, bool czy_skierowane)
{
	{
		bool *visited = new bool[n];
		for (int i = 0; i < n; i++)
			visited[i] = false;

		queue<int> Q;
		int w;

		//algorytm
		Q.push(-1);
		Q.push(startowy);
		visited[startowy] = true;

		while (Q.empty() == false)
		{
			startowy = Q.front();
			Q.pop();
			w = Q.front();
			Q.pop();

			if (startowy > -1)
			{
				drzewo[startowy][w] = 1;
				if (czy_skierowane == false)
					drzewo[w][startowy] = 1;
			}

			for (int i = 0; i < n; i++)
			{
				if (visited[i] == false && graf[w][i] == 1)
				{
					visited[i] = true;
					Q.push(w);
					Q.push(i);
				}
			}
		}

		delete[]visited;
	}
}


//*********************************************************
// spojnosc

bool spojnosc_lista_sasiedztwa(list<int>*graf, int startowy, int n)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	//cout << "algorytm DFS dla listy sasiedztwa: " << endl;
	spojnosc_lista_sasiedztwa_rek(graf, visited, startowy, n);

	//sprawdzenie i ewentualne wypisanie wierzcholkow nieodwiedzonych
	bool sa_nieodwiedzone = false;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			sa_nieodwiedzone = true;
			break;
		}
	}
	if (sa_nieodwiedzone)
	{
		delete[]visited;
		return false;
	}


	delete[]visited;
	return true;
}

void spojnosc_lista_sasiedztwa_rek(list<int>*graf, bool *visited, int startowy, int n)
{
	visited[startowy] = true;

	//cout << startowy << "  ";

	list<int>::iterator iter = graf[startowy].begin();

	for (iter = graf[startowy].begin(); iter != graf[startowy].end(); iter++)
	{
		if (visited[*iter] == false)
		{
			spojnosc_lista_sasiedztwa_rek(graf, visited, *iter, n);
		}
	}
}

void skladowe_spojne_lista_sasiedztwa(list<int>*graf, int n)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	int *C = new int[n];				//tablica zawierajaca informacje, do ktorej grupy nalezy dany wierzcholek
	for (int i = 0; i < n; i++)
		C[i] = 0;

	int biezaca_skladowa = 0;

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			biezaca_skladowa++;
			spojne_skladowe_lista_sasiedztwa_rek(graf, C, visited, i, biezaca_skladowa, n);
		}
	}

	for (int i = 1; i <= biezaca_skladowa; i++)
	{
		cout << "SSC " << i << " : ";
		for (int j = 0; j < n; j++)
		{
			if (C[j] == i)
				cout << setw(2) << j << " ";
		}
		cout << endl;
	}

	delete[]C;
	delete[]visited;
}

void spojne_skladowe_lista_sasiedztwa_rek(list<int>*graf, int*C, bool *visited, int startowy, int biezaca_skladowa, int n)
{
	visited[startowy] = true;
	C[startowy] = biezaca_skladowa;

	list<int>::iterator iter = graf[startowy].begin();

	for (iter = graf[startowy].begin(); iter != graf[startowy].end(); iter++)
	{
		if (visited[*iter] == false)
		{
			spojne_skladowe_lista_sasiedztwa_rek(graf, C, visited, *iter, biezaca_skladowa, n);
		}
	}
}

void bridge_Tarjan_lista_sasiedztwa(list<int>*graf, int n)
{
	int cv;

	int *D = new int[n];
	for (int i = 0; i < n; i++)
		D[i] = 0;

	list<pair<int, int>> *L = new list<pair<int, int>>;

	for (int i = 0; i < n; i++)
	{
		if (D[i] == 0)
		{
			cv = 1;
			DFSb_lista_sasiedztwa(graf, n, i, -1, D, L, cv);
		}
	}

	cout << "mosty: " << endl;
	for (list< pair<int, int> >::iterator it = (*L).begin(); it != (*L).end(); it++)
	{
		cout << (*it).first << " - " << (*it).second << endl;
	}

	if ((*L).empty())
		cout << "brak mostow w grafie" << endl;

	//zwalnianie pamieci
	delete[]D;
	delete L;
}

int DFSb_lista_sasiedztwa(list<int>*graf, int n, int v, int vf, int*D, list<pair<int, int>> *L, int &cv)
{
	int low = 0;
	int temp = 0;

	D[v] = cv;
	low = cv;
	cv += 1;

	for (list<int>::iterator it = graf[v].begin(); it != graf[v].end(); it++)
	{
		if (*it != vf)		//*it - sasied u wierzcholka v
		{
			if (D[*it] == 0)
			{
				temp = DFSb_lista_sasiedztwa(graf, n, *it, v, D, L, cv);
				if (temp < low)
					low = temp;
			}
			else if (D[*it] < low)
				low = D[*it];
		}
	}

	//test na most
	if (vf > -1 && low == D[v])
	{
		L->push_back(make_pair(vf, v));
		//cout << "dodano most" << endl;
	}

	return low;
}

void punkty_artykulacji_Tarjan_lista_sasiedztwa(list<int>*graf, int n)
{
	int dv = 0;
	int nc = 0;

	list<int>*L = new list<int>;

	int *D = new int[n];
	for (int i = 0; i < n; i++)
		D[i] = 0;

	for (int i = 0; i < n; i++)		//kolejne wierzcholki v
	{
		if (D[i] == 0)
		{
			dv = 2;
			nc = 0;
			D[i] = 1;
			for (list<int>::iterator it = graf[i].begin(); it != graf[i].end(); it++)
			{
				if (D[*it] == 0)		//*it - sasiad u wierzcholka i
				{
					nc += 1;
					DFSap(*it, i, graf, D, dv, L);
				}
			}
			if (nc > 1)
				(*L).push_back(i);
		}
	}

	cout << "punkty artykulacji:" << endl;
	for (list<int>::iterator it = (*L).begin(); it != (*L).end(); it++)
	{
		cout << *it << endl;
	}
	if ((*L).empty())
		cout << "brak punktow artykulacji w grafie" << endl;

	delete[]D;
	delete L;
}

int DFSap(int v, int vf, list<int>*graf, int* D, int& dv, list<int>* L)
{
	int low = 0;
	int temp = 0;
	bool test = false;

	D[v] = dv;
	low = dv;
	dv += 1;

	for (list<int>::iterator it = graf[v].begin(); it != graf[v].end(); it++)
	{
		if (*it != vf)		//*it - sasiad u wierzcholka v
		{
			if (D[*it] == 0)
			{
				temp = DFSap(*it, v, graf, D, dv, L);
				if (temp < low)
					low = temp;
				if (temp >= D[v])
					test = true;
			}
			else if (D[*it] < low)
				low = D[*it];
		}
	}

	if (test == true)
		L->push_back(v);

	return low;
}


//*********************************************************
// inne

bool czy_dwudzielny_lista_sasiedztwa(list<int>*graf, int n)
{
	int v = 0;
	queue<int> Q;

	int *C = new int[n];			//zawiera kolory wierzcholkow. 0-neutralny, 1-czerwony, -1-niebieski
	for (int i = 0; i < n; i++)
		C[i] = 0;

	for (int i = 0; i < n; i++)
	{
		if (C[i] == 0)
		{
			C[i] = 1;
			Q.push(i);
			while (Q.empty() == false)
			{
				v = Q.front();
				Q.pop();
				for (list<int>::iterator it = graf[v].begin(); it != graf[v].end(); it++)	//sasiedzi wierzcholka v
				{
					if (C[*it] == C[v])		//dwa sasiednie wierzcholki sa tego samego koloru
					{
						delete[]C;
						return false;
					}
					if (C[*it] == 0)
					{
						C[*it] = -C[v];
						Q.push(*it);
					}
				}
			}
		}
	}


	delete[]C;
	return true;
}

void kojarzenie_malzenstw_lista_sasiedztwa(list<int>*graf, int n, bool*color)
{
	int x = 0;
	int *augment = new int[n];		//n elementowa tablica pomocnicza do tworzenia naprzemiennej œcie¿ki rozszerzaj¹cej, przechowuje tworzon¹ przez BFS strukturê drzewa rozpinaj¹cego wszerz. Element i-ty zawiera numer swojego wierzcho³ka nadrzêdnego na drzewie rozpinaj¹cym
	int *matching = new int[n];		//	n elementowa tablica skojarzeñ. Indeksy elementów odpowiadaj¹ numerom wierzcho³ków grafu. Ka¿dy element zawiera numer skojarzonego wierzcho³ka z klasy przeciwnej
	for (int i = 0; i < n; i++)
	{
		matching[i] = -1;
		//augment[i] = 0;
	}

	bool *visited = new bool[n];		//n elementowa tablica logiczna s³u¿¹ca do zaznaczania wierzcho³ków odwiedzonych

	queue<int> Q;		//kolejka s³u¿¹ca do sk³adowania wierzcho³ków grafu dla metody BFS

	for (int i = 0; i < n; i++)		//1*
	{
		if (matching[i] == -1 && color[i] == false)
		{
			for (int j = 0; j < n; j++)
				visited[j] = false;
			while (Q.empty() == false)
				Q.pop();

			visited[i] = true;
			augment[i] = -1;
			Q.push(i);

			while (Q.empty() == false)		//2*
			{
				x = Q.front();
				Q.pop();
				if (color[x] == true)
				{
					if (matching[x] == -1)
					{
						while (augment[x] > -1)
						{
							if (color[x] == true)
							{
								matching[x] = augment[x];
								matching[augment[x]] = x;
								//cout << matching[x] << endl;
								//cout << matching[augment[x]] << endl;
							}
							x = augment[x];
						}
						break;		//przerwanie 2* - while (Q.empty() == false), powrot do glownej petli for 1*
					}
					else if (matching[x] > -1)
					{
						augment[matching[x]] = x;
						visited[matching[x]] = true;
						Q.push(matching[x]);
					}
				}
				else if (color[x] == false)
				{
					for (list<int>::iterator it = graf[x].begin(); it != graf[x].end(); it++)		//*it - sasiedzi y wierzcholka x
					{
						if (visited[*it] == false)
						{
							visited[*it] = true;
							augment[*it] = x;
							Q.push(*it);
						}
					}
				}
			}
		}
	}

	cout << "skojarzone malzenstwa:" << endl;
	for (int i = 0; i < n; i++)
		if (color[i] == false)
			cout << i << " - " << matching[i] << endl;

	delete[]augment;
	delete[]visited;
	delete[]matching;
}

void sortowanie_topologiczne_lista_sasiedztwa_DG(list<int>*graf, int n)
{
	int *kolory = new int[n];		//0-bialy, 1-szary, 2-zielony
	for (int i = 0; i < n; i++)
		kolory[i] = 0;
	stack<int>*S = new stack<int>;

	for (int i = 0; i < n; i++)
	{
		if (kolory[i] == 0)
			if (!DFS_sort_rek(graf, i, S, kolory))
				break;
	}

	cout << "graf posortowany topologicznie:" << endl;
	while (!S->empty())
	{
		cout << S->top() << " ";
		S->pop();
	}
	cout << endl;

	delete[]kolory;
	delete S;
}

bool DFS_sort_rek(list<int>*graf, int v, stack<int>*S, int*kolory)
{
	if (kolory[v] == 1)
	{
		cout << "NOT DAG" << endl;
		return false;
	}
	if (kolory[v] == 2)
		return true;

	kolory[v] = 1;

	for (list<int>::iterator it = graf[v].begin(); it != graf[v].end(); it++)
	{
		if (DFS_sort_rek(graf, *it, S, kolory) == false)
			return false;
	}
	kolory[v] = 2;
	S->push(v);
	return true;
}

void kopiowanie_stosu_int(stack<int>*zrodlo, stack<int>*cel)
{
	stack<int> temp;		//tu bedzie stos pierwotny w odwrotnej kolejnosci

	while (zrodlo->empty() == false)
	{
		temp.push(zrodlo->top());
		zrodlo->pop();
	}
	while (temp.empty() == false)
	{
		zrodlo->push(temp.top());	//bo kopiujemy a nie przenosimy, zeby przeniesc stos A do stosu B trzeba usunac te linie
		cel->push(temp.top());
		temp.pop();
	}
}

void TSP_lista_sasiedztwa(list<pair<int, int>>*graf, int n)
{
	int *visited = new int[n];
	stack<int> *S = new stack<int>;
	stack<int> *Sh = new stack<int>;

	for (int i = 0; i < n; i++)
		visited[i] = false;
	int d = INT_MAX;
	int dh = 0;
	int v0 = 0;

	if (n < 20)
		TSP_lista_sasiedztwa_rek(graf, n, v0, v0, d, dh, S, Sh, visited);	//przy pierwszym wywolaniu v biezace == v0
	else
	{
		cout << "slow down! to ma zlozonosc wykladnicza! algorytm nie zostanie wywolany" << endl;
		delete[]visited;
		delete S, Sh;
		return;
	}


	if (S->empty() == false)
	{
		cout << "d: " << d << endl << "cykl: " << v0 << "  ";
		while (!S->empty())
		{
			cout << S->top() << "  ";
			S->pop();
		}
		cout << endl;
	}
	else
		cout << "brak cyklu hamiltona" << endl;

	delete[]visited;
	delete S, Sh;
}

void TSP_lista_sasiedztwa_rek(list<pair<int, int>>*graf, int n, int &v, int &v0, int &d, int &dh, stack<int>*S, stack<int>*Sh, int*visited)
{
	//sprawdzanie, czy istnieje krawedz v-v0
	bool czy_istnieje_krawedz = false;	//zakladamy, ze nie
	list<pair<int, int>>::iterator v_v0 = graf[v].begin();	//iterator na krawedz v-v0 (czyli dostep do wagi v-v0)
	for (list<pair<int, int>>::iterator it = graf[v].begin(); it != graf[v].end(); it++)
		if ((*it).first == v0)	//jesli sie okaze, ze krawedz istnieje to jest to odnotowywane
		{
			czy_istnieje_krawedz = true;
			v_v0 = it;
			break;
		}
	int waga_v_v0 = (*v_v0).second;

	//
	Sh->push(v);

	if (Sh->size() == n)
	{
		if (czy_istnieje_krawedz)
		{
			dh = dh + waga_v_v0;
			if (dh < d)
			{
				d = dh;
				while (!S->empty())
					S->pop();
				kopiowanie_stosu_int(Sh, S);
			}
			dh = dh - waga_v_v0;
			Sh->pop();
			return;
		}
		else
		{
			Sh->pop();
			return;
		}
	}
	else
	{
		visited[v] = true;
		for (list<pair<int, int>>::iterator it = graf[v].begin(); it != graf[v].end(); it++)
		{
			if (visited[(*it).first] == false)
			{
				dh = dh + (*it).second;
				TSP_lista_sasiedztwa_rek(graf, n, (*it).first, v0, d, dh, S, Sh, visited);
				dh = dh - (*it).second;
			}
		}
		visited[v] = false;
	}
	Sh->pop();
}


//*********************************************************
// cyklicznosc

bool czy_cykliczny_lista_sasiedztwa_spojny_NDG(list<int>*graf, int n)
{
	stack<int> S;
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	int startowy = 0;
	int w = 0, v = 0;		//wierzcholek poprzedni oraz obecny

	S.push(startowy);
	S.push(-1);			//numer poprzedniego wierzcholka. -1 -> brak wierzcholka poprzedniego
	visited[startowy] = true;

	while (S.empty() == false)
	{
		w = S.top();
		S.pop();
		v = S.top();
		S.pop();

		for (list<int>::iterator it = graf[v].begin(); it != graf[v].end(); it++)		//*it sasiedzi z wierzcholka v
		{
			if (visited[*it] == false)
			{
				S.push(*it);
				S.push(v);
				visited[*it] = true;
			}
			else if (*it != w)
			{
				delete[]visited;
				return true;
			}
		}
	}

	delete[]visited;
	return false;
}

bool czy_cykliczny_lista_sasiedztwa_niespojny_NDG(list<int>*graf, int n)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			if (czy_komponent_jest_cykliczny(graf, i, visited) == true)
			{
				delete[]visited;
				return true;
			}

		}
	}

	delete[]visited;
	return false;
}

bool czy_komponent_jest_cykliczny(list<int>*graf, int v, bool*visited)
{
	int w = 0;
	stack<int> S;

	S.push(v);
	S.push(-1);
	visited[v] = true;

	while (S.empty() == false)
	{
		w = S.top();
		S.pop();
		v = S.top();
		S.pop();
		for (list<int>::iterator it = graf[v].begin(); it != graf[v].end(); it++)
		{
			if (visited[*it] == false)
			{
				S.push(*it);
				S.push(v);
				visited[*it] = true;
			}
			else if (*it != w)
				return true;
		}
	}

	return false;
}

bool czy_cykliczny_lista_sasiedztwa_spojny_DG(list<int>*graf, int n)
{
	int *visited = new int[n];		//0-bialy, 1-szary, 2-czarny
	for (int i = 0; i < n; i++)
		visited[i] = 0;


	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			if (czy_graf_cykliczny_rek(graf, i, visited) == true)
			{
				delete[]visited;
				return true;
			}
		}
	}

	delete[]visited;
	return false;
}

bool czy_graf_cykliczny_rek(list<int>*graf, int v, int*visited)
{
	visited[v] = 1;		//szary

	for (list<int>::iterator it = graf[v].begin(); it != graf[v].end(); it++)
	{
		if (visited[*it] != 2)
		{
			if (visited[*it] == 1)
				return true;
			if (czy_graf_cykliczny_rek(graf, *it, visited) == true)
				return true;
		}
	}

	visited[v] = 2;
	return false;
}

void cykle_lista_sasiedztwa_NDG(list<int>*graf, int n)
{
	int u = 0;
	bool *visited = new bool[n];
	stack<int>*S = new stack<int>;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			visited[j] = false;

		S->push(-1);		//alt (*S).push(-1)
		cout << "startowy: " << i << "	";
		if (DFS_szukanie_cyklu_NDG_rek(graf, i, i, S, visited) == false)
			S->pop();

		if (S->empty())
			cout << "brak cyklu";
		while (S->empty() == false)
		{
			u = S->top();
			S->pop();
			if (u > -1)
				cout << u << " ";
		}
		cout << endl;
	}

	delete[]visited;
	delete S;
}

bool DFS_szukanie_cyklu_NDG_rek(list<int>*graf, int v, int w, stack<int>*S, bool*visited)
{
	visited[w] = true;

	for (list<int>::iterator it = graf[w].begin(); it != graf[w].end(); it++)
	{
		if (*it != (*S).top())
		{
			S->push(w);
			if (*it == v)
				return true;
			if (visited[*it] == false && DFS_szukanie_cyklu_NDG_rek(graf, v, *it, S, visited) == true)
				return true;
			S->pop();		//alternatywnie (*S).pop()
		}
	}
	return false;
}

void cykle_lista_sasiedztwa_DG(list<int>*graf, int n)
{
	int u = 0;
	bool *visited = new bool[n];
	stack<int>*S = new stack<int>;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			visited[j] = false;

		cout << "startowy: " << i << "	";
		if (DFS_szukanie_cyklu_DG_rek(graf, i, i, S, visited) == true)
		{
			while (S->empty() == false)
			{
				cout << S->top() << " ";
				S->pop();
			}
		}
		else
			cout << "brak cyklu";
		cout << endl;
	}

	delete[]visited;
	delete S;
}

bool DFS_szukanie_cyklu_DG_rek(list<int>*graf, int v, int w, stack<int>*S, bool*visited)
{
	visited[w] = true;

	S->push(w);
	for (list<int>::iterator it = graf[w].begin(); it != graf[w].end(); it++)
	{
		if (*it != (*S).top())
		{
			if (*it == v)
				return true;
			if (visited[*it] == false && DFS_szukanie_cyklu_DG_rek(graf, v, *it, S, visited) == true)
				return true;
		}
	}

	S->pop();		//alternatywnie (*S).pop()
	return false;
}


//*********************************************************
// euler/hamilton

void czy_eulerowski_lista_sasiedztwa_NDG(list<int>*graf, int n)
{
	int i = 0, v = 0;;
	stack<int> S;
	int liczba_nieparzystych_stopni = 0;
	int liczba_sasiadow = 0;

	//szukanie wierzcholka o niezerowym stopniu
	for (int it = 0; it < n; it++)
	{
		if (graf[it].empty() == 0)
		{
			i = it;
			break;
		}
	}
	if (i == n)
	{
		cout << "graf nie ma krawedzi" << endl;
		return;
	}

	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	S.push(i);
	visited[i] = true;
	while (S.empty() == false)
	{
		v = S.top();
		S.pop();
		liczba_sasiadow = 0;
		for (list<int>::iterator it = graf[v].begin(); it != graf[v].end(); it++)
		{
			liczba_sasiadow++;
			if (visited[*it] == false)
			{
				visited[*it] = true;
				S.push(*it);
			}
		}
		if (liczba_sasiadow % 2 == 1)
			liczba_nieparzystych_stopni++;
	}
	for (v = i + 1; v < n; v++)
	{
		if (visited[v] == false && graf[v].empty() == false)
		{
			cout << "graf niespojny" << endl;
			delete[]visited;
			return;
		}
	}
	if (liczba_nieparzystych_stopni == 0)
	{
		cout << "graf zawiera cykl Eulera" << endl;
		delete[]visited;
		return;
	}
	if (liczba_nieparzystych_stopni == 2)
	{
		cout << "graf zawiera sciezke Eulera" << endl;
		delete[]visited;
		return;
	}

	cout << "graf nie zawiera sciezki lub cyklu Eulera" << endl;
	delete[]visited;
}

int czy_eulerowski_lista_sasiedztwa_DG(list<int>*graf, int n)
{
	int v = 0;					//numer wierzcholka
	int cvn = 0;				//numer biezacego wierzcholka lub wspolnej skladowej
	int *VN = new int[n];		//tablica numerow wsierzcholkow, ktore ustala funkcja rekurencyjna
	int *VLow = new int[n];		//tablica parametrow low
	bool *VS = new bool[n];		//tablica logiczna informujaca, czy dany wierzcholek jest na stosie S
	stack<int> *S = new stack<int>;		//stos wierzcholkow
	int *Vind = new int[n];		//tablica stopni wchodzacych
	int *Voutd = new int[n];	//tablica stopni wychodzacych
	int *C = new int[n];		//tablica numerow sladowych, do ktorych naleza wierzcholki
	int cInOut = 0;				//licznik wierzcholkow o wiekszych stopniach wchodzacych
	int cOutIn = 0;				//licznik wierzcholkow o wiekszych stopniach wychodzacych

	for (int i = 0; i < n; i++)		//zerowanie tablic
	{
		VN[i] = 0;
		VLow[i] = 0;
		VS[i] = false;
		Vind[i] = 0;
		Voutd[i] = 0;
		C[i] = 0;
	}

	for (int i = 0; i < n; i++)
		if (VN[i] == 0)
			DFS_czy_eulerowski_lista_sasiedztwa_DG_rek(i, cvn, VN, VLow, VS, Vind, Voutd, C, S, graf);


	v = 0;
	while (v < n && (Vind[v] + Voutd[v] == 0))
		v += 1;

	if (v == n)		//graf pusty
	{
		delete S;
		delete[]VN, VLow, VS, Vind, Voutd, C;
		return 0;
	}

	cvn = C[v];
	cInOut = 0;
	cOutIn = 0;

	while (v < n)
	{
		if (Vind[v] + Voutd[v] != 0)
		{
			if (C[v] != cvn)		//K14
			{
				delete S;
				delete[]VN, VLow, VS, Vind, Voutd, C;
				return 0;
			}

			if (Vind[v] == Voutd[v])		//K15
			{
				v += 1;
				continue;
			}

			if (Vind[v] - Voutd[v] != 1)		//K16, K21
			{
				cOutIn += 1;
				if (cOutIn > 1)	//K22
				{
					delete S;
					delete[]VN, VLow, VS, Vind, Voutd, C;
					return 0;
				}
				v += 1;		//K23
				continue;
			}

			cInOut += 1;
			if (cInOut > 1)
			{
				delete S;
				delete[]VN, VLow, VS, Vind, Voutd, C;
				return 0;
			}

			v += 1;
			continue;
		}
		else if (Vind[v] + Voutd[v] == 0)		//K13, K23
			v += 1;
	}

	if (cInOut == 1)
	{
		delete[]VN, VLow, VS, Vind, Voutd, C;
		delete S;
		return 1;
	}

	//zwalnianie pamieci;
	delete[]VN, VLow, VS, Vind, Voutd, C;
	delete S;

	return 2;
}

void DFS_czy_eulerowski_lista_sasiedztwa_DG_rek(int v, int cvn, int*VN, int*VLow, bool*VS, int*Vind, int*Voutd, int*C, stack<int>*S, list<int>*graf)
{
	int u = 0;
	cvn += 1;
	VN[v] = cvn;
	VLow[v] = cvn;
	(*S).push(v);
	VS[v] = true;

	for (list<int>::iterator it = graf[v].begin(); it != graf[v].end(); it++)		//*it - sasiedzi u wierzcholka v
	{
		Voutd[v] += 1;
		Vind[*it] += 1;
		if (VN[(*it)] != 0)
		{
			if (VS[*it] == true)
			{
				VLow[v] = min(VLow[v], VN[*it]);
				continue;
			}
		}
		DFS_czy_eulerowski_lista_sasiedztwa_DG_rek((*it), cvn, VN, VLow, VS, Vind, Voutd, C, S, graf);
		VLow[v] = min(VLow[v], VLow[*it]);
	}

	if (VLow[v] == VN[v])
	{
		do {
			u = S->top();
			S->pop();
			VS[u] = false;
			C[u] = v;
		} while (u != v);
	}
}

void DFS_cykl_eulera_rek(list<int>*graf, int v, stack<int>*S)
{
	for (list<int>::iterator it = graf[v].begin(); it != graf[v].end(); it++)
	{
		if (!graf[v].empty())
		{
			usun_krawedz_lista_sasiedztwa(graf, v, *it, 0);
			DFS_cykl_eulera_rek(graf, *it, S);
		}
	}
	S->push(v);
}

void cykl_eulera_lista_sasiedztwa_spojny_NDG(list<int>*graf, int n, int startowy)
{
	stack<int>*S = new stack<int>;
	list<int>*graf2 = stworz_liste_sasiedztwa(n);		//zeby nie ingerowac w pierwotny graf i usuwac krawedzie z grafu pomocniczego
	przepisz_liste_sasiedztwa(graf2, graf, n);
	DFS_cykl_eulera_rek(graf2, startowy, S);

	cout << "cykl eulera: " << endl;
	while (!S->empty())
	{
		cout << S->top() << "  ";
		S->pop();
	}
	cout << endl;

	usun_liste_sasiedztwa(graf2);
	delete S;
}

void cykl_lub_sciezka_hamiltona_lista_sasiedztwa(list<int>*graf, int n)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;
	list<int>*S = new list<int>;

	if (n > 25)
		cout <<  "zbyt duzy graf, algorytm sobie nie poradzi" << endl;
	else
		cykl_lub_sciezka_hamiltona_lista_sasiedztwa_rek(graf, n, 0, visited, S);

	delete[]visited;
	delete S;
}

void cykl_lub_sciezka_hamiltona_lista_sasiedztwa_rek(list<int>*graf, int n, int v, bool*visited, list<int>*S)
{
	bool test;

	S->push_back(v);
	if (S->size() >= n)
	{
		test = false;
		for (list<int>::iterator it = graf[v].begin(); it != graf[v].end(); it++)
		{
			if (*it == 0)
			{
				test = true;
				break;
			}
		}
		if (test == true)
			cout << "cykl    hamiltona:   ";
		else
			cout << "sciezka hamiltona:   ";
		for (list<int>::iterator it = (*S).begin(); it != S->end(); it++)
		{
			cout << *it << " ";
		}
		if (test == true)
			cout << "0" << " ";
		cout << endl;
		S->pop_back();
		return;
	}
	else
	{
		visited[v] = true;
		for (list<int>::iterator it = graf[v].begin(); it != graf[v].end(); it++)
		{
			if (visited[*it] == false)
				cykl_lub_sciezka_hamiltona_lista_sasiedztwa_rek(graf, n, *it, visited, S);
		}
		visited[v] = false;
		S->pop_back();
	}
}


//*********************************************************
// najkotsza sciezka w grafie wazonym

void dijkstra_lista_sasiedztwa(list<pair<int, int>> *graf, int n, int v)
{
	bool *S = new bool[n];		//wierzcholki przerobione przez algorytm dijkstry
	bool *Q = new bool[n];		//wierzcholki nieprzerobione
	int *p = new int[n];		//poprzednicy w sciezce
	int *d = new int[n];		//koszt drogi
	int wierzcholkow_w_Q = n;
	int min_koszt = INT_MAX;
	int ktory_przeniesc = -1;
	int u = -1;

	for (int i = 0; i < n; i++)
	{
		S[i] = false;
		Q[i] = true;
		p[i] = -1;
		d[i] = numeric_limits<int>::max();		//najwieksza liczba int; numeric_limits<int>::infinity() zwraca 0 (dziala tylko dla double i float)		//ew. d[i] = INT_MAX;
	}

	d[v] = 0;

	while (wierzcholkow_w_Q)
	{
		//szukanie wierzcholka u o najmniejszym koszcie
		min_koszt = INT_MAX;
		ktory_przeniesc = -1;
		for (int i = 0; i < n; i++)
			if (d[i] <= min_koszt && Q[i] == true)
			{
				ktory_przeniesc = i;
				min_koszt = d[i];
			}

		//przenoszenie wierzcholka z Q do S
		Q[ktory_przeniesc] = false;
		S[ktory_przeniesc] = true;
		wierzcholkow_w_Q--;					//liczba elementow znajdujacych sie w Q zmniejsza sie o 1

		u = ktory_przeniesc;

		for (list<pair<int, int>>::iterator it = graf[u].begin(); it != graf[u].end(); it++)	//(*it).first - sasiad w wierzcholka u; (*it).second - waga krawedzi u-w
		{
			if (Q[(*it).first] == true)		//jesli wierzcholek w jest w Q
			{
				if (d[(*it).first] > d[u] + (*it).second)
				{
					d[(*it).first] = d[u] + (*it).second;
					p[(*it).first] = u;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << "d[" << i << "]:  " << d[i] << "	" << "p[" << i << "]:  " << p[i] << endl;
	}

	//zwalnianie pamieci
	delete[]S, Q, p, d;
}

void bellman_ford_lista_sasiedztwa(list<pair<int, int>>*graf, int n, int v)
{
	int *d = new int[n];
	int *p = new int[n];

	if (!bellman_ford_lista_sasiedztwa_alg(graf, n, v, d, p))
		cout << "Blad! Prawdopodobnie cykl ujemny w grafie" << endl;
	else
	{
		for (int i = 0; i < n; i++)
		{
			cout << "d[" << i << "]:  " << d[i] << "	" << "p[" << i << "]:  " << p[i] << endl;
		}
	}

	delete[]d, p;
}

bool bellman_ford_lista_sasiedztwa_alg(list<pair<int, int>>*graf, int n, int v, int *d, int*p)
{
	bool test;				//sprawdzanie czy wystapila zmiana

	for (int i = 0; i < n; i++)
	{
		d[i] = INT_MAX;
		p[i] = -1;
	}
	d[v] = 0;

	for (int j = 0; j < n - 1; j++)		//n-1 przejsc petli glownej
	{
		test = true;
		for (int i = 0; i < n; i++)
		{
			for (list<pair<int, int>>::iterator it = graf[i].begin(); it != graf[i].end(); it++)	//(*it).first/(*it).second	-> sasiad/waga
			{
				if (d[(*it).first] > d[i] + (*it).second && d[i] != INT_MAX)	//drugi warunek dlatego, ze czasami licznik sie przekrecal i byly sytuacje typu (0 > INT_MAX + dodatnia_waga) -> true
				{
					test = false;
					d[(*it).first] = d[i] + (*it).second;
					p[(*it).first] = i;
				}
			}
		}
		if (test)
			return true;
	}

	for (int i = 0; i < n; i++)
		for (list<pair<int, int>>::iterator it = graf[i].begin(); it != graf[i].end(); it++)
			if (d[(*it).first] > d[i] + (*it).second)		//ujemny cykl
				return false;

	return true;
}

void floyd_warshall(list<pair<int, int>>*graf, int n)
{
	int **d = new int*[n];
	for (int i = 0; i < n; i++)
		d[i] = new int[n];

	//inicjacja tablicy
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = INT_MAX;

	//wpisanie podstawowych wag
	for (int i = 0; i < n; i++)
		for (list<pair<int, int>>::iterator it = graf[i].begin(); it != graf[i].end(); it++)
			d[i][(*it).first] = (*it).second;

	//czesc glowna
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (d[i][k] == INT_MAX || d[k][j] == INT_MAX)	//nie wiem po co, bez tego nie dziala
					continue;
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}

	//wyswietlanie
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "d[" << i << "," << j << "] = ";
			if (d[i][j] == INT_MAX)
				cout << "brak sciezki" << endl;
			else
				cout << d[i][j] << endl;
		}

	for (int i = 0; i < n; i++)
		delete[]d[i];
	delete[]d;
}


//*********************************************************
// minimalne drzewo rozpinajace - graf wazony

//strukrura zawierajaca elementy jednej krawedzi - wierzcholki krawedzi v-u oraz ich wage w
struct krawedz {
	int v;
	int u;
	int w;
};

//komarator wykorzystywany w kolejce priorytetowej. Sortuje rosnaco po wagach krawedzi
struct portownaj_krawedzie {
	bool operator()(const krawedz &k1, const krawedz &k2)
	{
		if (k1.w > k2.w)
			return true;
		if (k1.w < k2.w)
			return false;

		return false;
	}
};

int find_zbiory_rozlaczne(int *tab, int x)
{
	return tab[x];
}

void union_zbiory_rozlaczne(int *tab, int n, int x, int y)
{
	int rx, ry;
	rx = tab[x];
	ry = tab[y];
	if (rx == ry)
		return;

	for (int i = 0; i < n; i++)
		if (tab[i] == ry)
			tab[i] = rx;
}

void wyswietl_zbiory_rozlaczne(int *tab, int n)
{
	cout << "indeks" << "	zawartosc" << endl;
	for (int i = 0; i < n; i++)
		cout << i << "	" << tab[i] << endl;
	cout << endl;
}

void prim_lista_sasiedztwa(list<pair<int, int>> *graf, int n)
{
	priority_queue<krawedz, vector<krawedz>, portownaj_krawedzie> Q;
	krawedz k;			//element struktury o elementach {u, v, w}
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;
	int waga_koncowa = 0;

	list<pair<int, int>> *T = stworz_wazona_liste_sasiedztwa(n);
	//T[u].push_back(make_pair(v,w));

	int v = 0;
	visited[v] = true;

	for (int i = 0; i < n - 1; i++)
	{
		for (list<pair<int, int>>::iterator it = graf[v].begin(); it != graf[v].end(); it++)
		{
			if (visited[(*it).first] == false)
			{
				k = { v, (*it).first, (*it).second };
				Q.push(k);
			}
		}

		do {
			k = Q.top();
			Q.pop();
		} while (visited[k.u] == true);

		T[k.v].push_back(make_pair(k.u, k.w));
		T[k.u].push_back(make_pair(k.v, k.w));
		waga_koncowa += k.w;
		visited[k.u] = true;
		v = k.u;
	}
	cout << "struktura minimalnego drzewa rozpinajacego" << endl;
	wyswietl_wazona_liste_sasiedztwa(T, n);
	cout << "waga minimalnego drzewa rozpinajacego: " << waga_koncowa << endl;
	usun_liste_sasiedztwa(T);
	delete[]visited;
}

void kruskal_lista_sasiedztwa(list<pair<int, int>>*graf, int n)
{
	int *Z = new int[n];		//struktura zbiorow rozlacznych
	for (int i = 0; i < n; i++)
		Z[i] = i;

	priority_queue<krawedz, vector<krawedz>, portownaj_krawedzie> Q;
	krawedz k;
	int waga_calkowita = 0;

	list<pair<int, int>> *T = stworz_wazona_liste_sasiedztwa(n);
	//T[u].push_back(make_pair(v,w));

	for (int i = 0; i < n; i++)
	{
		for (list<pair<int, int>>::iterator it = graf[i].begin(); it != graf[i].end(); it++)
		{
			k = { i, (*it).first, (*it).second };
			Q.push(k);
		}
	}

	for (int i = 0; i < n-1; i++)
	{
		do {
			k = Q.top();
			Q.pop();
		} while (find_zbiory_rozlaczne(Z, k.v) == find_zbiory_rozlaczne(Z, k.u));
		T[k.v].push_back(make_pair(k.u, k.w));
		T[k.u].push_back(make_pair(k.v, k.w));
		waga_calkowita += k.w;
		union_zbiory_rozlaczne(Z, n, Z[k.u], Z[k.v]);
	}

	cout << "struktura minimalnego drzewa rozpinajacego" << endl;
	wyswietl_wazona_liste_sasiedztwa(T, n);
	cout << "waga minimalnego drzewa rozpinajacego: " << waga_calkowita << endl;

	usun_liste_sasiedztwa(T);
	delete[]Z;
}