//
// Created by Alexandra on 5/24/2021.
//

#pragma once
#include "Repository.h"

class Service {

private:
    Repository& repository;

public:
    Service(Repository& repository);
    ~Service();
    vector<weather> getAll();
    vector<weather> filterByPrecipitation(int precipitation);
    vector<weather> filterByDescription(vector<string> descriptions);
    vector<string> getDescriptions();
    vector<weather> filterByPrecipitationAndDescription(int precipitation, vector<string> descriptions);

};

