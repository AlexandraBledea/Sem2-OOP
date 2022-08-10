
//
// Created by Alexandra on 3/2/2021.
//


#pragma once
#include "../repository/repository.h"
#include "../undo_redo/repo_undo.h"

typedef struct
{
    Repository repo;
    UndoRepo undo_redo;

} Service;

Service* createService(Repository repository, UndoRepo UndoRedo);
//Service* createService(Repository repository);

/// With this function we add a new product
/// \param service represents the service
/// \param name represents the name of the product
/// \param type represents the type of the product
/// \param quantity represents the quantity of the product
/// \param date represents the expiration date of the function
void add_product_s(Service* service, char name[], char type[], int quantity, char date[]);

/// With this function we delete a product
/// \param service represents the service
/// \param name represents the name of the product
/// \param type represents the type of the product
/// \return returns 0 if the given product doesn't exits or 1 otherwise
int delete_product_s(Service* service, char name[], char type[]);

/// With this function we update the product's quantity
/// \param service represents the service
/// \param name represents the name of the product
/// \param type represents the type of the product
/// \param quantity represents the new quantity of the product
/// \return it returns 1 if the given product was updated successfully and 0 otherwise
int update_products_quantity_s(Service* service, char name[], char type[], int quantity);

/// With this function we update the product's expiration date
/// \param service represents the service
/// \param name represents the name of the product
/// \param type represents the type of the product
/// \param date represents the new expiration date of the product
/// \return it returns 1 if the given product was updated successfully and 0 otherwise
int update_products_expiration_date_s(Service* service, char name[], char type[], char date[]);

/// With this function we destroy the created service
/// \param service represents the service we are about to destroy
void destroy_s(Service* service);

/// With this function we sort the array by the name of the products
/// \param service represents the service
/// \param r represents the repository
void sort_function_name(Service* service, Repository* r);

/// With this function we sort the array by the quantity of the products
/// \param service represents the service
/// \param r represents the repository
void sort_function_quantity(Service* service, Repository* r);

/// With this function we search elements by a given string
/// \param service represents the service
/// \param string represents the string after which we search the elements
/// \param repository represents the repository
/// \param criteria represents the criteria after which we will sort the array in the end
void search_elements_by_string_s(Service* service, char string[], Repository* repository, int criteria);

/// With this function we compute the number of days between two different dates
/// \param service represents the service
/// \param date1 represents the expiration date of the product
/// \return returns the number of days between the two dates
int compute_number_days_between_two_dates(Service* service, char date1[]);

/// With this function we create a copy of the repository
/// \param service represents the service
/// \param UndoRedo represents the undo redo repository
void copy_repo_service(Service* service, UndoRepo * UndoRedo);

/// With this function we search elements by a given category
/// \param service represents the service
/// \param string represents the category by which we search the elements
/// \param repository represents the repository
/// \param number_of_days represents the number of days between the current date and the product's expiration date
/// \return returns 0 if there are no products which check the given conditions, 1 if there are no products from that
/// given category and we take them all in consideration, or 2 if all the conditions were checked and we have products.
int search_elements_by_category_s(Service* service, char string[], Repository* repository, int number_of_days);