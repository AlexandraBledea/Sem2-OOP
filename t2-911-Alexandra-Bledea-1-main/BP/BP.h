//
// Created by Alexandra on 4/26/2021.
//

#pragma Once
#include "Measurement.h"


class BP: public Measurement {

private:
    int systolicValue;
    int diastolicValue;

public:
    BP();
    BP(string date, int systolicValue, int diastolicValue);
    bool isNormalValue() override;
    string ToString() override;
    ~BP() override;
    friend ostream &operator<<(ostream &output, const BP &b);

};

