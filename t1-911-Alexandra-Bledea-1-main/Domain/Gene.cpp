//
// Created by Alexandra on 4/5/2021.
//
#include <string>
#include "Gene.h"
using namespace std;
Gene::Gene() {

}

Gene::Gene(string organism_name, string gene_name, string sequence): organism_name{organism_name},
gene_name{gene_name}, sequence{sequence}{

}

string Gene::GetOrganismName() {
    return this->organism_name;
}

string Gene::GetGeneName() {
    return this->gene_name;
}

string Gene::GetSequence() {
    return this->sequence;
}
