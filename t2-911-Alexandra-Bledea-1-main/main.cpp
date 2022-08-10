//
// Created by Alexandra on 4/26/2021.
//
#include "Person.h"
#include "Console.h"
int main()
{
    Person person;
    person.init();
    Console console(person);
    console.Start();
    return 0;
}