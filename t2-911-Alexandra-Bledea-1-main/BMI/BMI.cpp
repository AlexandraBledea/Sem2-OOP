//
// Created by Alexandra on 4/26/2021.
//

#include "BMI.h"
#include <dos.h>
#include <ctime>
#include <sstream>

BMI::BMI() {

}

BMI::BMI(string date, double value) {
    this->date = date;
    this->value = value;
}

bool BMI::isNormalValue() {
    if(value >= 18.5 && value <=25)
        return true;
    else
        return false;
}

string BMI::ToString() {
    stringstream buffer;
    buffer.width(25);
    buffer << std:: left << this->date << " | ";
    buffer.width(25);
    buffer << std:: left <<this->value << " | \n";
    return buffer.str();
}

BMI::~BMI() {

}

ostream &operator<<(ostream &output, const BMI &b) {
    output<<b.date<<" "<<b.value;
    return output;
}
