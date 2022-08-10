//
// Created by Alexandra on 4/5/2021.
//

#include "Service.h"

/// With this function we add a new gene
/// \param organism_name the name of the organism
/// \param gene_name the name of the gene
/// \param sequence the sequence
/// \return It returns 0 of the gene was added successfully or 1 if it already exists
int Service::AddService(string organism_name, string gene_name, string sequence) {
    Gene Gene(organism_name, gene_name, sequence);
    if(this->repository->AddRepo(Gene) == 0)
        return 0;
    else
        return 1;
}

DynamicArray<Gene> *Service::GetAll() {
    return this->repository->GetDynArr();
}

Service::Service(Repository *repository) {
    this->repository=repository;

}
Service::~Service() {
    delete this->repository;

}

void Service::Sort() {
    for(int i=0; i < this->repository->GetSize()-1; i++)
        for(int j=i+1; j<this->repository->GetSize(); j++)
            if((*this->repository->GetDynArr())[i].GetSequence().length() < (*this->repository->GetDynArr())[j].GetSequence().length())
            {
                Gene aux;
                 aux = (*this->repository->GetDynArr())[i];
                (*this->repository->GetDynArr())[i] = (*this->repository->GetDynArr())[j];
                (*this->repository->GetDynArr())[j] = aux;

            }
}

int Service::GetSize() {
    return this->repository->GetSize();
}
