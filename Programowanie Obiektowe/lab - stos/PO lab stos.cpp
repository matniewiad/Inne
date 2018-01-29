#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Stos.h"
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	//stos stringow!
	Stos ob1;

	int ile;
	cout << "ile slow pobrac?" << endl;
	cin >> ile;
	for (int i = 0 ; i<ile ; i++)
	{
		ob1.push();
	}
	cout << "wyswietlanie slow od konca" << endl;
	
	for (int i = 0 ; i<ile ; i++)
	{
		ob1.pop();
	}

    system("pause");
    return 0;
}
