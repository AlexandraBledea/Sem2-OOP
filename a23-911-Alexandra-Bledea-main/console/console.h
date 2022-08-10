
//
// Created by Alexandra on 3/2/2021.
//

#pragma once
#include "../domain/domain.h"
#include "repository.h"
#include "service.h"
#include <stdio.h>

typedef struct
{
    Service service;
} Console;


///  With this function we create the console
/// \param service represents the service
/// \return it returns the created console
Console* createConsole(Service service);

/// With this function we destroy the console
/// \param console
void destroy_ui(Console* console);

/// With this function we display all the products
/// \param console
void display_products_ui(Console* console);

/// With this function we add a product
/// \param console
void add_product_ui(Console* console);

/// With this function we delete a product
/// \param console
void delete_product_ui(Console* console);

/// With this function we update the expiration date of a product
/// \param console
void update_products_expiration_date_ui(Console* console);

/// With this function we update the quantity of a product
/// \param console
void update_products_quantity_ui(Console* console);

/// With this function we search for products which contain in their name a given string
/// \param console
void search_elements_by_string_ui(Console* console);

/// With this function we display the products of a given category
/// \param console
void display_products_by_category(Console* console);

/// With this function we execute an undo operation
/// \param console
void undo_ui(Console* console);

/// With this function we execute a redo operation
/// \param console
void redo_ui(Console* console);

/// With this function we display the commands available in the program
/// \param console
void menu(Console* console);

/// With this function we start the program
void start();
