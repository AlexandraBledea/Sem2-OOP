//
// Created by Alexandra on 3/17/2021.
//

#include "service.h"

//Service::Service() {
//
//}

Service::Service(Repository *repository, Repository *user_repository) {
    this->repository = repository;
    this->user_repository = user_repository;
    this->total_price = 0;
}

Service::~Service() {
    delete this->repository;
    delete this->user_repository;
}

int Service::AddService(string size, string color, int price, int quantity, string photograph) {
    if(this->repository->AddRepo(size, color, price, quantity, photograph) == 0)
        return 0;
    else
        return 1;
}

DynamicArray<Coat> *Service::GetRepository() {
    return this->repository->GetDynArr();
}

DynamicArray<Coat> *Service::GetUserRepository() {
    return this->user_repository->GetDynArr();
}

int Service::GetSize() {
    return this->GetRepository()->GetSize();
}

int Service::DeleteService(string size, string color, string photograph, int criteria) {
    if (criteria == 1) {
        if (this->repository->DeleteEntireProductRepo(size, color, photograph) == 0)
            return 0;
        else
            return 1;
    } else if (criteria == 2) {
        if (this->repository->DeleteSoldOutProductRepo(size, color, photograph) == 0)
            return 0;
        else
            return 1;
    }
    return 1;
}

int Service::UpdatePriceService(string size, string color, string photograph, int price) {
    if(this->repository->UpdatePriceRepo(size, color, photograph, price) == 0)
        return 0;
    else
        return 1;
}

int Service::UpdateQuantityService(string size, string color, string photograph, int quantity) {
    if(this->repository->UpdateQuantityRepo(size, color, photograph, quantity) == 0)
        return 0;
    else
        return 1;
}

int Service::AddUserService(Coat c, Coat cUser) {
    int index = this->user_repository->CheckExistenceCoat(cUser.GetSize(), cUser.GetColor(), cUser.GetPhotograph());
    if(index == -1) {
        this->user_repository->AddRepo(cUser.GetSize(), cUser.GetColor(), cUser.GetPrice(), cUser.GetQuantity(),
                                       c.GetPhotograph());
        this->total_price = this->total_price + cUser.GetPrice();
    }
    else {
        int new_quantity = (*this->user_repository->GetDynArr())[index].GetQuantity() + 1;
        this->user_repository->UpdateQuantityRepo(cUser.GetSize(), cUser.GetColor(), cUser.GetPhotograph(), new_quantity);
        this->total_price = this->total_price + cUser.GetPrice();
    }
    if(c.GetQuantity() == 0) {
        this->repository->DeleteSoldOutProductRepo(c.GetSize(), c.GetColor(), c.GetPhotograph());
        return 1;
    }
    return 0;
}

int Service::GetTotalPrice() const {
    return this->total_price;
}


//void Service::print() {
//    this->repository->print_repository();
//}



