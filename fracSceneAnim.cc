#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

float brightness = 4000;
int numFrames = 10;

const char * header [] = 
{
    "Display \"Starry Night\"  \"Screen\"  \"rgbdouble\"",
    "Format 640 480",
    "CameraAt 50 50 20", 
    "CameraUp 0 0 1",
    "CameraEye -10 100 10",
    "CameraFOV 60" 
};

struct coord
{
	float p[3];
};

struct star
{
	float pos[3];
	float size;
	float col[3];

	void draw();
};

struct moon
{
	float pos[3];
};

struct sun
{
	float pos[3];
};

vector<star> stars;
sun suns;
moon moons;

void draw(star s)
{
	cout << "XformPush\n";
	cout << "Color ";
	for(int i = 0; i < 3; i++)
	{
		cout << s.col[i] << " ";
	}
	cout << endl;
	cout << "Translate ";
	for(int i = 0; i < 3; i++)
	{
		cout << s.pos[i] << " ";
	}
	cout << endl;
	cout << "Sphere " << s.size << " " << s.size*-1 << " " << s.size << " 360\n";
	
	cout << "XformPop\n";
}

void draw(moon m)
{
	cout << "XformPush\n";
	cout << "Color 1.0 1.0 0.85\n";
	cout << "Translate ";
	for(int i = 0; i < 3; i++)
	{
		cout << m.pos[i] << " ";
	}
	cout << endl;
	cout << "Sphere 40 -40 40 360\n";
	
	cout << "XformPop\n";

	cout << "PointLight ";
	for (int i = 0; i < 3; i++)
	{
		cout << m.pos[i] << " ";
	}
	cout << " 1 1 1 " << brightness << "\n";
}

void draw(sun s)
{
	cout << "XformPush\n";
	cout << "Color 1.0 1.0 0.5\n";
	cout << "Translate ";
	for(int i = 0; i < 3; i++)
	{
		cout << s.pos[i] << " ";
	}
	cout << endl;
	cout << "Sphere 40 -40 40 360\n";
	
	cout << "XformPop\n";

	cout << "PointLight ";
	for (int i = 0; i < 3; i++)
	{
		cout << s.pos[i] << " ";
	}
	cout << " 1 1 1 " << brightness << "\n";
}

void advanceFrame(vector<star> stars, sun suns, moon moons, int frame)
{
	cout << "XformPush\n";
	cout << "Rotate \"X\" 45";
	cout << "Rotate \"Z\" " << 0.1*frame;

	draw(suns);
	draw(moons);

	cout << "XformPop\n";

	cout << "XformPush\n";
	cout << "Rotate \"X\" 45";
	cout << "Rotate \"Z\" " << 0.05*frame;

	for (int i = 0; i < stars.size(); i ++)
	{
		draw(stars[i]);
	}

	cout << "XformPop\n";
}

int nlines = sizeof(header) / sizeof(char *);

int main (int argc, char * argv[])
{
  	// Print out header
  	
  	for (int i = 0; i < nlines; i++)
	cout << header[i] << endl;
	
	//light
	//cout << "Background 0.125 0.65 1.0\n";

	string land,c;
	land = "";
	while(getline(cin, c, '\0'))
	{
		land += c;
	}

	for (int i = 0; i < 20000; i ++)
	{
		star s;
		s.size = (rand() % 750/1000.0);
		s.pos[0] = rand() % 300000/100.0 - 50;
		s.pos[1] = rand() % 300000/100.0 - 150;
		s.pos[2] = rand() % 10000/100.0 + 50;

		stars.push_back(s);
	}

	suns.pos[0] = -150; suns.pos[1] = 150; suns.pos[2] = -20;
	moons.pos[0] = 150; moons.pos[1] = -150; moons.pos[2] = 20;

	cout << "Background 0.0 0.0 0.0\n";
	
	for (int frame = 0; frame < numFrames; frame++)
	{
		cout << "WorldBegin\n";
		
		advanceFrame(stars, suns, moons, frame);
		
		cout << "Ks 0.82\n";
		cout << "Kd 0.82\n";
		cout << "Ka 0.18\n";
		
		cout << land;
		
		cout << "\nWorldEnd\n";
	}

	return 0;
}
