#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//otwieranie pliku
	fstream plik; // plik z danymi
	plik.open("dane.txt", ios::in);
	int a;
	cout << "wczytuje a" << endl;
	plik >> a;
	cout << "udalo sie, ilosc procesow wynosi: " << a << endl;

	//tworzenie tablicy dynamicznej dwuwymiarowej
	int **F;
	F = new int*[a];
	for(int i = 0 ; i < a ; i++)
	{
		F[i] = new int [a];
	}
	cout << "utworzono tablice" << endl;

	//wypelnianie i wyswietlanie
	int x, y;
	for(int i = 0; i < a; i++)
	{
		plik >> x >> y;
		F[i][0] = x;
		F[i][1] = y;
		cout << F[i][0] << "	" << F[i][1] << "	" << endl; 
	}

	//zamykanie pliku
	plik.close();
	cout << "plik zamkniety" << endl;
	
	//usuwanie zmiennych dynamicznych
	for(int i = 0 ; i < a ; i++)
	{
		delete [] F[i];
	}
	delete [] F;
	
	system("pause");
	return 0;
}