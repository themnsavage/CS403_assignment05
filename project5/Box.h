#ifndef _Box_H_
#define _Box_H_

#include "Shape.h"
#include <cmath>
using namespace std;

class Box: public Shape{
    public:
        Box(string& name, double l, double w, double h);
        double getArea() const; // get the surface area          
        double getVolume() const; // get the volume          
        bool test(const vector<string>& cond) const; // test if the conditions are statisfied
        string getInfo() const; // get all the info in a string
        virtual bool isConditionStatementTrue(string name, string op, string value)const;
    private:
        double length, width, height;
        string type = "box";
};
#endif