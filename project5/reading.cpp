#include "reading.h"

using namespace std;

vector<Shape*> *readFrom(string fileName){
    ifstream ifs(fileName);
    string line;
    vector <Shape*> *shapes = new vector<Shape*>(0);
    while(getline(ifs,line)){//grap each line from file
        //create a vector with line seperated by spaces
        string word;
        stringstream lineStream(line);
        vector<string> listOfWords;
        while(getline(lineStream, word, ' ')){
            listOfWords.push_back(word);
        }
        //create shapes
        string name = listOfWords[0];
        string type = listOfWords[1];
        if(type.compare("sphere") == 0){
            shapes->push_back(new Sphere(name, stod(listOfWords[2])));
        }
        else if(type.compare("cylinder") == 0){
            shapes->push_back(new Cylinder(name, stod(listOfWords[2]), stod(listOfWords[3])));
        }
        else if(type.compare("torus") == 0){
            shapes->push_back(new Torus(name, stod(listOfWords[2]), stod(listOfWords[3])));
        }
        else if(type.compare("box") == 0){
            shapes->push_back(new Box(name, stod(listOfWords[2]), stod(listOfWords[3]), stod(listOfWords[4])));
        }
    }
    return shapes;
}

