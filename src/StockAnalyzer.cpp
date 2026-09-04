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

    selectedSymbol = "";

    if (!data.empty()) {
        selectedSymbol = data[0].symbol;
    }
}


// Check if data is empty
bool StockAnalyzer::isEmpty() const {
    return data.empty();
}


// Get total number of records
int StockAnalyzer::getRecordCount() const {
    return data.size();
}


// Get available stock symbols
vector<string> StockAnalyzer::getSymbols() const {

    vector<string> symbols;

    for (const StockData& stock : data) {

        bool alreadyExists = false;

        for (const string& symbol : symbols) {

            if (symbol == stock.symbol) {
                alreadyExists = true;
                break;
            }
        }

        if (!alreadyExists) {
            symbols.push_back(stock.symbol);
        }
    }

    return symbols;
}


// Display available stocks
void StockAnalyzer::displayAvailableStocks() const {

    vector<string> symbols = getSymbols();

    cout << "\n";
    cout << "============================================================\n";
    cout << "                    AVAILABLE STOCKS\n";
    cout << "============================================================\n";

    for (int i = 0; i < symbols.size(); i++) {

        cout << i + 1 << ". " << symbols[i];

        if (symbols[i] == selectedSymbol) {
            cout << "  <- selected";
        }

        cout << "\n";
    }
}


// Select a stock
bool StockAnalyzer::selectStock(const string& symbol) {

    for (const StockData& stock : data) {

        if (stock.symbol == symbol) {

            selectedSymbol = symbol;
            return true;
        }
    }

    return false;
}


// Get currently selected stock
string StockAnalyzer::getSelectedSymbol() const {
    return selectedSymbol;
}


// Get selected stock records
vector<StockData> StockAnalyzer::getSelectedData() const {

    vector<StockData> selectedData;

    for (const StockData& stock : data) {

        if (stock.symbol == selectedSymbol) {
            selectedData.push_back(stock);
        }
    }

    return selectedData;
}


// Get closing prices
vector<double> StockAnalyzer::getClosingPrices() const {

    vector<double> prices;

    vector<StockData> selectedData = getSelectedData();

    for (const StockData& stock : selectedData) {
        prices.push_back(stock.close);
    }

    return prices;
}


// Display selected stock data
void StockAnalyzer::displayData() const {

    vector<StockData> selectedData = getSelectedData();

    if (selectedData.empty()) {

        cout << "\nNo stock data available.\n";
        return;
    }

    cout << "\n";
    cout << "============================================================\n";
    cout << "                    STOCK DATA - "
         << selectedSymbol
         << "\n";
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

    for (const StockData& stock : selectedData) {

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

    vector<double> prices = getClosingPrices();

    if (prices.empty()) {

        cout << "\nNo stock data available.\n";
        return;
    }

    vector<double> changes = calculateChanges(prices);

    cout << "\n";
    cout << "============================================================\n";
    cout << "                 ANALYSIS - "
         << selectedSymbol
         << "\n";
    cout << "============================================================\n";

    cout << fixed << setprecision(2);

    cout << "\nNumber of records       : " << prices.size();

    cout << "\nHighest closing price   : Rs. "
         << findMaximum(prices);

    cout << "\nLowest closing price    : Rs. "
         << findMinimum(prices);

    cout << "\nAverage closing price   : Rs. "
         << calculateAverage(prices);

    cout << "\nPrice range             : Rs. "
         << findMaximum(prices) - findMinimum(prices);

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

    vector<StockData> selectedData = getSelectedData();

    if (selectedData.size() < 2) {

        cout << "\nNot enough data.\n";
        return;
    }

    vector<double> prices = getClosingPrices();
    vector<double> changes = calculateChanges(prices);

    cout << "\n";
    cout << "============================================================\n";
    cout << "              DAILY CHANGES - "
         << selectedSymbol
         << "\n";
    cout << "============================================================\n";

    for (int i = 0; i < changes.size(); i++) {

        cout << selectedData[i + 1].date << " : ";

        if (changes[i] >= 0) {
            cout << "+";
        }

        cout << fixed << setprecision(2)
             << changes[i] << "\n";
    }
}


// Display moving average
void StockAnalyzer::displayMovingAverage(int window) const {

    vector<StockData> selectedData = getSelectedData();

    vector<double> prices = getClosingPrices();

    vector<double> averages =
        calculateMovingAverage(prices, window);

    if (averages.empty()) {

        cout << "\nInvalid window size.\n";
        return;
    }

    cout << "\n";
    cout << "============================================================\n";
    cout << "             MOVING AVERAGE - "
         << selectedSymbol
         << "\n";
    cout << "============================================================\n";

    for (int i = 0; i < averages.size(); i++) {

        cout << "Ending "
             << selectedData[i + window - 1].date
             << " : Rs. "
             << fixed << setprecision(2)
             << averages[i] << "\n";
    }
}


// Display sorted prices
void StockAnalyzer::displaySortedPrices() const {

    vector<double> prices = getClosingPrices();

    if (prices.empty()) {

        cout << "\nNo stock data available.\n";
        return;
    }

    vector<double> sorted = sortPrices(prices);

    cout << "\n";
    cout << "============================================================\n";
    cout << "             SORTED PRICES - "
         << selectedSymbol
         << "\n";
    cout << "============================================================\n";

    for (double price : sorted) {

        cout << "Rs. "
             << fixed << setprecision(2)
             << price << "\n";
    }
}


// Search for a price
void StockAnalyzer::searchPrice(double target) const {

    vector<double> prices = getClosingPrices();

    if (prices.empty()) {

        cout << "\nNo stock data available.\n";
        return;
    }

    vector<double> sorted = sortPrices(prices);

    int position = binarySearch(sorted, target);

    cout << "\n";

    if (position != -1) {

        cout << "Price found!\n";
        cout << "Stock: " << selectedSymbol << "\n";
        cout << "Sorted-array index: "
             << position << "\n";

    } else {

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


// Run performance benchmark
void StockAnalyzer::runBenchmark() const {

    vector<double> prices = getClosingPrices();

    if (prices.empty()) {

        cout << "\nNo stock data available.\n";
        return;
    }

    auto start =
        chrono::high_resolution_clock::now();

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
        chrono::duration_cast<chrono::microseconds>(
            end - start
        );

    cout << "\n";
    cout << "============================================================\n";
    cout << "                 BENCHMARK - "
         << selectedSymbol
         << "\n";
    cout << "============================================================\n";

    cout << "\nRecords analyzed : "
         << prices.size();

    cout << "\nExecution time   : "
         << duration.count()
         << " microseconds\n";
}
