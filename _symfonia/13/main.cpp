#include <iostream>
using namespace std;
#include "zespol.h"

int main()
{
	zespol A;
	A.wprowadz();
	A.wyswietl();
	
	zespol B;
	B.wprowadz();
	B.wyswietl();

	zespol C;
	C.wyswietl();

	C = A * B;
	C.wyswietl();


	cout << endl << endl << "dziala" << endl;
	system("pause");
	return 0;
}