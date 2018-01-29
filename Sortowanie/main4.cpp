#include <iostream>
#include <ctime>
using namespace std;
#define N 100

template<typename T>
void sortowanie_szybkie(T tab[], int poczatek, int koniec)
{
	int i = poczatek;
	int j = koniec;
	int x = poczatek; //indeks elementu osiowego

	while(i <= j)
	{
		while(tab[i] < tab[x]) // po lewej stronie tablicy szukamy elementu wiekszego od elementu osiowego
		{
			i++;
		}
		while(tab[j] > tab[x]) // od konca tablicy szukamy elementu mniejszego od elementu osiowego
		{
			j--;
		}
		
		if(i <= j)
		{
			swap(tab[i], tab[j]);
			i++;
			j--;
		}
	}
	// rekurencje
	if(poczatek < j)
	{
		sortowanie_szybkie(tab, poczatek, j);
	}
	if(koniec > i)
	{
		sortowanie_szybkie(tab, i, koniec);
	}
}

int main()
{
	//srand(time(NULL));
	int tab[N];
	double tab2[N];

	for(int i = 0; i < N; i++)
	{
		//tab2[i] = 100-i;
		tab2[i] = rand()%101;
	}

	for(int i = 0; i < N; i++)
	{
		cout << tab2[i] << endl;
	}

	sortowanie_szybkie<double>(tab2, 0, N-1);

	cout << endl << "po sortowaniu:" << endl;

	for(int i = 0; i < N; i++)
	{
		cout << tab2[i] << endl;
	}

	system("pause");
	return 0;
}