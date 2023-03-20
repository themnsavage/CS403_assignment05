#ifndef _Torus_H_
#define _Torus_H_

#include "Shape.h"
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;

class Torus: public Shape{
    public:
        Torus(string name, double radius1, double radius2);
        double getArea() const; // get the surface area          
        double getVolume() const; // get the volume          
        bool test(const vector<string>& cond) const; // test if the conditions are statisfied
        string getInfo() const; // get all the info in a string
        virtual bool isConditionStatementTrue(string name, string op, string value) const;
    private:
        double bigRadius, smallRadius;
        string type = "torus";
};
#endif