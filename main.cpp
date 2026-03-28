//
// Created by Sandi on 3/23/26.
//
#include <iostream>
#include <vector>
#include <string>
#include "record.h"
#include "load_csv.h"
using namespace std;

void printMainMenu(); // prints main menu
sortingCategories printSortingCategories(); // prints sorting category options
emissionType printEmissionTypes(); // prints emission types
sectorType printSectorTypes(); // prints out all the different sectors
void printTopK(const vector<Record>& data, int k);

int main() {
    vector<Record> data; // stores the dataset
    string filename = "../emissions.csv";

    if (!loadCSV(filename, data)) { // check if dataset properly loaded
        cout << "Error loading dataset.\n";
        return 1;
    }
    cout << "Dataset loaded successfully\n";
    cout << "Records: " << data.size() << "\n";

    int choice;
    do {
        printMainMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                sortingCategories category = printSortingCategories(); // prints sorting categories
                if (category == sortingCategories::EMISSION_TYPE) {
                    emissionType emission = printEmissionTypes(); // prints emission types if selected
                    cout << "Selected: Emission Type\n";
                    if (emission == emissionType::CO2) { // print out nicely
                        cout << "CO2 selected.\n";
                    }
                    else if (emission == emissionType::N2O) {
                        cout << "N2O selected.\n";
                    }
                    else if (emission == emissionType::CH4) {
                        cout << "CH4 selected.\n";
                    }
                }
                else if (category == sortingCategories::YEAR) { // same for year
                    cout << "Selected: Year\n";
                }
                else if (category == sortingCategories::COUNTRY) { // same for country
                    cout << "Selected: Country\n";
                }
                else if (category == sortingCategories::SECTOR) {
                    sectorType sector = printSectorTypes(); // print out sector categories
                    cout << "Selected: Sector\n";
                    if (sector == sectorType::POWER_INDUSTRY) {
                        cout << "Power industry selected.\n";
                    }
                    else if (sector == sectorType::BUILDINGS) {
                        cout << "Buildings selected.\n";
                    }
                    else if (sector == sectorType::TRANSPORT) {
                        cout << "Transport selected.\n";
                    }
                    else if (sector == sectorType::OTHER_INDUSTRY) {
                        cout << "Other industry selected.\n";
                    }
                    else if (sector == sectorType::OTHER_SECTOR) {
                        cout << "Other Sector selected.\n";
                    }
                }
                break;
            }
            case 2:
                cout << "Waiting to implement merge sort\n"; // placeholder for now
                break;
            case 3:
                cout << "Waiting to implement quick sort\n"; // placeholder for now
                break;
            case 4:
                printTopK(data, 10);
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
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

sectorType printSectorTypes() {
    int choice;
    cout << "\nChoose Sector:\n";
    cout << "[1] Power Industry\n";
    cout << "[2] Buildings\n";
    cout << "[3] Transport\n";
    cout << "[4] Other Industry\n";
    cout << "[5] Other Sector\n";
    cout << "Enter Choice: ";
    cin >> choice;
    return static_cast<sectorType>(choice);
}

void printTopK(const vector<Record>& data, int k) { // prints the top 10 elements from the sorted data
    cout << "\nShowing first: " << k << " records\n";
    for (int i = 0; i < k && i < static_cast<int>(data.size()); i++) { // loop through
        cout << i + 1 << ". "
        << data[i].country << " | " // print it out in a readable way
        << data[i].year << " | "
        << "CO2: " << data[i].co2 << " | "
        << "N2O: " << data[i].n2o << " | "
        << "CH4: " << data[i].ch4 << "\n";
    }
}
