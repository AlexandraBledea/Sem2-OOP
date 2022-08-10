//
// Created by Alexandra on 4/5/2021.
//

#pragma once
#include "Service.h"

class Console {
private:
    Service* service;

public:

Console();

~Console();

Console(Service* service);

void Display();

void Menu();

void Start();

void AddGeneUI();
};

