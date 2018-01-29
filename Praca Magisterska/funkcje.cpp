#include "funkcje.h"

//wczytywanie
void wczytaj_dane_modul(vector<Modul>&moduly)
{
	moduly.clear();
	//uwazac w ktorym miejscu jest kursor w pliku! -> plik.eof()
	fstream plik;
	plik.open("C:\\Users\\Mateusz\\Desktop\\pliki_mag\\dane.txt", ios::in);

	if (!plik.good())		//plik.good() == false
	{
		cout << "Nie udalo sie otworzyc pliku z modulami!" << endl;
		getchar();
		exit(0);
	}
	int lp, inx, prg;
	int zam[6];
	while (!plik.eof())
	{
		plik >> lp >> inx >> prg;
		for (int i = 0; i < 6; i++)
			plik >> zam[i];
		moduly.push_back(Modul(lp, inx, 1, prg, zam));
	}
	plik.close();
}

void wczytaj_dane_zadanie(vector<Zadanie>&zadania)
{
	zadania.clear();
	//uwazac w ktorym miejscu jest kursor w pliku! -> plik.eof()
	fstream plik;
	plik.open("C:\\Users\\Mateusz\\Desktop\\pliki_mag\\dane3.txt", ios::in);

	if (!plik.good())		//plik.good() == false
	{
		cout << "Nie udalo sie otworzyc pliku z zadaniami!" << endl;
		getchar();
		exit(0);
	}
	int lp, inx, prg;
	int j = 1;
	int zam[6];
	int too_big = 0;
	int prev_lp = -1;
	while (!plik.eof())
	{
		plik >> lp >> inx >> prg;
		if (lp != prev_lp)		//zeby nie wczytywac 2 razy ostatniej linii
		{
			for (int i = 0; i < 6; i++)
			{
				plik >> zam[i];
				if (i != 0 && zam[i] != 0)
				{
					if (zam[i] > 480)
					{
						too_big = zam[i];
						while (too_big > 480)
						{
							zadania.push_back(Zadanie(j, inx, prg, i, 480));
							too_big -= 480;
							j++;
						}
						if (too_big > 0)
						{
							zadania.push_back(Zadanie(j, inx, prg, i, too_big));
							j++;
						}
					}
					else
					{
						zadania.push_back(Zadanie(j, inx, prg, i, zam[i]));
						++j;
					}
				}
				prev_lp = lp;
			}
			/*for (int i = 0; i < 6; i++)
			{
				plik >> zam[i];
				if (i != 0 && zam[i] != 0)
				{
					if (zam[i] > 480)
					{
						too_big = zam[i];
						while (too_big > 480)
						{
							zadania.push_back(Zadanie(j, inx, prg, i, 480));
							too_big -= 480;
							j++;
						}
						if(too_big > 0)
						{
							zadania.push_back(Zadanie(j, inx, prg, i, too_big));
							j++;
						}
					}
					else
					{
						zadania.push_back(Zadanie(j, inx, prg, i, zam[i]));
						++j;
					}
				}*/
		}
	}

	plik.close();
}

void wczytaj_wydajnosc_maszyn(vector<vector<int>> &wydajnosc, int*maszyn, int*programow)
{
	wydajnosc.clear();
	//uwazac w ktorym miejscu jest kursor w pliku! -> plik.eof()
	fstream plik;
	plik.open("C:\\Users\\Mateusz\\Desktop\\pliki_mag\\wydajnosc.txt", ios::in);

	if (!plik.good())		//plik.good() == false
	{
		cout << "Nie udalo sie otworzyc pliku z wydajnosciami!" << endl;
		getchar();
		exit(0);
	}
	int kolumn = 0;
	int wierszy = 0;		//zeby indeksowac od 1
	plik >> wierszy >> kolumn;
	int initial_value = 0;
	wydajnosc.resize(wierszy + 1, vector<int>(kolumn + 1, initial_value));
	*maszyn = kolumn;
	*programow = wierszy;

	int program, wyd1, wyd2, wyd3, wyd4, i = 1;
	for (int j = 0; j < wierszy; j++)
	{
		plik >> program >> wyd1 >> wyd2 >> wyd3 >> wyd4;
		wydajnosc[i][0] = program;
		wydajnosc[i][1] = wyd1;
		wydajnosc[i][2] = wyd2;
		wydajnosc[i][3] = wyd3;
		wydajnosc[i][4] = wyd4;
		++i;
	}
	plik.close();
}

