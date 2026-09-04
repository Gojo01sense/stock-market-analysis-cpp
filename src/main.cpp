#include <iostream>
#include <string>
#include <vector>

#include "CSVReader.h"
#include "StockAnalyzer.h"

using namespace std;


// DISPLAY MENU
void displayMenu() {

    cout << "\n";
    cout << "============================================================\n";
    cout << "             STOCK MARKET ANALYSIS ENGINE\n";
    cout << "============================================================\n";

    cout << "\nCurrently selected stock: ";

    cout << "\n\n1. Select stock";
    cout << "\n2. Display stock data";
    cout << "\n3. Display statistics";
    cout << "\n4. Display daily changes";
    cout << "\n5. Moving average";
    cout << "\n6. Sort closing prices";
    cout << "\n7. Binary search price";
    cout << "\n8. Show algorithm complexities";
    cout << "\n9. Run benchmark";
    cout << "\n10. Reload CSV data";
    cout << "\n0. Exit";

    cout << "\n\nEnter your choice: ";
}


// MAIN
int main() {

    cout << "\n";
    cout << "============================================================\n";
    cout << "          STOCK MARKET ANALYSIS ENGINE\n";
    cout << "============================================================\n";


    CSVReader reader;
    StockAnalyzer analyzer;


    // Try the normal repository path first
    string filename = "data/stocks.csv";

    vector<StockData> data =
        reader.readCSV(filename);


    // Alternative paths for local testing
    if (data.empty()) {
        data = reader.readCSV("../data/stocks.csv");
    }

    if (data.empty()) {
        data = reader.readCSV("stocks.csv");
    }


    if (data.empty()) {

        cout << "\nError: No stock data was loaded.\n";

        cout << "\nMake sure stocks.csv exists in the data folder.\n";

        return 1;
    }


    analyzer.setData(data);


    cout << "\nStock data loaded successfully!";

    cout << "\nTotal records loaded: "
         << analyzer.getRecordCount();

    cout << "\nCurrently selected stock: "
         << analyzer.getSelectedSymbol()
         << "\n";


    int choice;


    do {

        displayMenu();

        cout << "Currently selected stock: "
             << analyzer.getSelectedSymbol();

        cout << "\n\nEnter your choice: ";

        cin >> choice;


        switch (choice) {


            // SELECT STOCK
            case 1: {

                analyzer.displayAvailableStocks();

                string symbol;

                cout << "\nEnter stock symbol: ";

                cin >> symbol;


                if (analyzer.selectStock(symbol)) {

                    cout << "\nStock selected successfully: "
                         << analyzer.getSelectedSymbol()
                         << "\n";

                } else {

                    cout << "\nStock symbol not found.\n";
                }

                break;
            }


            // DISPLAY DATA
            case 2:

                analyzer.displayData();

                break;


            // STATISTICS
            case 3:

                analyzer.displayStatistics();

                break;


            // DAILY CHANGES
            case 4:

                analyzer.displayDailyChanges();

                break;


            // MOVING AVERAGE
            case 5: {

                int window;

                cout << "\nEnter moving average window: ";

                cin >> window;

                analyzer.displayMovingAverage(window);

                break;
            }


            // SORT
            case 6:

                analyzer.displaySortedPrices();

                break;


            // BINARY SEARCH
            case 7: {

                double target;

                cout << "\nEnter closing price to search: ";

                cin >> target;

                analyzer.searchPrice(target);

                break;
            }


            // COMPLEXITIES
            case 8:

                analyzer.displayComplexities();

                break;


            // BENCHMARK
            case 9:

                analyzer.runBenchmark();

                break;


            // RELOAD
            case 10: {

                vector<StockData> newData =
                    reader.readCSV(filename);


                if (newData.empty()) {

                    newData =
                        reader.readCSV("../data/stocks.csv");
                }


                if (newData.empty()) {

                    newData =
                        reader.readCSV("stocks.csv");
                }


                if (!newData.empty()) {

                    analyzer.setData(newData);

                    cout << "\nData reloaded successfully!";

                    cout << "\nRecords loaded: "
                         << analyzer.getRecordCount();

                    cout << "\nSelected stock: "
                         << analyzer.getSelectedSymbol()
                         << "\n";

                } else {

                    cout << "\nFailed to reload data.\n";
                }

                break;
            }


            // EXIT
            case 0:

                cout << "\nExiting Stock Market Analysis Engine...\n";

                break;


            default:

                cout << "\nInvalid choice. Please try again.\n";
        }


    } while (choice != 0);


    return 0;
}
