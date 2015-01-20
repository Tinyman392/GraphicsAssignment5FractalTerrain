#include "frac.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <random>
using namespace std;

const int matSize = 1000;

default_random_engine generator;
normal_distribution<float> distribution;

int n, s;
float D, sigma;

float X[matSize][matSize];
float maxlevel;
float H;
bool addition = true;
int seed;
float delta;
float gWidth;

int i, N, stage;
int x, y, d;

vector<coord> color;
vector<float> colInd;

void init(int n1, float D1, int s1, float sigma1)
{	
	n = n1;
	D = D1;
	s = s1;
	sigma = sigma1;
	
	maxlevel = n;
	
	H = 3 - D;
	seed = s;
	delta = sigma;
	//N = n;
	
	default_random_engine gen(seed);
	normal_distribution<float> dist(0.0, 1.0);
	
	generator = gen;
	distribution = dist;
	
	for(int i = 0; i < 5; i++)
	{
		colInd.push_back(0);
		coord c;
		color.push_back(c);
	}
	
	colInd[0] = -50;
	colInd[1] = -1;
	colInd[2] = 1;
	colInd[3] = 3;
	colInd[4] = 50;
	colInd[5] = 1000;
	
	color[0].p[0] = 0.00; color[0].p[1] = 0.42; color[0].p[2] = 1.00;
	color[1].p[0] = 0.00; color[1].p[1] = 0.42; color[1].p[2] = 1.00;
	color[2].p[0] = 0.94; color[2].p[1] = 0.87; color[2].p[2] = 0.44;
	color[3].p[0] = 0.00; color[3].p[1] = 0.64; color[3].p[2] = 0.09;
	color[4].p[0] = 1.00; color[4].p[1] = 1.00; color[4].p[2] = 1.00;
	color[5].p[0] = 1.00; color[5].p[1] = 1.00; color[5].p[2] = 1.00;
}

float f3(float delta, float x0, float x1, float x2)
{
	float f = (x0 + x1 + x2)/3 + delta*Gauss(0, 1);
	return f;
}

float f4(float delta, float x0, float x1, float x2, float x3)
{
	float f = (x0 + x1 + x2 + x3)/4 + delta*Gauss(0, 1);
	return f;
}

float Gauss(float m, float s)
{	
	return distribution(generator);
	/*
	float U1, U2, W, mult, X1, X2;
	
	do
	{
		U1 = -1 + (float) rand()/RAND_MAX * 2;
		U2 = -1 + (float) rand()/RAND_MAX * 2;
		
		W = pow(U1, 2) + pow(U2, 2);
	}while(W >= 1 || W == 0);
	
	mult = sqrt(-2*log(W) / W);
	X1 = U1 * mult;
	X2 = U2 * mult;
	
	return -1*(m + s * X1);
	*/
}

void fractal()
{	
	int D;
	int y0;	
	//srand(seed);
	
	N = pow(2, maxlevel);
	gWidth = 100.0 / N;
	
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= N; j++)
		{
			X[i][j] = 0;
		}
	}
	
	/* set initial random values */
	delta = sigma;
	X[0][0] = delta * Gauss(0, 1);
	X[0][N] = delta * Gauss(0, 1);
	X[N][0] = delta * Gauss(0, 1);
	X[N][N] = delta * Gauss(0, 1);
	D = N;
	d = N/2.0;
	
	for(int stage = 1; stage <= maxlevel; stage++)
	{
		delta = delta*pow(0.5, 0.5*H);
		
		for(int x = d; x <= N-d; x += D)
		{
			for(int y = d; y <= N-d; y += D)
			{
				X[x][y] = f4(delta, X[x+d][y+d], X[x+d][y-d], 
							 X[x-d][y+d], X[x-d][y-d]);
			}
		}
		
		if(addition)
		{
			for(int x = 0; x <= N; x+= D)
			{
				for(int y = 0; y <= N; y+= D)
				{
					X[x][y] = X[x][y] + delta*Gauss(0, 1);
				}
			}
		}
		
		delta = delta*pow(0.5, 0.5*H);
		
		for(int x = d; x <= N-d; x += D)
		{
			X[x][0] = f3(delta, X[x+d][0], X[x-d][0], X[x][d]);
			X[x][N] = f3(delta, X[x+d][N], X[x-d][N], X[x][N-d]);
			X[0][x] = f3(delta, X[0][x+d], X[0][x-d], X[d][x]);
			X[N][x] = f3(delta, X[N][x+d], X[N][x-d], X[N-d][x]);
		}
		
		for(int x = d; x <= N-d; x += D)
		{
			for(int y = D; y <= N-d; y += D)
			{
				X[x][y] = f4(delta, X[x][y+d], X[x][y-d], 
							 X[x+d][y], X[x-d][y]);
			}
		}
		
		for(int x = D; x <= N-d; x += D)
		{
			for(int y = d; y <= N-d; y += D)
			{
				X[x][y] = f4(delta, X[x][y+d], X[x][y-d],
							 X[x+d][y], X[x-d][y]);
			}
		}
		
		if(addition)
		{
			for(int x = 0; x <= N; x += D)
			{
				for(int y = 0; y <= N; y += D)
				{
					X[x][y] += delta * Gauss(0, 1);
				}
			}
			
			for(int x = d; x <= N-d; x += D)
			{
				for(int y = d; y <= N-d; y += D)
				{
					X[x][y] += delta * Gauss(0, 1);
				}
			}
		}
		
		D /= 2.0;
		d /= 2.0;
	}
}



void printPoints()
{
	//cerr << "N =      " << N << endl;
	//cerr << "gWidth = " << gWidth << endl;
	for(int x = 0; x <= N; x++)
	{
		for(int y = 0; y <= N; y++)
		{
			cerr << fixed << setprecision(3) << setw(7) << X[x][y];
		}
		cerr << endl;
	}
}

void printPoly(bool col)
{
	int nVerts = (N+1)*(N+1);
	int nFaces = (N)*(N) * 2;
	
	if(col)
		cout << "PolySet \"PC\"\n";
	else
		cout << "PolySet \"P\"\n";
	
	cout << nVerts << " " << nFaces << endl;

	for(int i = 0; i <= N; i++)
	{
		float x = gWidth * i;
		for(int j = 0; j <= N; j++)
		{
			float y = gWidth * j;
			
			cout << x << " " << y << " " << X[i][j] << " ";
			
			if(col)
			{
				coord c = calcCol(X[i][j]);
				for(int k = 0; k < 3; k++)
					cout << c.p[k] << " ";
			}
			
			cout << endl;
		}
	}
	
	for(int i = 0; i < (N+1)*(N);)
	{
		cout << i << " " << i+1 << " " << i+N+1 << " -1\n";
		cout << i+1 << " " << i+N+2 << " " << i+N+1 << " -1\n";
		
		i++;
		if((i+1) % (N+1) == 0)
			i++;
	}
}

coord calcCol(float z)
{
	int ind[2];
	ind[0] = 0;
	
	for(int i = 0; i < 5; i++)
	{
		if(z <= colInd[i])
		{
			ind[1] = i;
			break;
		}
		ind[0] = i;
	}
	
	float d1 = abs(z - colInd[ind[0]]);
	float d2 = abs(z - colInd[ind[1]]);
	float t = d1 / (d1 + d2);
	
	return interpolate(color[ind[0]], color[ind[1]], t);
}

coord interpolate(coord a, coord b, float t)
{
	coord c;
	for(int i = 0; i < 3; i++)
	{
		c.p[i] = a.p[i] + t*(b.p[i] - a.p[i]);
	}
	
	return c;
}