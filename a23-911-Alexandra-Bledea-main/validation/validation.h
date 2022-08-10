//
// Created by Alexandra on 3/3/2021.
//

#pragma once


/// With this function we validate the product's name
/// \param name represents the product's name
/// \return return 0 if the name is not valid and 1 otherwise
int validate_product_name(char name[]);

/// With this function we validate the product's quantity
/// \param quantity represents the product's quantity
/// \return return 0 if the quantity is not valid and 1 otherwise
int validate_product_quantity(char quantity[]);

/// With this function we validate the product's type
/// \param type represents the product's type
/// \return return 0 if the type is not valid and 1 otherwise
int validate_product_type(char type[]);

/// With this function we validate the product's type
/// \param date represents the product's expiration date
/// \return return 0 if the expiration date is not valid and 1 otherwise
int validate_expiration_date(char date[]);

/// With this function we check if a given criteria is valid or not
/// \param criteria the criteria after which we will sort the array of products
/// \return return 0 if the criteria is not valid and 1 otherwise
int validate_criteria(int criteria);