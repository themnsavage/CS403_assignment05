using namespace std;
#include <string.h>
#include "Cylinder.h"

//constructor
Cylinder::Cylinder(string name, double radius, double height)
    :Shape(name)
{
    this->radius = radius;
    this->height = height;
}
//helper function
bool Cylinder::isConditionStatementTrue(string name, string op, string value) const{
    //convert name and value to correct values
    double leftStatement;
    double rightStatement;
    if(name.compare("area") == 0){
        leftStatement = this->getArea();
        rightStatement = stod(value);
    }
    else if (name.compare("volume") == 0){
        leftStatement = this->getVolume();
        rightStatement = stod(value);
    }
    else{
        leftStatement = this->type.compare(value);
        rightStatement = 0;
    }
    // condition statement
    if(op.compare("==") == 0){
        return leftStatement == rightStatement;
    }
    else if(op.compare("!=") == 0){
        return leftStatement != rightStatement;
    }
    else if(op.compare(">=") == 0){
        return leftStatement >= rightStatement;
    }
    else if(op.compare("<=") == 0){
        return leftStatement <= rightStatement;
    }
    else if(op.compare(">") == 0){
        return leftStatement > rightStatement;
    }
    else if(op.compare("<") == 0){
        return leftStatement < rightStatement;
    }

    return false;
}
// get the surface area
double Cylinder::getArea() const{
    double area = 2*PI * this->radius*this->height + 2*PI * (this->radius * this->radius);
    return ceil(area * 100.0) / 100.0;
}
// get the volume
double Cylinder::getVolume() const{
    double volume = PI * (this->radius*this->radius) * this->height;
    return ceil(volume * 100.0) / 100.0;
}
// test if the conditions are statisfied
bool Cylinder::test(const vector<string>& cond) const{
    string name, op, value;
    int count = 0;
    for(size_t index = 0; index < cond.size(); index++){
        if(count == 0){// get name
            name = cond[index];
            count++;
        }
        else if(count == 1){//get operator
            op = cond[index];
            count++;
        }
        else{// get value and test condition statement
            value = cond[index];
            count = 0;
            if(isConditionStatementTrue(name, op, value) == false){
                return false;
            }
        }

    }
    return true;
}
// get all the info in a string
string Cylinder::getInfo() const{
    string dimension = "Cylinder: "+this->getName()+", Radius="+to_string(this->radius)+", Height="+to_string(this->height);
    string caculations = "         Surface Area: "+to_string(this->getArea())+ ", Volume: "+to_string(this->getVolume());
    return dimension+"\n"+caculations;
}
