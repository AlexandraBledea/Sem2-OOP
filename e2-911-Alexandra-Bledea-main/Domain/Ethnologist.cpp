//
// Created by Alexandra on 6/22/2021.
//

#include "Ethnologist.h"

Ethnologist::Ethnologist(string name, string area): name{name}, area{area} {

}

Ethnologist::~Ethnologist() {

}

string Ethnologist::getName() {
    return this->name;
}

string Ethnologist::getArea() {
    return this->area;
}

vector<string> Ethnologist::tokenize(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

istream &operator>>(istream &input, Ethnologist &q) {
    string line;
    getline(input, line);
    vector<string> tokens = Ethnologist::tokenize(line, ';');
    if(tokens.size() != 2)
        return input;
    q.name = tokens[0];
    q.area = tokens[1];
    return input;
}

Ethnologist::Ethnologist() {

}
