//
// Created by Alexandra on 4/26/2021.
//

#pragma once
#include "Measurement.h"
#include <vector>
using namespace std;
class Person {

private:
    string name;
    vector<Measurement*> measurements;

public:
    void SetName(string name);
    string GetName();
    void addMeasurement(Measurement* measurement);
    void init();
    vector<Measurement*> getAllMeasurements();
    vector<Measurement*> getMeasurementsByMonth(int month);
    bool isHealthy(int month);
    vector<string> tokenize(string str, char delimiter);
    vector<Measurement*> getMeasurementNewerThan(string date);
    void writeToFile(string filename, string date);
};


