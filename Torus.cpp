using namespace std;

#include "Torus.h";
#include <string.h>
//constructor
Torus::Torus(string& name, double radius1, double radius2)
    :Shape(name)
{
    if(radius1 < radius2){
        this->smallRadius = radius1;
        this->bigRadius = radius2;
    }
    else{
        this->smallRadius = radius2;
        this->bigRadius = radius1;
    }
}
//helper function
bool Torus::isConditionStatementTrue(string name, string op, string value) const{
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
        return false; // need to find the hiearchy for shape values
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
double Torus::getArea() const{
    return (4*PI*this->smallRadius)*(4*PI*this->bigRadius);
}
// get the volume
double Torus::getVolume() const{
    return (PI*(this->smallRadius*this->smallRadius))*(2*PI*this->bigRadius);
}
// test if the conditions are statisfied
bool Torus::test(const vector<string>& cond) const{
    string name, op, value;
    int count = 0;
    for(int index = 0; index < cond.size(); index++){
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
string Torus::getInfo() const{}
