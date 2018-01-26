#include <iostream>
using namespace std;
#include "Test.h"

int main()
{
	Test a;
	cout << "dziala" << endl;

	/*a.a = 65;
	a.b = 2 * a.a;*/

	cout << "1: " << a.a << endl << "2: " << a.b << endl;

	cout << "tworze b operatorem new" << endl;
	Test *b = new Test;
	b->a = 0;
	cout << "1: " << b -> a << endl << "2: " << b -> b << endl;
	b->b = 4;
	cout << "kasuje b operatorem delete" << endl;
	delete b;

	//2 sposoby wywolywania destruktora
	//a.Test::~Test();
	//a.~Test();

	cout << endl << endl << "dziala" << endl;
	system("pause");
	return 0;
}