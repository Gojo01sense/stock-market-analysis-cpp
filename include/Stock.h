#ifndef STOCK_H
#define STOCK_H

#include <string>

using namespace std;

struct StockData {

    string date;

    double open;
    double high;
    double low;
    double close;

    long long volume;
};

#endif
