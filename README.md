# Stock Market Analysis Engine

A modular C++ application that analyzes historical stock-market data using fundamental Data Structures and Algorithms.

The project demonstrates how DSA concepts can be applied to a practical data-analysis problem.

## Features

- Load stock-market data from CSV
- Support multiple stock symbols
- Select and analyze individual stocks
- Display historical stock data
- Calculate highest and lowest closing prices
- Calculate average closing price
- Calculate price range
- Calculate daily price changes
- Find largest single-day gain
- Find largest single-day loss
- Calculate maximum continuous gain using Kadane's Algorithm
- Calculate maximum drawdown
- Calculate moving averages using a sliding-window technique
- Sort closing prices
- Search prices using binary search
- Display algorithm time and space complexities
- Run a performance benchmark
- Reload CSV data
- Automated algorithm tests


## DSA Concepts Demonstrated

This project implements and applies:

- Arrays / Vectors
- Linear Search
- Binary Search
- Sorting
- Sliding Window
- Kadane's Algorithm
- Maximum / Minimum traversal
- Prefix-style running calculations
- Time and Space Complexity Analysis


## Algorithms and Complexity

| Algorithm | Time Complexity | Space Complexity |
|---|---:|---:|
| Find Maximum | O(n) | O(1) |
| Find Minimum | O(n) | O(1) |
| Average Calculation | O(n) | O(1) |
| Daily Price Changes | O(n) | O(n) |
| Kadane's Algorithm | O(n) | O(1) |
| Maximum Drawdown | O(n) | O(1) |
| Moving Average | O(n) | O(n) |
| Sorting | O(n log n) | O(n) |
| Binary Search | O(log n) | O(1) |


## Architecture

The project follows a modular design:

CSV Dataset
    |
    v
CSVReader
    |
    v
StockData
    |
    v
StockAnalyzer
    |
    v
Algorithms
    |
    v
Console Output

### Components

**StockData**

Defines the structure representing a stock record.

**CSVReader**

Reads and parses stock-market data from the CSV file.

**Algorithms**

Contains the independent DSA implementations.

**StockAnalyzer**

Handles stock selection, filtering, analysis, and benchmarking.

**Main Program**

Provides the command-line interface.

**Tests**

Verifies the correctness of the core algorithms.


## Dataset

The included dataset contains historical records for:

- AAPL
- MSFT
- NVDA

Each record contains:

- Date
- Symbol
- Open
- High
- Low
- Close
- Volume


## Project Structure

stock-market-analysis-cpp/
|
+-- data/
|   +-- stocks.csv
|   +-- README.md
|   +-- .gitkeep
|
+-- include/
|   +-- Stock.h
|   +-- CSVReader.h
|   +-- Algorithms.h
|   +-- StockAnalyzer.h
|
+-- src/
|   +-- main.cpp
|   +-- CSVReader.cpp
|   +-- Algorithms.cpp
|   +-- StockAnalyzer.cpp
|
+-- tests/
|   +-- test_algorithms.cpp
|
+-- docs/
|   +-- algorithms.md
|   +-- architecture.md
|
+-- README.md
+-- LICENSE
+-- .gitignore


## How It Works

### Step 1: Load Data

The program reads `stocks.csv` using the `CSVReader` class.

### Step 2: Store Records

Each CSV row is converted into a `StockData` structure.

### Step 3: Select Stock

The user can select a stock such as:

AAPL

MSFT

NVDA

### Step 4: Extract Closing Prices

The selected stock's closing prices are extracted into a vector.

### Step 5: Apply Algorithms

The program applies different algorithms to analyze the selected stock.

For example:

- Linear traversal for maximum and minimum
- Kadane's Algorithm for maximum continuous gain
- Sliding window for moving average
- Sorting followed by binary search for price searching

### Step 6: Display Results

The calculated results are displayed through the command-line interface.


## Example Analysis

For a selected stock, the program can display:

Number of records

Highest closing price

Lowest closing price

Average closing price

Price range

Largest single-day gain

Largest single-day loss

Maximum continuous gain

Maximum drawdown


## Testing

The project includes automated tests in:

tests/test_algorithms.cpp

The tests verify the correctness of the core algorithms, including:

- Maximum
- Minimum
- Average
- Daily changes
- Largest increase
- Largest decrease
- Kadane's Algorithm
- Maximum drawdown
- Moving average
- Sorting
- Binary search

The test program prints:

All tests passed successfully!

when all assertions succeed.


## Compilation

From the project root, compile the application using:

g++ src/main.cpp src/CSVReader.cpp src/StockAnalyzer.cpp src/Algorithms.cpp -Iinclude -o stock_analyzer

Run the application:

./stock_analyzer


## Compile the Tests

Compile the algorithm tests using:

g++ tests/test_algorithms.cpp src/Algorithms.cpp -Iinclude -o test_algorithms

Run the tests:

./test_algorithms


## Example Menu

============================================================
             STOCK MARKET ANALYSIS ENGINE
============================================================

Currently selected stock: AAPL

1. Select stock
2. Display stock data
3. Display statistics
4. Display daily changes
5. Moving average
6. Sort closing prices
7. Binary search price
8. Show algorithm complexities
9. Run benchmark
10. Reload CSV data
0. Exit


## Why This Project?

This project was built to strengthen practical understanding of Data Structures and Algorithms by applying them to a real-world-style dataset.

Instead of implementing algorithms only as isolated coding problems, the project integrates them into a complete application involving:

- File handling
- Data parsing
- Data structures
- Algorithm design
- Searching
- Sorting
- Sliding-window techniques
- Dynamic programming
- Complexity analysis
- Testing
- Modular C++ development


## Future Improvements

Possible future versions could include:

- Larger real-world datasets
- More technical indicators
- Additional searching algorithms
- More advanced sorting comparisons
- Interactive charts
- Database integration
- Portfolio analysis
- Risk metrics
- REST API integration
- Performance comparison between different algorithms


## Learning Goals

This project focuses on developing practical skills in:

- C++
- Data Structures and Algorithms
- Object-Oriented Programming
- File Handling
- Algorithm Complexity
- Software Modularity
- Testing
- Git and GitHub


## License

This project is licensed under the MIT License.
