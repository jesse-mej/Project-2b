<H1> COP3530 - Project 2 </h1>

## Greenhouse Gas Emissions Sorting Tool

This program loads a greenhouse gas emissions dataset and lets the user sort the data using Merge Sort or Quick Sort.

You can sort by year, country, emission type, or sector, and then view the top 10 results.

## How to Run

Open the project in CLion and run `main.cpp`.

## How to Use

After running `main.cpp`, the program will load the emissions dataset and show a menu. Enter the number for the action you want to perform. The program allows you to choose how to sort the data, run either Merge Sort or Quick Sort, and then view the top 10 records based on your selection. The sorted data is displayed in descending order by default. You can sort based on:

- Emissions Type (CO2, N2O, CH4)
- Country
- Year of Emissions
- Emissions Produced by Sector (Power Industry, Buildings, Transport, Other Industry, Other Sector)

## Files Needed

Make sure all `.cpp` and `.h` files are included, along with `emissions.csv`.

## Notes

- The program uses `emissions.csv` as input.
- It looks for the file using the path `../emissions.csv`.
- If the file is not found, the program will not run correctly.
