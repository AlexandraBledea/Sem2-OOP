//
// Created by Alexandra on 4/15/2021.
//

#include "CSVShoppingBasket.h"
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

void CSVShoppingBasket::write() {
    ofstream outFile(this->FileName);
    for(auto CurrentElement: this->elements)
    {
        outFile << CurrentElement.GetSize()<<','<<CurrentElement.GetColor()<<','<<CurrentElement.GetPrice()<<','
                <<CurrentElement.GetQuantity()<<','<<CurrentElement.GetPhotograph()<<'\n';
    }
    outFile.close();
    this->elements.clear();
}

void CSVShoppingBasket::open() {
    ifstream  inFile(this->FileName);

    ShellExecute(nullptr, nullptr,
                 R"(C:\Users\Alexandra\Desktop\Facultate\Semestru 2\911\a10-911-Alexandra-Bledea-1\ShoppingBasket.csv)",
                 nullptr, nullptr, SW_SHOWNORMAL);
}

CSVShoppingBasket::CSVShoppingBasket() {
    this->FileName = R"(C:\Users\Alexandra\Desktop\Facultate\Semestru 2\911\a10-911-Alexandra-Bledea-1\ShoppingBasket.csv)";
}

void CSVShoppingBasket::set_data(vector<Coat> data) {
    this->elements = move(data);
}


