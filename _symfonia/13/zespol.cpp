#include "zespol.h"
#include <iostream>
using namespace std;


zespol::zespol()
{
	Rz = 0;
	Im = 0;
}

zespol::zespol(float a, float b):Rz(a),Im(b)
{
}

zespol::~zespol()
{
}

void zespol::wprowadz(float A, float B)
{
	Rz = A;
	Im = B;
}

void zespol::wprowadz()
{
	cout << "podaj Rz: ";
	cin >> Rz;
	cout << "podaj Im: ";
	cin >> Im;
}

void zespol::wyswietl()
{
	cout << "(" << Rz << ", " << Im << "i)" << endl;
}

zespol zespol::operator+(zespol a)
{
	zespol temp;
	//cout << "dziala operator +" << endl;
	temp.Rz = this->Rz + a.Rz;
	temp.Im = this->Im + a.Im;
	return temp;
}

zespol zespol::operator-(zespol a)
{
	zespol temp;
	//cout << "dziala operator -" << endl;
	temp.Rz = this->Rz - a.Rz;
	temp.Im = this->Im - a.Im;
	return temp;
}

zespol zespol::operator++()
{
	//cout << "dziala operator preinkrementacji ++a" << endl;
	this->Rz = this->Rz + 1;		//zeby pokazac, ze mozna na 2 sposoby
	Im = Im + 1;					//raz jest wsk this-> a raz nie ma
	return *this;
}

zespol zespol::operator++(int)
{
	//cout << "dziala operator postinkrementacji a++" << endl;
	this->Rz = this->Rz + 1;
	Im = Im + 1;
	return *this;
}

zespol zespol::operator--()
{
	//cout << "dziala operator predekrementacji --a" << endl;
	this->Rz = this->Rz - 1;
	Im = Im - 1;
	return *this;
}

zespol zespol::operator--(int)
{
	//cout << "dziala operator postdekrementacji a--" << endl;
	this->Rz = this->Rz - 1;
	Im = Im - 1;
	return *this;
}

zespol zespol::operator*(zespol a)
{
	zespol temp;
	//cout << "dziala operator *" << endl;
	temp.Rz = (Rz*a.Rz)-(Im*a.Im);
	temp.Im = Rz*a.Im + Im*a.Rz;
	return temp;
}

