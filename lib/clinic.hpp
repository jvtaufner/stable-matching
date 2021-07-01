#ifndef CLINIC_H
#define CLINIC_H

#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Clinic{

public:

    Clinic(int capacity, int x, int y);
    pair<int, int> coordinates;
    int capacity;
};

#endif
