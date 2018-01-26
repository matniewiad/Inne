#include <iostream>
using namespace std;

void fun_ref(int &wart);
void fun_wsk(int *wart);
void pokazywacz(const int *wart);
void zmieniacz(int *wart);

int main()
{
	int a = 5, b = 5;
	cout << "przez referencje: " << endl;
	fun_ref(a);
	cout << "przez wskaznik: " << endl;
	fun_wsk(&b);

	cout << endl << "po funkcji: " << endl <<"a: " << a << endl << "b: " << b << endl;


	cout << endl << endl << "dziala" << endl;
	system("pause");
	return 0;
}

// 1 funkcja - przesylanie wartosci do funkcji przez referencje
void fun_ref(int &wart)
{
	cout << "wart: " << wart << endl;
	wart += 5;
	cout << "wart2: " << wart << endl;
}

// 2 funckja - przesylanie wartosci do funkcji przez wskaznik
void fun_wsk(int *wart)
{
	cout << "wart: " << *wart << endl;
	*wart += 5;
	cout << "wart2: " << *wart << endl;
}

// 3 - const int - brak mozliwosci zmiany wartosci wskaznika
void pokazywacz(const int *wart)
{
	cout << "wart: " << *wart << endl;
	//*wart += 5;           //expression must be a modifiable lvalue
	cout << "wart2: " << *wart << endl;
}
// 4 - tu wolno zmieniac wartosc wskaznika
void zmieniacz(int *wart)
{
	cout << "wart: " << *wart << endl;
	*wart += 5;
	cout << "wart2: " << *wart << endl;
}
