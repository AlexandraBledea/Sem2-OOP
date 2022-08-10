//
// Created by Alexandra on 4/26/2021.
//

#pragma once
#include "Person.h"
using namespace std;

class Console {
private:
    Person& person;

public:
    Console(Person &person);
    void addMeasurementUI();
    void displayMeasurementUI();
    void ShowIfHealthy();
    void WriteToFile();
    void Menu();
    void Start();
};

