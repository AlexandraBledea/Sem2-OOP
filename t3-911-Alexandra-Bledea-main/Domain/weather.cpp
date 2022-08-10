//
// Created by Alexandra on 5/24/2021.
//

#include "weather.h"
#include <sstream>

vector<string> weather::tokenize(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

weather::weather() {

}

weather::weather(int startHour, int endHour, int precipitation, string description): startHour{startHour}, endHour{endHour}, precipitation{precipitation}, description{description} {

}

weather::~weather() {

}

int weather::getStartHour() {
    return this->startHour;
}

int weather::getEndHour() {
    return this->endHour;
}

int weather::getPrecipitation() {
    return this->precipitation;
}

string weather::getDescription() {
    return this->description;
}

istream &operator>>(istream &input, weather &w) {
    string line;
    getline(input, line);
    vector<string> tokens = weather::tokenize(line, ';');
    if(tokens.size() != 4)
        return input;
    w.startHour = stoi(tokens[0]);
    w.endHour = stoi(tokens[1]);
    w.precipitation = stoi(tokens[2]);
    w.description = tokens[3];
    return input;
}
