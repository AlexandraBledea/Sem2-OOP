//
// Created by Alexandra on 4/5/2021.
//

#pragma once
#include <cstdlib>
#include "Gene.h"
#include "dynamic_array.h"
class Repository {

private:
    DynamicArray<Gene>* DArray;

public:

DynamicArray<Gene>* GetDynArr();

void init_repository();

int AddRepo(Gene gene);

Gene& operator [] (int position) {
        return (*this->DArray)[position];
    }

~Repository();

int CheckExistenceGene(string organism_name, string gene_name);

int GetSize();

Repository(DynamicArray<Gene>* DArray);
};


