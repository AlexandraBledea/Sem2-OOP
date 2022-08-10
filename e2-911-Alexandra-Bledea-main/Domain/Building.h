//
// Created by Alexandra on 6/22/2021.
//

#pragma
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Building {

private:
    string id;
    string description;
    string area;
    vector<string> location;

public:
    Building();
    Building(string id, string description, string area, vector<string> location);
    ~Building();

    string getID();
    string getDescription();
    string getArea();
    vector<string> getLocation();

    void setDescription(string description);
    void setLocation(vector<string> newLocation);

    static vector<string> tokenize(string str, char delimiter);
    friend istream& operator>>(istream&, Building&);

};
