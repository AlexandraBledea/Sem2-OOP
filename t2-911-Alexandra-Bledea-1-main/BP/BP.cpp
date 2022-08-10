//
// Created by Alexandra on 4/26/2021.
//

#include "BP.h"
#include <dos.h>
#include <ctime>
#include <sstream>

BP::BP() {

}

BP::BP(string date, int systolicValue, int diastolicValue) {
    this->date = date;
    this->systolicValue = systolicValue;
    this->diastolicValue = diastolicValue;
}

bool BP::isNormalValue() {
    if(this->systolicValue >=90 && this->systolicValue <=119 && this->diastolicValue >= 60 && this->diastolicValue <=79)
        return true;
    else
        return false;
}

string BP::ToString() {
    stringstream buffer;
    buffer.width(25);
    buffer << std:: left <<this->date << " | ";
    buffer.width(25);
    buffer << std:: left <<this->systolicValue << " | ";
    buffer.width(25);
    buffer << std:: left <<this->diastolicValue << " | \n";
    return buffer.str();
}

BP::~BP() {

}

ostream &operator<<(ostream &output, const BP &b) {
    output<<b.date<<" "<<b.systolicValue<<" "<<b.diastolicValue<<" ";
    return output;;
}