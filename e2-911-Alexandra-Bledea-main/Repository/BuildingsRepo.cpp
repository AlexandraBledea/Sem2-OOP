//
// Created by Alexandra on 6/22/2021.
//

#include "BuildingsRepo.h"

void BuildingsRepo::LoadData() {
    ifstream inFile("buildings.txt");
    Building currentElement;
    this->buildings.clear();
    while(inFile >> currentElement){
        this->buildings.push_back(currentElement);
    }
    inFile.close();
}

BuildingsRepo::BuildingsRepo() {
    this->LoadData();
}

BuildingsRepo::~BuildingsRepo() {

}

vector<Building> &BuildingsRepo::getAll() {
    return this->buildings;
}

int BuildingsRepo::checkExistence(Building b) {
    for(int i = 0; i < this->buildings.size(); i++){
        vector<string> locations1 = this->buildings[i].getLocation();
        vector<string> locations2 = b.getLocation();
        for(auto & j : locations2){
            for(auto & k : locations1){
                if(k == j)
                    return i;
            }
        }
    }
    return -1;
}

void BuildingsRepo::addBuilding(Building b) {
    int pos = this->checkExistence(b);
    if(pos == -1){
        this->buildings.push_back(b);
    }
    else
    {
        throw exception();
    }
}

void BuildingsRepo::updateBuilding(string id, string description, vector<string> location) {
    int pos = this->checkExistenceID(id);
    int pos2 = this->checkExistenceBuilding2(location);
    if(pos2 == -1){
        this->buildings[pos].setDescription(description);
        this->buildings[pos].setLocation(location);
    }
    else
    {
        throw exception();
    }
}

int BuildingsRepo::checkExistenceID(string id) {
    for(int i = 0; i < this->buildings.size(); i++){
        if(this->buildings[i].getID() == id){
            return i;
        }
    }
    return -1;
}

void BuildingsRepo::updateBuildingDescription(string id, string description) {
    int pos = this->checkExistenceID(id);
    this->buildings[pos].setDescription(description);
}

void BuildingsRepo::updateBuildingLocation(string id, vector<string> location) {
    int pos = this->checkExistenceID(id);
    int pos2 = this->checkExistenceBuilding2(location);
    if(pos2 == -1){
        this->buildings[pos].setLocation(location);
    }
    else
    {
        throw exception();
    }
}

int BuildingsRepo::checkExistenceBuilding2(vector<string> location) {
    for(int i = 0; i < this->buildings.size(); i++){
        vector<string> locations1 = this->buildings[i].getLocation();
        vector<string> locations2 = location;
        for(auto & j : locations2){
            for(auto & k : locations1){
                if(k == j)
                    return i;
            }
        }
    }
    return -1;
}
