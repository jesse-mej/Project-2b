//
// Created by Sandi on 3/23/26.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "record.h"
#include "load_csv.h"
#include "merge_sort.h"
#include "quick_sort.h"
using namespace std;

void printMainMenu(); // prints main menu
sortingCategories printSortingCategories(); // prints sorting category options
emissionType printEmissionTypes(); // prints emission types
sectorType printSectorTypes(); // prints out all the different sectors
void printTopK(const vector<Record>& data, int k, sortingCategories category, emissionType emission, sectorType sector);
string categoryAsString(sortingCategories category, emissionType emission, sectorType sector);
void runMerge(vector<Record>& data, sortingCategories category, emissionType emission, sectorType sector);
void runQuick(vector<Record>& data, sortingCategories category,emissionType emission, sectorType sector);

int main() {
    vector<Record> data; // stores the dataset
    string filename = "../emissions.csv";

    if (!loadCSV(filename, data)) { // check if dataset properly loaded
        cout << "Error loading dataset.\n";
        return 1;
    }
    cout << "Dataset loaded successfully\n";
    cout << "Records: " << data.size() << "\n";
    // create default choice for merge and quick sort
    sortingCategories selectedCategory = sortingCategories::YEAR;
    emissionType selectedEmission = emissionType::CO2;
    sectorType selectedSector = sectorType::POWER_INDUSTRY;

    int choice;
    do {
        printMainMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                selectedCategory = printSortingCategories(); // prints sorting categories
                if (selectedCategory == sortingCategories::EMISSION_TYPE) {
                    selectedEmission = printEmissionTypes(); // prints emission types if selected
                    cout << "Selected: Emission Type\n";
                }
                else if (selectedCategory == sortingCategories::YEAR) { // same for year
                    cout << "Selected: Year\n";
                }
                else if (selectedCategory == sortingCategories::COUNTRY) { // same for country
                    cout << "Selected: Country\n";
                }
                else if (selectedCategory == sortingCategories::SECTOR) {
                    selectedSector = printSectorTypes(); // print out sector categories
                    cout << "Selected: Sector\n";
                }
                break;
            }
            case 2: { // call merge sort function
                string categoryString = categoryAsString(selectedCategory, selectedEmission, selectedSector);
                mergeAndPrint(data, categoryString, false);
                break;
            }
            case 3: { // call quick sort function
                string categoryString = categoryAsString(selectedCategory, selectedEmission, selectedSector);
                quick_sort sorter;
                sorter.printQuickSort(data, categoryString, false);
                break;
            }
            case 4: // call print top k function
                printTopK(data, 10, selectedCategory, selectedEmission, selectedSector);
                break;
            case 5: // exiting the program
                cout << "Exiting the program.\n";
                break;
            default: // did not enter a valid choice
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

void printTopK(const vector<Record>& data, int k, sortingCategories category, emissionType emission, sectorType sector) { // prints the top 10 elements from the sorted data
    cout << "\nShowing first: " << k << " records\n";
    for (int i = 0; i < k && i < static_cast<int>(data.size()); i++) { // loop through
        cout << i + 1 << ". " << data[i].country << " | ";

        if (category == sortingCategories::EMISSION_TYPE) {
            if (emission == emissionType::CO2) cout << "CO2: " << data[i].co2;
            else if (emission == emissionType::N2O) cout << "N2O: " << data[i].n2o;
            else cout << "CH4: " << data[i].ch4;
        }
        else if (category == sortingCategories::YEAR) {
            cout << "Year: " << data[i].year;
        }
        else if (category == sortingCategories::COUNTRY) {
            cout << "Country: " << data[i].country;
        }
        else if (category == sortingCategories::SECTOR) {
            if (sector == sectorType::POWER_INDUSTRY) cout << "Power: " << data[i].powerIndustry;
            else if (sector == sectorType::BUILDINGS) cout << "Buildings: " << data[i].buildings;
            else if (sector == sectorType::TRANSPORT) cout << "Transport: " << data[i].transport;
            else if (sector == sectorType::OTHER_INDUSTRY) cout << "Other Industry: " << data[i].otherIndustry;
            else cout << "Other Sector: " << data[i].otherSector;
        }
        cout << endl;
    }
}

string categoryAsString(sortingCategories category, // convert to string for sorting
                         emissionType emission,
                         sectorType sector) {

    if (category == sortingCategories::YEAR) return "year";
    if (category == sortingCategories::COUNTRY) return "country";

    if (category == sortingCategories::EMISSION_TYPE) {
        if (emission == emissionType::CO2) return "co2";
        if (emission == emissionType::N2O) return "n2o";
        if (emission == emissionType::CH4) return "ch4";
    }

    if (category == sortingCategories::SECTOR) {
        if (sector == sectorType::POWER_INDUSTRY) return "powerIndustry";
        if (sector == sectorType::BUILDINGS) return "buildings";
        if (sector == sectorType::TRANSPORT) return "transport";
        if (sector == sectorType::OTHER_INDUSTRY) return "otherIndustry";
        if (sector == sectorType::OTHER_SECTOR) return "otherSector";
    }

    return "year";
}

