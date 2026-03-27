//
// Created by Sandi on 3/23/26.
//
#include "load_csv.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
// removes the quotation marks from each entry
string removeQuotes(string s) {
    s.erase(remove(s.begin(), s.end(), '"'), s.end());
    return s;
}

// reads each line into a record struct
bool loadCSV(const string& filename, vector<Record>& data) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open file " << filename << endl;
        return false;
    }
    string line;
    getline(file, line); // skip the header line

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string token;
        Record r;

        try {
            // read country like this -> account for countries with commas in their name
            getline(ss, token, '"');   // skip opening quote
            getline(ss, r.country, '"'); // read full country name, even if it has commas
            getline(ss, token, ',');   // skip comma after country

            getline(ss, token, ',');
            r.year = stoi(removeQuotes(token));

            getline(ss, token, ',');
            r.co2 = stod(removeQuotes(token));

            getline(ss, token, ',');
            r.n2o = stod(removeQuotes(token));

            getline(ss, token, ',');
            r.ch4 = stod(removeQuotes(token));

            getline(ss, token, ',');
            r.powerIndustry = stod(removeQuotes(token));

            getline(ss, token, ',');
            r.buildings = stod(removeQuotes(token));

            getline(ss, token, ',');
            r.transport = stod(removeQuotes(token));

            getline(ss, token, ',');
            r.otherIndustry = stod(removeQuotes(token));

            getline(ss, token, ',');
            r.otherSector = stod(removeQuotes(token));

            getline(ss, token, ',');
            getline(ss, token, ',');

            data.push_back(r);
        }
        catch (...) {
            cout << "Skipping invalid row " << line << endl;
            continue;
        }
    }
    file.close();
    return true;
}