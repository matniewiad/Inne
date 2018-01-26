#include <iostream>
using namespace std;

int main()
{
	const int rozmiar = 10;
	int *tablica = new int[rozmiar];

	for (int i = 0 ; i < rozmiar ; i++)
	{
		*(tablica+i) = i;		//to samo co tablica[i]=i;
		cout << *(tablica+i) << endl;	//to samo co cout << tablica[i];
	}

	cout << "adres tablicy: " << tablica << endl;
	delete [] tablica;

	cout << "adres tablicy po usubnieciu: " << tablica << endl;
	cout << "ustawianie adresu tablica na null" << endl;
	tablica = NULL;
	cout << "adres tablicy po NULLowaniu: " << tablica << endl;
	cout << "przypadkowy, drugi delete nieistniejacej juz tablicy" << endl;
	delete[] tablica;
	cout << "adres tablicy po 2 usubnieciu: " << tablica << endl;

	cout << endl << endl << "dziala" << endl;
	system("pause");
	return 0;
}