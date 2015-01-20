#include <iostream>
#include <stdlib.h>
using namespace std;

float brightness = 4000;

const char * header [] = 
{
    "Display \"Starry Night\"  \"Screen\"  \"rgbdouble\"",
    "Format 640 480",
    "CameraAt 50 50 20", 
    "CameraUp 0 0 1",
    "CameraEye -10 100 10",
    "CameraFOV 60" 
};

int nlines = sizeof(header) / sizeof(char *);

int main (int argc, char * argv[])
{
  	// Print out header
  	
  	for (int i = 0; i < nlines; i++)
	cout << header[i] << endl;
	
	//light
	//cout << "Background 0.125 0.65 1.0\n";
	cout << "Background 0.0 0.0 0.0\n";
	cout << "MapLoad \"moon.pgm\" \"moon\"";	
	cout << "WorldBegin\n";
	
	cout << "XformPush\n";
	
	cout << "Translate 150 -150 20\n";
	//light
	//cout << "Color 1.0 1.0 0.5\n";
	cout << "Color 1.0 1.0 0.85\n";
	cout << "Surface \"painted plastic\"";
	cout << "Map \"texture\" \"moon\"";
	cout << "Sphere 40 -40 40 360\n";
	cout << "Map \"texture\" \"none\"";
	
	cout << "XformPop\n";
	//cout << "PointLight 0 100 40 1 1 1 " << brightness << endl;
	//cout << "PointLight 100 100 40 1 1 1 " << brightness << endl;
	//cout << "PointLight 100 0 40 1 1 1 " << brightness << endl;
	//cout << "PointLight 0 0 40 1 1 1 " << brightness << "\n";
	cout << "PointLight 150 -150 20 1 1 1 " << brightness << "\n";
	
	for(int i = 0; i < 20000; i++)
	{
		float size = (rand() % 750/1000.0);
		float x = rand() % 300000/100.0 - 50;
		float y = rand() % 300000/100.0 - 150;
		float z = rand() % 10000/100.0 + 50;
		
		cout << "XformPush\n";
		cout << "Color 1.0 1.0 1.0\n";
		cout << "Translate " << x << " " << y << " " << z << endl;
		cout << "Sphere " << size << " " << size*-1 << " " << size << " 360\n";
		
		cout << "XformPop\n";
	}
	
	cout << "Ks 0.82\n";
	cout << "Kd 0.82\n";
	cout << "Ka 0.18\n";
	
	string s;
	
	while(getline(cin, s, '\0'))
	{
		
		cout << s;
	}	
	
	cout << "\nWorldEnd\n";
}