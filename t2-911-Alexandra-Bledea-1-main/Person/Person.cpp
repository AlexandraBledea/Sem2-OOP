//
// Created by Alexandra on 4/26/2021.
//

#include "Person.h"
#include "BP.h"
#include "BMI.h"
#include <sstream>
#include <fstream>
#include <iostream>

void Person::addMeasurement(Measurement *measurement) {
    this->measurements.push_back(measurement);
}

void Person::init() {
    Measurement* m1 = new BMI("27.04.2021", 19);
    this->addMeasurement(m1);
    Measurement* m2 = new BMI("28.04.2021", 21);
    this->addMeasurement(m2);
    Measurement* m3 = new BP("20.03.2021", 100, 70);
    this->addMeasurement(m3);
    Measurement* m4 = new BP("18.02.2021", 200, 71);
    this->addMeasurement(m4);
    Measurement* m5 = new BMI("27.02.2020", 20);
    this->addMeasurement(m5);
}

void Person::SetName(string name) {
    this->name = name;
}

vector<string> Person::tokenize(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

vector<Measurement *> Person::getAllMeasurements() {
    return this->measurements;
}

string Person::GetName() {
    return this->name;
}

vector<Measurement *> Person::getMeasurementsByMonth(int month) {
    vector<Measurement*> byMonth;
    vector<string> tokens;
    for(auto & measurement: this->measurements)
    {
        tokens = tokenize(measurement->GetDate(), '.');
        if(stol(tokens[1]) == month)
            byMonth.push_back(measurement);
    }
    return byMonth;
}

bool Person::isHealthy(int month) {
    if(month == 1)
    {
        vector<Measurement*> one_month = getMeasurementsByMonth(month);
        for(auto & measurement: one_month)
            if(!measurement->isNormalValue())
                return false;
        return true;
    }
    else
    {
        int current_month = month;
        int previous_month = current_month - 1;
        vector<Measurement*> CurMonths= getMeasurementsByMonth(current_month);
        vector<Measurement*> PrevMonths = getMeasurementsByMonth(previous_month);
        for(auto & measurement: CurMonths)
            if(!measurement->isNormalValue())
                return false;
        for(auto & measurement: PrevMonths)
            if(!measurement->isNormalValue())
                return false;
        return true;
    }
}

vector<Measurement *> Person::getMeasurementNewerThan(string date) {
    vector<Measurement*> newer;
    vector<string> tokens = tokenize(date, '.');
    vector<string> tokens2;
    for(auto & measurement: this->measurements){
            tokens2 = tokenize(measurement->GetDate(), '.');
            if(tokens2[1] >= tokens[1] && tokens2[2] == tokens[2])
                newer.push_back(measurement);
            else if ( tokens2[2] > tokens[2])
                newer.push_back(measurement);
    }
    return newer;
}

void Person::writeToFile(string filename, string date) {
    vector<Measurement*> newer;
    newer = getMeasurementNewerThan(date);
    ofstream  outFile(filename);
    for(auto CurrentElement: newer)
    {
        outFile << CurrentElement->ToString() <<'\n';
    }
}
