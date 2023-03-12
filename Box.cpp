using namespace std;

#include "Box.h";

//constructor
Box::Box(string& name, double l, double w, double h)
    :Shape(name)
{
    this->length = l;
    this->width = w;
    this->height = h;
};
//helper function
bool Box::isConditionStatementTrue(string name, string op, string value) const{
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
double Box::getArea() const{
    return 2 * (this->length*this->width + this->length*this->height + this->width*this->height);
}
// get the volume
double Box::getVolume() const{
    return this->length*this->height*this->width;
}
// test if the conditions are statisfied
bool Box::test(const vector<string>& cond) const{
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
string Box::getInfo() const{}
