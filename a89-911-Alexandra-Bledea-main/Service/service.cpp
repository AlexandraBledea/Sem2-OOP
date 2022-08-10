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
    this->repository.AddRepo(size, color, price, quantity, photograph);
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
        this->repository.DeleteEntireProductRepo(size, color, photograph);
    } else if (criteria == 2) {
        this->repository.DeleteSoldOutProductRepo(size, color, photograph);
    }
}

void Service::UpdatePriceService(string size, string color, string photograph, int price) {
    this->repository.UpdatePriceRepo(size, color, photograph, price);
}

void Service::UpdateQuantityService(string size, string color, string photograph, int quantity) {
    this->repository.UpdateQuantityRepo(size, color, photograph, quantity);
}

int Service::AddUserService(Coat c, Coat cUser) {
    int index = this->user_repository.CheckExistenceCoat(cUser.GetSize(), cUser.GetColor(), cUser.GetPhotograph());
    if(index == -1) {
        this->user_repository.AddRepo(cUser.GetSize(), cUser.GetColor(), cUser.GetPrice(), cUser.GetQuantity(),
                                       c.GetPhotograph());
        this->total_price = this->total_price + cUser.GetPrice();
    }
    else {
        int new_quantity = this->user_repository.GetDynArr()[index].GetQuantity() + 1;
        this->user_repository.UpdateQuantityRepo(cUser.GetSize(), cUser.GetColor(), cUser.GetPhotograph(), new_quantity);
        this->total_price = this->total_price + cUser.GetPrice();
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


//void Service::print() {
//    this->repository->print_repository();
//}



