// PO vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Zwierz.h"
#include "Pies.h"
#include "Kot.h"
using namespace std;
#include <vector>


int _tmain(int argc, _TCHAR* argv[])
{
	vector <Zwierz*> tab;
    char *a = "imie1";
    int b = 10;
    int c = 20;
    tab.push_back(new Kot(a, 5));
    tab.push_back(new Pies(a, 6));
    tab.push_back(new Kot(a, 7));
    cout << "rozmiar kontenera: ";
    cout << tab.size() << endl;
    for (int i = 0; i < tab.size(); i++)
    {
        cout << "zwierz nr: " << i+1 << endl;
        tab[i] -> daj_glos();
        cout << "imie zwierza: " << tab[i] -> imie << endl;
        cout << "wiek zwierza: " << tab[i] -> wiek << endl;
    }

	system("pause");
	return 0;
}

