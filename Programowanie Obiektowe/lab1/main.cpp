// temp.cpp : Defines the entry point for the console application.
//

#include <cstdlib>
#include <iostream>
using namespace std;

    struct baza
    {
        char imie[10];
        char nazwisko[20];
        int nr;
        int ocena;
    }; //struktura
    
baza dodaj_osobe(int nr)
{
	baza nowa_osoba;
	cout << "podaj imie:" << endl;
	cin >> nowa_osoba.imie;
	cout << "podaj nazwisko:" << endl;
	cin >> nowa_osoba.nazwisko;
	cout << "podaj ocene:" << endl;
	cin >> nowa_osoba.ocena;
	nowa_osoba.nr = nr;
	return nowa_osoba;
}


void usun(baza tablica[], int *licznik, int *i, int *lu)
{
	int index;
	cout << "podaj nr studenta, ktorego dane chcesz usunac: " << endl;
	cin >> index;
	if(index >= 0)
	{
		for(int i = index - *lu ; i < *licznik ; i++)
		{
			tablica[i-1] = tablica[i];
		}
		(*licznik)--;
		(*i)--;
		cout << "dane studenta zostaly usuniete z listy" << endl;
	}
	else
	{
		cout << "podano zly nr studenta" << endl;
	}
}


void sortuj(baza tablica[], int licznik)
  {
  	for(int j = licznik - 1; j > 0; j--)
  {
    int p = 1;
    for(int i = 0; i < j; i++)
      if(tablica[i].nazwisko[0] > tablica[i + 1].nazwisko[0])
      {
        swap(tablica[i], tablica[i + 1]);
        p = 0;
      }
    if(p) break;
  }
}

int main(int argc, char** argv) 
{
    int i = 1; // sam nie wiem co to robi, ale niech na razie jest. NIE NAZYWAC ZMIENNYCH "i"!!!
    int nr_studenta = 1; // numer studenta widoczny w strukturze. Zaczynamy od 1 i zwiekszamy orzy kazdym dodaniu nowego studenta, nie zmniejszamy przy usuwaniu
    int lu = 0; //liczba studentow usunietych z bazy
    int licznik = 0; // licznik osob w bazie, tylko do pomocy
    int rozm; // rozmiar tablicy
    int rozm2; // do jakiegos warunku
    
    cout << "BAZA DANYCH - GRUPA STUDENCKA" << endl<<endl<<endl;
    cout << "podaj rozmiar bazy danych" << endl;
    cin >> rozm;
    rozm2 = rozm;
    baza *tablica = new baza[rozm]; // tablica struktur
    
    int koniec = 0;
    while(koniec==0)
    {
    cout << "wybierz opcje:" << endl << "1. dodaj do bazy studenta" << endl << "2. usun studenta z bazy danych" << endl;
	cout << "3. posortuj baze danych alfabetycznie" << endl <<"4. wyswietl baze danych" <<"5. koniec dzialania programu" << endl << endl;
	
	int wybor;
    cin >> wybor;
    switch(wybor)
    {
    case 1:
    	cout << "licznik przed:" << licznik << endl;
    	if(licznik>=rozm2)
    	{
    		baza *tab_n = new baza[rozm2+1];
    		for(int i=0 ; i<rozm2 ; i++)
    		{
    			tab_n[i] = tablica[i];
    		}
    		tab_n[rozm2] = dodaj_osobe(nr_studenta);
    		tablica = tab_n;
    		delete [] tablica;
    		rozm2++;
    	}
    	else
    	{
    		cout << "podaj dane studenta:" << endl;
        	tablica[i-1] = dodaj_osobe(nr_studenta);
    	}
        i++;	
        licznik++;
        nr_studenta++;
        cout << "licznik po: " << licznik << endl;
        cout << endl;
        break;

    case 2:
        usun(tablica, &licznik, &i, &lu);
        cout << "licznik:" << licznik << endl;
        lu++;
        break;

    case 3:
    	sortuj(tablica, licznik);
    	cout << "lista posortowana" << endl << endl;
        break;
    	
    case 4:
    	if (licznik != 0)
    	{
    		for(int i=0 ; i<licznik ; i++)
    		{
    			cout << "student:	" << i+1 << endl;
    			cout << "imie:		" << tablica[i].imie << endl;
    			cout << "nazwisko:	" << tablica[i].nazwisko << endl;
    			cout << "nr studenta:	" << tablica[i].nr << endl;
    			cout << "ocena:		" << tablica[i].ocena << endl << endl;
    		}
    	}
    	
    case 5:
    	koniec = 1;
    	cout << "koniec dzialania programu" << endl << endl;
    	break;
    	cout << "licznik:" << licznik << endl;
    	break;

    default:
    	cout << "bledny wybor" << endl << endl;
        break;

    }
	}


    system("pause");
    return 0;
}
