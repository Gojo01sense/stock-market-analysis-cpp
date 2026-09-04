#include "Algorithms.h"

#include <algorithm>

using namespace std;


// Finds the highest value
double findMaximum(const vector<double>& values) {

    if (values.empty())
        return 0;

    double maximum = values[0];

    for (int i = 1; i < values.size(); i++) {

        if (values[i] > maximum)
            maximum = values[i];
    }

    return maximum;
}


// Finds the lowest value
double findMinimum(const vector<double>& values) {

    if (values.empty())
        return 0;

    double minimum = values[0];

    for (int i = 1; i < values.size(); i++) {

        if (values[i] < minimum)
            minimum = values[i];
    }

    return minimum;
}


// Calculates average
double calculateAverage(const vector<double>& values) {

    if (values.empty())
        return 0;

    double sum = 0;

    for (double value : values) {

        sum += value;
    }

    return sum / values.size();
}


// Calculates changes between consecutive prices
vector<double> calculateChanges(
    const vector<double>& prices) {

    vector<double> changes;

    for (int i = 1; i < prices.size(); i++) {

        double change =
            prices[i] - prices[i - 1];

        changes.push_back(change);
    }

    return changes;
}


// Finds largest increase
double largestIncrease(
    const vector<double>& changes) {

    if (changes.empty())
        return 0;

    double largest = changes[0];

    for (int i = 1; i < changes.size(); i++) {

        if (changes[i] > largest)
            largest = changes[i];
    }

    return largest;
}


// Finds largest decrease
double largestDecrease(
    const vector<double>& changes) {

    if (changes.empty())
        return 0;

    double largest = changes[0];

    for (int i = 1; i < changes.size(); i++) {

        if (changes[i] < largest)
            largest = changes[i];
    }

    return largest;
}


// Kadane's Algorithm
double maximumContinuousGain(
    const vector<double>& changes) {

    if (changes.empty())
        return 0;

    double currentGain = changes[0];

    double bestGain = changes[0];

    for (int i = 1; i < changes.size(); i++) {

        currentGain =
            max(changes[i],
                currentGain + changes[i]);

        bestGain =
            max(bestGain, currentGain);
    }

    return bestGain;
}


// Maximum Drawdown
double maximumDrawdown(
    const vector<double>& prices) {

    if (prices.empty())
        return 0;

    double peak = prices[0];

    double maximumDrop = 0;

    for (int i = 1; i < prices.size(); i++) {

        if (prices[i] > peak)
            peak = prices[i];

        double drop =
            peak - prices[i];

        if (drop > maximumDrop)
            maximumDrop = drop;
    }

    return maximumDrop;
}


// Moving Average
vector<double> calculateMovingAverage(
    const vector<double>& prices,
    int window) {

    vector<double> result;

    if (window <= 0 ||
        window > prices.size()) {

        return result;
    }

    double sum = 0;

    // First window
    for (int i = 0; i < window; i++) {

        sum += prices[i];
    }

    result.push_back(sum / window);


    // Sliding window
    for (int i = window;
         i < prices.size();
         i++) {

        sum += prices[i];

        sum -= prices[i - window];

        result.push_back(sum / window);
    }

    return result;
}


// Sort prices
vector<double> sortPrices(
    const vector<double>& prices) {

    vector<double> sortedPrices = prices;

    sort(sortedPrices.begin(),
         sortedPrices.end());

    return sortedPrices;
}


// Binary Search
int binarySearch(
    const vector<double>& sortedPrices,
    double target) {

    int left = 0;

    int right = sortedPrices.size() - 1;


    while (left <= right) {

        int middle =
            left + (right - left) / 2;


        if (sortedPrices[middle] == target) {

            return middle;
        }


        if (sortedPrices[middle] < target) {

            left = middle + 1;
        }


        else {

            right = middle - 1;
        }
    }


    return -1;
}