void wczytaj_przezbrojenia(vector<vector<int>> &tabela_przezbrojen, int programow)
{
	tabela_przezbrojen.clear();
	//uwazac w ktorym miejscu jest kursor w pliku! -> plik.eof()
	fstream plik;
	plik.open("C:\\Users\\Mateusz\\Desktop\\pliki_mag\\tabela_przezbrojen.txt", ios::in);

	if (!plik.good())		//plik.good() == false
	{
		cout << "Nie udalo sie otworzyc plikuz przezbrojeniami!" << endl;
		getchar();
		exit(0);
	}
	int wierszy = programow + 1, kolumn = programow + 1, initial_value = 1;
	tabela_przezbrojen.resize(wierszy, vector<int>(kolumn, initial_value));
	int czas = 0;
	wierszy--;
	kolumn--;
	while (!plik.eof())
	{
		for (int i = 0; i < wierszy; i++)
		{
			for (int j = 0; j < kolumn; j++)
			{
				plik >> czas;
				tabela_przezbrojen[i][j] = czas;
				//cout << tabela_przezbrojen[i][j] << " ";
				//if ((i < 6 && j < 6) || (i < 6 && j > 39))
				//	cout << "[" << i << "][" << j << "]=" << tabela_przezbrojen[i][j] << " ";
			}
			//if (i < 6 || i > 39)
			//	cout << endl;
			//cout << endl;
		}
	}
	plik.close();
}

//wyswietlanie
void wyswietl_moduly(vector<Modul>moduly)
{
	for (auto &i : moduly)
		i.wyswietl_modul();
}

void wyswietl_zadania_vec_more(vector<Zadanie>zadania)
{
	for (auto &i : zadania)
		i.wyswietl_zadanie();
}

void wyswietl_zadania_vec_less(vector<Zadanie>zadania)
{
	for (auto &i : zadania)
		i.wyswietl_zadanie_less();
}

void wyswietl_zadania_vec_tab(vector<Zadanie>zadania)
{
	cout << setw(9) << "index" << setw(9) << "ilosc" << setw(9) << "program" << setw(9) << "q" << endl;
	cout << "------------------------------------" << endl;
	for (auto &i : zadania)
		i.wyswietl_zadanie_tab();
}

void wyswietl_zadania_list_more(list<Zadanie>zadania)
{
	for (auto &i : zadania)
		i.wyswietl_zadanie();
}

void wyswietl_zadania_list_less(list<Zadanie>zadania)
{
	for (auto &i : zadania)
		i.wyswietl_zadanie_less();
}

void wyswietl_zadania_list_tab(list<Zadanie>zadania)
{
	cout << setw(9) << "index" << setw(9) << "ilosc" << setw(9) << "program" << setw(9) << "q" << endl;
	cout << "------------------------------------" << endl;
	for (auto &i : zadania)
		i.wyswietl_zadanie_tab();
}

void wyswietl_wydajnosc(vector<vector<int>> &wydajnosc, int maszyn, int programow)
{
	cout << setw(4) << "prog" << setw(4) << "m1" << setw(4) << "m2" << setw(4) << "m3" << setw(4) << "m4" << endl;
	cout << "--------------------" << endl;
	for (int i = 1; i <= programow; i++)
	{
		for (int j = 0; j < maszyn + 1; j++)
			cout << setw(4) << wydajnosc[i][j];
		cout << "\n";
	}
}

void wyswietl_przezbrojenia(vector<vector<int>> tabela_przezbrojen, int programow)
{
	for (int i = 0; i < programow + 1; i++)
	{
		if (i == 1)
		{
			for (int j = 0; j < programow + 1; j++)
				cout << setw(3) << "---";
			cout << endl;
		}
		for (int j = 0; j < programow + 1; j++)
		{
			cout << setw(3) << tabela_przezbrojen[i][j];
			if (j == 0)
				cout << "|";
		}
		cout << endl;
	}
}

void wyswietl_linie(vector<list<Zadanie>>linie, int maszyn)
{
	for (int i = 1; i <= maszyn; i++)
	{
		cout << "\n\nlinia " << i << endl;
		wyswietl_zadania_list_tab(linie[i - 1]);
	}
}

void wyswietl_zapelnienie_wszstkich_linii(vector<list<Zadanie>>linie)
{
	cout << "Zapelnienie poszczegolnych linii bez uwzglednienia przezbrojen\n";
	for (int i = 0; i < (int)linie.size(); i++)
		cout << "zajetosc lini " << i + 1 << "   - " << zapelnienie_linii(linie[i]) << endl;
	cout << endl;
}

void wyswietl_zapelnienie_wszstkich_linii_z_przezbrojeniami(vector<list<Zadanie>>linie, vector<list<int>>przezbrojenia)
{
	cout << "Zapelnienie poszczegolnych linii z uwzglednieniem przezbrojen\n";
	for (int i = 0; i < (int)linie.size(); i++)
		cout << "zajetosc lini " << i + 1 << "   - " << zapelnienie_linii_z_przezbrojeniami(linie[i], przezbrojenia[i]) << endl;
	cout << endl;
}

