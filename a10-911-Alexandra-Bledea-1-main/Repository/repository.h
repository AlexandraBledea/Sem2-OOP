//
// Created by Alexandra on 3/17/2021.
//

#pragma once
#include <cstdlib>
#include "domain.h"
#include <vector>

class Repository
{
protected:
    vector<Coat> elements;

public:

/// Constructor
//Repository;
//~Repository();

Coat getCoat(string size, string color, string photograph);

/// With this function we initialize the repository
void init_repository();

/// With this function we get the number of elements from the repository
virtual int GetSize() ;

/// With this function we get the dynamic array
virtual const vector<Coat>& GetDynArr();

//virtual vector<Coat> GetDynArr();

/// With this function we initialize the repository with the dynamic array
/// \param DArray the dynamic array
Repository();

/// With this function we add a product to the repository
/// \param size the size of the product
/// \param color the color of the product
/// \param price the price of the product
/// \param quantity the quantity of the product
/// \param photograph the link to the photograph of the product
/// \return it returns 0 if the product was added and 1 if it already exists.
virtual void AddRepo(string size, string color, int price, int quantity, string photograph);


/// With this function we check if a product already exists in the repository
/// \param size the size of the product
/// \param color the color of the product
/// \param photograph the photograph of the product
/// \return it returns -1 if the product doesn't exist or the position of the product in case it exists
virtual int CheckExistenceCoat(string size, string color, string photograph);

/// With this function we delete an entire product from the repository
/// \param size the size of the product
/// \param color the color of the product
/// \param photograph the link to the photograph of the product
/// \return it returns 0  if the product was deleted and 1 otherwise
virtual void DeleteEntireProductRepo(string size, string color, string photograph);

/// With this function we delete a product from the repository in case of a sold out(quantity = 0)
/// \param size the size of the product
/// \param color the color of the product
/// \param photograph the link to the photograph of the product
/// \return it returns 0 if the product was deleted and 1 otherwise
virtual void DeleteSoldOutProductRepo(string size, string color, string photograph);

/// With this function we update the price of a product
/// \param size the size of the product
/// \param color the color of the product
/// \param photograph the link to the photograph of the product
/// \param price the new price
/// \return it return 0 if the product was updated and 1 otherwise
virtual void UpdatePriceRepo(string size, string color, string photograph, int price);

/// With this function we update the quantity of a product
/// \param size the size of the product
/// \param color the color of the product
/// \param photograph the link to the photograph of the product
/// \param quantity the new quantity
/// \return it return 0 if the product was updated and 1 otherwise
virtual void UpdateQuantityRepo(string size, string color, string photograph, int quantity);

/// With this function we make the repository iterable
/// \param position represents the position of the product
/// \return returns the product from the given position
//Coat& operator [] (int position) {
//    return this->elements[position];
//}
//Repository GetRepository();

};