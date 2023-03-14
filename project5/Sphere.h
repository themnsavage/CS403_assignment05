#include "Shape.h"
using namespace std;

class Sphere: public Shape{
    Sphere(string& name, double radius);
    double getArea() override; // get the surface area          
    double getVolume() override; // get the volume          
    bool test(const vector<string>& cond) override; // test if the conditions are statisfied
    string getInfo() override; // get all the info in a string
    bool isConditionStatementTrue(string name, string op, string value);
    private:
        double radius;
        string name;
};