//
// Created by Alexandra on 6/22/2021.
//

#include "Building.h"

Building::Building(string id, string description, string area, vector<string> location): id{id}, description{description},
area{area}, location{location}
{

}

Building::~Building() {

}

string Building::getID() {
    return this->id;
}

string Building::getDescription() {
    return this->description;
}

string Building::getArea() {
    return this->area;
}

vector<string> Building::getLocation() {
    return this->location;
}

void Building::setDescription(string d) {
    this->description = d;
}

void Building::setLocation(vector<string> newLocation) {
    this->location.clear();
    for(auto & l: newLocation){
        this->location.push_back(l);
    }
}

vector<string> Building::tokenize(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

istream &operator>>(istream &input, Building &v) {
    string line;
    getline(input, line);
    vector<string> tokens = Building::tokenize(line, ';');
    if(tokens.size() != 4)
        return input;
    v.id = tokens[0];
    v.description = tokens[1];
    v.area = tokens[2];
    string parts = tokens[3];
    vector<string> locations = Building::tokenize(parts, ',');
    v.location = locations;
    return input;
}

Building::Building() {

}
