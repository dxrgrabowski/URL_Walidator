#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InputParse {
private:
    int selection;
    string file_path;
    string address;
public:
    vector<string> addresses;
    
    InputParse() {
        getDataSourceSelection();
    }
    ~InputParse() = default;
    

    // Method to get user selection for data entry
    void getDataSourceSelection();

    // Method to get data from file
    void getDataFromFile();

    // Method to get data from console
    void getDataFromConsole();
    
};