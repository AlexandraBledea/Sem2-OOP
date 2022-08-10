//
// Created by Alexandra on 5/24/2021.
//

#include "Repository.h"
#include <fstream>

void Repository::LoadData() {
    ifstream inFile(R"(C:\Users\Alexandra\Desktop\Facultate\Semestru 2\911\t3-911-Alexandra-Bledea\input.txt)");
    weather CurrentElement;
    this->elements.clear();
    while (inFile >> CurrentElement)
    {
        this->elements.push_back(CurrentElement);
    }
    inFile.close();
}

Repository::Repository() {
    this->LoadData();
}

Repository::~Repository() {

}

vector<weather> Repository::getAll() {
    return this->elements;
}
