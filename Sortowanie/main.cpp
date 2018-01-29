#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;
#define R 1000

template<typename T>
void zamien(T tab[], int i, int j)
{
	T temp;
	temp = tab[i];
	tab[i] = tab[j];
	tab[j] = temp;
}

template<typename T>
void sortowanie_kopcowe(T tab[], int N) // N - rozmiar
{
	int i;
	for(i = N/2 ; i > 0 ; i--)
	{
		napraw(tab-1, i, N);
	}
	for(i = N-1 ; i>0 ; i--)
	{
		//zamien(tab, 0, i);
		swap(tab[0], tab[i]);
		napraw(tab-1, 1, i);
	}
}

template<typename T>
void napraw(T tab[], int i, int N)
{
	int j;
	while(i <= N/2)
	{
		j = 2*i;
		if(j+1 <= N && tab[j+1] > tab[j])
		{
			j++;
		}
		if(tab[i] < tab[j])
		{
			//zamien(tab, i, j);
			swap(tab[i], tab[j]);
		}
		else
			break;
		i=j;
	}
}

template<typename T>
void wyswietl(T tab[], int N)
{
    for(int i = 0; i < N; i++)
    {
        cout << tab[i] << endl;
    }
}

template<typename T>
void czy_posortowana(T tab[], int N)
{
	cout << "sprawdzam, czy tablica jest posortowana prawidlowo" << endl;
    for( int i = 0 ; i < N-1 ; i++)
    {
        if(tab[i] > tab[i+1])
        {
            cout << "blad w linii:" << i+1 << endl;
        }
    }
    cout << "wszystko dobrze" << endl;
}

template<typename T>
void wypelnianie(T tab[], int N)
{
	//wszystko losowo
	for(int i = 0 ; i < N ; i++)
    {
        tab[i] = rand();
    }

	//czesc tablicy posortowana
    /*for(int i = 0 ; i < (N)/2 ; i++)
    {
        tab[i] = i;
    }
	for(int j = (N)/2 ; j < N ; j++)
	{
		tab[j] = rand()+N/2;
	}*/	
	
	//odwrotna kolejnosc
	/*for(int i = 0 ; i < R ; i++)
	{
		tab[i] = R-i;
	}*/
}


int main()
{
	srand(time(NULL));
	int tablica[R];

	//mierzenie czasu
	clock_t start, stop;

	/*wypelnianie<int>(tablica, R);
	//wyswietl<int>(tablica, R);
	start = clock();
	sortowanie_kopcowe<int>(tablica, R);
	stop = clock();
	long delta = (long)(stop - start);
	czy_posortowana<int>(tablica, R);
	//wyswietl<int>(tablica, R);*/
	
	long delta = 0;
	for (int i = 0 ; i < 100 ; i++)
	{
		wypelnianie<int>(tablica, R);
		start = clock();
		sortowanie_kopcowe<int>(tablica, R);
		stop = clock();
		delta = delta + (long)(stop - start);
	}
	czy_posortowana<int>(tablica, R);
	
	cout << endl << "czas wykonywania algorytmu: " << delta << endl;

	cout << "Koniec programu" << endl;
	system("pause");
	return 0;
}