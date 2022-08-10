//
// Created by Alexandra on 4/26/2021.
//

#include "Console.h"
#include <iostream>
#include "BMI.h"
#include "BP.h"
#include "ExceptionPerson.h"
#include <string>
#include <string.h>
using namespace std;

Console::Console(Person &person) : person{person} {
}


void Console::ShowIfHealthy() {
    int month;
    cout<<"Type in the current month!\n";
    cin>>month;
    if(month > 12|| month < 1)
        throw ExceptionsPerson("Invalid input!\n");
    if(this->person.isHealthy(month))
        cout<<"The person is healthy!\n";
    else
        cout<<"The person is not healthy!\n";

}


void Console::displayMeasurementUI() {
    cout<<this->person.GetName()<<"\n";
    for(int i = 0; i<this->person.getAllMeasurements().size(); i++)
        cout<<this->person.getAllMeasurements()[i]->ToString();
}

void Console::addMeasurementUI() {
    string mode;
    string date;
    cout<<"Type in the date: \n";
    cin>>date;
    if(date.length() != 10)
        throw ExceptionsPerson("Invalid input!\n");
    cout<<"Type in 1 for adding a BMI or type 2 for adding a BP: \n";
    cin>>mode;
    if(mode == "1")
    {
        double value;
        cout<<"Type in the value: \n";
        cin>>value;
        Measurement* measurement = new BMI(date, value);
        this->person.addMeasurement(measurement);
        if(measurement->isNormalValue())
            cout<<"The measurement is in normal range!\n";
        else
            cout<<"The measurement is not in normal range!\n";
    }
    else if(mode == "2")
    {
        int systolicValue;
        int diastolicValue;
        cout<<"Type in the systolic value: \n";
        cin>>systolicValue;
        cout<<"Type in the diastolic value: \n";
        cin>>diastolicValue;
        Measurement* measurement = new BP(date, systolicValue, diastolicValue);
        this->person.addMeasurement(measurement);
        if(measurement->isNormalValue())
            cout<<"The measurement is in normal range!\n";
        else
            cout<<"The measurement is not in normal range!\n";
    }
    else
        throw ExceptionsPerson("Invalid input!\n");
}

void Console::WriteToFile() {
    string filename;
    filename = R"(C:\Users\Alexandra\Desktop\Facultate\Semestru 2\911\t2-911-Alexandra-Bledea-1\measurements.txt)";
    string date;
    cout<<"Type in the date: \n";
    cin>>date;
    if(date.length() != 10)
        throw ExceptionsPerson("Invalid input!\n");
    this->person.writeToFile(filename, date);
}

void Console::Start() {
    bool Done = false;
    string name;
    cout<<"Type in your name: ";
    cin>>name;
    this->person.SetName(name);
    Menu();
    while(!Done)
    {
        try {
            string command;
            cout << "Command:  ";
            cin >> command;
            cout << '\n';
            if (command != "1" && command != "2" && command != "3" && command != "4" && command != "H" && command != "E")
                cout << "Invalid command!\n";
            else
                switch (command[0]) {
                    case '1':
                        addMeasurementUI();
                        break;

                    case '2':
                        displayMeasurementUI();
                        break;

                    case '3':
                        ShowIfHealthy();
                        break;

                    case '4':
                        WriteToFile();
                        break;

                    case 'H':
                        Menu();
                        break;

                    case 'E':
                        Done = true;
                        break;
                }
        }
        catch(ExceptionsPerson)
        {
            cout<<"Invalid input!\n";
        }

    }
}

void Console::Menu() {
    cout<<"Type 1 for adding a measurement!\n";
    cout<<"Type 2 for displaying the measurements!\n";
    cout<<"Type 3 for checking if healthy!\n";
    cout<<"Type 4 for saving to file!\n";
    cout<<"Type H for help!\n";
    cout<<"Type E for exit!\n";

}





