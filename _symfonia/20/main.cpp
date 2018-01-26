#include <iostream>
using namespace std;
#include "Serial.h"
#include <vector>
#include <conio.h>
#include <fstream>

void wczytaj_z_pliku(vector<Serial>&);
void zapisz_do_pliku(vector<Serial>&);
void wyswietl_liste(vector<Serial>);

int main()
{
	vector <Serial> seriale;
	char wybor;		//do switcha
	string t;		//do wprowadzania tytulu dla nowego serialu
	int ktory_s;	//do zwiekszania liczby odcinkow i zmiany sezonu
	char czy_na_pewno;	//do potwierdzania decyzji y/n

	while(true)
	{
		wyswietl_liste(seriale);
		cout << "-------------------------------------" << endl;
		cout << "----------------MENU-----------------" << endl;
		cout << "-------------------------------------" << endl;
		cout << "1. Dodaj serial" << endl;
		cout << "2. Obejrzano odcinek" << endl;
		cout << "3. Koniec sezonu" << endl;
		cout << "4. Usun serial z listy" << endl;
		cout << "5. Wczytaj liste z pliku" << endl;
		cout << "6. Zapisz do pliku" << endl;
		cout << "7. Liczba seriali" << endl;
		cout << "9. Wyjscie" << endl;
		cout << "Wybor: " << endl;
		wybor = _getch();		//zamiast cin'a. Nie trzeba zatwierdzac enterem

		switch (wybor)
		{
		case '1':
			cout << "--------Dodaj serial--------" << endl;
			cout << "Podaj tytul: ";
			getline(cin, t);
			seriale.push_back(Serial(t));
			Serial::ilosc_seriali++;
			break;

		case '2':
			cout << "------Obejrzano odcinek------" << endl;
			cout << "ktory serial? ";
			cin >> ktory_s;
			seriale[ktory_s-1].dodaj_odcinek();		//bo wyswietla od 1, a vector iteruje od 0
			break;

		case '3':
			cout << "------Koniec sezonu------" << endl;
			cout << "ktory serial? ";
			cin >> ktory_s;
			seriale[ktory_s - 1].koniec_sezonu();
			break;

		case '4':
			cout << "------Usun serial z listy------" << endl;
			cout << "ktory serial? ";
			cin >> ktory_s;
			seriale.erase(seriale.begin()+ktory_s-1);
			Serial::ilosc_seriali -= 1;
			break;

		case '5':
			cout << "Czy aby na pewno wczytac? Obecna lista zostanie zastapiona ta z pliku seriale.txt (y/n): ";
			cin >> czy_na_pewno;
			if (czy_na_pewno == 'y' || czy_na_pewno == 'Y')
			{
				wczytaj_z_pliku(seriale);
				czy_na_pewno = '0';
			}
			break;

		case '6':
			cout << "Czy aby na pewno zapisac? Tresc obecnego pliku zostanie zastapiony wyswietlona lista (y/n): ";
			cin >> czy_na_pewno;
			if (czy_na_pewno == 'y' || czy_na_pewno == 'Y')
			{
				zapisz_do_pliku(seriale);
				czy_na_pewno = '0';
			}
			break;

		case '7':
			cout << "liczba seriali: " << Serial::ilosc_seriali << endl;
			break;
			
		case '9':
			cout << "Czy na pewno wyjsc? (y/n): ";
			cin >> czy_na_pewno;
			if (czy_na_pewno == 'y' || czy_na_pewno == 'Y')
			{
				exit(0);
			}
			else
				break;

		default:
			cout << "Bledny wybor!" << endl;
			break;
		}

		getchar();		//troche pomaga
		system("cls");	//czysci ekran
	};

	return 0;
}

//***************************************
void wyswietl_liste(vector<Serial> seriale)
{
	//system("CLS");
	cout << endl << "--------Lista seriali--------" << endl;
	for (size_t i = 0; i < seriale.size(); i++)		//w funkcji zapisujacej podobna petla zrobiona na iteratorach
	{
		cout << i + 1 << ". ";
		seriale[i].wyswietl();
	}
	cout << endl;
}

//***************************************
void wczytaj_z_pliku(vector<Serial>& seriale)
{
	//czyszczenie vectora przy wczytywaniu oraz resetowanie Serial::liczba_seriali
	seriale.clear();
	Serial::ilosc_seriali = 0;

	string linia;
	int nr_linii = 1;
	string title;
	int season, episode;

	fstream plik;
	plik.open("seriale.txt", ios::in);

	if (!plik.good())		//plik.good() == false
	{
		cout << "Nie udalo sie otworzyc pliku!" << endl;
		getchar();
		exit(0);
	}

	while (getline(plik, linia))
	{
		if (nr_linii == 1)
			Serial::ilosc_seriali += atoi(linia.c_str());
		else if ((nr_linii+1)%3 == 0)
			title = linia;
		else if ((nr_linii) % 3 == 0)
			season = atoi(linia.c_str());
		else if ((nr_linii - 1) % 3 == 0)
		{
			episode = atoi(linia.c_str());
			seriale.push_back(Serial(title, season, episode));
		}
		nr_linii++;
	}
	cout << "Wczytano!" << endl;
	plik.close();
}

//***************************************
void zapisz_do_pliku(vector<Serial>& seriale)
{
	fstream plik;
	plik.open("seriale.txt", ios::out);

	plik << Serial::ilosc_seriali << endl;

	for (vector<Serial>::iterator it=seriale.begin() ; it != seriale.end() ; it++)
	{
		plik << it->get_tytul() << endl;		//or (*it).get_sezon()
		plik << it->get_sezon() << endl;
		plik << it->get_odcinek() << endl;
	}

	plik.close();
	cout << "Prawdopodobnie zapisano!" << endl;

	
}