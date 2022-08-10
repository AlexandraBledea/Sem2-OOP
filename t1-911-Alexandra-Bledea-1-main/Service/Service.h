//
// Created by Alexandra on 4/5/2021.
//

#pragma once
#include <cstdlib>
#include "dynamic_array.h"
#include "Repository.h"
#include "Gene.h"


class Service {

private:
    Repository* repository;

public:

~Service();

Service(Repository* repository);

int AddService(string organism_name, string gene_name, string sequence);

void Sort();

int GetSize();

DynamicArray<Gene>* GetAll();

};