void wyswietl_czasy_przezbrojen(vector<list<int>>przezbrojenia)
{
	int licznik = 0;				//po 10 wystapien w linii
	cout << "PRZEZBROJENIA\n";
	for (int i = 0; i < (int)przezbrojenia.size(); i++)
	{
		licznik = 0;
		cout << "linia " << i + 1 << endl;
		for (auto &j : przezbrojenia[i])
		{
			cout << setw(6) << j;
			licznik++;
			if (licznik == 10)
			{
				cout << endl;
				licznik = 0;
			}
		}
		cout << endl << endl;
	}
}

void wyswietl_rozwiazania(vector<list<Rozwiazanie>>rozwiazania)
{
	for (int it = 0; it < (int)rozwiazania.size(); it++)
	{
		cout << "\nLinia " << it + 1 << endl;
		cout << setw(9) << "index" << setw(9) << "maszyna" << setw(9) << "S" << setw(9) << "C" << endl;
		cout << "------------------------------------" << endl;
		for (auto i : rozwiazania[it])
			i.wyswietl_rozwiazanie();
	}
}

//INNE
void vec_to_list(vector<Zadanie> wek, list<Zadanie>&lista)
{
	for (auto &i : wek)
		lista.push_back(i);
}


//*******************************************************************************************
//FUNKCJE GLOWNE
int zapelnienie_linii(list<Zadanie>lista)
{
	int zapelnienie = 0;
	for (auto &i : lista)
		zapelnienie += i.p_calkowite;

	return zapelnienie;
}

int zapelnienie_linii_z_przezbrojeniami(list<Zadanie>lista, list<int>przezbrojenia_tej_linii)
{
	int zapelnienie = 0;
	for (auto &i : lista)						//liczenie samego czasu wykonania 
		zapelnienie += i.p_calkowite;

	for (auto &i : przezbrojenia_tej_linii)		//liczenie samych przezbrojen
		zapelnienie += i;

	return zapelnienie;
}

void proste_rozlozenie(list<Zadanie>lista_zadan, vector<list<Zadanie>>&linie, vector<vector<int>>wydajnosc, int maszyn, list<Zadanie>& nieprzetworzone)
{
	linie.resize(maszyn);
	int na_ktora_linie = 0;
	for (auto &przetwarzane_zadanie : lista_zadan)					//rozkladamy wszystkie zadania
	{
		na_ktora_linie = na_ktora_linie_wrzucic(przetwarzane_zadanie, wydajnosc, linie);
		if (na_ktora_linie != -1)
			linie[na_ktora_linie].push_back(przetwarzane_zadanie);
		else
			nieprzetworzone.push_back(przetwarzane_zadanie);		//zadanie nie moze zostac nigdzie wrzucone (na_ktora_linie = -1)
	}
}

int na_ktora_linie_wrzucic(Zadanie zadanie, vector<vector<int>>wydajnosc, vector<list<Zadanie>> linie)
{
	int maszyn = linie.size();
	int najlepsza_zapelnienie = INT_MAX;			//zapelnieni najlepszej liniii/ najmniej zajetej
	int najlepsza_index = -1;						//indeks najlepszej linii/ najmniej zajetej
	int zapelnienie_obecnej = 0;					//zeby 2 razy nie wywolywac funkcji

	for (int i = 0; i < maszyn; i++)					//poszukiwania najlepszej linii, na ktorej umieszczone zostanie zadanie
	{													//jesli dane zadanie mozna w ogole wykonac na danej linii
		zapelnienie_obecnej = zapelnienie_linii(linie[i]);
		if (wydajnosc[zadanie.program][i + 1] == 1)		//'i+1', bo w 'wydajnosc' maszyny sa na 1-4
			//zapelnienie_obecnej = zapelnienie_linii(linie[i]);	
			if (zapelnienie_obecnej < najlepsza_zapelnienie)
			{
				najlepsza_zapelnienie = zapelnienie_obecnej;
				najlepsza_index = i;
			}
	}
	return najlepsza_index;
}

