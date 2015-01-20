#include "frac.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

bool col = true;

void outUsage();
int setVars(int argc, char* argv[], int &n, int &s, float &D, float &sigma);
void outputVars(int n, int s, float D, float sigma);

int main(int argc, char* argv[])
{
	int n, s;
	float D, sigma;
	
	int error = setVars(argc, argv, n, s, D, sigma);
	if(error == -1)
		return -1;
	
	init(n, D, s, sigma);
	fractal();
	//printPoints();
	printPoly(col);
}

void outUsage()
{
	cerr << "Usage Information\n";
	cerr << "----------------------------------------\n";
	cerr << "frac <n> <D> <s> <sigma>\n";
	cerr << "<n> - gride size = (2^n + 1) x (2^n + 1)\n";
	cerr << "<D> - fractal dimension inside the bound\n";
	cerr << "      [2.0, 3.0]\n";
	cerr << "<s> - number seed\n";
	cerr << "<sigma> - initial standard deviation\n";
}

int setVars(int argc, char* argv[], int &n, int &s, float &D, float &sigma)
{
	if(argc != 5)
	{
		outUsage();
		return -1;
	}
	else
	{
		n = atoi(argv[1]);
		D = atof(argv[2]);
		s = atoi(argv[3]);
		sigma = atof(argv[4]);
	}
	
	//outputVars(n, s, D, sigma);
	
	return 0;
}

void outputVars(int n, int s, float D, float sigma)
{
	cerr << "n     " << n << endl;
	cerr << "D     " << D << endl;
	cerr << "s     " << s << endl;
	cerr << "sigma " << sigma << endl;
}

