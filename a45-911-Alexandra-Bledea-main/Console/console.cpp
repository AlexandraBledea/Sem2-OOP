//
// Created by Alexandra on 3/17/2021.
//

#include "console.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

Console::Console() {

}

Console::Console(Service *service, Validator* validator) {
    this->service = service;
    this->validator = validator;
}

Console::~Console() {
    delete this->service;
    delete this->validator;
}

void Console::AddAdminConsole() {
    string size;
    string color;
    string str_price;
    int price;
    string str_quantity;
    int quantity;
    string photograph;
    cout<<"Type in the size: ";
    cin>>size;
    cout<<"\nType in the color: ";
    cin>>color;
    cout<<"\nType in the price: ";
    cin>>str_price;
    cout<<"\nType in the quantity: ";
    cin>>str_quantity;
    cout<<"\nType in the photograph: ";
    cin>>photograph;
    price = this->validator->validate_price_product(str_price);
    quantity = this->validator->validate_quantity_product(str_quantity);
    if(!this->validator->validate_color_product(color) || !this->validator->validate_size_product(size) || price == -1
    || quantity == -1 || !this->validator->validate_photograph_product(photograph))
        cout<<"Invalid input!\n";
    else
    {
        if(this->service->AddService(size, color, price, quantity, photograph) == 0)
            cout<<"The product was added successfully!\n";
        else
            cout<<"The given product already exists!\n";
    }
}

void Console::DisplayProductsAdmin() {
    //this->service->print();
    for(int i = 0; i < this->service->GetSize(); i++)
        cout<<i+1<<")  ""Size: "<<(*this->service->GetRepository())[i].GetSize()<<" Color: " <<
        (*this->service->GetRepository())[i].GetColor() << " Price: " << (*this->service->GetRepository())[i].GetPrice()
        <<" Quantity: " << (*this->service->GetRepository())[i].GetQuantity()<<"\nLink Photo: "
        << (*this->service->GetRepository())[i].GetPhotograph()<<"\n"<<"\n";
}


void Console::UpdateProductsPriceAdmin() {
    string size;
    string color;
    string str_price;
    int price;
    string photograph;
    cout<<"Type in the size: ";
    cin>>size;
    cout<<"\nType in the color: ";
    cin>>color;
    cout<<"\nType in the price: ";
    cin>>str_price;
    cout<<"\nType in the photograph: ";
    cin>>photograph;
    price = this->validator->validate_price_product(str_price);
    if(!this->validator->validate_color_product(color) || !this->validator->validate_size_product(size) || price == -1
       || !this->validator->validate_photograph_product(photograph))
        cout<<"Invalid input!\n";
    else
    {
        if(this->service->UpdatePriceService(size, color, photograph, price) == 0)
            cout<<"The product was updated successfully!\n";
        else
            cout<<"The given product doesn't exist!";
    }

}

void Console::UpdateProductsQuantityAdmin() {
    string size;
    string color;
    string str_quantity;
    int quantity;
    string photograph;
    cout<<"Type in the size: ";
    cin>>size;
    cout<<"\nType in the color: ";
    cin>>color;
    cout<<"\nType in the quantity: ";
    cin>>str_quantity;
    cout<<"\nType in the photograph: ";
    cin>>photograph;
    quantity = this->validator->validate_quantity_product(str_quantity);
    if(!this->validator->validate_color_product(color) || !this->validator->validate_size_product(size) ||
       quantity == -1 || !this->validator->validate_photograph_product(photograph))
        cout<<"Invalid input!\n";
    else
    {
        if(this->service->UpdateQuantityService(size, color, photograph, quantity) == 0)
            cout<<"The product was updated successfully!\n";
        else
            cout<<"The given product doesn't exist!";
    }
}

void Console::DeleteSoldOutProductAdmin() {
    string size;
    string color;
    string photograph;
    cout<<"Type in the size: ";
    cin>>size;
    cout<<"\nType in the color: ";
    cin>>color;
    cout<<"\nType in the photograph: ";
    cin>>photograph;

    if(!this->validator->validate_color_product(color) || !this->validator->validate_size_product(size) ||
       !this->validator->validate_photograph_product(photograph))
        cout<<"Invalid input!\n";
    else
    {
        if(this->service->DeleteService(size, color, photograph, 2) == 0)
            cout<<"The product was deleted successfully!\n";
        else
            cout<<"The given product isn't sold out or it doesn't exist!\n";
    }
}

void Console::DeleteEntireProductAdmin() {
    string size;
    string color;
    string photograph;
    cout<<"Type in the size: ";
    cin>>size;
    cout<<"\nType in the color: ";
    cin>>color;
    cout<<"\nType in the photograph: ";
    cin>>photograph;
    if(!this->validator->validate_color_product(color) || !this->validator->validate_size_product(size) ||
       !this->validator->validate_photograph_product(photograph))
        cout<<"Invalid input!\n";
    else
    {
        if(this->service->DeleteService(size, color, photograph, 1) == 0)
            cout<<"The product was deleted successfully!\n";
        else
            cout<<"The given product doesn't exist!\n";
    }
}

void Console::MenuAdminMode() {

    cout<<"Type 1 for adding a product!\n";
    cout<<"Type 2 for displaying the products!\n";
    cout<<"Type 3 for deleting a product!\n";
    cout<<"Type 4 for deleting a sold out product!\n";
    cout<<"Type 5 for updating the price of a product!\n";
    cout<<"Type 6 for updating the quantity of a product!\n";
    cout<<"Type H for displaying the menu!\n";
    cout<<"Type E in order to exit the program!\n";
}

