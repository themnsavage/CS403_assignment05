using namespace std;

#include "Box.h"

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
double Box::getArea() const{
    double area = 2.0 * (this->length*this->width + this->length*this->height + this->width*this->height);
    return round(area * 100.0) / 100.0;
}
// get the volume
double Box::getVolume() const{
    double volume = this->length*this->height*this->width;
    return round(volume * 100.0) / 100.0;
}
// test if the conditions are satisfied
bool Box::test(const vector<string>& cond) const{
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
string Box::getInfo() const{
    stringstream ssLength, ssWidth, ssHeight, ssArea, ssVolume;
    ssLength<<fixed<<setprecision(2)<<this->length;
    ssWidth<<fixed<<setprecision(2)<<this->width;
    ssHeight<<fixed<<setprecision(2)<<this->height;
    ssArea<<fixed<<setprecision(2)<<this->getArea();
    ssVolume<<fixed<<setprecision(2)<<this->getVolume();

    string dimension = "Box: "+this->getName()+", Length="+ssLength.str()+", Width="+ssWidth.str()+", Height="+ssHeight.str();
    string calculations = "         Surface Area: "+ssArea.str()+ ", Volume: "+ssVolume.str();
    return dimension+"\n"+calculations;
}
