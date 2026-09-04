#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

#include "Algorithms.h"

using namespace std;


bool approximatelyEqual(double a, double b) {
    return fabs(a - b) < 0.0001;
}


int main() {

    cout << "Running algorithm tests...\n";


    // Test data
    vector<double> prices = {
        100, 105, 103, 110, 108
    };


    // Test maximum
    assert(
        approximatelyEqual(
            findMaximum(prices),
            110
        )
    );


    // Test minimum
    assert(
        approximatelyEqual(
            findMinimum(prices),
            100
        )
    );


    // Test average
    assert(
        approximatelyEqual(
            calculateAverage(prices),
            105.2
        )
    );


    // Test price changes
    vector<double> changes =
        calculateChanges(prices);

    assert(changes.size() == 4);

    assert(
        approximatelyEqual(
            changes[0],
            5
        )
    );

    assert(
        approximatelyEqual(
            changes[1],
            -2
        )
    );


    // Test largest increase
    assert(
        approximatelyEqual(
            largestIncrease(changes),
            7
        )
    );


    // Test largest decrease
    assert(
        approximatelyEqual(
            largestDecrease(changes),
            -2
        )
    );


    // Test Kadane's Algorithm
    vector<double> kadaneData = {
        -2, 5, -1, 3, -4
    };

    assert(
        approximatelyEqual(
            maximumContinuousGain(kadaneData),
            7
        )
    );


    // Test maximum drawdown
    vector<double> drawdownData = {
        100, 120, 110, 90, 130
    };

    assert(
        approximatelyEqual(
            maximumDrawdown(drawdownData),
            30
        )
    );


    // Test moving average
    vector<double> movingAverageData = {
        10, 20, 30, 40, 50
    };

    vector<double> averages =
        calculateMovingAverage(
            movingAverageData,
            3
        );

    assert(averages.size() == 3);

    assert(
        approximatelyEqual(
            averages[0],
            20
        )
    );

    assert(
        approximatelyEqual(
            averages[1],
            30
        )
    );

    assert(
        approximatelyEqual(
            averages[2],
            40
        )
    );


    // Test sorting
    vector<double> unsorted = {
        50, 10, 40, 20, 30
    };

    vector<double> sorted =
        sortPrices(unsorted);

    assert(sorted[0] == 10);
    assert(sorted[1] == 20);
    assert(sorted[2] == 30);
    assert(sorted[3] == 40);
    assert(sorted[4] == 50);


    // Test binary search
    assert(
        binarySearch(sorted, 30) == 2
    );

    assert(
        binarySearch(sorted, 100) == -1
    );


    cout << "\nAll tests passed successfully!\n";


    return 0;
}
