#ifndef _Sphere_H_
#define _Sphere_H_

#include "Shape.h"
#include <cmath>
using namespace std;

class Sphere: public Shape{
    public:
        Sphere(string, double);
        // ~Sphere() override;
        double getArea() const; // get the surface area          
        double getVolume() const; // get the volume          
        bool test(const vector<string>& cond) const; // test if the conditions are statisfied
        string getInfo() const; // get all the info in a string
        virtual bool isConditionStatementTrue(string name, string op, string value) const;
    private:
        double radius;
        string type = "sphere";
};

#endif