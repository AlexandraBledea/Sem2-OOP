//
// Created by Alexandra on 7/7/2021.
//

#pragma once
#include "Person.h"

class Players {

private:
    vector<Person> players;
    void LoadData();

public:
    Players();
    ~Players();
    vector<Person>& getAll();

};

