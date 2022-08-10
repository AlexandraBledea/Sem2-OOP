//
// Created by Alexandra on 7/7/2021.
//

#include "Cell.h"

Cell::Cell(state status, string text, bool mine): status{status}, text{text}, mine{mine} {

}

Cell::Cell(): status{state::not_revealed}, text{""}, mine{false} {

}

Cell::~Cell() {

}

state Cell::getStatus() {
    return this->status;
}

string Cell::getText() {
    return this->text;
}

void Cell::setStatus(state status) {
    this->status = status;
}

void Cell::setText(string text) {
    this->text = text;
}

void Cell::setMine(bool mine) {
    this->mine = mine;
}

bool Cell::getMine() {
    return this->mine;
}
