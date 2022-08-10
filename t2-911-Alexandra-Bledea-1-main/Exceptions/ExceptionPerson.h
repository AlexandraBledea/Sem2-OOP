//
// Created by Alexandra on 4/26/2021.
//


#pragma once
#include <string>
#include <exception>
#include <utility>
using namespace std;

class Exceptions : public exception
{
protected:
    string message;

public:
    explicit Exceptions(string MessageException);

    const char* what() const noexcept override;

};

class ExceptionsPerson: public Exceptions
{
public:
    explicit ExceptionsPerson(string MessageException);
};
