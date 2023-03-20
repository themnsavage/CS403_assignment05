#ifndef _Cylinder_H_
#define _Cylinder_H_

#include "Shape.h"
#include <cmath>
using namespace std;

class Cylinder: public Shape{
    public:
        Cylinder(string, double, double);
        double getArea() const; // get the surface area          
        double getVolume() const; // get the volume          
        bool test(const vector<string>& cond) const; // test if the conditions are statisfied
        string getInfo() const; // get all the info in a string
        virtual bool isConditionStatementTrue(string name, string op, string value) const;
    private:
        double radius, height;
        string type = "cylinder";    
};
#endif