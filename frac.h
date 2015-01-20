#ifndef FRAC_H
#define FRAC_H

struct coord
{
	float p[3];
};

void init(int n1, float D1, int s1, float sigma1);
float f3(float delta, float x0, float x1, float x2);
float f4(float delta, float x0, float x1, float x2, float x3);
float Gauss(float m, float s);
void fractal();
void printPoly(bool col);
coord calcCol(float z);
coord interpolate(coord a, coord b, float t);

void printPoints();

#endif