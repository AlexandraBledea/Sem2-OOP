//
// Created by Alexandra on 4/15/2021.
//

#pragma once
#include "AbstractShoppingBasket.h"
#include <string>
#include <vector>
#include "domain.h"
using namespace std;

class CSVShoppingBasket: public AbstractShoppingBasket {
private:
    vector<Coat> elements;
    string FileName;
public:
    CSVShoppingBasket();
    void write() override;
    void open() override;
    void set_data(vector<Coat> elements) override;
    ~CSVShoppingBasket() override = default;

};


