#ifndef CSV_READER_H
#define CSV_READER_H

#include <vector>
#include <string>
#include "Stock.h"

using namespace std;

class CSVReader {

public:

    vector<StockData> readCSV(string filename);
};

#endif
