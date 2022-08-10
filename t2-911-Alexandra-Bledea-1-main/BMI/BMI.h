//
// Created by Alexandra on 4/26/2021.
//

#pragma once
#include "Measurement.h"

class BMI: public Measurement {
private:
    double value;

public:
    BMI();
    BMI(string date, double value);
    bool isNormalValue() override;
    string ToString() override;
    friend ostream& operator<<(ostream&, const BMI&);
    ~BMI() override;

};

