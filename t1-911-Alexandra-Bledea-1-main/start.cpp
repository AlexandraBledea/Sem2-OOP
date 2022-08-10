//
// Created by Alexandra on 4/5/2021.
//
#include <iostream>
#include <Repository.h>
#include "dynamic_array.h"
#include "Service.h"
#include "Gene.h"
#include "Test/Test.h"
#include "Console.h"
using namespace std;

int main()
{
    DynamicArray<Gene>* DA = new DynamicArray<Gene>(100);
    Repository* repo = new Repository(DA);
    repo->init_repository();
    Service* service = new Service(repo);
    Console* console = new Console(service);
    Test T;
    T.TestAll();
    console->Start();

    delete console;
    return 0;
}