void wyznacz_przezbrojenia_w_prostym_harmonogramie(vector<vector<int>>tabela_przezbrojen, vector<list<Zadanie>>&linie, vector<list<int>>&przezbrojenia)
{
	przezbrojenia.resize(linie.size());
	vector<int> kolejne_programy;
	for (int i = 0; i < (int)linie.size(); i++)						//dla kazdej linii
	{
		kolejne_programy.clear();
		for (auto &zadanie : linie[i])							//kazde zadanie na danej linii
			kolejne_programy.push_back(zadanie.program);		//zapamietujemy program

		for (int j = 0; j < (int)kolejne_programy.size() - 1; j++)		// 'j < ...-1', bo po ostatnim zadaniu nie ma przezbrojenia
			przezbrojenia[i].push_back(tabela_przezbrojen[kolejne_programy[j] - 1][kolejne_programy[j + 1] - 1]);		//-1 w indeksach, bo tablica przezbrojen ma indeksy 0-43 a nie 1-44
	}
}

//08.12

void wypelnij_rozwiazania(vector<list<Rozwiazanie>>&rozwiazania, vector<list<Zadanie>>linie, vector<list<int>> przezbrojenia)
{
	cout << "Zaczynam tworzyc rozwiazania\n";
	cout << "maszyn: " << linie.size() << endl;
	int maszyn = (int)linie.size();
	rozwiazania.resize(maszyn);
	int licznik = 0;
	int C = 0;
	list<int>::iterator it_przezborjenia;
	for (int i = 0; i < maszyn; i++)
	{
		it_przezborjenia = przezbrojenia[i].begin();	//iterator po przezbrojeniach
		C = 0;											//przy rozpatrywaniu kolejnych linii 'C' jest zerowane
		licznik = 0;
		for (Zadanie zad : linie[i])
		{
			C += zad.p_calkowite;
			rozwiazania[i].push_back(Rozwiazanie(zad, C, i));	//dodanie rozwiazania do wektora rozwiazan
			licznik++;
			C += *it_przezborjenia;							//dodanie przezborjenia
			if (it_przezborjenia != przezbrojenia[i].end())	//jesli nie jest to koniec listy przezbrojen
				it_przezborjenia++;							//przesun iterator (przezbrojen jest o 1 mniej niz zadan) -> to jest w sumie niepotrzebe, bo przyostatnim zadaniu to co sie wydazy to przesuniecie iteratora, ktory i tak nie bedzie wyluskany, bo petla sie przerwie
		}
		cout << "na lini " << i + 1 << " jest " << licznik << " zadan\n";
	}
}

void zapisz_rozwiazanie_do_pliku(vector<list<Rozwiazanie>>rozwiazania, vector<list<int>> przezbrojenia)
{
	fstream plik;
	string fbasename = "C:\\Users\\Mateusz\\Desktop\\pliki_mag\\linia";		//poczatek sciezki
	string fname = "";														//to co wyzej + koncowka + '.txt'
	char delimiter = ';';
	int maszyn = (int)rozwiazania.size();
	int licznik_linii = 0;							//zeby nie bylo pustej linii na koncu
	int linii = 0;
	list<int>::iterator it_przezborjenia;
	for (int i = 0; i < maszyn; i++)
	{
		it_przezborjenia = przezbrojenia[i].begin();	//iterator po przezbrojeniach
		licznik_linii = 0;
		fname = fbasename + int_to_string(i + 1) + ".txt";
		plik.open(fname, ios::out);
		linii = rozwiazania[i].size();
		plik << linii << endl;
		for (auto i : rozwiazania[i])
		{
			if (licznik_linii != linii - 1)
			{
				plik << i.zad.index << delimiter << i.zad.program << delimiter << i.zad.ilosc << delimiter << i.ktora_maszyna << delimiter << i.S << delimiter << i.C << delimiter << i.day << delimiter << i.start_time << delimiter << i.end_time << delimiter << (*it_przezborjenia) << delimiter << endl;
				it_przezborjenia++;
			}
			else		//w ostatniej linii nie ma endl i przezbrojenie = 0
				plik << i.zad.index << delimiter << i.zad.program << delimiter << i.zad.ilosc << delimiter << i.ktora_maszyna << delimiter << i.S << delimiter << i.C << delimiter << i.day << delimiter << i.start_time << delimiter << i.end_time << delimiter << 0 << delimiter;
			licznik_linii++;
		}
		plik.close();
		cout << "zapisano plik " << fname << endl;
	}
}

string int_to_string(int n)
{
	ostringstream ss;
	ss << n;
	string str = ss.str();
	return str;
}

void zapisz_nieprzetworzone_do_pliku(list<Zadanie> nieprzetworzone)
{
	fstream plik;
	string fname = "C:\\Users\\Mateusz\\Desktop\\pliki_mag\\nieprzetworzone.txt";
	char delimiter = ';';
	plik.open(fname, ios::out);
	for (auto i : nieprzetworzone)
		plik << i.index << delimiter << i.program << delimiter << i.ilosc << endl;

	plik.close();
	cout << "zapisano plik " << fname << endl;
}