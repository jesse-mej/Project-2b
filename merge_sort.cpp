//
// Created by Jesse Mejia on 3/24/26.
//
#include "merge_sort.h"

#include <iostream>

// helper function used for efficiently grabbing each value that needs to be sorted within mergeSort
double categoryValue(const Record& record, const string& category) {
    if (category == "year") {
        return record.year;
    }
    else if (category == "co2") {
        return record.co2;
    }
    else if (category == "n2o") {
        return record.n2o;
    }
    else if (category == "ch4") {
        return record.ch4;
    }
    else if (category == "powerIndustry") {
        return record.powerIndustry;
    }
    else if (category == "buildings") {
        return record.buildings;
    }
    else if (category == "transport") {
        return record.transport;
    }
    else if (category == "otherIndustry") {
        return record.otherIndustry;
    }
    else if (category == "otherSector") {
        return record.otherSector;
    }

    return 0;
}

void mergeSort(vector<Record>& emissionData, int left, int right, string category, bool descending) {
    if (left >= right) { // this means that this section would only have 1 thing or less, so we can stop
        return;
    }

    int middle = (left + right) / 2; // find the middle of the array

    int sizeOfLeft = middle - left + 1;
    int sizeOfRight = right - middle;

    // split the unsorted data into two arrays, of the left and right sides
    vector<Record> leftSide(sizeOfLeft);
    vector<Record> rightSide(sizeOfRight);

    for (int i = 0; i < sizeOfLeft; i++) { // add everything left of the center to separate array
        leftSide[i] = emissionData[left + i];
    }
    for (int i = 0; i < sizeOfRight; i++) { // add everything right of the center to separate array
        rightSide[i] = emissionData[middle + 1 + i];
    }

    // recursively sort both sides
    mergeSort(leftSide, 0, leftSide.size() - 1, category, descending);
    mergeSort(rightSide, 0, rightSide.size() - 1, category, descending);

    int leftIndex = 0, rightIndex = 0, mergedIndex = left; // now both halves are sorted, so create indexes to keep track of where we are

    if (category != "country") {
        while (leftIndex < leftSide.size() && rightIndex < rightSide.size()) {
            if (descending == false) { // for ascending
                if (categoryValue(leftSide[leftIndex], category) <= categoryValue(rightSide[rightIndex], category)) { // uses helper to grab values and sees which should come first
                    // if left is smaller
                    emissionData[mergedIndex] = leftSide[leftIndex];
                    leftIndex++;
                }
                else {
                    // if right is smaller
                    emissionData[mergedIndex] = rightSide[rightIndex];
                    rightIndex++;
                }
            }
            else { // for descending
                if (categoryValue(leftSide[leftIndex], category) >= categoryValue(rightSide[rightIndex], category)) { // uses helper to grab values and sees which should come first
                    // if left is bigger
                    emissionData[mergedIndex] = leftSide[leftIndex];
                    leftIndex++;
                }
                else {
                    // if right is bigger
                    emissionData[mergedIndex] = rightSide[rightIndex];
                    rightIndex++;
                }
            }
            mergedIndex++;
        }
        while (leftIndex < leftSide.size()) { // place the rest of sorted elements on the left into emissionsData
            emissionData[mergedIndex] = leftSide[leftIndex];
            leftIndex++;
            mergedIndex++;
        }
        while (rightIndex < rightSide.size()) { // do the same for the right side
            emissionData[mergedIndex] = rightSide[rightIndex];
            rightIndex++;
            mergedIndex++;
        }
    }
    else { // all the same process as before but since country is a string, done separately
        while (leftIndex < leftSide.size() && rightIndex < rightSide.size()) {
            if (descending == false) { // for ascending
                if (leftSide[leftIndex].country <= rightSide[rightIndex].country) {
                    emissionData[mergedIndex] = leftSide[leftIndex];
                    leftIndex++;
                }
                else {
                    emissionData[mergedIndex] = rightSide[rightIndex];
                    rightIndex++;
                }
            }
            else { // for descending
                if (leftSide[leftIndex].country >= rightSide[rightIndex].country) {
                    emissionData[mergedIndex] = leftSide[leftIndex];
                    leftIndex++;
                }
                else {
                    emissionData[mergedIndex] = rightSide[rightIndex];
                    rightIndex++;
                }
            }
            mergedIndex++;
        }

        while (leftIndex < leftSide.size()) {
            emissionData[mergedIndex] = leftSide[leftIndex];
            leftIndex++;
            mergedIndex++;
        }

        while (rightIndex < rightSide.size()) {
            emissionData[mergedIndex] = rightSide[rightIndex];
            rightIndex++;
            mergedIndex++;
        }
    }
}

// helper function that prints out, in order, all of the necessary data i.e. country, year, category in order
void mergeAndPrint(vector<Record>& emissionData, string category, bool descending) {
    mergeSort(emissionData, 0, emissionData.size() -1, category, descending);
    for (int i = 0; i < emissionData.size() - 1; i++) {
        cout << i + 1 << ". "; // print out ranking
        if (category == "country") {
            cout << emissionData[i].country << " | " << emissionData[i].year << endl;
        }
        else if (category == "year") {
            cout << emissionData[i].country << " | " << emissionData[i].year << endl;
        }
        else {
            // print out country - year - category value for these rankings
            cout << emissionData[i].country << " | " << emissionData[i].year << " | " << category << ": " << categoryValue(emissionData[i], category) << endl;
        }
    }
}

