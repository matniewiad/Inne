#include <iostream>
using namespace std;
#include "numer.h"

void fun_float(float a);
void fun_int(int a);
void fun_kl(numer);

int main()
{
	numer A;
	numer B;

	A.liczba = 3.111;
	char tempA[] = "trzy";
	strcpy_s(A.nazwa, tempA);


	B.liczba = 5.125;
	char tempB[] = "piec";
	strcpy_s(B.nazwa, tempB);

	float a1=5.234;
	float b1=2.125;

	fun_float(a1);
	fun_int(b1);

	//z obiektami
	fun_float(A);
	fun_int(B);

	cout << endl << endl;
	int a = 10;
	fun_kl(A);
	fun_kl(a);


	cout << endl << endl << "dziala" << endl;
	system("pause");
	return 0;
}

void fun_float(float a)
{
	cout << "konwersja flaot: " << a << endl;
}

void fun_int(int a)
{
	cout << "konwersja int: " << a << endl;
}

void fun_kl(numer A)
{
	cout << "dziala funkcja z argumentem typu obiekt" << endl;
}