#pragma once
#include "Punkt1D.h"
class Punkt2D :
	private Punkt1D
{
private:
	int y_priv;
protected:
	int y_prot;
public:
	int y_pub;
	Punkt1D::x_pub;

	Punkt2D();
	Punkt2D(int);
	Punkt2D(int,int);
	~Punkt2D();
};

