//
// Created by Alexandra on 4/6/2021.
//

#pragma once
#include "repository.h"
#include <fstream>
using namespace std;

class FileRepository: public Repository
{
public:
    FileRepository(string file);

    const vector<Coat>& GetDynArr() override;
//    vector<Coat> GetDynArr() override;
    void AddRepo(string size, string color, int price, int quantity, string photograph) override;
    void DeleteEntireProductRepo(string size, string color, string photograph) override;
    void DeleteSoldOutProductRepo(string size, string color, string photograph) override;
    void UpdatePriceRepo(string size, string color, string photograph, int price) override;
    void UpdateQuantityRepo(string size, string color, string photograph, int quantity) override;
    int CheckExistenceCoat(string size, string color, string photograph) override;
    int GetSize() override;

private:
    string FileName;
//    Coat GetElement(int position);
//    vector<Coat> LoadData();
//    void WriteData( vector<Coat> Data);
    void LoadData();
    void WriteData();
};

