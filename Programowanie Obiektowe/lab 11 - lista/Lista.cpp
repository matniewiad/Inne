#include "StdAfx.h"
#include "Lista.h"


Lista::Lista(void)
{
	pierwszy = 0;
}


Lista::~Lista(void)
{
}

void Lista::push(int liczba)
{
	Element *nowy = new Element;

	nowy->elem = liczba;
	
	if(pierwszy==0) //sprawdzamy czy pierwszy element listy
	{
		pierwszy = nowy;
	}
	else //jesli nie idziemy na koniec
	{
		Element *temp = pierwszy;
		while(temp->nastepny)
		{
			temp = temp->nastepny; //szukamy konca listy
		}
		temp->nastepny = nowy;   //"stary" ostani wskazuje na "nowy" ostatni element
		nowy->nastepny = 0;		 //"nowy" ostatni nie wskazuje na nic
	}
}

void Lista::wyswietl()
{
	Element *temp = pierwszy;
	while(temp)
	{
		cout << "element: " << temp->elem << endl;
		temp = temp->nastepny;
	}
}

void Lista::pop(int ktory)
{
	if(ktory==1)
	{
		Element *temp = pierwszy;
		pierwszy = temp->nastepny;
	}
	if(ktory>=2)
	{
		int i = 1;
		Element *temp = pierwszy;
		while(temp)
		{
			if((i+1)==ktory)
				break;
			temp = temp->nastepny;
			i++;
		}
		if(temp->nastepny->nastepny==0) //sprawdzamy czy nie jestesmy na koncu listy
			temp->nastepny=0;
		else
			temp->nastepny=temp->nastepny->nastepny;
	}
}