void Console::AdministratorMode() {
    bool Administrator_Mode = false;
    MenuAdminMode();
    while(Administrator_Mode == false)
    {
        string command;
        cout<<"\nCommand> ";
        cin>>command;
        if(command != "1" && command != "2" && command != "3" && command != "4" && command != "5" && command != "6" &&
        command != "E" && command != "H")
            cout<<"Invalid command!\n";
        else
            switch(command[0])
            {

                case '1':
                    AddAdminConsole();
                    break;

                case '2':
                    DisplayProductsAdmin();
                    break;

                case '3':
                    DeleteEntireProductAdmin();
                    break;

                case '4':
                    DeleteSoldOutProductAdmin();
                    break;

                case '5':
                    UpdateProductsPriceAdmin();
                    break;

                case '6':
                    UpdateProductsQuantityAdmin();
                    break;

                case 'H':
                    MenuAdminMode();
                    break;

                case 'E':
                    Administrator_Mode = true;
                    break;
            }

    }
}

void MenuUserMode()
{
    cout<<"Type 1 for buying products!\n";
    cout<<"Type 2 for displaying the shopping basket!\n";
    cout<<"Type E for exit!\n";
}

int Console::DisplayProductsUser() {
    int i = 0;
    if(i < this->service->GetSize())
    {
        cout<<"Size: "<<(*this->service->GetRepository())[i].GetSize()<<" Color: " <<
            (*this->service->GetRepository())[i].GetColor() << " Price: " << (*this->service->GetRepository())[i].GetPrice()
            <<" Quantity: " << (*this->service->GetRepository())[i].GetQuantity()<<"\nLink Photo: "
            << (*this->service->GetRepository())[i].GetPhotograph()<<"\n"<<"\n";
        ShellExecute(NULL, "open", (*this->service->GetRepository())[i].GetPhotograph().c_str(), NULL, NULL, SW_SHOWNORMAL);
        cout<<"Buy or go Next\n";
        while(i < this->service->GetSize())
        {
            string command;
            cout<<"\nCommand> ";
            cin>>command;
            if(command != "Buy" && command != "Next" && command != "Pay")
                cout<<"Invalid command!";
            else
            {
                if(command == "Buy")
                {
                    this->service->UpdateQuantityService((*this->service->GetRepository())[i].GetSize(),
                                                         (*this->service->GetRepository())[i].GetColor(), (*this->service->GetRepository())[i].GetPhotograph(),
                                                         (*this->service->GetRepository())[i].GetQuantity() - 1);
                    Coat c((*this->service->GetRepository())[i].GetSize(),(*this->service->GetRepository())[i].GetColor(),
                           (*this->service->GetRepository())[i].GetPrice(), 1, (*this->service->GetRepository())[i].GetPhotograph());
                    if( this->service->AddUserService((*this->service->GetRepository())[i], c) == 1)
                        i--;
                }
                if(command == "Next")
                {
                    i++;
                    if(i < this->service->GetSize()) {
                        cout << "Size: " << (*this->service->GetRepository())[i].GetSize() << " Color: " <<
                             (*this->service->GetRepository())[i].GetColor() << " Price: "
                             << (*this->service->GetRepository())[i].GetPrice()
                             << " Quantity: " << (*this->service->GetRepository())[i].GetQuantity() << "\nLink Photo: "
                             << (*this->service->GetRepository())[i].GetPhotograph() << "\n" << "\n";
                        ShellExecute(NULL, "open", (*this->service->GetRepository())[i].GetPhotograph().c_str(), NULL,
                                     NULL, SW_SHOWNORMAL);
                        cout<<"Buy or go Next\n";
                    }
                    else
                        return 0;
                }
                if(command == "Pay")
                {
                    return -1;
                }
            }
        }
    }
    return 1;
}


void Console::MenuDisplayProductsUser()
{
    int done = 0;
    if(this->service->GetSize() == 0)
        cout<<"There are no products on stock!";
    else{
        while(done == 0)
        {
            done = DisplayProductsUser();
        }
    }
    if(done == 1)
        cout<<"There are no products left on stock!";

}

void Console::DisplayShoppingBag() {
    for(int i = 0; i < this->service->GetUserRepository()->GetSize(); i++)
        cout<<i+1<<")  ""Size: "<<(*this->service->GetUserRepository())[i].GetSize()<<" Color: " <<
            (*this->service->GetUserRepository())[i].GetColor() << " Price: " << (*this->service->GetUserRepository())[i].GetPrice()
            <<" Quantity: " << (*this->service->GetUserRepository())[i].GetQuantity()<<"\nLink Photo: "
            << (*this->service->GetUserRepository())[i].GetPhotograph()<<"\n"<<"\n";
    cout<<"Total price of the items: "<<this->service->GetTotalPrice()<<'\n';
}


void Console::UserMode() {
    bool User_Mode = false;

    MenuUserMode();
    while(!User_Mode)
    {
        string command;
        cout<<"\nCommand> ";
        cin>>command;
        if(command != "1" && command != "2" && command != "E" && command != "H")
            cout<<"Invalid command!\n";
        else
            switch(command[0])
            {

                case '1':
                    MenuDisplayProductsUser();
                    break;

                case '2':
                    DisplayShoppingBag();
                    break;

                case 'H':
                    MenuUserMode();
                    break;

                case 'E':
                    User_Mode = true;
                    break;
            }

    }
}


void Console::Start() {

    bool Done = false;

    while(!Done)
    {
        string command;
        cout<<"Type 1 for Administrator Mode or type 2 for User Mode:  ";
        cin>>command;
        cout<<'\n';
        if(command != "1" && command != "2" && command != "E")
            cout<<"Invalid command!\n";
        else
            switch(command[0])
            {
                case '1':
                    AdministratorMode();
                    break;

                case '2':
                    UserMode();
                    break;


                case 'E':
                    Done = true;
                    break;
            }

    }
}


