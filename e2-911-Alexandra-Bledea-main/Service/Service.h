//
// Created by Alexandra on 6/22/2021.
//

#pragma once
#include "PeopleRepo.h"
#include "BuildingsRepo.h"
#include "Observer.h"

class Service: public Observable{

private:
    PeopleRepo& peopleRepo;
    BuildingsRepo& buildingsRepo;

public:
    Service(PeopleRepo& peopleRepo, BuildingsRepo& buildingsRepo);
    vector<Building> getBuildingsByArea(Ethnologist e);
    void addBuilding(string description, string area, string location);
    int findID();
    static vector<string> tokenize(string str, char delimiter);
    void updateBuilding(string id, string description, string location);
    void updateBuildingDescription(string id, string description);
    void updateBuildingLocation(string id, string location);
    bool checkContiguousArea(vector<string> location);
};
