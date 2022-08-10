//
// Created by Alexandra on 5/24/2021.
//

#pragma once
#include "weather.h"
#include <string>
#include <vector>
using namespace std;

class Repository {

private:
    vector<weather> elements;
    void LoadData();

public:
    Repository();
    ~Repository();
    vector<weather> getAll();

};

