//
// Created by Alexandra on 3/17/2021.
//

#include "console.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "repository.h"
#include "CSVShoppingBasket.h"
#include "HTMLShoppingBasket.h"
#include <algorithm>
#include "Exceptions.h"
using namespace std;


Console::Console(Service& service):
service{service}
{

}

//Console::~Console() {
//    delete this->service;
//    delete this->validator;
//}

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
//    cin>>color;
    cin.ignore();
    getline(cin, color);
    cout<<"\nType in the price: ";
    cin>>str_price;
    cout<<"\nType in the quantity: ";
    cin>>str_quantity;
    cout<<"\nType in the photograph: ";
    cin>>photograph;
    price = Validator::validate_price_product(str_price);
    quantity = Validator::validate_quantity_product(str_quantity);
    if(!Validator::validate_color_product(color) || !Validator::validate_size_product(size) || price == -1
    || quantity == -1 || !Validator::validate_photograph_product(photograph))
        throw ExceptionsValidator("Invalid input!");
    else
    {
        this->service.AddService(size, color, price, quantity, photograph);
            cout<<"The product was added successfully!\n";
    }
}

void Console::DisplayProductsAdmin() {
    //this->service->print();
    int count=0;
    for(auto i: this->service.GetRepository())
    {
        cout << count + 1 << ")  ""Size: " << i.GetSize() << " Color: " << i.GetColor() << " Price: " << i.GetPrice()
             << " Quantity: " << i.GetQuantity() << "\nLink Photo: "
             << i.GetPhotograph() << "\n" << "\n";
        count++;
    }
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
    price = Validator::validate_price_product(str_price);
    if(!Validator::validate_color_product(color) || !Validator::validate_size_product(size) || price == -1
       || !Validator::validate_photograph_product(photograph))
        throw ExceptionsValidator("Invalid input!");
    else
    {
        this->service.UpdatePriceService(size, color, photograph, price);
            cout<<"The product was updated successfully!\n";
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
    quantity = Validator::validate_quantity_product(str_quantity);
    if(!Validator::validate_color_product(color) || !Validator::validate_size_product(size) ||
       quantity == -1 || !Validator::validate_photograph_product(photograph))
        throw ExceptionsValidator("Invalid input!");
    else
    {
        this->service.UpdateQuantityService(size, color, photograph, quantity);
            cout<<"The product was updated successfully!\n";
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

    if(!Validator::validate_color_product(color) || !Validator::validate_size_product(size) ||
       !Validator::validate_photograph_product(photograph))
        throw ExceptionsValidator("Invalid input!");
    else
    {
        this->service.DeleteService(size, color, photograph, 2);
            cout<<"The product was deleted successfully!\n";
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
    if(!Validator::validate_color_product(color) || !Validator::validate_size_product(size) ||
       !Validator::validate_photograph_product(photograph))
        throw ExceptionsValidator("Invalid input!");
    else
    {
        this->service.DeleteService(size, color, photograph, 1);
            cout<<"The product was deleted successfully!\n";
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
    while(Administrator_Mode == false) {
        try{
        string command;
        cout << "\nCommand> ";
        cin >> command;
        if (command != "1" && command != "2" && command != "3" && command != "4" && command != "5" && command != "6" &&
            command != "E" && command != "H")
            cout << "Invalid command!\n";
        else
            switch (command[0]) {

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
        catch(ExceptionsValidator& message)
        {
            cout<<message.what();
        }
        catch(ExceptionsRepository& message)
        {
            cout<<message.what();
        }
    }
}

void MenuUserMode()
{
    cout<<"Type 1 for buying products!\n";
    cout<<"Type 2 for displaying the shopping basket!\n";
    cout<<"Type 3 for opening the application!\n";
    cout<<"Type E for exit!\n";
}

int Console::DisplayProductsUser() {
    int i = 0;
    if(i < this->service.GetSize())
    {
        cout<<"Size: "<<this->service.GetRepository()[i].GetSize()<<" Color: " <<
            this->service.GetRepository()[i].GetColor() << " Price: " << this->service.GetRepository()[i].GetPrice()
            <<" Quantity: " << this->service.GetRepository()[i].GetQuantity()<<"\nLink Photo: "
            << this->service.GetRepository()[i].GetPhotograph()<<"\n"<<"\n";
        ShellExecute(NULL, "open", this->service.GetRepository()[i].GetPhotograph().c_str(), NULL, NULL, SW_SHOWNORMAL);
        cout << "Buy, go Next or go Pay\n";
        while(i < this->service.GetSize())
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
                    this->service.UpdateQuantityService(this->service.GetRepository()[i].GetSize(),
                                                         this->service.GetRepository()[i].GetColor(), this->service.GetRepository()[i].GetPhotograph(),
                                                         this->service.GetRepository()[i].GetQuantity() - 1);
                    Coat c(this->service.GetRepository()[i].GetSize(),this->service.GetRepository()[i].GetColor(),
                           this->service.GetRepository()[i].GetPrice(), 1, this->service.GetRepository()[i].GetPhotograph());
                    if( this->service.AddUserService(this->service.GetRepository()[i], c) == 1)
//                        i--;
                    cout << "Buy, go Next or go Pay\n";
                }
                if(command == "Next")
                {
                    i++;
                    if(i < this->service.GetSize()) {
                        cout << "Size: " << this->service.GetRepository()[i].GetSize() << " Color: " <<
                             this->service.GetRepository()[i].GetColor() << " Price: "
                             << this->service.GetRepository()[i].GetPrice()
                             << " Quantity: " << this->service.GetRepository()[i].GetQuantity() << "\nLink Photo: "
                             << this->service.GetRepository()[i].GetPhotograph() << "\n" << "\n";
                        ShellExecute(NULL, "open", this->service.GetRepository()[i].GetPhotograph().c_str(), NULL,
                                     NULL, SW_SHOWNORMAL);
                        cout << "Buy, go Next or go Pay\n";
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

int Console::DisplayProductsUserWithSize(string size) {
    int i = 0;
    vector<Coat> elements(this->service.GetRepository().size());
    auto it = copy_if(this->service.GetRepository().begin(), this->service.GetRepository().end(), elements.begin(),
                      [size](Coat coat){ return coat.GetSize()==size;});
    elements.resize(it - elements.begin());
    int size1 =elements.size();
//    for(auto j: this->service.GetRepository())
//        if(j.GetSize() == size)
//            count++;
    if(!elements.empty())
    {
        if (i < elements.size())
        {
            cout << "Size: " << elements[i].GetSize() << " Color: " << elements[i].GetColor() << " Price: "
                 << elements[i].GetPrice()
                 << " Quantity: " << elements[i].GetQuantity() << "\nLink Photo: "
                 << elements[i].GetPhotograph() << "\n" << "\n";
            ShellExecute(NULL, "open", elements[i].GetPhotograph().c_str(), NULL, NULL,
                         SW_SHOWNORMAL);
            cout << "Buy, go Next or go Pay\n";
            while (i < elements.size()) {

                string command;
                cout << "\nCommand> ";
                cin >> command;
                if (command != "Buy" && command != "Next" && command != "Pay")
                    cout << "Invalid command!";
                else {
                    if (command == "Buy") {
                        int new_quantity = elements[i].GetQuantity() - 1;
                        this->service.UpdateQuantityService(elements[i].GetSize(),
                                                             elements[i].GetColor(),
                                                             elements[i].GetPhotograph(),
                                                             new_quantity);
                        elements[i].SetQuantity(new_quantity);
                        Coat c(elements[i].GetSize(),
                               elements[i].GetColor(),
                               elements[i].GetPrice(), 1,
                               elements[i].GetPhotograph());
                        if(this->service.AddUserService(elements[i], c) == 1)
                            elements.erase(elements.begin() + i);
//                            i--;
                        cout << "Buy, go Next or go Pay\n";
                    }
                    if (command == "Next") {
                        i++;
                        if (i < elements.size())
                        {
                            cout << "Size: " << elements[i].GetSize() << " Color: " <<
                                 elements[i].GetColor() << " Price: "
                                 << elements[i].GetPrice()
                                 << " Quantity: " << elements[i].GetQuantity()
                                 << "\nLink Photo: "
                                 << elements[i].GetPhotograph() << "\n" << "\n";
                            ShellExecute(NULL, "open", elements[i].GetPhotograph().c_str(),
                                         NULL,
                                         NULL, SW_SHOWNORMAL);
                                cout << "Buy, go Next or go Pay\n";
                        }
                        else
                            return 0;
                    }
                    if (command == "Pay") {
                        return -1;
                    }
                }
            }
        }
        return 1;
    }
return 2;
}

void Console::MenuDisplayProductsUser() {
    string size;
    int done = 0;
    if (this->service.GetSize() == 0)
        cout << "There are no products on stock!";
    else {
        cout << "Type in the size: ";
        cin.ignore();
        getline(cin, size);
        if (size != "S" && size != "M" && size != "XS" && size != "XL" && size != "XL" && !size.empty() && size != "XXL") {
            cout << "Invalid size!";
        } else {
            while (done == 0) {
                if (size.empty())
                    done = DisplayProductsUser();
                else
                    done = DisplayProductsUserWithSize(size);
            }

            if (done == 1)
                throw ExceptionsRepository("There are no products left on stock!");
            else if (done == 2)
                throw ExceptionsRepository("There are no products with the given size!");
        }
    }
    this->ASB->set_data(this->service.GetUserRepository());
    this->ASB->write();
}

void Console::DisplayShoppingBag() {
    int count=0;
    for(auto i: this->service.GetUserRepository()) {
        cout << count + 1 << ")  ""Size: " << i.GetSize() << " Color: " << i.GetColor() << " Price: "
             << i.GetPrice() << " Quantity: " << i.GetQuantity() << "\nLink Photo: "
             << i.GetPhotograph() << "\n" << "\n";
        count++;
    }
    cout << "Total price of the items: " << this->service.GetTotalPrice() << '\n';
}

void Console::OpenApplication()
{
    this->ASB->set_data(this->service.GetUserRepository());
    this->ASB->write();
    this->ASB->open();
}

void Console::UserMode() {
    bool User_Mode = false;

    while(!User_Mode)
    {
        try {
            string command;
            cout << '\n';
            MenuUserMode();
            cout << '\n';
            cin >> command;
            if (command != "1" && command != "2" && command != "3" && command != "E" && command != "H")
                cout << "Invalid command!\n";
            else
                switch (command[0]) {

                    case '1':
                        MenuDisplayProductsUser();
                        break;
                    case '2':
                        DisplayShoppingBag();
                        break;

                    case '3':
                        OpenApplication();
                        break;

                    case 'H':
                        MenuUserMode();
                        break;

                    case 'E':
                        User_Mode = true;
                        break;
                }
        }
        catch(ExceptionsRepository& message)
        {
            cout<<message.what();
        }
    }
}


void Console::Start() {

    bool Done = false;
    bool DoneChoosingFile = false;
    while(!DoneChoosingFile)
    {
        string FileType;
        cout<<"Type 1 for CSV file or type 2 for HTML file: ";
        cin>>FileType;
        if ( FileType != "1" && FileType != "2")
            cout << "Invalid file type!";
        else
            switch (FileType[0])
            {
                case '1':
                    this->ASB = new CSVShoppingBasket();
                    DoneChoosingFile = true;
                    break;
                case '2':
                    this->ASB = new HTMLShoppingBasket();
                    DoneChoosingFile = true;
                    break;
            }
    }
    while(!Done)
    {
        try {
            string command;
            cout << "Type 1 for Administrator Mode or type 2 for User Mode:  ";
            cin >> command;
            cout << '\n';
            if (command != "1" && command != "2" && command != "E")
                cout << "Invalid command!\n";
            else
                switch (command[0]) {
                    case '1':
                        AdministratorMode();
                        break;

                    case '2':
                        UserMode();
                        break;


                    case 'E':
                        Done = true;
                        delete this->ASB;
                        break;
                }
        }
        catch(ExceptionsValidator)
        {

        }
    }
}



