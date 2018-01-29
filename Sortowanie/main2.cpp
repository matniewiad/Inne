#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;
#define N 100000  //rozmiar tablicy

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

template<typename T>
void wyswietl(T tab[], int rozmiar)
{
    for(int i = 0; i < rozmiar; i++)
    {
        cout << tab[i] << endl;
    }
}

template<typename T>
void czy_posortowana(T tab[], int rozmiar)
{
    for( int i = 0 ; i < rozmiar-1 ; i++)
    {
        if(tab[i] > tab[i+1])
        {
            cout << "blad w linii:" << i+1 << endl;
        }
    }
    cout << "wszystko dobrze" << endl;
}

template<typename T>
void wypelnianie(T tab[], int rozmiar)
{
    //wszystko losowo
	for(int i = 0 ; i < rozmiar ; i++)
    {
        tab[i] = rand();
    }

	//czesc tablicy posortowana
    /*for(int i = 0 ; i < (rozmiar)/2 ; i++)
    {
        tab[i] = i;
    }
	for(int j = (rozmiar)/2 ; j < rozmiar ; j++)
	{
		tab[j] = rand()+rozmiar/2;
	}*/	
	
	//odwrotna kolejnosc
	/*for(int i = 0 ; i < rozmiar ; i++)
	{
		tab[i] = i;
	}*/
}

int main()
{
    srand(time(NULL));
    int tab2[N];
   
    //mierzenie czasu
    clock_t start, stop;

	/*wypelnianie<int>(tab2, N);
    //wyswietl<int>(tab2, N);
    start = clock();
    sortowanie_szybkie<int>(tab2, 0, N-1);
    stop = clock();
    long delta = (long)(stop - start);
	czy_posortowana<int>(tab2, N);
	//wyswietl<int>(tab2, N);*/
    
    long delta = 0;
    for(int i = 0 ; i < 100 ; i++)
    {
        wypelnianie<int>(tab2, N);
		start = clock();
        sortowanie_szybkie<int>(tab2, 0, N-1);
		stop = clock();
		delta = delta + (long)(stop - start);
    }
	czy_posortowana<int>(tab2, N);

    cout << endl << "czas wykonywania: " << delta << endl;

	cout << "Koniec programu" << endl;
    system("pause");
    return 0;
}