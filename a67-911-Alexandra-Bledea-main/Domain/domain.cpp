//
// Created by Alexandra on 3/17/2021.
//

#include <cstring>
#include "domain.h"
#include <iostream>

Coat::Coat() {
}

Coat::Coat(string size, string color, int price, int quantity, string photograph):
size{size}, color{color}, price{price}, quantity{quantity}, photograph{photograph}{
}


void Coat::SetQuantity(int quantity) {
    this->quantity = quantity;
}

void Coat::SetPrice(int price) {
    this->price = price;
}

const string& Coat::GetSize() const{
    return this->size;
}

const string& Coat::GetColor() const{
    return this->color;
}

const int& Coat::GetPrice() const{
    return this->price;
}

int Coat::GetQuantity() const{
    return this->quantity;
}

const string& Coat::GetPhotograph() const{
    return this->photograph;
}

Coat &Coat::operator=(const Coat &c) {
    this->size = c.size;
    this->color = c.color;
    this->price = c.price;
    this->quantity = c.quantity;
    this->photograph = c.photograph;
    return *this;
}

ostream &operator<<(ostream &output, const Coat &c) {
    output<<c.size<<" "<<c.color<<" "<<c.price<<" "<<c.quantity<<" "<<c.photograph;
    return output;
}

istream &operator>>(istream &input, Coat &c) {
    input>>c.size>>c.color>>c.price>>c.quantity>>c.photograph;
    return input;
}
