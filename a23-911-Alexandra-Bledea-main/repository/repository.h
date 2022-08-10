//
// Created by Alexandra on 3/2/2021.
//


#pragma once
#include "../domain/domain.h"
#include "dynamic-array.h"

typedef struct
{
    DynamicArray array;

} Repository;

/// With this function we create the repository
/// \param capacity represents the initial capacity of the repository
/// \return it returns the created repository
Repository* createRepo(DynamicArray arr);

/// With this function we check if a product already exists in the array
/// \param repo represents the repository
/// \param name represents the name of the product
/// \param type represents the type of the product
/// \return it returns -1 if the product doesn't exist or its position in case it actually exists
int check_existence_product(Repository* repo, char name[], char type[]);

 /// With this function we get the length of the array
 /// \param r represents the repository which contain our array
 /// \return it returns the length of the array
int getCount(Repository* r);

 /// With this function we add a product
 /// \param r represents the repository
 /// \param name represents the name of the product
 /// \param type represents the type of the product
 /// \param quantity represents the quantity of the product
 /// \param date represents the expiration date of the product
void add_product_r(Repository* r, char name[], char type[], int quantity, char date[]);

 /// With this function we delete a product
 /// \param r represents the repository
 /// \param name represents the name of the product
 /// \param type represents the type of the product
 /// \return returns 0 if the given product doesn't exits or 1 otherwise
int delete_product_r(Repository* r, char name[], char type[]);

 /// With this function we update the product's quantity
 /// \param r represents the repository
 /// \param name represents the name of the product
 /// \param type represents the type of the product
 /// \param quantity represents the new quantity of the product
 /// \return returns 1 if the product was updated successfully and 0 otherwise
int update_products_quantity_r(Repository* r, char name[], char type[], int quantity);

/// With this function we update the product's expiration date
/// \param r represents the repository
/// \param name represents the name of the product
/// \param type represents the type of the product
/// \param date represents the new expiration date for the product
/// \return returns 1 if the product was updated successfully and 0 otherwise
int update_products_expiration_date_r(Repository* r, char name[], char type[], char date[]);

/// With this function we dealloc the space for the repository
/// \param r represents the repository
void destroy_r(Repository* r);

/// With this function we search for products which names contain a given substring
/// \param r represents the repository
/// \param string represents the string after which we look in the products names
/// \param repository represents the new repository in which we add the products which contain the given string
void search_elements_by_string_r(Repository* r, char string[], Repository* repository);

/// With this function we search for elements of a given category
/// \param r represents the repository
/// \param string represents the category by which we look for the products
/// \param repository represents the new repository in which we add the products with that category
/// \return returns 1 if there existed products with the given category or 0 otherwise
int search_elements_by_category_r(Repository* r, char string[], Repository* repository);

/// With this function we initialize the repository with 10 datas.
/// \param repo represents the repository
void init_repo(Repository* repo);

/// With this function we duplicate the repository
/// \param repo the repository we want to copy
/// \return returns the address of the new repository
Repository duplicate_repo(Repository* repo);

/// With this function we copy the elements of a repository into another repository
/// \param repo represents the initial repository
/// \param new_repo represents the new repository in which we saved the values
void copy_repo(Repository* repo, Repository new_repo);



///TODO - Test for destroy_r and destroy_r_2