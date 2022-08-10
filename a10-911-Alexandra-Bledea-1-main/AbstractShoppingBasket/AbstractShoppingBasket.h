//
// Created by Alexandra on 4/15/2021.
//

#pragma once
#include <vector>
#include "domain.h"
class AbstractShoppingBasket {
public:
    virtual void write() = 0;
    virtual void open() = 0;
    virtual void set_data(vector<Coat> elements) = 0;
    virtual ~AbstractShoppingBasket() = default;
};

//
//class HTMLShoppingBasket: public AbstractShoppingBasket{
//    void write(){
//
//    }
//
//    void open(){
//
//    }
//};

//class CSVShoppingBasket: public AbstractShoppingBasket{
//
//    void Repository::UpdateQuantityRepo(string size, string color, string photograph, int quantity);
//
//    void write()
//    {
//
//    }
//
//    void open(){
//
//    }
//};
