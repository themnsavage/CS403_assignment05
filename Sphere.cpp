using namespace std;

#include "Sphere.h";

//constructor
Sphere::Sphere(string& name, double radius)
    :Shape(name)
{
    this->radius = radius;
}
// get the surface area
double Sphere::getArea() const{
    return 4*PI*(this->radius*this->radius);
}
// get the volume
double Sphere::getVolume() const{
    return (4/3)*PI*(this->radius*this->radius*this->radius);
}
// test if the conditions are statisfied
bool Sphere::test(const vector<string>& cond) const{}
// get all the info in a string
string Sphere::getInfo() const{}
