#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <limits>
#include <cctype>
#include "../project5/Sphere.h"

using namespace std;

int main()
{
    string name = "globe";
    double radius = 1.2;
    Sphere s(name, radius);
    return 0;
}