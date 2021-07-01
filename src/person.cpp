#include "../lib/person.hpp"

Person::Person(int age, int x, int y, int index){

    this->age = age;
    this->coordinates.first = x;
    this->coordinates.second = y;
    this->index = index;
}

bool Person::comparePeople(Person p1, Person p2){
    return (p1.age == p2.age ? p1.index < p2.index : p1.age > p2.age);
}