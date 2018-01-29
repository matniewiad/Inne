#include <iostream>
#include <ctime>
using namespace std;
#define N 15

int temp[N]; // tablica pomocnicza

template <typename T>
void scalanie(T tab[], int poczatek, int srodek, int koniec)
{
	int i, j;
	for(i = srodek+1 ; i > poczatek ; i--) // lewa czesc tablicy w tablicy pomocniczej
	{
		temp[i-1] = tab[i-1];
	}

	for(j = srodek ; j < koniec ; j++)
	{
		temp[koniec+srodek-j] = tab[j+1];
	}

	for(int k = poczatek ; k <= koniec ; k++)
	{
		if(temp[j] < temp[i])
		{
			tab[k] = temp[j];
			j--;
		}
		else
		{
			tab[k] = temp[i];
			i++;
		}
	}
}

template <typename T>
void sortowanie_scalanie(T tab[], int poczatek, int koniec)
{
	if(koniec == poczatek) //jeden element tablicy
	{
		return;
	}

	int srodek = (poczatek+koniec)/2;

	sortowanie_scalanie<T>(tab, poczatek, srodek);
	sortowanie_scalanie<T>(tab, srodek+1, koniec);

	scalanie<T>(tab, poczatek, srodek, koniec);
}

int main()
{
	srand(time(NULL));

	int tab[N];

	for(int i = 0; i < N; i++)
	{
		//tab[i] = 100-i;
		tab[i] = rand()%101;
	}

	for(int i = 0; i < N; i++)
	{
		cout << tab[i] << endl;
	}

	sortowanie_scalanie<int>(tab, 0, N-1);

	cout << endl << "po: " << endl;

	for(int i = 0; i < N; i++)
	{
		cout << tab[i] << endl;
	}

	cout << "KONIEC" << endl;
	system("pause");
	return 0;
}