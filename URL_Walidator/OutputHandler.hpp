#pragma once
#include <iostream>
#include <vector>


class OutputHandler {
private:
    Log& logs;
    InputParse& parser;
public:
    // Konstruktor przyjmuj¹cy wektor z logami
    OutputHandler(Log& logs,InputParse& input) : logs(logs), parser(input) {
        printLogs();
    }

    // Metoda wypisuj¹ca logi
    void printLogs() {
        int i = 0;
        for (Url urlParts : logs.multipleUrlInfo) {
            cout << "Url adress: " + parser.addresses[i] << endl
                << "Protocol: " + urlParts.protocol << endl;
            if (!(urlParts.subdomain == ""))
                cout << "Sub-domain: " + urlParts.subdomain << endl;
            cout << "Second-level domain: " + urlParts.secondLevelDomain << endl
                << "Top-level domain: " + urlParts.topLevelDomain << endl;
            if (!(urlParts.path == ""))
                cout << "Path: " + urlParts.path << endl;
            if (!(urlParts.params == ""))
                cout << "Params: " + urlParts.params << endl;
            if (!(urlParts.anchor == ""))
                cout << "Anchor: " + urlParts.anchor << endl;
                i++;
        }
    }

};