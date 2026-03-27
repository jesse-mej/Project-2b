//
// Created by Sandi on 3/23/26.
//
#include <iostream>
#include <vector>
#include <string>
#include "record.h"
#include "load_csv.h"
using namespace std;

int main() {
    void printMainMenu(); // prints main menu
    sortingCategories printSortingCategories(); // prints sorting category options
    emissionType printEmissionTypes(); // prints emission types
}

void printMainMenu() {
    cout << "\n=========================================\n";
    cout << " Greenhouse Gas Emissions Sorting Tool\n";
    cout << "=========================================\n";
    cout << "[1] Choose Sort Key\n";
    cout << "[2] Run Merge Sort\n";
    cout << "[3] Run Quick Sort\n";
    cout << "[4] View Top Ten Records\n";
    cout << "[5] Exit\n";
    cout << "Enter Choice: ";
}

sortingCategories printSortingCategories() {
    int choice;
    cout << "\nChoose Sort Category:\n";
    cout << "[1] Emission Type\n";
    cout << "[2] Year\n";
    cout << "[3] Country\n";
    cout << "[4] Sector\n";
    cout << "Enter Choice: ";
    cin >> choice;
    return static_cast<sortingCategories>(choice);
}

emissionType printEmissionTypes() {
    int choice;
    cout << "\nChoose Emission Type:\n";
    cout << "[1] CO2\n";
    cout << "[2] N2O\n";
    cout << "[3] CH4\n";
    cout << "Enter Choice: ";
    cin >> choice;
    return static_cast<emissionType>(choice);
}