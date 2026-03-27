//
// Created by Alejandra Reyes Medina on 3/26/2026.
//

#ifndef PROJECT_2B_QUICK_SORT_H
#define PROJECT_2B_QUICK_SORT_H

#include "record.h"
#include <string>
#include <vector>
using namespace std;

class quick_sort {
    void quickSort(vector<Record> &records, int low, int high, string category);
    int partition(vector<Record> &records, int low, int high, string category);
};


#endif //PROJECT_2B_QUICK_SORT_H