//
// Created by Alexandra on 4/6/2021.
//

#include "FileRepository.h"
#include "Exceptions.h"

FileRepository::FileRepository(string file):Repository() {
    this->FileName = file;
    this->LoadData();
//    ofstream outFile(file);
//    outFile<< "";
}

void FileRepository::AddRepo(string size, string color, int price, int quantity, string photograph) {

    int position;
    position = this->CheckExistenceCoat(size, color, photograph);
    if(position != -1)
    {
        throw ExceptionsRepository("The given product already exists!");
    }
    else
    {
        Coat c(size, color, price, quantity, photograph);
        elements.push_back(c);
        WriteData();
    }
}

void FileRepository::DeleteEntireProductRepo(string size, string color, string photograph) {
    int position = this->CheckExistenceCoat(size, color, photograph);
    if(position != -1)
    {
        elements.erase(elements.begin() + position);
        WriteData();
    }
    else
        throw ExceptionsRepository("The given product doesn't exist!");
}

void FileRepository::UpdatePriceRepo(string size, string color, string photograph, int price) {
    int position = this->CheckExistenceCoat(size, color, photograph);
    if(position != -1)
    {
        int quantity = elements[position].GetQuantity();
        Coat c(size, color, price, quantity, photograph);
        elements[position] = c;
        WriteData();
    }
    else
        throw ExceptionsRepository("The given product doesn't exist!");
}

void FileRepository::UpdateQuantityRepo(string size, string color, string photograph, int quantity) {
    int position = this->CheckExistenceCoat(size, color, photograph);
    if(position != -1)
    {
        int price = elements[position].GetPrice();
        Coat c(size, color, price, quantity, photograph);
        elements[position] = c;
        WriteData();
    }
    else
        throw ExceptionsRepository("The given product doesn't exist!");
}

void FileRepository::DeleteSoldOutProductRepo(string size, string color, string photograph) {
    int position = this->CheckExistenceCoat(size, color, photograph);
    int quantity = elements[position].GetQuantity();
    if(position != -1 && quantity == 0)
    {
        elements.erase(elements.begin() + position);
        WriteData();
    }
    else
        throw ExceptionsRepository("The given product isn't sold out or it doesn't exist!");
}

int FileRepository::CheckExistenceCoat(string size, string color, string photograph) {
    for(int i = 0; i < elements.size(); i++)
        if(elements[i].GetSize() == size && elements[i].GetColor() == color && elements[i].GetPhotograph() == photograph)
            return i;
    return -1;
}

int FileRepository::GetSize() {
    return elements.size();
}

void FileRepository::WriteData() {

    ofstream  outFile(this->FileName);
    for(auto CurrentElement: this->elements)
    {
        outFile << CurrentElement<<'\n';
    }
}

void FileRepository::LoadData() {
    ifstream inFile(this->FileName);
    Coat CurrentElement;
    while (inFile >> CurrentElement)
    {
        this->elements.push_back(CurrentElement);
    }
}

const vector<Coat> &FileRepository::GetDynArr() {
    return elements;
}

//vector<Coat> FileRepository::LoadData() {
//    ifstream inFile(this->FileName);
//    vector<Coat> elements;
//    Coat CurrentElement;
//    while (inFile >> CurrentElement)
//    {
//        elements.push_back(CurrentElement);
//    }
//    return elements;
//}


//void FileRepository::WriteData(vector<Coat> Data) {
//
//    ofstream  outFile(this->FileName);
//    for(auto CurrentElement: Data)
//    {
//        outFile << CurrentElement<<'\n';
//    }
//}


//const vector<Coat> &FileRepository::GetDynArr() {
//    vector<Coat>* elements = new vector<Coat>;
//    elements->reserve(this->GetSize());
//    for(int i = 0; i < this->GetSize(); i++)
//    {
//        elements->push_back(this->GetElement(i));
//    }
//    return *elements;
//}


//vector<Coat> FileRepository::GetDynArr() {
//    vector<Coat> elements;
//    elements.reserve(this->GetSize());
//    for(int i = 0; i < this->GetSize(); i++)
//    {
//        elements.push_back(this->GetElement(i));
//    }
//    return elements;
//}

//Coat FileRepository::GetElement(int position) {
//    vector<Coat> elements = LoadData();
//    return elements[position];
//}
