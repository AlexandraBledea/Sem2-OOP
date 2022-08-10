//
// Created by Alexandra on 6/22/2021.
//

#pragma once
#include "Ethnologist.h"
#include <fstream>
#include <vector>

class PeopleRepo {

private:

    vector<Ethnologist> people;
    void LoadData();

public:
    PeopleRepo();
    ~PeopleRepo();
    vector<Ethnologist>& getAll();

};

