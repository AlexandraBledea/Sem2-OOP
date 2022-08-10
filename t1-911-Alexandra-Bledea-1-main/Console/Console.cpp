//
// Created by Alexandra on 4/5/2021.
//

#include <iostream>
#include "Console.h"
#include <iomanip>
using namespace std;
Console::Console() {

}

Console::~Console() {
    delete this->service;
}


void Console::Display() {
    this->service->Sort();
    for(int i=0; i<this->service->GetSize(); i++)
        cout<< setw(3)<<(*this->service->GetAll())[i].GetOrganismName()<< setw(15)<< " | " << setw(3) << (*this->service->GetAll())[i].GetGeneName() <<
       setw(3) << " | " << setw(30) << (*this->service->GetAll())[i].GetSequence()<<setw(3)<<'\n';
}

void Console::AddGeneUI() {
    string organism_name;
    string gene_name;
    string sequence;
    cout<<"Type in the organism name: ";
    cin>>organism_name;
    cout<<"Type in the gene name: ";
    cin>>gene_name;
    cout<<"Type in the sequence: ";
    cin>>sequence;
    if ((sequence.find('ACGT') == std::string::npos) || (sequence.find(
            '1234567890') != std::string::npos) || (sequence.find('bdefhijklmnopqrsuvwqxyBDEFHIJKLMNOPQRSUVWXYZ') != std::string::npos) ||
            (sequence.find('!@#$%^&*(_)+{}":?><|}~') != std::string::npos))
        cout<<"Invalid sequence input!\n";
    else
    {
        if(this->service->AddService(organism_name, gene_name, sequence) == 0)
            cout<<"The gene was successfully added!\n";
        else
            cout<<"There exists a gene with the given name for the organism and for the gene!\n";
    }
}

Console::Console(Service *service) {
    this->service = service;
}

void Console::Menu() {

    cout<<"Type 1 for adding a new gene!\n";
    cout<<"Type 2 for displaying all the genes!\n";
    cout<<"Type 3 for searching the genes by a given substring!\n";
    cout<<"Type 4 for searching the longest subsequence!\n";
}


void Console::Start() {
    bool Done = false;

    while(!Done)
    {
        cout<<"\n";
        Menu();
        string command;
        cout<<"Type in the command: ";
        cin>>command;
        cout<<'\n';
        if(command != "1" && command != "2" && command != "3"  && command != "4" && command != "E")
            cout<<"Invalid command!\n";
        else
            switch(command[0])
            {
                case '1':
                    AddGeneUI();
                    break;

                case '2':
                    Display();
                    break;

                case '3':
                    break;

                case '4':
                    break;

                case 'E':
                    Done = true;
                    break;
            }

    }
}
