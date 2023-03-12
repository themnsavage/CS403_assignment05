using namespace std;

#include "Sphere.h";

//constructor
Sphere::Sphere(string& name, double radius)
    :Shape(name)
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
double Sphere::getArea() const{
    return 4*PI*(this->radius*this->radius);
}
// get the volume
double Sphere::getVolume() const{
    return (4/3)*PI*(this->radius*this->radius*this->radius);
}
// test if the conditions are statisfied
bool Sphere::test(const vector<string>& cond) const{
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
string Sphere::getInfo() const{}
