//
// Created by Alexandra on 4/7/2021.
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

class ExceptionsValidator: public Exceptions
{
    public:
        explicit ExceptionsValidator(string MessageException);
};

class ExceptionsRepository: public Exceptions
{
    public:
        explicit ExceptionsRepository(string MessageException);
};

class ExceptionsService: public Exceptions{

public:
    explicit ExceptionsService(string MessageException);
};