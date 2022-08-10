//
// Created by Alexandra on 5/23/2021.
//

#include "Action.h"

AddAction::AddAction(Repository &repository, Coat addedCoat): repository{repository} {
    this->addedCoat = addedCoat;
}

void AddAction::executeUndo() {
    this->repository.DeleteEntireProductRepo(this->addedCoat.GetSize(), this->addedCoat.GetColor(), this->addedCoat.GetPhotograph());
}

void AddAction::executeRedo() {
    this->repository.AddRepo(this->addedCoat.GetSize(), this->addedCoat.GetColor(), this->addedCoat.GetPrice(), this->addedCoat.GetQuantity(), this->addedCoat.GetPhotograph());
}

DeleteAction::DeleteAction(Repository &repository, Coat deletedCoat): repository{repository} {
    this->deletedCoat = deletedCoat;
}

void DeleteAction::executeUndo() {
    this->repository.AddRepo(this->deletedCoat.GetSize(), this->deletedCoat.GetColor(), this->deletedCoat.GetPrice(), this->deletedCoat.GetQuantity(), this->deletedCoat.GetPhotograph());
}

void DeleteAction::executeRedo() {
    this->repository.DeleteEntireProductRepo(this->deletedCoat.GetSize(), this->deletedCoat.GetColor(), this->deletedCoat.GetPhotograph());
}


UpdateQuantityAction::UpdateQuantityAction(Repository &repository, Coat oldCoat, Coat newCoat): repository{repository} {
    this->oldCoat = oldCoat;
    this->newCoat = newCoat;
}

void UpdateQuantityAction::executeUndo() {
    this->repository.UpdateQuantityRepo(this->oldCoat.GetSize(), this->oldCoat.GetColor(), this->oldCoat.GetPhotograph(), this->oldCoat.GetQuantity());
}

void UpdateQuantityAction::executeRedo() {
    this->repository.UpdateQuantityRepo(this->newCoat.GetSize(), this->newCoat.GetColor(), this->newCoat.GetPhotograph(), this->newCoat.GetQuantity());
}

UpdatePriceAction::UpdatePriceAction(Repository &repository, Coat oldCoat, Coat newCoat): repository{repository} {
    this->oldCoat = oldCoat;
    this->newCoat = newCoat;
}

void UpdatePriceAction::executeUndo() {
    this->repository.UpdatePriceRepo(this->oldCoat.GetSize(), this->oldCoat.GetColor(), this->oldCoat.GetPhotograph(), this->oldCoat.GetPrice());
}

void UpdatePriceAction::executeRedo() {
    this->repository.UpdatePriceRepo(this->newCoat.GetSize(), this->newCoat.GetColor(), this->newCoat.GetPhotograph(), this->newCoat.GetPrice());
}
///We use this action if we are about to add to the shoppingBasket for the first time an item, whose quantity is greater than 1
///In this case for undo we update the quantity in the AdminRepo and delete the item from the shoppingBasket
///In this case for redo we update the quantity for the AdminRepo and add the item to the shoppingBasket
AddActionUserMode::AddActionUserMode(Repository &repository, Repository &user_repository, Coat oldCoat, Coat newCoat): repository{repository}, user_repository{user_repository} {
    this->oldCoat = oldCoat;
    this->newCoat = newCoat;
}

void AddActionUserMode::executeUndo() {
    this->user_repository.DeleteEntireProductRepo(this->oldCoat.GetSize(), this->oldCoat.GetColor(), this->oldCoat.GetPhotograph());
    this->repository.UpdateQuantityRepo(this->oldCoat.GetSize(), this->oldCoat.GetColor(), this->oldCoat.GetPhotograph(), this->oldCoat.GetQuantity() + 1);
}

void AddActionUserMode::executeRedo() {
    this->user_repository.AddRepo(this->newCoat.GetSize(), this->newCoat.GetColor(), this->newCoat.GetPrice(), this->newCoat.GetQuantity(), this->newCoat.GetPhotograph());
    this->repository.UpdateQuantityRepo(this->oldCoat.GetSize(), this->oldCoat.GetColor(), this->oldCoat.GetPhotograph(), this->oldCoat.GetQuantity());
}
///We use this action if we are about to increase the quantity of an item from the shoppingBasket, meaning that it was already there
///In this case for undo and redo for both shoppingBasket and AdminRepo we just update the quantity
UpdateActionUserMode::UpdateActionUserMode(Repository &repository, Repository &user_repository, Coat oldCoatUser,
                                           Coat newCoatUser, Coat oldCoatAdmin): repository{repository}, user_repository{user_repository} {
    this->oldCoatAdmin = oldCoatAdmin;
    this->oldCoatUser = oldCoatUser;
    this->newCoatUser = newCoatUser;
}


