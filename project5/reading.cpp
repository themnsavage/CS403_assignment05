#include "reading.h"

using namespace std;

vector<Shape*> *readFrom(string fileName){
    ifstream ifs(fileName);
    string line;
    vector <Shape*> shapes;
    while(getline(ifs,line)){//grap each line from file
        //create a vector with line seperated by spaces
        string word;
        stringstream lineStream(line);
        vector<string> listOfWords;
        while(getline(lineStream, word, ' ')){
            listOfWords.push_back(word);
        }
        //create shapes
        Shape *newShape = NULL;
        string name = listOfWords[0];
        string type = listOfWords[1];
        if(type.compare("sphere") == 0){
            newShape = new Sphere(name, stod(listOfWords[2]));
        }
        else if(type.compare("cylinder") == 0){
            newShape = new Cylinder(name, stod(listOfWords[2]), stod(listOfWords[3]));
        }
        else if(type.compare("torus") == 0){
            newShape = new Torus(name,stod(listOfWords[2]),stod(listOfWords[3]));
        }
        else if(type.compare("box") == 0){
            newShape = new Box(name,stod(listOfWords[2]),stod(listOfWords[3]),stod(listOfWords[4]));
        }
        shapes.push_back(newShape);
    }
    vector<Shape*> * shapePointer = &shapes;
    return shapePointer;
}

