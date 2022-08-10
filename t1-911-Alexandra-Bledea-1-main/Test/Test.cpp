//
// Created by Alexandra on 4/5/2021.
//
#include "Service.h"
#include "Test.h"
#include "assert.h"
#include <iostream>
using namespace std;

void Test::test_add_service() {
    DynamicArray<Gene>* DA = new DynamicArray<Gene>(100);
    Repository* repo = new Repository(DA);
    Service* service = new Service(repo);

    assert(service->AddService("ABC", "Gna", "ATG") == 0);
    assert((*service->GetAll())[0].GetGeneName() == "Gna");
    assert((*service->GetAll())[0].GetOrganismName() == "ABC");
    assert((*service->GetAll())[0].GetSequence() == "ATG");
    assert(service->AddService("ABC", "Gna", "ATG") == 1);
}


void Test::test_add_repository() {
    DynamicArray<Gene>* DA = new DynamicArray<Gene>(100);
    Repository* repo = new Repository(DA);
    assert(repo->AddRepo(Gene("ABC", "Gna", "ATG")) == 0);
    assert((*repo->GetDynArr())[0].GetOrganismName() == "ABC");
    assert((*repo->GetDynArr())[0].GetSequence() == "ATG");
    assert((*repo->GetDynArr())[0].GetGeneName() == "Gna");
}

void Test::TestAll(){
    test_add_service();
    test_add_repository();
}

