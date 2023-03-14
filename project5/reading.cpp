#include "reading.h"

using namespace std;

vector<Shape*> *readFrom(string fileName){
    ifstream ifs(fileName);
    string line;
    vector <Shape*> shapes;
    while(getline(ifs,line)){//grap each line from file
        //create a vector with line seperated by spaces
        stringstream ss(line);
        string s = "";
        vector <string> lineVector;
    }
}

