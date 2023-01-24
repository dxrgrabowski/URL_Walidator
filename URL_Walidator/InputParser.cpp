#pragma once
#include "InputParser.hpp"

void InputParse::getDataSourceSelection() {
    cout << "Please select a data source:" << endl;
    cout << "1. File ( Multiple URL adress validation )" << endl;
    cout << "2. Console ( Single URL adress validation )" << endl;
    cin >> selection;
    if (selection == 1)
        getDataFromFile();
    else if (selection == 2)
        getDataFromConsole();
    else
        cout << "INAPROPIATE ARGUMENT";
        // THROW EXCEPTION
}
void InputParse::getDataFromFile() {
    
    cout << "Please enter the file path: ";
    cin >> file_path;

    ifstream file(file_path);
    
    if (!file.is_open()) {
        cout << "ERROR: Could not open file, check the path '" << endl;
        //THORW EXCEPTION
    }

    while (getline(file, address))
        addresses.push_back(address);

    file.close();
}

void InputParse::getDataFromConsole() {
    cout << "Please enter the URL: ";
    cin >> address;
    addresses.push_back(address);
}