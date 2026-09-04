#include "CSVReader.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;


vector<StockData> CSVReader::readCSV(string filename) {

    vector<StockData> data;

    ifstream file(filename);


    if (!file.is_open()) {

        cout << "Error: Could not open file "
             << filename << endl;

        return data;
    }


    string line;


    // Skip the first line because it contains column names
    getline(file, line);


    while (getline(file, line)) {

        stringstream ss(line);

        string value;

        StockData stock;


        // Date
        getline(ss, stock.date, ',');


        // Stock symbol
        getline(ss, stock.symbol, ',');


        // Open
        getline(ss, value, ',');
        stock.open = stod(value);


        // High
        getline(ss, value, ',');
        stock.high = stod(value);


        // Low
        getline(ss, value, ',');
        stock.low = stod(value);


        // Close
        getline(ss, value, ',');
        stock.close = stod(value);


        // Volume
        getline(ss, value, ',');
        stock.volume = stoll(value);


        data.push_back(stock);
    }


    file.close();


    return data;
}
