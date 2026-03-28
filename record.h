//
// Created by Sandi on 3/23/26.
//

#ifndef PROJECT_2B_RECORD_H
#define PROJECT_2B_RECORD_H

#include <string>
using namespace std;

struct Record { // represents a single row from the dataset
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

enum class sortingCategories { // options the user can sort by
    EMISSION_TYPE = 1,
    YEAR,
    COUNTRY,
    SECTOR
};

enum class emissionType { // options for emission to sort by if chosen previously
    CO2 = 1,
    N2O,
    CH4,
    NONE // used for when not sorting by emission
};

enum class sectorType { // options for sectors to sort by if chosen previously
    POWER_INDUSTRY = 1,
    BUILDINGS,
    TRANSPORT,
    OTHER_INDUSTRY,
    OTHER_SECTOR,
    NONE
};

#endif //PROJECT_2B_RECORD_H