using namespace std;

#include "Sphere.h";

//constructor
Sphere::Sphere(string& name, double radius)
    :Shape(name)
{
    this->radius = radius;
}
// get the surface area
double Sphere::getArea() const{}           
// get the volume
double Sphere::getVolume() const{}
// test if the conditions are statisfied
bool Sphere::test(const vector<string>& cond) const{}
// get all the info in a string
string Sphere::getInfo() const{}
