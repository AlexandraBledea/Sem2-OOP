#pragma once


#include <string>
using namespace std;
class Gene {
private:
    string organism_name;
    string gene_name;
    string sequence;

public:

    Gene();

    Gene(string organism_name, string gene_name, string sequence);

    string GetOrganismName();

    string GetGeneName();

    string GetSequence();
};

