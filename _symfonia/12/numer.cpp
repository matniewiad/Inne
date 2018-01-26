#include "numer.h"
#include <iostream>
using namespace std;



numer::numer()
{
}


//konstruktor konwertujacy
numer::numer(int a)
{
	liczba = a;
	cout << "konwersja!" << endl;
}


numer::~numer()
{
}


numer::operator float()
{
	return (float)liczba;
}


numer::operator int()
{
	return (int)liczba;
}