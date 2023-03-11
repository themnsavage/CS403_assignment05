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
double Cylinder::getArea() const{
    return 2*PI * this->radius*this->height + 2*PI * (this->radius * this->radius);
}
// get the volume
double Cylinder::getVolume() const{
    return PI * (this->radius*this->radius) * this->height;
}
// test if the conditions are statisfied
bool Cylinder::test(const vector<string>& cond) const{}
// get all the info in a string
string Cylinder::getInfo() const{}
