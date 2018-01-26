#pragma once
class numer
{
public:
	float liczba;
	char nazwa[20];

	numer();
	numer(int);
	~numer();
	
	operator int();
	operator float();
};

