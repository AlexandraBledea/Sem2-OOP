//
// Created by Alexandra on 6/22/2021.
//

#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Ethnologist {

private:
    string name;
    string area;

public:
    Ethnologist();
    Ethnologist(string name, string area);
    ~Ethnologist();
    string getName();
    string getArea();
    friend istream& operator>>(istream&, Ethnologist&);
    static vector<string> tokenize(string str, char delimiter);

};

