#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;

class Punkt
{

	
	public:
		int x;
		int y;
		
		Punkt(int a, int b)  // konstruktor z parametrami, wpisujemy wspolrzedne punktu
		{
			x = a;
			y = b;
		}
		
		Punkt(void)  // konstruktor bezparametrowy losujacy wspolrzedne punktu
		{
			srand(time(NULL));
			x = rand()%101-50;
			y = rand()%101-50;
		}
		
		void pokaz_punkt()
		{
			cout << "x: " << x <<"	y: " << y << endl;  
		}
};

class Okrag
{	
	public:
		Punkt srodek;
		double promien;
		
		Okrag(double a, int b, int c)  // konstruktor z parametrami, wpisujemy promien i wspolrzedne punktu
		{
			srodek.x = b;
			srodek.y = c;
			promien = a;
		}
		
		Okrag(void)  // konstruktor bezparametrowy losujacy promien
		{
			srand(time(NULL));
			promien = (rand()%2001-1000)/100;
		}
		void pokaz_okrag()
		{
			cout << "x: " << srodek.x << "	y: " << srodek.y << endl; 
			cout << "promien: " << promien << endl;
		}
};

int main(int argc, char** argv) {

// ad.1 Klasa Punkt, konstruktor z parametrami zadanymi przez uzytkownika

	cout << "zad.1 Klasa Punkt, konstruktor z parametrami zadanymi przez uzytkownika" << endl;
	int x1, y1;	
	cout << "podaj x i y dla punkt1" << endl;
   	cout << "x: ";
    cin >> x1;
   	cout << "y: ";
   	cin >> y1;		
   	Punkt punkt1(x1,y1);
	punkt1.pokaz_punkt();
	cout << endl;
		
// ad.2 Klasa Punkt, konstruktor bezparametrowy
	cout << "zad.2 Klasa Punkt, konstruktor bezparametrowy, punkt2:" << endl;
	Punkt punkt2;
	punkt2.pokaz_punkt();
	cout << endl;

	
// ad.3 Klasa Okrag, konstruktor z parametrami zadanymi przez uzytkownika
	cout << "zad.3" << endl;

	double r1;
	int o1, o2;
	cout << "podaj r dla okrag1" << endl;
	cout << "r: ";
	cin >> r1;
	cout << "podaj x dla okrag1" << endl;
	cout << "x: ";
	cin >> o1;
	cout << "podaj y dla okrag1" << endl;
	cout << "y: ";
	cin >> o2;
	Okrag okrag1(r1, o1, o2);
		
	okrag1.pokaz_okrag();
	cout << endl;
	
// ad.4 Klasa Okrag, konstruktor bezparametrowy
	cout << "zad.4 Klasa Okrag, konstruktor bezparametrowy, okrag2:" << endl;
	Okrag okrag2;
	
	okrag2.pokaz_okrag();
	cout << endl;
	
	

	return 0;
}
