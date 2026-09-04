#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

using namespace std;

// Finds the highest value in an array
double findMaximum(const vector<double>& values);

// Finds the lowest value in an array
double findMinimum(const vector<double>& values);

// Calculates the average of an array
double calculateAverage(const vector<double>& values);

// Calculates differences between consecutive prices
vector<double> calculateChanges(const vector<double>& prices);

// Finds the largest single increase
double largestIncrease(const vector<double>& changes);

// Finds the largest single decrease
double largestDecrease(const vector<double>& changes);

// Kadane's Algorithm
// Finds the maximum continuous gain
double maximumContinuousGain(const vector<double>& changes);

// Finds maximum drawdown
double maximumDrawdown(const vector<double>& prices);

// Calculates moving average using sliding window
vector<double> calculateMovingAverage(
    const vector<double>& prices,
    int window
);

// Sorts prices
vector<double> sortPrices(const vector<double>& prices);

// Binary search in a sorted array
int binarySearch(
    const vector<double>& sortedPrices,
    double target
);

#endif
