#ifndef _Box_H_
#define _Box_H_

#include "Shape.h"
using namespace std;

class Box: public Shape{
    public:
        Box(string& name, double l, double w, double h);
        double getArea(); // get the surface area          
        double getVolume(); // get the volume          
        bool test(const vector<string>& cond); // test if the conditions are statisfied
        string getInfo(); // get all the info in a string
        bool isConditionStatementTrue(string name, string op, string value);
    private:
        double length, width, height;
};
#endif