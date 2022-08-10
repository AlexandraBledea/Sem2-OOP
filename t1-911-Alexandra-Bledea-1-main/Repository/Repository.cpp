//
// Created by Alexandra on 4/5/2021.
//

#include "Repository.h"

Repository::~Repository() {
    delete this->DArray;
}

void Repository::init_repository() {
    AddRepo(Gene("E_Coli_K12", "yqgE", "ATGACATCATCATTG"));
    AddRepo(Gene("M_tuberculosis", "ppiA", "TCTTCATCATCATCGG"));
    AddRepo(Gene("Mouse", "Col2a1", "TTAAAGCATGGCTCTGTG"));
    AddRepo(Gene("E_Coli_ETEC", "yqgE", "GTGACAGCGCCCTTCTTTCCACG"));
    AddRepo(Gene("E_Coli_K12", "hokC", "TTAATGAAGCATAAGCTTGATTTC"));
}

/// With this function we check if a gene do already exist
/// \param organism_name the name of the organism
/// \param gene_name the name of the gene
/// \return it returns -1 if the gene doesn't exist and its position in case it does
int Repository::CheckExistenceGene(string organism_name, string gene_name) {
    for(int i = 0; i < this->DArray->GetSize(); i++)
        if((*this->DArray)[i].GetOrganismName() == organism_name && (*this->DArray)[i].GetGeneName() == gene_name)
            return i;
    return -1;
}

Repository::Repository(DynamicArray<Gene> *DArray) {
    this->DArray = DArray;
}

/// With this function we add a new gene
/// \param gene the gene we are about to add
/// \return it returns 0 if the gene was added and 1 if it already exists
int Repository::AddRepo(Gene gene) {
    int position;
    position = CheckExistenceGene(gene.GetOrganismName(), gene.GetGeneName());
    if(position == -1)
    {
        this->DArray->Add(gene);
        return 0;
    }
    return 1;
}


DynamicArray<Gene>* Repository::GetDynArr() {
    return this->DArray;
}

int Repository::GetSize() {

    return this->DArray->GetSize();
}

