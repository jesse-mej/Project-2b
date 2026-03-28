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
private:
    void quickSort(vector<Record> &records, int low, int high, string category); // Quick Sort Implementation
    int partition(vector<Record> &records, int low, int high, string category); // Returns partitioning index to quickSort().
public:
    void printQuickSort(vector<Record> &records, string category, bool descending); // Sorts and prints vector dataset.
    void printTopK(vector<Record> &records, string category, bool descending, int num); // Sorts and prints top N records from vector dataset.
};


#endif //PROJECT_2B_QUICK_SORT_H