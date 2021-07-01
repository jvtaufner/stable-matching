#ifndef PERSON_H
#define PERSON_H

#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Person{

public:

    int age;
    int index;
    pair<int, int> coordinates;
    Person(int age, int x, int y, int index);
    static bool comparePeople(Person p1, Person p2);
};

#endif
