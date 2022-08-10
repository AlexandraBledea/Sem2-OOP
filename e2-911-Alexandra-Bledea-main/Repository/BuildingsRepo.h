//
// Created by Alexandra on 6/22/2021.
//

#pragma once
#include "Building.h"
#include <fstream>

class BuildingsRepo{

private:
    vector<Building> buildings;
    void LoadData();

public:

    BuildingsRepo();
    ~BuildingsRepo();
    vector<Building>& getAll();
    int checkExistence(Building b);
    void addBuilding(Building b);
    int checkExistenceID(string id);
    void updateBuilding(string id, string description, vector<string> location);
    void updateBuildingDescription(string id, string description);
    void updateBuildingLocation(string id, vector<string> location);
    int checkExistenceBuilding2(vector<string> location);
};
