//
// Created by Alexandra on 3/17/2021.
//

#pragma once
#include "service.h"
#include "validation.h"

class Console
{
private:
    Service* service;
    Validator* validator;

public:

/// Constructor
Console();

/// Destructor
~Console();

Console(Service* service, Validator* validator);
void Start();

void AdministratorMode();

void UserMode();

void DisplayShoppingBag();

void MenuAdminMode();

void UpdateProductsPriceAdmin();

void UpdateProductsQuantityAdmin();

void DeleteEntireProductAdmin();

int DisplayProductsUser();

void DeleteSoldOutProductAdmin();

void MenuDisplayProductsUser();

void DisplayProductsAdmin();

void AddAdminConsole();

};