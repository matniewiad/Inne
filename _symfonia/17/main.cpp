#include <iostream>
#include <string>
using namespace std;
#include "Prostokat.h"
#include "Punkt.h"

void sedzia(Punkt&, Prostokat&);

int main()
{
	Prostokat p1;
	Punkt pkt1;

	p1.wczytaj();
	pkt1.wczytaj();

	sedzia(pkt1, p1);


	cout << endl << endl << "dziala" << endl;
	system("pause");
	return 0;
}


//*****************************************************
void sedzia(Punkt& pkt, Prostokat& p)
{
	bool czy_x = false;
	bool czy_y = false;

	//sprawdzenie osi x
	if (pkt.x >= p.x_w && pkt.x <= p.x_w+p.szerokosc)
	{
		czy_x = true;
	}

	//sprawdzenie osi y
	if (pkt.y >= p.y_w && pkt.y <= p.y_w + p.wysokosc)
	{
		czy_y = true;
	}

	//ostateczne sprawdzenie
	if (czy_x == true && czy_y == true)
	{
		cout << "punkt " << pkt.nazwa_punktu << " nalezy do prostokata " << p.nazwa_prostokata << endl;
	}
	else cout << "punkt " << pkt.nazwa_punktu << " nie nalezy do prostokata " << p.nazwa_prostokata << endl;
	
}