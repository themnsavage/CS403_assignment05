using namespace std;

#include "Box.h";

//constructor
Box::Box(string& name, double l, double w, double h)
    :Shape(name)
{
    this->length = l;
    this->width = w;
    this->height = h;
};

// get the surface area
double Box::getArea() const{
    return 2 * (this->length*this->width + this->length*this->height + this->width*this->height);
}
// get the volume
double Box::getVolume() const{
    return this->length*this->height*this->width;
}
// test if the conditions are statisfied
bool Box::test(const vector<string>& cond) const{}
// get all the info in a string
string Box::getInfo() const{}
