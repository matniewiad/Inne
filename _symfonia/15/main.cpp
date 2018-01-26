#include <iostream>
using namespace std;
#include <string>

void fun_5(float *tab, int ile);

int main()
{
	/*string A;// = "ala";
	//A = "alalal";
	//cin.ignore();			//niby mialo byc, ale psuje. Usuwa 1 znak
	getline(cin, A);
	cout << A;*/

	//wczytywanie n liczb. Znajdowanie liczby, ktora jest najblizej sredniej;
	const int ile = 4;
	float tablica[ile];
	
	//wczytywanie
	cout << "wczytaj " << ile << " liczb:" << endl;
	for (int i = 0 ; i < ile ; i++)
	{
		cin >> tablica[i];
	}

	fun_5(tablica,ile);
	
	system("pause");
	return 0;
}

void fun_5(float *tab, int ile)
{
	float *const tab_pocz = tab;		//wskaznik staly pokazujacy zawsze na poczatek tablicy
	float suma = 0;
	float srednia = 0;

	for (int i = 0 ; i<ile ; i++)
	{
		//suma += tab[i];
		suma += *tab;
		tab++;
	}
	tab = tab_pocz;

	srednia = suma / ile;
	cout << "srednia: " << srednia << endl;

	float min_roznica;
	min_roznica = abs(srednia - (*tab));

	float *szukana_liczba = new float[ile];
	int licznik_liczb = 0;
	float *const szukana_liczba_pocz = szukana_liczba;		//wskaznik staly pokazujacy zawsze na poczatek tablicy
	
	//szukanie minimalnej roznicy
	for (int i = 0 ; i < ile ; i++)
	{
		if ( abs(srednia - (*tab)) <= min_roznica)
		{
			min_roznica = abs(srednia - (*tab));
		}
		tab++;
	}
	tab = tab_pocz;

	int czy_powtorzona = 0;
	//szukanie liczb spelniajacych warunek minimalnej roznicy, sprawdzanie powtorzen, sprawdzanie, czy jest kilka takich liczb
	for (int i = 0; i < ile; i++)
	{
		if (abs(srednia - (*tab)) == min_roznica)
		{
			if (licznik_liczb == 0)
			{
				szukana_liczba[licznik_liczb] = *tab;
				licznik_liczb++;
			}
			else
			{
				for (int j = 0; j < licznik_liczb; j++)
				{
					if (szukana_liczba[j] == *tab)
					{
						czy_powtorzona = 1;
					}
				}
				if (czy_powtorzona == 0)
				{
					szukana_liczba[licznik_liczb] = *tab;
					licznik_liczb++;
				}
				czy_powtorzona = 0;
			}
		}
		tab++;
	}

	//wyswietlanie
	cout << "min roznica: " << min_roznica << endl;
	if (licznik_liczb==1)
	{
		cout << "szukana liczba: " << *szukana_liczba << endl;
	}
	else
	{
		cout << "szukane liczby: ";
		for (int i = 0 ; i < licznik_liczb ; i++)
		{
			cout << *szukana_liczba << ", ";
			szukana_liczba++;
		}
		cout << endl;
	}

	szukana_liczba = szukana_liczba_pocz;
	delete[]szukana_liczba;
}