//
// Created by Alexandra on 6/22/2021.
//

#include "Service.h"
#include <time.h>

vector<Building> Service::getBuildingsByArea(Ethnologist e) {
    vector<Building> buildings;
    for(auto & b: this->buildingsRepo.getAll()){
        if(b.getArea() == e.getArea()){
            buildings.push_back(b);
        }
    }
    vector<Building> sorted(this->buildingsRepo.getAll());
    for(int i = 0; i < sorted.size(); i++){
        for(int j = i + 1; j < sorted.size() - 1; j++){
            if(sorted[i].getArea() > sorted[j].getArea())
            {
                swap(sorted[i], sorted[j]);
            }
        }
    }

    for(auto & b: sorted){
        if(b.getArea() != e.getArea() && b.getArea() != "office"){
            buildings.push_back(b);
        }
    }

    for(auto & b: sorted)
        if(b.getArea() == "office")
            buildings.push_back(b);

    return buildings;

}

Service::Service(PeopleRepo &peopleRepo, BuildingsRepo &buildingsRepo):
peopleRepo{peopleRepo}, buildingsRepo{buildingsRepo}
{

}

void Service::addBuilding(string description, string area, string location) {
    if(location[0] == ' ')
        location.erase(location.begin() + 0);
    if(location[location.size()-1] == ' ')
        location.erase(location.begin() + location.size()-1);
    int id = this->findID();
    string finalID = to_string(id);
    vector<string> locations = tokenize(location, ' ');
    if(!checkContiguousArea(locations))
        throw exception();
    Building b(finalID, description, area, locations);
    this->buildingsRepo.addBuilding(b);
    this->notify();
}

int Service::findID() {
    bool done = false;
    int id;
    while(!done){
        for(auto & a: this->buildingsRepo.getAll()) {
            srand(time(NULL));
            id = rand() % 1000;
            if(to_string(id) != a.getID()){
                done = true;
                break;
            }
        }
    }
    return id;
}

vector<string> Service::tokenize(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

void Service::updateBuilding(string id, string description, string location) {
    if(location.empty() && !description.empty()){
        this->updateBuildingDescription(id, description);
    }
    else if(!location.empty() && description.empty()){
        this->updateBuildingLocation(id, location);
    }
    else {
        if (location[0] == ' ')
            location.erase(location.begin() + 0);
        if (location[location.size() - 1] == ' ')
            location.erase(location.begin() + location.size() - 1);
        vector<string> locations = tokenize(location, ' ');
        if(!checkContiguousArea(locations))
            throw exception();
        this->buildingsRepo.updateBuilding(id, description, locations);
        this->notify();
    }
}

void Service::updateBuildingDescription(string id, string description) {
    this->buildingsRepo.updateBuildingDescription(id, description);
    this->notify();
}

void Service::updateBuildingLocation(string id, string location) {
    if(location[0] == ' ')
        location.erase(location.begin() + 0);
    if(location[location.size()-1] == ' ')
        location.erase(location.begin() + location.size()-1);
    vector<string> locations = tokenize(location, ' ');
    if(!checkContiguousArea(locations))
        throw exception();
    this->buildingsRepo.updateBuildingLocation(id, locations);
    this->notify();
}

bool Service::checkContiguousArea(vector<string> location) {
    for(int i = 0; i < location.size() - 1; i++){
        string loc1 = location[i];
        string loc2 = location[i+1];
        if(!((loc1[0]==loc2[0] && loc1[1]!=loc2[1]) || (loc1[1]==loc2[1] && loc1[0]!=loc2[0]))){
            return false;
        }
    }
    return true;
}

