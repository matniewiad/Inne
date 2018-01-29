// PO lista lab11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Lista.h"
#include "Element.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Lista *baza = new Lista; //nowa lista
	baza->push(1);
	baza->push(2);
	baza->push(3);	
	baza->push(4);
	baza->push(5);
	cout <<"przed usunieciem" << endl;
	baza->wyswietl();
	baza->pop(3);
	cout << "po usunieciu" << endl;
	baza->wyswietl();

	delete(baza);
	system("pause");
	return 0;
}

