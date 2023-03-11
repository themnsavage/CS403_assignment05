using namespace std;

#include "Torus.h";

//constructor
Torus::Torus(string& name, double radius1, double radius2)
    :Shape(name)
{
    if(radius1 < radius2){
        this->smallRadius = radius1;
        this->bigRadius = radius2;
    }
    else{
        this->smallRadius = radius2;
        this->bigRadius = radius1;
    }
}
// get the surface area
double Torus::getArea() const{}           
// get the volume
double Torus::getVolume() const{}
// test if the conditions are statisfied
bool Torus::test(const vector<string>& cond) const{}
// get all the info in a string
string Torus::getInfo() const{}
