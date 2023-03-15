#ifndef _Cylinder_H_
#define _Cylinder_H_

#include "Shape.h"
using namespace std;

class Cylinder: public Shape{
    public:
        Cylinder(string, double, double);
        double getArea() override; // get the surface area          
        double getVolume() override; // get the volume          
        bool test(const vector<string>& cond) override; // test if the conditions are statisfied
        string getInfo() override; // get all the info in a string
        bool isConditionStatementTrue(string name, string op, string value);
    private:
        double radius, height;    
};
#endif