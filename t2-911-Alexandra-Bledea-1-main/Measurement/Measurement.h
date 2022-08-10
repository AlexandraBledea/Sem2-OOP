//
// Created by Alexandra on 4/26/2021.
//

#pragma once
#include <string>
using namespace std;

class Measurement {
protected:
    string date;

public:
    string GetDate();
    virtual bool isNormalValue() = 0;
    virtual string ToString() = 0;
    virtual ~Measurement();

};


