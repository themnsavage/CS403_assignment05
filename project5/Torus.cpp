using namespace std;

#include "Torus.h"
//constructor
Torus::Torus(string name, double radius1, double radius2)
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
double Torus::getArea() const{
    double area = (2.0*PI*this->smallRadius)*(2.0*PI*this->bigRadius);
    return round(area * 100.0) / 100.0;
}
// get the volume
double Torus::getVolume() const{
    double volume =  (PI*(this->smallRadius*this->smallRadius))*(2.0*PI*this->bigRadius);
    return round(volume * 100.0) / 100.0;
}
// test if the conditions are satisfied
bool Torus::test(const vector<string>& cond) const{
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
string Torus::getInfo() const{
    stringstream ssSmallRadius, ssBigRadius, ssArea, ssVolume;
    ssSmallRadius<<fixed<<setprecision(2)<<this->smallRadius;
    ssBigRadius<<fixed<<setprecision(2)<<this->bigRadius;
    ssArea<<fixed<<setprecision(2)<<this->getArea();
    ssVolume<<fixed<<setprecision(2)<<this->getVolume();

    string dimension = "Torus: "+this->getName()+", Small Radius="+ssSmallRadius.str()+", Big Radius="+ssBigRadius.str();
    string calculations = "         Surface Area: "+ssArea.str()+ ", Volume: "+ssVolume.str();
    return dimension+"\n"+calculations;
}
