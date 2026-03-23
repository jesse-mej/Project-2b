//
// Created by Sandi on 3/23/26.
//
#include "load_csv.h"
#include <fstream>
#include <sstream>
using namespace std;

bool loadCSV(const string& filename, vector<Record>& data) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        Record r;

        getline(ss, r.country, ',');

        getline(ss, token, ',');
        r.year = stoi(token);

        getline(ss, token, ',');
        r.co2 = stod(token);

        getline(ss, token, ',');
        r.n2o = stod(token);

        getline(ss, token, ',');
        r.ch4 = stod(token);

        getline(ss, token, ',');
        r.powerIndustry = stod(token);

        getline(ss, token, ',');
        r.buildings = stod(token);

        getline(ss, token, ',');
        r.transport = stod(token);

        getline(ss, token, ',');
        r.otherIndustry = stod(token);

        getline(ss, token, ',');
        r.otherSector = stod(token);

        getline(ss, token, ',');
        getline(ss, token, ',');

        data.push_back(r);
    }
    file.close();
    return true;
}