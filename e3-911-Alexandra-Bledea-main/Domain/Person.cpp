//
// Created by Alexandra on 7/7/2021.
//

#include "Person.h"

Person::Person(string name): name{name} {

}

Person::~Person() {

}

Person::Person() {

}

string Person::getName() {
    return this->name;
}

istream &operator>>(istream &input, Person &p) {
    input>>p.name;
    return input;
}
