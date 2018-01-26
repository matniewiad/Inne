#include <iostream>
using namespace std;
#include <stack>
#include <queue>
#include "Punkt.h"
#include "PorownajPunkt.h"

struct PorownajPunkt  //komparator do typu danych zdefiniowanego przez uzytkownika
{
	bool operator()(Punkt const & p1, Punkt const & p2)
	{
		return p1.x < p2.x;
	}
};

//gdy dane sa private -> getery (analogicznie dla klasy)
//struct PorownajPunkt  //komparator do typu danych zdefiniowanego przez uzytkownika
//{
//	bool operator()(Punkt & p1, Punkt & p2)
//	{
//		float t1 = p1.get_x();
//		float t2 = p2.get_y();
//		return t1 < t2;
//	}
//};

int main()
{
	Punkt pkt1("aaa",1,1), pkt2("bbb",2,2), pkt3("ccc",3,3);

	//******STOS**********
	//stack <Punkt> stos;
	//stos.push(pkt1);
	//stos.push(pkt2);

	//stos.top().wyswietl();


	//******KOLEJKA******
	//queue <Punkt> kolejka;
	//kolejka.push(pkt2);
	//kolejka.push(pkt3);

	//kolejka.front().wyswietl();
	//kolejka.pop();
	//kolejka.front().wyswietl();



	//******KOLEJKA PRIORYTETOWA******
	//priority_queue < Punkt, vector<Punkt>, CPorownajPunkt> kolejka_p;

	//kolejka_p.push(pkt2);
	//kolejka_p.push(pkt3);
	//kolejka_p.push(pkt1);

	//Punkt temp;
	//temp = kolejka_p.top();
	//temp.wyswietl();

	
	




	cout << endl << endl << "dziala" << endl;
	system("pause");
	return 0;
}