#include <iostream>
#include <string>

#include "CSVReader.h"
#include "StockAnalyzer.h"

using namespace std;


// ============================================================
// DISPLAY MENU
// ============================================================

void displayMenu() {

    cout << "\n";
    cout << "============================================================\n";
    cout << "             STOCK MARKET ANALYSIS ENGINE\n";
    cout << "============================================================\n";

    cout << "\n1. Display stock data";
    cout << "\n2. Display statistics";
    cout << "\n3. Display daily changes";
    cout << "\n4. Moving average";
    cout << "\n5. Sort closing prices";
    cout << "\n6. Binary search price";
    cout << "\n7. Show algorithm complexities";
    cout << "\n8. Run benchmark";
    cout << "\n9. Reload CSV data";
    cout << "\n0. Exit";

    cout << "\n\nEnter your choice: ";
}


// ============================================================
// MAIN
// ============================================================

int main() {

    cout << "\n";
    cout << "============================================================\n";
    cout << "          STOCK MARKET ANALYSIS ENGINE\n";
    cout << "============================================================\n";


    CSVReader reader;

    StockAnalyzer analyzer;


    // --------------------------------------------------------
    // Load stock data
    // --------------------------------------------------------

    string filename =
        "../data/stocks.csv";


    vector<StockData> data =
        reader.readCSV(filename);


    // If the above path does not work,
    // try the current folder.
    if (data.empty()) {

        data =
            reader.readCSV("stocks.csv");
    }


    if (data.empty()) {

        cout << "\nError: No stock data was loaded.\n";

        cout << "\nMake sure stocks.csv exists in the data folder.\n";

        return 1;
    }


    analyzer.setData(data);


    cout << "\nStock data loaded successfully!";

    cout << "\nRecords loaded: "
         << analyzer.getRecordCount()
         << "\n";


    // --------------------------------------------------------
    // Menu loop
    // --------------------------------------------------------

    int choice;


    do {

        displayMenu();

        cin >> choice;


        switch (choice) {


            // ------------------------------------------------
            // Display data
            // ------------------------------------------------

            case 1:

                analyzer.displayData();

                break;


            // ------------------------------------------------
            // Statistics
            // ------------------------------------------------

            case 2:

                analyzer.displayStatistics();

                break;


            // ------------------------------------------------
            // Daily changes
            // ------------------------------------------------

            case 3:

                analyzer.displayDailyChanges();

                break;


            // ------------------------------------------------
            // Moving average
            // ------------------------------------------------

            case 4: {

                int window;

                cout << "\nEnter moving average window: ";

                cin >> window;

                analyzer.displayMovingAverage(window);

                break;
            }


            // ------------------------------------------------
            // Sorting
            // ------------------------------------------------

            case 5:

                analyzer.displaySortedPrices();

                break;


            // ------------------------------------------------
            // Binary search
            // ------------------------------------------------

            case 6: {

                double target;

                cout << "\nEnter closing price to search: ";

                cin >> target;

                analyzer.searchPrice(target);

                break;
            }


            // ------------------------------------------------
            // Complexity
            // ------------------------------------------------

            case 7:

                analyzer.displayComplexities();

                break;


            // ------------------------------------------------
            // Benchmark
            // ------------------------------------------------

            case 8:

                analyzer.runBenchmark();

                break;


            // ------------------------------------------------
            // Reload data
            // ------------------------------------------------

            case 9: {

                vector<StockData> newData =
                    reader.readCSV(filename);


                if (newData.empty()) {

                    newData =
                        reader.readCSV("stocks.csv");
                }


                if (!newData.empty()) {

                    analyzer.setData(newData);

                    cout << "\nData reloaded successfully!";

                    cout << "\nRecords loaded: "
                         << analyzer.getRecordCount()
                         << "\n";
                }

                else {

                    cout << "\nFailed to reload data.\n";
                }

                break;
            }


            // ------------------------------------------------
            // Exit
            // ------------------------------------------------

            case 0:

                cout << "\nExiting Stock Market Analysis Engine...\n";

                break;


            // ------------------------------------------------
            // Invalid option
            // ------------------------------------------------

            default:

                cout << "\nInvalid choice. Please try again.\n";
        }


    } while (choice != 0);


    return 0;
}
