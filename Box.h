#include "Shape.h"
using namespace std;

class Box: public Shape{
    Box(string& name, double l, double w, double h);
    double getArea() const = 0; // get the surface area          
    double getVolume() const = 0; // get the volume          
    bool test(const vector<string>& cond) const = 0; // test if the conditions are statisfied
    string getInfo() const = 0; // get all the info in a string
    
    private:
        double length, width, height;
};