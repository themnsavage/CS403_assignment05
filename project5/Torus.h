#ifndef _Torus_H_
#define _Torus_H_

#include "Shape.h"
using namespace std;

class Torus: public Shape{
    public:
        Torus(string name, double radius1, double radius2);
        double getArea(); // get the surface area          
        double getVolume(); // get the volume          
        bool test(const vector<string>& cond); // test if the conditions are statisfied
        string getInfo(); // get all the info in a string
        bool isConditionStatementTrue(string name, string op, string value);
    private:
        double bigRadius, smallRadius;
};
#endif