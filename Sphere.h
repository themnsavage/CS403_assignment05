#include "Shape.h"
using namespace std;

class Sphere: public Shape{
    Sphere(string& name, double radius);
    double getArea() const = 0; // get the surface area          
    double getVolume() const = 0; // get the volume          
    bool test(const vector<string>& cond) const = 0; // test if the conditions are statisfied
    string getInfo() const = 0; // get all the info in a string
    virtual bool isConditionStatementTrue(string name, string op, string value) const = 0;
    private:
        double radius;
};