Display "Checkers" "Screen" "rgbobject"

Format 960 480

Background 0 0 0.2

MapLoad "earth3.ppm" "dark"
MapLoad "moon.pgm"   "light"

CameraUp 0 0 1
CameraAt 16 16 0
CameraEye -20 -20 15
CameraFOV 20.0


ObjectBegin "DarkSquare"
XformPush
Color 0.3 0.3 0.1
Ka 0.3
Kd 1.0
Ks 0.0
Scale 2 2 0.1
Translate 0 0 -1
Cube 
XformPop
ObjectEnd

ObjectBegin "LightSquare"
XformPush
Color 0.5 0.6 0.2
Ka 0.3
Kd 1.0
Ks 0.0
Scale 2 2 0.1
Translate 0 0 -1
Cube
XformPop
ObjectEnd

ObjectBegin "SquareRow"
XformPush
Translate 2 2 0
ObjectInstance "DarkSquare"
Translate 4 0 0
ObjectInstance "LightSquare"
Translate 4 0 0
ObjectInstance "DarkSquare"
Translate 4 0 0
ObjectInstance "LightSquare"
Translate 4 0 0
ObjectInstance "DarkSquare"
Translate 4 0 0
ObjectInstance "LightSquare"
Translate 4 0 0
ObjectInstance "DarkSquare"
Translate 4 0 0
ObjectInstance "LightSquare"

Translate -28 4 0
ObjectInstance "LightSquare"
Translate 4 0 0
ObjectInstance "DarkSquare"
Translate 4 0 0
ObjectInstance "LightSquare"
Translate 4 0 0
ObjectInstance "DarkSquare"
Translate 4 0 0
ObjectInstance "LightSquare"
Translate 4 0 0
ObjectInstance "DarkSquare"
Translate 4 0 0
ObjectInstance "LightSquare"
Translate 4 0 0
ObjectInstance "DarkSquare"
XformPop

ObjectEnd


ObjectBegin "Checkerboard"
XformPush
ObjectInstance "SquareRow"
Translate 0 8 0
ObjectInstance "SquareRow"
Translate 0 8 0
ObjectInstance "SquareRow"
Translate 0 8 0
ObjectInstance "SquareRow"
XformPop
ObjectEnd

ObjectBegin "Dark Checker"
XformPush
Ka 0.3
Kd 0.8
Ks 0.2
Color 0.2 0.2 0.2
Rotate "Z" 150.0
Translate 0 0 1
Map "texture" "dark"
#OptionReal "MaxTextureLevel" 1
Sphere 1.0 -1.0 1.0 360.0
XformPop
ObjectEnd

ObjectBegin "Light Checker"
XformPush
Ka 0.3
Kd 1.0
Ks 0.0
Color 0.8 0.8 0.8
Rotate "Z" 80.0
Translate 0 0 1
Map "textue" "light"
#OptionReal "MaxTextureLevel" 1
Sphere 1.0 -1.0 1.0 360.0
XformPop
ObjectEnd

ObjectBegin "DarkCheckerRow"
XformPush
Translate 2 2 0
ObjectInstance "Dark Checker"
Translate 8 0 0 
ObjectInstance "Dark Checker"
Translate 8 0 0 
ObjectInstance "Dark Checker"
Translate 8 0 0 
ObjectInstance "Dark Checker"
XformPop
ObjectEnd

ObjectBegin "LightCheckerRow"
XformPush
Translate 2 2 0
ObjectInstance "Light Checker"
Translate 8 0 0 
ObjectInstance "Light Checker"
Translate 8 0 0 
ObjectInstance "Light Checker"
Translate 8 0 0 
ObjectInstance "Light Checker"
XformPop
ObjectEnd  

ObjectBegin "Scene"
XformPush
Surface "painted plastic"
Map "texture" "none"
ObjectInstance "Checkerboard"
XformPush
ObjectInstance "DarkCheckerRow"
Translate 4 4 0
ObjectInstance "DarkCheckerRow"
Translate -4 4 0
ObjectInstance "DarkCheckerRow"
Translate 4 12 0
ObjectInstance "LightCheckerRow"
Translate -4 4 0
ObjectInstance "LightCheckerRow"
Translate 4 4 0
ObjectInstance "LightCheckerRow"
XformPop
XformPop
ObjectEnd


FrameBegin 0
WorldBegin
Rotate "Z" 0
FarLight -1 0 -1 1.0 1.0 1.0 0.5
FarLight  1 1 -1 1.0 1.0 1.0 0.5

Surface "matte"
# A light bulb 
XformPush
Translate 16 16 16
Scale 0.2 0.2 0.2
Sphere -1 1 1 360
XformPop
PointLight 16 16 16 1.0 1.0 1.0 500.0

Surface "painted plastic"
Ka 0.05
Kd 0.9
Ks 0.2

Specular 1.0 1.0 1.0 20

#Some shadows

PointLight  2 2 1 1.0 1.0 1.0 -3
PointLight 10 2 1 1.0 1.0 1.0 -3
PointLight 18 2 1 1.0 1.0 1.0 -3
PointLight 26 2 1 1.0 1.0 1.0 -3
PointLight  6 6 1 1.0 1.0 1.0 -3
PointLight 14 6 1 1.0 1.0 1.0 -3
PointLight 22 6 1 1.0 1.0 1.0 -3
PointLight 30 6 1 1.0 1.0 1.0 -3
PointLight  2 10 1 1.0 1.0 1.0 -3
PointLight 10 10 1 1.0 1.0 1.0 -3
PointLight 18 10 1 1.0 1.0 1.0 -3
PointLight 26 10 1 1.0 1.0 1.0 -3
PointLight  6 22 1 1.0 1.0 1.0 -3
PointLight 14 22 1 1.0 1.0 1.0 -3
PointLight 22 22 1 1.0 1.0 1.0 -3
PointLight 30 22 1 1.0 1.0 1.0 -3
PointLight  2 26 1 1.0 1.0 1.0 -3
PointLight 10 26 1 1.0 1.0 1.0 -3
PointLight 18 26 1 1.0 1.0 1.0 -3
PointLight 26 26 1 1.0 1.0 1.0 -3
PointLight  6 30 1 1.0 1.0 1.0 -3
PointLight 14 30 1 1.0 1.0 1.0 -3
PointLight 22 30 1 1.0 1.0 1.0 -3
PointLight 30 30 1 1.0 1.0 1.0 -3

ObjectInstance "Scene"
WorldEnd
FrameEnd
