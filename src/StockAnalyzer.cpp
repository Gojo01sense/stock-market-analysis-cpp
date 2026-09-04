#include "StockAnalyzer.h"
#include "Algorithms.h"

#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;


// Store stock data
void StockAnalyzer::setData(
    const vector<StockData>& stockData) {

    data = stockData;
}


// Check if data is empty
bool StockAnalyzer::isEmpty() const {

    return data.empty();
}


// Get number of records
int StockAnalyzer::getRecordCount() const {

    return data.size();
}


// Get closing prices
vector<double> StockAnalyzer::getClosingPrices() const {

    vector<double> prices;

    for (const StockData& stock : data) {

        prices.push_back(stock.close);
    }

    return prices;
}


// Display stock data
void StockAnalyzer::displayData() const {

    if (data.empty()) {

        cout << "\nNo stock data available.\n";
        return;
    }

    cout << "\n";
    cout << "============================================================\n";
    cout << "                       STOCK DATA\n";
    cout << "============================================================\n";

    cout << left
         << setw(13) << "Date"
         << setw(10) << "Open"
         << setw(10) << "High"
         << setw(10) << "Low"
         << setw(10) << "Close"
         << setw(12) << "Volume"
         << "\n";

    cout << "------------------------------------------------------------\n";

    for (const StockData& stock : data) {

        cout << left
             << setw(13) << stock.date
             << setw(10) << fixed << setprecision(2) << stock.open
             << setw(10) << stock.high
             << setw(10) << stock.low
             << setw(10) << stock.close
             << setw(12) << stock.volume
             << "\n";
    }
}


// Display statistics
void StockAnalyzer::displayStatistics() const {

    if (data.empty()) {

        cout << "\nNo stock data available.\n";
        return;
    }

    vector<double> prices =
        getClosingPrices();

    vector<double> changes =
        calculateChanges(prices);

    cout << "\n";
    cout << "============================================================\n";
    cout << "                    ANALYSIS RESULTS\n";
    cout << "============================================================\n";

    cout << fixed << setprecision(2);

    cout << "\nNumber of records       : "
         << data.size();

    cout << "\nHighest closing price   : Rs. "
         << findMaximum(prices);

    cout << "\nLowest closing price    : Rs. "
         << findMinimum(prices);

    cout << "\nAverage closing price   : Rs. "
         << calculateAverage(prices);

    cout << "\nPrice range             : Rs. "
         << findMaximum(prices) -
            findMinimum(prices);

    cout << "\nLargest single-day gain : Rs. "
         << largestIncrease(changes);

    cout << "\nLargest single-day loss : Rs. "
         << largestDecrease(changes);

    cout << "\nMaximum continuous gain : Rs. "
         << maximumContinuousGain(changes);

    cout << "\nMaximum drawdown        : Rs. "
         << maximumDrawdown(prices);

    cout << "\n";
}


// Display daily changes
void StockAnalyzer::displayDailyChanges() const {

    if (data.size() < 2) {

        cout << "\nNot enough data.\n";
        return;
    }

    vector<double> prices =
        getClosingPrices();

    vector<double> changes =
        calculateChanges(prices);

    cout << "\n";
    cout << "============================================================\n";
    cout << "                    DAILY CHANGES\n";
    cout << "============================================================\n";

    for (int i = 0; i < changes.size(); i++) {

        cout << data[i + 1].date << " : ";

        if (changes[i] >= 0)
            cout << "+";

        cout << fixed << setprecision(2)
             << changes[i]
             << "\n";
    }
}


// Display moving average
void StockAnalyzer::displayMovingAverage(
    int window) const {

    if (data.empty()) {

        cout << "\nNo stock data available.\n";
        return;
    }

    vector<double> prices =
        getClosingPrices();

    vector<double> averages =
        calculateMovingAverage(
            prices,
            window
        );

    if (averages.empty()) {

        cout << "\nInvalid window size.\n";
        return;
    }

    cout << "\n";
    cout << "============================================================\n";
    cout << "                  MOVING AVERAGE\n";
    cout << "============================================================\n";

    for (int i = 0; i < averages.size(); i++) {

        cout << "Ending "
             << data[i + window - 1].date
             << " : Rs. "
             << fixed << setprecision(2)
             << averages[i]
             << "\n";
    }
}


// Display sorted prices
void StockAnalyzer::displaySortedPrices() const {

    if (data.empty()) {

        cout << "\nNo stock data available.\n";
        return;
    }

    vector<double> prices =
        getClosingPrices();

    vector<double> sorted =
        sortPrices(prices);

    cout << "\n";
    cout << "============================================================\n";
    cout << "                    SORTED PRICES\n";
    cout << "============================================================\n";

    for (double price : sorted) {

        cout << "Rs. "
             << fixed << setprecision(2)
             << price
             << "\n";
    }
}


// Search for a price
void StockAnalyzer::searchPrice(
    double target) const {

    if (data.empty()) {

        cout << "\nNo stock data available.\n";
        return;
    }

    vector<double> prices =
        getClosingPrices();

    vector<double> sorted =
        sortPrices(prices);

    int position =
        binarySearch(sorted, target);

    cout << "\n";

    if (position != -1) {

        cout << "Price found!\n";

        cout << "Sorted-array index: "
             << position
             << "\n";
    }

    else {

        cout << "Price not found.\n";
    }
}


// Display algorithm complexities
void StockAnalyzer::displayComplexities() const {

    cout << "\n";
    cout << "============================================================\n";
    cout << "                 ALGORITHM COMPLEXITIES\n";
    cout << "============================================================\n";

    cout << "\nFinding Maximum       : O(n)";
    cout << "\nFinding Minimum       : O(n)";
    cout << "\nAverage Calculation   : O(n)";
    cout << "\nDaily Changes         : O(n)";
    cout << "\nKadane's Algorithm    : O(n)";
    cout << "\nMaximum Drawdown      : O(n)";
    cout << "\nMoving Average        : O(n)";
    cout << "\nSorting               : O(n log n)";
    cout << "\nBinary Search         : O(log n)";

    cout << "\n\nSpace Complexity      : O(n)";

    cout << "\n";
}


// Run benchmark
void StockAnalyzer::runBenchmark() const {

    if (data.empty()) {

        cout << "\nNo stock data available.\n";
        return;
    }

    vector<double> prices =
        getClosingPrices();

    auto start =
        chrono::high_resolution_clock::now();


    // Run several algorithms
    findMaximum(prices);
    findMinimum(prices);
    calculateAverage(prices);

    vector<double> changes =
        calculateChanges(prices);

    largestIncrease(changes);
    largestDecrease(changes);
    maximumContinuousGain(changes);
    maximumDrawdown(prices);
    calculateMovingAverage(prices, 5);
    sortPrices(prices);


    auto end =
        chrono::high_resolution_clock::now();


    auto duration =
        chrono::duration_cast<
            chrono::microseconds
        >(end - start);


    cout << "\n";
    cout << "============================================================\n";
    cout << "                       BENCHMARK\n";
    cout << "============================================================\n";

    cout << "\nRecords analyzed : "
         << data.size();

    cout << "\nExecution time   : "
         << duration.count()
         << " microseconds\n";
}
