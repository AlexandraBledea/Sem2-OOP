//
// Created by Alexandra on 3/17/2021.
//

#pragma once
#include <cstdlib>
#include "dynamic_array.h"
#include "repository.h"
#include <algorithm>
#include "domain.h"
#include <memory>
#include "Exceptions.h"
#include "Action.h"
#include <stack>

class Service
{
private:

    std::vector<Action*> undoStackAdminMode;
    std::vector<Action*> redoStackAdminMode;
    std::vector<Action*> undoStackUserMode;
    std::vector<Action*> redoStackUserMode;

    Repository& repository;
    Repository& user_repository;
    int total_price;
public:

void undoLastAction(std::vector<Action*>& currentUndoStack, std::vector<Action*>& currentRedoStack);
void redoLastAction(std::vector<Action*>& currentUndoStack, std::vector<Action*>& currentRedoStack);
void undoAdminMode();

void redoAdminMode();

void undoUserMode();

void redoUserMode();

///Construct
//Service();
///Destructor
//~Service();

int GetTotalPrice() const;

/// With this function we initialize the Service
/// \param repository
Service(Repository& repository, Repository& user_repository);

/// With this function we add a product to the user repository
/// \param c the initial product
/// \param cUser the product we are about to add to the user
/// \return it returns 1 if the initial product had quantity 0 and 0 otherwise
int AddUserService(Coat c, Coat cUser);

/// With this function we add a product
/// \param size the size of the product
/// \param color the color of the product
/// \param price the price of the product
/// \param quantity the quantity of the product
/// \param photograph the link to the photograph of the product
/// \return returns 0 if the product was added or 0 otherwise
void AddService(string size, string color, int price, int quantity, string photograph);

/// With this function we get the repository
/// \return returns the repository
const vector<Coat>& GetRepository();

//vector<Coat> GetRepository();

vector<Coat> GetFilteredRepository(string size);

/// With this function we get the user repository
/// \return returns the user repository
vector<Coat> GetUserRepository();

/// With this function we print the products
//void print();

/// With this function we delete a product
/// \param size the size of the product
/// \param color the color of the product
/// \param photograph the link to the photograph of the product
/// \param criteria if it is 1 it means we delete the entire product and if it is 2 it means we delete the product
/// because of a SOLD OUT
/// \return return 0 if the product was deleted or 1 otherwise
void DeleteService(string size, string color, string photograph, int criteria);

/// With this function we update the price of a product
/// \param size the size of the product
/// \param color the color of the product
/// \param photograph the link to the photograph of the product
/// \param price the new price of the product
/// \return returns 0 if the product was updated and 1 otherwise
void UpdatePriceService(string size, string color, string photograph, int price);

/// With this function we update the quantity of a product
/// \param size the size of the product
/// \param color the color of the product
/// \param photograph the link to the photograph of the product
/// \param quantity the new quantity of the product
/// \return returns 0 if the product was updated and 1 otherwise
void UpdateQuantityService(string size, string color, string photograph, int quantity);

/// With this function we get the number of products
int GetSize();

};