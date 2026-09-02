#include <iostream>
#include "CSVReader.h"

using namespace std;

int main() {

    CSVReader reader;

    vector<StockData> data =
        reader.readCSV("../data/stock_data.csv");

    cout << "Stock data loaded successfully!\n";

    cout << "Number of records: "
         << data.size() << "\n";

    if (!data.empty()) {

        cout << "\nFirst record:\n";

        cout << "Date: "
             << data[0].date << "\n";

        cout << "Open: "
             << data[0].open << "\n";

        cout << "High: "
             << data[0].high << "\n";

        cout << "Low: "
             << data[0].low << "\n";

        cout << "Close: "
             << data[0].close << "\n";

        cout << "Volume: "
             << data[0].volume << "\n";
    }

    return 0;
}
