#pragma once
class Punkt1D
{
private:
	int x_priv;
protected:
	int x_prot;
public:
	int x_pub;
	
	Punkt1D();
	Punkt1D(int);
	~Punkt1D();
};

