#ifndef STOCK_ANALYZER_H
#define STOCK_ANALYZER_H

#include <vector>
#include <string>
#include "Stock.h"

using namespace std;

class StockAnalyzer {

private:

    vector<StockData> data;


public:

    // Store stock data
    void setData(const vector<StockData>& stockData);

    // Check if data is empty
    bool isEmpty() const;

    // Number of records
    int getRecordCount() const;

    // Get all closing prices
    vector<double> getClosingPrices() const;

    // Display stock data
    void displayData() const;

    // Display complete analysis
    void displayStatistics() const;

    // Display daily changes
    void displayDailyChanges() const;

    // Display moving average
    void displayMovingAverage(int window) const;

    // Display sorted prices
    void displaySortedPrices() const;

    // Search for a closing price
    void searchPrice(double target) const;

    // Display algorithm complexities
    void displayComplexities() const;

    // Run performance benchmark
    void runBenchmark() const;
};

#endif
