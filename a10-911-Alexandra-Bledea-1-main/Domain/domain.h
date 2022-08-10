
//
// Created by Alexandra on 3/17/2021.
//

#pragma once
#include <string>
#include <vector>
using namespace std;
class Coat{
private:
    string size;
    string color;
    int price;
    int quantity;
    string photograph;

public:

/// Constructor
Coat();

/// With this function we initialize the coat
/// \param size the size of the coat
/// \param color the color of the coat
/// \param price the price of the coat
/// \param quantity the quantity of the coat
/// \param photograph the link to the photograph of the coat
Coat(string size, string color, int price, int quantity, string photograph);

//void SetSize(string size);

/// With this function we set the quantity of the coat
/// \param quantity the quantity we want to set
void SetQuantity(int quantity);

/// With this function we set the price of the coat
/// \param price the price we want to set
void SetPrice(int price);

/// With this function we get the size of the coat
/// \return returns the size of the coat
const string& GetSize() const;

/// With this function we get the color of the coat
/// \return returns the color of the coat
const string& GetColor() const;

/// With this function we get the price of the coat
/// \return returns the price of the coat
const int& GetPrice() const;

/// With this function we get the quantity of the coat
/// \return returns the quantity of the goat
int GetQuantity() const;

static vector<string> tokenize(string str, char delimiter);

/// With this function we get the link to the photograph of the coat
/// \return returns the the link to the photograph of the coat
const string& GetPhotograph() const;

friend ostream& operator<<(ostream&, const Coat&);

friend istream& operator>>(istream&, Coat&);

Coat& operator=(const Coat &c);

};
