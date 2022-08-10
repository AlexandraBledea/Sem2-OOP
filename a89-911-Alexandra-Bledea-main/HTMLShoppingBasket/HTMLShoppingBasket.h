//
// Created by Alexandra on 4/15/2021.
//

#pragma once
#include "AbstractShoppingBasket.h"
#include <string>
#include "domain.h"
#include <vector>
using namespace std;

class HTMLShoppingBasket: public AbstractShoppingBasket {
private:
    vector<Coat> elements;
    string FileName;

public:
    HTMLShoppingBasket();
    void write() override;
    void open() override;
    void set_data(vector<Coat> elements) override;
    ~HTMLShoppingBasket() override = default;

};


