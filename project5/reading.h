#ifndef _READING_H_
#define _READING_H_

#include <fstream>
#include <bits/stdc++.h>
#include "Shape.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Torus.h"
#include "Box.h"

using namespace std;

vector<Shape*> *readFrom(string fileName);

#endif
