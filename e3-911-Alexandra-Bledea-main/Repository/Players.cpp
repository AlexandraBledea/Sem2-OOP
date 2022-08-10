//
// Created by Alexandra on 7/7/2021.
//

#include "Players.h"
#include <fstream>

void Players::LoadData() {
    ifstream inFile("input.txt");
    int a;
    inFile >> a;
    inFile >> a;
    Person currentElement;
    this->players.clear();
    while(inFile >> currentElement){
        this->players.push_back(currentElement);
    }
    inFile.close();
}

Players::Players() {
    this->LoadData();
}

Players::~Players() {

}

vector<Person> &Players::getAll() {
    return this->players;
}
