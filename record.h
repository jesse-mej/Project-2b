//
// Created by Sandi on 3/23/26.
//

#ifndef PROJECT_2B_RECORD_H
#define PROJECT_2B_RECORD_H

#include <string>
using namespace std;

struct Record {
    string country;
    int year;
    double co2;
    double n2o;
    double ch4;
    double powerIndustry;
    double buildings;
    double transport;
    double otherIndustry;
    double otherSector;
};

enum class sortingCategories {
    EMISSION_TYPE = 1,
    YEAR,
    COUNTRY,
    SECTOR
};

enum class emissionType {
    CO2 = 1,
    N2O,
    CH4,
    NONE
};

enum class sectorType {
    POWER_INDUSTRY = 1,
    BUILDINGS,
    TRANSPORT,
    OTHER_INDUSTRY,
    OTHER_SECTOR,
    NONE
};

#endif //PROJECT_2B_RECORD_H