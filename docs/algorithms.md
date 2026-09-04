# Algorithms Used

This project demonstrates several fundamental Data Structures and Algorithms concepts through stock-market data analysis.

## 1. Finding Maximum

Finds the highest closing price in the selected stock's data.

### Algorithm
Traverse the array once and keep track of the largest value.

### Complexity
- Time: O(n)
- Space: O(1)

---

## 2. Finding Minimum

Finds the lowest closing price.

### Complexity
- Time: O(n)
- Space: O(1)

---

## 3. Average Calculation

Calculates the average closing price by summing all prices and dividing by the number of records.

### Complexity
- Time: O(n)
- Space: O(1)

---

## 4. Daily Price Changes

Calculates the difference between consecutive closing prices.

Formula:

Change = Current Close - Previous Close

### Complexity
- Time: O(n)
- Space: O(n)

---

## 5. Kadane's Algorithm

Kadane's Algorithm is used to find the maximum continuous gain from a sequence of daily price changes.

The algorithm maintains:

- Current gain
- Best gain found so far

At every position, it decides whether to extend the existing sequence or start a new sequence.

### Complexity
- Time: O(n)
- Space: O(1)

---

## 6. Maximum Drawdown

Maximum drawdown measures the largest decline from a previous peak.

The algorithm keeps track of the highest price seen so far and calculates the decline from that peak.

### Complexity
- Time: O(n)
- Space: O(1)

---

## 7. Moving Average

The project calculates a simple moving average using a sliding-window technique.

Instead of recalculating the entire window every time, the algorithm:

1. Adds the new price.
2. Removes the price leaving the window.
3. Calculates the new average.

This avoids unnecessary repeated calculations.

### Complexity
- Time: O(n)
- Space: O(n)

---

## 8. Sorting

Closing prices are copied into a separate vector and sorted using the C++ standard sorting algorithm.

### Complexity
- Time: O(n log n)
- Space: O(n)

---

## 9. Binary Search

Binary search is performed on the sorted closing-price array.

The search space is repeatedly divided in half.

### Complexity
- Time: O(log n)
- Space: O(1)

---

## Algorithm Summary

| Algorithm | Time Complexity | Space Complexity |
|---|---:|---:|
| Maximum | O(n) | O(1) |
| Minimum | O(n) | O(1) |
| Average | O(n) | O(1) |
| Daily Changes | O(n) | O(n) |
| Kadane's Algorithm | O(n) | O(1) |
| Maximum Drawdown | O(n) | O(1) |
| Moving Average | O(n) | O(n) |
| Sorting | O(n log n) | O(n) |
| Binary Search | O(log n) | O(1) |

## Why These Algorithms Matter

The purpose of this project is not only to calculate stock statistics. It demonstrates how common DSA techniques can be applied to a practical data-analysis problem.

The project combines:

- Arrays and vectors
- Linear traversal
- Sliding window
- Kadane's Algorithm
- Sorting
- Binary search
- Time and space complexity analysis