void UpdateActionUserMode::executeUndo() {
    this->user_repository.UpdateQuantityRepo(this->oldCoatUser.GetSize(), this->oldCoatUser.GetColor(), this->oldCoatUser.GetPhotograph(), this->oldCoatUser.GetQuantity());
    this->repository.UpdateQuantityRepo(this->oldCoatAdmin.GetSize(), this->oldCoatAdmin.GetColor(), this->oldCoatAdmin.GetPhotograph(), this->oldCoatAdmin.GetQuantity() + 1);

}

void UpdateActionUserMode::executeRedo() {
    this->user_repository.UpdateQuantityRepo(this->newCoatUser.GetSize(), this->newCoatUser.GetColor(), this->newCoatUser.GetPhotograph(), this->newCoatUser.GetQuantity());
    this->repository.UpdateQuantityRepo(this->oldCoatAdmin.GetSize(), this->oldCoatAdmin.GetColor(), this->oldCoatAdmin.GetPhotograph(), this->oldCoatAdmin.GetQuantity());
}

///We use action in case the element we just added to the UserRepo had quantity 1, which means in case of an Undo
///We have to add it back to the AdminRepo and update the quantity for the shoppingBasket
///In case of a Redo we delete the item from the AdminRepo and update again the quantity for the shoppingBasket
UpdateActionDeletedUserMode::UpdateActionDeletedUserMode(Repository &repository, Repository &user_repository,
                                                         Coat oldCoatUser, Coat newCoatUser, Coat oldCoatAdmin): repository{repository}, user_repository{user_repository} {
    this->oldCoatUser = oldCoatUser;
    this->oldCoatAdmin = oldCoatAdmin;
    this->newCoatUser = newCoatUser;

}
void UpdateActionDeletedUserMode::executeUndo() {
    this->user_repository.UpdateQuantityRepo(this->oldCoatUser.GetSize(), this->oldCoatUser.GetColor(), this->oldCoatUser.GetPhotograph(), this->oldCoatUser.GetQuantity());
    this->repository.AddRepo(oldCoatAdmin.GetSize(), oldCoatAdmin.GetColor(), oldCoatAdmin.GetPrice(), oldCoatAdmin.GetQuantity() + 1, oldCoatAdmin.GetPhotograph());
}

void UpdateActionDeletedUserMode::executeRedo() {
    this->user_repository.UpdateQuantityRepo(this->newCoatUser.GetSize(), this->newCoatUser.GetColor(), this->newCoatUser.GetPhotograph(), this->newCoatUser.GetQuantity());
    this->repository.DeleteEntireProductRepo(this->oldCoatAdmin.GetSize(), this->oldCoatAdmin.GetColor(), this->oldCoatAdmin.GetPhotograph());
}

///We use this action in case we buy something which has the quantity 1
///Which means in this case if we undo the operation we have to add it back to the AdminRepo and delete it from the UserRepo
///In the redo case it acts in the opposite way
AddDeleteActionUserMode::AddDeleteActionUserMode(Repository &repository, Repository &user_repository, Coat oldCoat, Coat newCoat): repository{repository}, user_repository{user_repository} {
    this->oldCoat = oldCoat;
    this->newCoat = newCoat;
}

void AddDeleteActionUserMode::executeUndo() {
    this->repository.AddRepo(this->oldCoat.GetSize(), this->oldCoat.GetColor(), this->oldCoat.GetPrice(), this->oldCoat.GetQuantity() + 1, this->oldCoat.GetPhotograph());
    this->user_repository.DeleteEntireProductRepo(this->newCoat.GetSize(), this->newCoat.GetColor(), this->newCoat.GetPhotograph());
}

void AddDeleteActionUserMode::executeRedo() {
    this->repository.DeleteEntireProductRepo(this->oldCoat.GetSize(), this->oldCoat.GetColor(), this->oldCoat.GetPhotograph());
    this->user_repository.AddRepo(this->newCoat.GetSize(), this->newCoat.GetColor(), this->newCoat.GetPrice(), this->newCoat.GetQuantity(), this->newCoat.GetPhotograph());
}
