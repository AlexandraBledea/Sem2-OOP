//
// Created by Alexandra on 3/23/2021.
//
#include "dynamic_array.h"
#include "repository.h"
#include "service.h"
#include "test_service.h"
#include <assert.h>

void Test_Service::TestAddService() {
    DynamicArray<Coat>* UserDA = new DynamicArray<Coat>(100);
    DynamicArray<Coat>* DA = new DynamicArray<Coat>(100);
    Repository* UserRepo = new Repository(UserDA);
    Repository* repo = new Repository(DA);
    Service* service = new Service(repo, UserRepo);
    assert(service->AddService("XL", "Pink", 100, 10, "https://abcd.com") == 0);
    assert(service->AddService("XL", "Pink", 100, 10, "https://abcd.com") == 1);
    delete service;
}

void Test_Service::TestGetRepository() {
    DynamicArray<Coat>* UserDA = new DynamicArray<Coat>(100);
    DynamicArray<Coat>* DA = new DynamicArray<Coat>(100);
    Repository* UserRepo = new Repository(UserDA);
    Repository* repo = new Repository(DA);
    Service* service = new Service(repo, UserRepo);
    assert(service->GetRepository() == DA);
    delete service;
}

void Test_Service::TestDeleteService() {
    DynamicArray<Coat>* UserDA = new DynamicArray<Coat>(100);
    DynamicArray<Coat>* DA = new DynamicArray<Coat>(100);
    Repository* UserRepo = new Repository(UserDA);
    Repository* repo = new Repository(DA);
    Service* service = new Service(repo, UserRepo);

    service->AddService("XL", "Pink", 100, 10, "https://abcd.com");
    assert(service->DeleteService("XL", "Pink", "https://abcd.com", 1) == 0);
    assert(service->DeleteService("XL", "Pink", "https://abcd.com", 1) == 1);

    service->AddService("XL", "Pink", 100, 0, "https://abcd.com");
    assert(service->DeleteService("XL", "Pink", "https://abcd.com", 2) == 0);
    assert(service->DeleteService("XL", "Pink", "https://abcd.com", 2) == 1);
    assert(service->DeleteService("XL", "Pink", "https://abcd.com", 4) == 1);

    delete service;
}

void Test_Service::TestUpdatePriceService() {
    DynamicArray<Coat>* UserDA = new DynamicArray<Coat>(100);
    DynamicArray<Coat>* DA = new DynamicArray<Coat>(100);
    Repository* UserRepo = new Repository(UserDA);
    Repository* repo = new Repository(DA);
    Service* service = new Service(repo, UserRepo);
    service->AddService("XL", "Pink", 100, 10, "https://abcd.com");
    assert(service->UpdatePriceService("XL", "Pink", "https://abcd.com", 200) == 0);
    assert(service->UpdatePriceService("XL", "Purple", "https://abcdaadsd.com", 200) == 1);

    delete service;
}

void Test_Service::TestUpdateQuantityService() {
    DynamicArray<Coat>* UserDA = new DynamicArray<Coat>(100);
    DynamicArray<Coat>* DA = new DynamicArray<Coat>(100);
    Repository* UserRepo = new Repository(UserDA);
    Repository* repo = new Repository(DA);
    Service* service = new Service(repo, UserRepo);
    service->AddService("XL", "Pink", 100, 10, "https://abcd.com");
    assert(service->UpdateQuantityService("XL", "Pink", "https://abcd.com", 200) == 0);
    assert(service->UpdateQuantityService("XL", "Purple", "https://abcdaadsd.com", 200) == 1);

    delete service;
}

void Test_Service::TestGetSize() {
    DynamicArray<Coat>* UserDA = new DynamicArray<Coat>(100);
    DynamicArray<Coat>* DA = new DynamicArray<Coat>(100);
    Repository* UserRepo = new Repository(UserDA);
    Repository* repo = new Repository(DA);
    Service* service = new Service(repo, UserRepo);
    service->AddService("XL", "Pink", 100, 10, "https://abcd.com");
    assert(service->GetSize() == 1);
    delete service;
}

void Test_Service::TestAddUserService() {
    DynamicArray<Coat>* UserDA = new DynamicArray<Coat>(100);
    DynamicArray<Coat>* DA = new DynamicArray<Coat>(100);
    Repository* UserRepo = new Repository(UserDA);
    Repository* repo = new Repository(DA);
    Service* service = new Service(repo, UserRepo);
    service->AddService("XL", "Pink", 100, 10, "https://abcd.com");
    Coat c("XL", "Pink", 100, 3, "https://abcd.com");
    Coat cUser("XL", "Pink", 100, 1, "https://abcd.com");
    assert(service->AddUserService(c, cUser) == 0);
    assert((*UserRepo->GetDynArr())[0].GetSize() == "XL");
    assert((*UserRepo->GetDynArr())[0].GetColor() == "Pink");
    assert((*UserRepo->GetDynArr())[0].GetPrice() == 100);
    assert((*UserRepo->GetDynArr())[0].GetQuantity() == 1);
    assert((*UserRepo->GetDynArr())[0].GetPhotograph() == "https://abcd.com");
    assert(service->AddUserService(c, cUser) == 0);
    assert((*UserRepo->GetDynArr())[0].GetQuantity() == 2);
    Coat cc("XL", "Purple", 100, 0, "https://sag.com");
    assert(service->AddUserService(cc, cUser) == 1);
    delete service;
}

void Test_Service::TestGetTotalPrice() {
    DynamicArray<Coat>* UserDA = new DynamicArray<Coat>(100);
    DynamicArray<Coat>* DA = new DynamicArray<Coat>(100);
    Repository* UserRepo = new Repository(UserDA);
    Repository* repo = new Repository(DA);
    Service* service = new Service(repo, UserRepo);
    assert(service->GetTotalPrice() == 0);
    delete service;
}

void Test_Service::TestGetUserRepository() {
    DynamicArray<Coat>* UserDA = new DynamicArray<Coat>(100);
    DynamicArray<Coat>* DA = new DynamicArray<Coat>(100);
    Repository* UserRepo = new Repository(UserDA);
    Repository* repo = new Repository(DA);
    Service* service = new Service(repo, UserRepo);
    assert(service->GetUserRepository() == UserDA);
    delete service;
}

void Test_Service::TestAllService() {
    TestAddService();
    TestGetRepository();
    TestDeleteService();
    TestUpdatePriceService();
    TestUpdateQuantityService();
    TestGetSize();
    TestAddUserService();
    TestGetUserRepository();
    TestGetTotalPrice();
}


