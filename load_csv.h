//
// Created by Sandi on 3/23/26.
//

#ifndef PROJECT_2B_LOAD_CSV_H
#define PROJECT_2B_LOAD_CSV_H

#include <vector>
#include <string>
#include "record.h"
using namespace std;

bool loadCSV(const string& filename, vector<Record>& data);

#endif //PROJECT_2B_LOAD_CSV_H