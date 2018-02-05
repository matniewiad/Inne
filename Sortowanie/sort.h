//Algorytmy sortuj¹ce
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

//proste wyswietlanie wektora w jednej lini
template <typename T>
void show_vec(const std::vector<T>& vec)
{
	/**
	Wyswietl wektor poziomo
	**/
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(std::cout, " "));
	std::cout << std::endl;
}

//zamiana 2 obiektow miejscami
template <typename T>
void swap(T&a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

//sortowanie przez wstawianie - O(n^2)
template <typename T>
void InsertSort(std::vector<T>& tab)
{
	/**
	Sortowanie przez wstawianie
	Nalezy podaæ vector<type> o dowolnym typie przechowywanych wartosci,
	które daj¹ siê porównywaæ miêdzy sob¹ znakiem '<'
	**/
	int n = tab.size();
	for (int i = 0; i < n; i++)
	{
		int j = i;
		T temp = tab[j];
		while ((j > 0) && (tab[j - 1] > temp))
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = temp;
	}
}

//sortowanie bombelkowe - O(n^2)
template <typename T>
void BubbleSort(std::vector<T>& tab)
{
	/**
		Sortowanie bobmbelkowe
	**/
	int n = tab.size();
	for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
			if (tab[j] < tab[j - 1])
				swap(tab[j], tab[j - 1]);
	}
}

//sortowanie szybkie - Quicsort - O(N log N)
template <typename T>
void Quicksort(std::vector<T>& tab, int left, int right)
{
	/**
		Sortowanie szybkie - quciksort
		Nalezy podac vector do posortowania oraz jego skrajne indexy
	**/
	if (left < right)
	{
		int m = left;
		for (int i = left + 1; i <= right; i++)
			if (tab[i] < tab[left])
				swap(tab[++m], tab[i]);
		swap(tab[left], tab[m]);
		Quicksort(tab, left, m - 1);
		Quicksort(tab, m + 1, right);
	}
}

//sortowanie kopcowe - HeapSort - O(N log N)
template <typename T>
void MakeHeapGreatAgain(std::vector<T>& tab, int k, int n)
{
	/**
		Funkcja przywracajaca wlasciwosci kopca
		Funkcja pomocnicza dla sortowania przez kopcowanie
	**/
	T temp = tab[k - 1];
	while (k <= n / 2)
	{
		int i = 2 * k;
		if ((i < n) && (tab[i - 1] < tab[i]))
			i++;
		if (temp >= tab[i - 1])
			break;
		tab[k - 1] = tab[i - 1];
		k = i;
	}
	tab[k - 1] = temp;
}

template <typename T>
void HeapSort(std::vector<T>& tab)
{
	/**
		sortowanie przez kopcowanie - HeapSort
		wykorzystanie struktury danych typu kopiec/sterta
	**/
	int n = tab.size();
	for (int i = n / 2; i > 0; i--)
		MakeHeapGreatAgain(tab, i, n);
	do {
		swap(tab[0], tab[n - 1]);
		n--;
		MakeHeapGreatAgain(tab, 1, n);
	} while (n > 1);
}

//sortowanie przez scalanie - MergeSort - O(N log N)
template <typename T>
void MergeVectors(std::vector<T>& tab, int left, int right)
{
	/**
		Funckcja pomocnicza dla sortowania przez scalanie
		Funkcja scalajaca 2 polowy vectora tab w sposob posortowany
	**/
	int mid = (left + right) / 2;
	std::vector<T> tab2(tab.size());		//tablica pomocnicza
	int left1 = left;						//podtablica 1
	int right1 = mid;
	int left2 = mid + 1;					//podtablica 2
	int right2 = right;
	int i = left;

	while ((left1 <= right1) && (left2 <= right2))
		if (tab[left1] < tab[left2])
			tab2[i++] = tab[left1++];
		else
			tab2[i++] = tab[left2++];
	while (left1 <= right1)
		tab2[i++] = tab[left1++];
	while (left2 <= right2)
		tab2[i++] = tab[left2++];
	for (i = left; i <= right; i++)
		tab[i] = tab2[i];
}

template <typename T>
void MergeSort(std::vector<T> &tab, int left, int right)
{
	/**
		Sortowanie przez scelanie - MergeSort
	**/
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(tab, left, mid);
		MergeSort(tab, mid + 1, right);
		MergeVectors(tab, left, right);
	}
}





