//
// Created by Alexandra on 3/17/2021.
//

#include "service.h"

//Service::Service() {
//
//}

Service::Service(Repository& repository, Repository& user_repository):
    repository{repository}, user_repository{user_repository}, total_price{0}
{
}

//Service::~Service() {
//    delete this->repository;
//    delete this->user_repository;
//}

void Service::AddService(string size, string color, int price, int quantity, string photograph) {
    Coat newCoat{size, color, price, quantity, photograph};
    this->repository.AddRepo(size, color, price, quantity, photograph);
    Action* currentAction = new AddAction(this->repository, newCoat);
    this->undoStackAdminMode.push_back(currentAction);
    this->redoStackAdminMode.clear();
}

const vector<Coat>& Service::GetRepository() {
    return this->repository.GetDynArr();
}

//vector<Coat> Service::GetRepository() {
//    return this->repository.GetDynArr();
//}

vector<Coat> Service::GetUserRepository() {
    return this->user_repository.GetDynArr();
}

int Service::GetSize() {
    return this->repository.GetSize();
}

void Service::DeleteService(string size, string color, string photograph, int criteria) {
    if (criteria == 1) {
        Coat deletedCoat = this->repository.getCoat(size, color, photograph);
        this->repository.DeleteEntireProductRepo(size, color, photograph);
        Action* currentAction = new DeleteAction(this->repository, deletedCoat);
        this->undoStackAdminMode.push_back(currentAction);
        this->redoStackAdminMode.clear();
    } else if (criteria == 2) {
        Coat deletedCoat = this->repository.getCoat(size, color, photograph);
        this->repository.DeleteSoldOutProductRepo(size, color, photograph);
        Action* currentAction = new DeleteAction(this->repository, deletedCoat);
        this->undoStackAdminMode.push_back(currentAction);
        this->redoStackAdminMode.clear();
    }
}

void Service::UpdatePriceService(string size, string color, string photograph, int price) {
    Coat oldCoat = this->repository.getCoat(size, color, photograph);
    Coat newCoat = Coat{size, color, price, oldCoat.GetQuantity(), photograph};
    this->repository.UpdatePriceRepo(size, color, photograph, price);
    Action* currentAction = new UpdatePriceAction(this->repository, oldCoat, newCoat);
    this->undoStackAdminMode.push_back(currentAction);
    this->redoStackAdminMode.clear();
}

void Service::UpdateQuantityService(string size, string color, string photograph, int quantity) {
    Coat oldCoat = this->repository.getCoat(size, color, photograph);
    Coat newCoat = Coat{size, color, oldCoat.GetPrice(), quantity, photograph};
    this->repository.UpdateQuantityRepo(size, color, photograph, quantity);
    Action* currentAction = new UpdateQuantityAction(this->repository, oldCoat, newCoat);
    this->undoStackAdminMode.push_back(currentAction);
    this->redoStackAdminMode.clear();
}

int Service::AddUserService(Coat c, Coat cUser) {

    int index = this->user_repository.CheckExistenceCoat(cUser.GetSize(), cUser.GetColor(), cUser.GetPhotograph());
    if(index == -1) {

        this->user_repository.AddRepo(cUser.GetSize(), cUser.GetColor(), cUser.GetPrice(), cUser.GetQuantity(),
                                       c.GetPhotograph());
        if(c.GetQuantity() == 0){
            Action* currentAction = new AddDeleteActionUserMode(this->repository, this->user_repository, c, cUser);
            this->undoStackUserMode.push_back(currentAction);
            this->redoStackUserMode.clear();
        }
        else {
            Action* currentAction = new AddActionUserMode(this->repository, this->user_repository, c,
                                                                                        cUser);
            this->undoStackUserMode.push_back(currentAction);
            this->redoStackUserMode.clear();
        }
        this->total_price = this->total_price + cUser.GetPrice();
    }
    else {

        Coat oldCoatUser = this->user_repository.getCoat(cUser.GetSize(), cUser.GetColor(), cUser.GetPhotograph());
        Coat newCoatUser = Coat{oldCoatUser.GetSize(), oldCoatUser.GetColor(), oldCoatUser.GetPrice(), oldCoatUser.GetQuantity() + 1, oldCoatUser.GetPhotograph()};
        int new_quantity = this->user_repository.GetDynArr()[index].GetQuantity() + 1;

        this->user_repository.UpdateQuantityRepo(cUser.GetSize(), cUser.GetColor(), cUser.GetPhotograph(), new_quantity);
        this->total_price = this->total_price + cUser.GetPrice();
        if(c.GetQuantity() == 0){
            Action* currentAction = new UpdateActionDeletedUserMode(this->repository, this->user_repository, oldCoatUser, newCoatUser, c);
            this->undoStackUserMode.push_back(currentAction);
            this->redoStackUserMode.clear();
        }
        else {
            Action* currentAction = new UpdateActionUserMode(this->repository, this->user_repository, oldCoatUser, newCoatUser, c);
            this->undoStackUserMode.push_back(currentAction);
            this->redoStackUserMode.clear();
        }
    }
    if(c.GetQuantity() == 0) {
        this->repository.DeleteSoldOutProductRepo(c.GetSize(), c.GetColor(), c.GetPhotograph());

        return 1;
    }
    return 0;
}

int Service::GetTotalPrice() const {
    return this->total_price;
}

vector<Coat> Service::GetFilteredRepository(string size) {
    if(size == "All sizes")
        return this->GetRepository();
    else{
        vector<Coat> elements(GetRepository().size());
        auto it = copy_if(GetRepository().begin(), GetRepository().end(), elements.begin(),
                          [size](Coat coat){ return coat.GetSize()==size;});
        elements.resize(it - elements.begin());
        return elements;
    }
}

void Service::undoLastAction(std::vector<Action*> &currentUndoStack, std::vector<Action*> &currentRedoStack) {
    if (currentUndoStack.empty()) {
        throw ExceptionsService("no more undos");
    }

    Action* currentAction = currentUndoStack.back();
    currentAction->executeUndo();
    currentRedoStack.push_back(currentAction);
    currentUndoStack.pop_back();
}

void Service::redoLastAction(std::vector<Action*> &currentUndoStack, std::vector<Action*> &currentRedoStack) {
    if (currentRedoStack.size() == 0) {
        throw ExceptionsService("no more redos");
    }

    Action* currentAction = currentRedoStack.back();
    currentAction->executeRedo();
    currentUndoStack.push_back(currentAction);
    currentRedoStack.pop_back();
}

void Service::undoAdminMode() {
    this->undoLastAction(this->undoStackAdminMode, this->redoStackAdminMode);
}

void Service::redoAdminMode() {
    this->redoLastAction(this->undoStackAdminMode, this->redoStackAdminMode);
}

void Service::undoUserMode() {
    this->undoLastAction(this->undoStackUserMode, this->redoStackUserMode);
}

void Service::redoUserMode() {
    this->redoLastAction(this->undoStackUserMode, this->redoStackUserMode);
}



//void Service::print() {
//    this->repository->print_repository();
//}



