//
// Created by Alexandra on 4/26/2021.
//

#include "ExceptionPerson.h"
#include <utility>
#include <string>
using namespace std;

Exceptions::Exceptions(string MessageException) {
    this->message = move(MessageException);
}

const char *Exceptions::what() const noexcept {
    return this->message.c_str();
}


ExceptionsPerson::ExceptionsPerson(string MessageException) : Exceptions(move(MessageException)) {

}
