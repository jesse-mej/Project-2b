//
// Created by Alejandra Reyes Medina on 3/26/2026.
//

#include <algorithm>
#include <iostream>
#include "record.h"
#include "quick_sort.h"
using namespace std;

/*===========================HELPER FUNCTIONS===========================*/

double categoryIntValue(const Record &record, string category) {
    // Returns the integer value that pertains to the category for a record.
    if (category == "year") {
        return record.year;
    }
    if (category == "co2") {
        return record.co2;
    }
    if (category == "n2o") {
        return record.n2o;
    }
    if (category == "ch4") {
        return record.ch4;
    }
    if (category == "powerIndustry") {
        return record.powerIndustry;
    }
    if (category == "buildings") {
        return record.buildings;
    }
    if (category == "transport") {
        return record.transport;
    }
    if (category == "otherIndustry") {
        return record.otherIndustry;
    }
    if (category == "otherSector") {
        return record.otherSector;
    }
    return 0;
}

/*===========================QUICK SORT CLASS===========================*/

void quick_sort::quickSort(vector<Record> &records, int low, int high, string category) {
    // Recursively implements quick sort algorithm. Default Order: Ascending
    // Based on Lecture "6 - Sorting" Slide 85

    // initial low = 0, initial high = size of records vector
    if (low < high) {
        int pivot = partition(records, low, high, category); // Makes pivot equal to partitioning index.
        quickSort(records, low, pivot - 1, category); // Left Subarray
        quickSort(records, pivot + 1, high, category); // Right Subarray
    }
}

int quick_sort::partition(vector<Record> &records, int low, int high, string category) {
    // Selects a pivot, the lowest element in the vector, and rearranges the elements, such that greater elements
    // are to the right of the pivot and all those less than or equal to the pivot are to its left.
    // Based on Lecture "6 - Sorting" Slide 85

    // Determine if pivot is a string (country) or integer.
    if (category == "country") {
        // Select pivot country.
        string pivot = records[low].country;
        // Initialize up index to low index and down index to high index.
        int up = low;
        int down = high;

        while (up < down) {
            // Increment up until it is equal to the index of the first element greater than the pivot or reaches the end.
            for (int i = up; i < high; i++) {
                if (records[up].country > pivot) {
                    break;
                }
                up++;
            }
            // Decrement down until it is equal to the index of the first element less than or equal to the pivot
            // or reaches the beginning.
            for (int j = high; j > low; j--) {
                if (records[down].country < pivot) {
                    break;
                }
                down--;
            }
            if (up < down) {
                // Swap element at up index with element at down index if the latter is greater than the former.
                swap(records[up], records[down]);
            }
        }
        // Swap element at low index with element at down index,
        // such that pivot element is positioned to the right of all elements that are less than or equal.
        swap(records[low], records[down]);
        return down; // Return new pivot value.
    }
    else {
        // Select pivot element of chosen sorting category.
        double pivot = categoryIntValue(records[low], category);
        // Initialize up index to low index and down index to high index.
        int up = low;
        int down = high;

        while (up < down) {
            // Increment up until it is equal to the index of the first element greater than the pivot or reaches the end.
            for (int i = up; i < high; i++) {
                if (categoryIntValue(records[up], category) > pivot) {
                    break;
                }
                up++;
            }
            // Decrement down until it is equal to the index of the first element less than or equal to the pivot
            // or reaches the beginning.
            for (int j = high; j > low; j--) {
                if (categoryIntValue(records[down], category) < pivot) {
                    break;
                }
                down--;
            }
            if (up < down) {
                // Swap element at up index with element at down index if the latter is greater than the former.
                swap(records[up], records[down]);
            }
        }
        // Swap element at low index with element at down index,
        // such that pivot element is positioned to the right of all elements that are less than or equal.
        swap(records[low], records[down]);
        return down; // Return new pivot value.
    }
}

void quick_sort::printQuickSort(vector<Record> &records, string category, bool descending) {
    // Takes in a dataset vector, a chosen category string to sort by,
    // and whether the output is to be printed in ascending or descending order.

    // Implement quick sort based on chosen category.
    quickSort(records, 0, static_cast<int>(records.size()) - 1, category); // Default output is ascending.

    // Print sorted data.
    int rank = 1;
    if (descending == true) {
        // Print in descending order.
        for (auto it = records.rbegin(); it != records.rend(); ++it) {
            cout << rank << ". "; // Rank
            const Record& record = *it;
            if (category == "country" || category == "year") {
                // Sort by country or year.
                // Country | Year | CO2 | N2O | CH4
                cout << record.country << " | " << record.year << endl;
                //cout << "CO2: " << record.co2 << " | " << "N2O: " << record.n2o << " | " << "CH4: " << record.ch4 << endl;
            }
            else {
                // Sort by specific emission.
                // Country | Year | Emission Category
                cout << record.country << " | " << record.year << " | ";
                cout << category << ": " << categoryIntValue(record, category) << endl;
            }
            rank++;
        }
    }
    else {
        // Print in ascending order.
        for (const auto& record : records) {
            cout << rank << ". "; // Rank
            if (category == "country" || category == "year") {
                // Sort by country or year.
                // Country | Year | CO2 | N2O | CH4
                cout << record.country << " | " << record.year << endl;
                //cout << "CO2: " << record.co2 << " | " << "N2O: " << record.n2o << " | " << "CH4: " << record.ch4 << endl;
            }
            else {
                // Sort by specific emission.
                // Country | Year | Emission Category
                cout << record.country << " | " << record.year << " | ";
                cout << category << ": " << categoryIntValue(record, category) << endl;
            }
            rank++;
        }
    }
}

void quick_sort::printTopK(vector<Record> &records, string category, bool descending, int num) {
    // Takes in a dataset vector, a chosen category string to sort by,
    // whether the output is to be printed in ascending or descending order, and number of records to print.

    // Implement quick sort based on chosen category.
    quickSort(records, 0, static_cast<int>(records.size()) - 1, category); // Default output is ascending.

    // Print sorted data.
    int rank = 1;
    if (descending == true) {
        // Print in descending order.
        for (auto it = records.rbegin(); it != records.rend(); ++it) {
            cout << rank << ". "; // Rank
            const Record& record = *it;
            if (category == "country" || category == "year") {
                // Sort by country or year.
                // Country | Year | CO2 | N2O | CH4
                cout << record.country << " | " << record.year << " | ";
                //cout << "CO2: " << record.co2 << " | " << "N2O: " << record.n2o << " | " << "CH4: " << record.ch4 << endl;
            }
            else {
                // Sort by specific emission.
                // Country | Year | Emission Category
                cout << record.country << " | " << record.year << " | ";
                cout << category << ": " << categoryIntValue(record, category) << endl;
            }
            if (rank == num) {
                break;
            }
            else {
                rank++;
            }
        }
    }
    else {
        // Print in ascending order.
        for (const auto& record : records) {
            cout << rank << ". "; // Rank
            if (category == "country" || category == "year") {
                // Sort by country or year.
                // Country | Year | CO2 | N2O | CH4
                cout << record.country << " | " << record.year << " | ";
                //cout << "CO2: " << record.co2 << " | " << "N2O: " << record.n2o << " | " << "CH4: " << record.ch4 << endl;
            }
            else {
                // Sort by specific emission.
                // Country | Year | Emission Category
                cout << record.country << " | " << record.year << " | ";
                cout << category << ": " << categoryIntValue(record, category) << endl;
            }
            if (rank == num) {
                break;
            }
            else {
                rank++;
            }
        }
    }
}
