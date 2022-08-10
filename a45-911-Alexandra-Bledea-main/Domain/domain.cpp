//
// Created by Alexandra on 3/17/2021.
//

#include <cstring>
#include "domain.h"

Coat::Coat() {
}

Coat::Coat(string size, string color, int price, int quantity, string photograph):
size{size}, color{color}, price{price}, quantity{quantity}, photograph{photograph}{
//    this->size = size;
//    this->color = color;
//    this->price = price;
//    this->quantity = quantity;
//    this->photograph = photograph;
}

//void Coat::SetSize(string size) {
//    this->size =  size;
//}

void Coat::SetQuantity(int quantity) {
    this->quantity = quantity;
}

void Coat::SetPrice(int price) {
    this->price = price;
}

string Coat::GetSize() {
    return this->size;
}

string Coat::GetColor() {
    return this->color;
}

int Coat::GetPrice() {
    return this->price;
}

int Coat::GetQuantity() {
    return this->quantity;
}

string Coat::GetPhotograph() {
    return this->photograph;
}


//void Coat::createCoat(char *size, char *color, double price, int quantity, char *photograph) {
//    strcpy(this->size, size);
//    strcpy(this->color, color);
//    this->price = price;
//    this->quantity = quantity;
//    strcpy(this->photograph, photograph);
//}

