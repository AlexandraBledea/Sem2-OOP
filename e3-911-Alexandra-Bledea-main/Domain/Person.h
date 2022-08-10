//
// Created by Alexandra on 7/7/2021.
//

#pragma once
#include <string>
#include <vector>
using namespace std;


class Person {

private:
    string name;

public:
    Person(string name);
    ~Person();
    Person();
    string getName();
    friend istream& operator>>(istream&, Person&);

};
