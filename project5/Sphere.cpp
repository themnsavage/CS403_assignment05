using namespace std;
#include "Sphere.h"

//constructor
Sphere::Sphere(string name, double radius)
    : Shape(name)
{
    this->radius = radius;
}
// helper function
bool Sphere::isConditionStatementTrue(string name, string op, string value) const{
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
double Sphere::getArea() const{
    double area = 4.0*PI*(this->radius*this->radius);
    return ceil(area * 100.0) / 100.0;
}
// get the volume
double Sphere::getVolume() const{
    double volume = (4.0/3.0)*PI*(this->radius*this->radius*this->radius);
    return ceil(volume * 100.0) / 100.0;
}
// test if the conditions are statisfied
bool Sphere::test(const vector<string>& cond) const{
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
string Sphere::getInfo() const{
    stringstream ssRadius, ssArea, ssVolume;
    ssRadius<<fixed<<setprecision(2)<<this->radius;
    ssArea<<fixed<<setprecision(2)<<this->getArea();
    ssVolume<<fixed<<setprecision(2)<<this->getVolume();
    
    string dimension = "Sphere: "+this->getName()+", Radius="+ssRadius.str();
    string caculations = "         Surface Area: "+ssArea.str()+ ", Volume: "+ssVolume.str();
    return dimension+"\n"+caculations;
}