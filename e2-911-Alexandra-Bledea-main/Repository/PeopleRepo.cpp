//
// Created by Alexandra on 6/22/2021.
//

#include "PeopleRepo.h"

void PeopleRepo::LoadData() {
    ifstream inFile("ethnologists.txt");
    Ethnologist currentElement;
    this->people.clear();
    while(inFile >> currentElement){
        this->people.push_back(currentElement);
    }
    inFile.close();
}

PeopleRepo::PeopleRepo() {
    this->LoadData();
}

PeopleRepo::~PeopleRepo() {

}

vector<Ethnologist> &PeopleRepo::getAll() {
    return this->people;
}
