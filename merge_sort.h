//
// Created by Jesse Mejia on 3/24/26.
//

#ifndef PROJECT_2B_MERGE_SORT_H
#define PROJECT_2B_MERGE_SORT_H

#include <vector>
#include <string>
#include "record.h"
using namespace std;

void mergeSort(vector<Record>& emissionData, int left, int right, string category); // main function
double categoryValue(const Record& record, const string& category); // helper for grabbing different values for different categories


#endif //PROJECT_2B_MERGE_SORT_H