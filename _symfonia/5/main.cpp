#include <iostream>
using namespace std;

int main()
{
	int a = 5;
	int b = 15;
	int c = 45;
	int d = 55;

	int *wsk1 = &a;
	cout << "adres wskaznika 1: " << &wsk1 << endl << "wartosc wsk1: " << *wsk1 << endl << endl;
	//delete wsk1;	//BLAD

	int *wsk2;
	wsk2 = new int;
	wsk2 = &b;
	cout << "adres wskaznika 2: " << &wsk2 << endl << "wartosc wsk2: " << *wsk2 << endl << endl;
	//delete wsk2;	//BLAD

	int *wsk3;
	wsk3 = new int;
	*wsk3 = c;
	cout << "adres wskaznika 3: " << &wsk3 << endl << "wartosc wsk3: " << *wsk3 << endl << endl;
	delete wsk3;
	//cout << endl << "po usunieciu" << endl;
	//cout << "adres wskaznika 3: " << &wsk3 << endl << "wartosc wsk3: " << *wsk3 << endl;		//BLAD - wskaznik nie istnieje

	int *wsk4 = new int;
	cout << "przed zapisaniem czegos do wskaznika" << endl;
	cout << "adres wskaznika 4: " << &wsk4 << endl << "wartosc wsk4: " << *wsk4 << endl;
	*wsk4 = d;
	cout << "po zapisaniu czegos do wskaznika" << endl;
	cout << "adres wskaznika 4: " << &wsk4 << endl << "wartosc wsk4: " << *wsk4 << endl;
	delete wsk4;

	//nie mozna tak. Nie mozna deletowac czegos, co nie powstalo przez new, czegos co nie jest wskaznikiem (local variable wsk5 doesnt exist)
	/*int *wsk5;
	delete wsk5;*/

	//nie mozna wyluskac wskaznika o adresie NULL - blad
	//wsk = NULL;
	//cout << "wsk: " << *wsk << endl;

	cout << endl << endl << "dziala" << endl;
	system("pause");
	return 0;
}