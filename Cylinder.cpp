using namespace std;

#include "Cylinder.h";
//constructor
Cylinder::Cylinder(string& name, double radius, double height)
    :Shape(name)
{
    this->radius = radius;
    this->height = height;
}
// get the surface area
double Cylinder::getArea() const{}           
// get the volume
double Cylinder::getVolume() const{}
// test if the conditions are statisfied
bool Cylinder::test(const vector<string>& cond) const{}
// get all the info in a string
string Cylinder::getInfo() const{}
