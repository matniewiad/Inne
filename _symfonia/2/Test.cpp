#include "Test.h"
#include <iostream>
using namespace std;



Test::Test()
{
	c = 5;
	a = c + 1;
	b = a + 1;
	cout << "utwrzono obiekt klasy Test" << endl;
}


Test::~Test()
{
	cout << "usunieto obiekt klasy Test" << endl;
}
