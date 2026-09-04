# Project Architecture

The Stock Market Analysis Engine follows a modular architecture.

## Project Flow

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


## Components

### 1. StockData

File:

include/Stock.h

Purpose:

Defines the structure used to represent one stock record.

Each record contains:

- Date
- Stock symbol
- Opening price
- Highest price
- Lowest price
- Closing price
- Trading volume


### 2. CSVReader

Files:

include/CSVReader.h
src/CSVReader.cpp

Responsibilities:

- Open the CSV file
- Read each row
- Parse the values
- Convert numerical values
- Create StockData objects
- Store records in a vector


### 3. Algorithms

Files:

include/Algorithms.h
src/Algorithms.cpp

Contains the independent DSA algorithms used by the project.

Algorithms include:

- Finding maximum
- Finding minimum
- Calculating average
- Calculating daily changes
- Kadane's Algorithm
- Maximum drawdown
- Moving average
- Sorting
- Binary search


### 4. StockAnalyzer

Files:

include/StockAnalyzer.h
src/StockAnalyzer.cpp

Responsibilities:

- Store loaded stock data
- Display available stock symbols
- Select a stock
- Filter data for the selected stock
- Extract closing prices
- Run DSA algorithms
- Display analysis results
- Run performance benchmarks


### 5. Main Program

File:

src/main.cpp

Purpose:

Provides the command-line interface for the user.

The user can:

1. Select a stock
2. Display stock data
3. Display statistics
4. Display daily changes
5. Calculate moving average
6. Sort closing prices
7. Search for a price
8. View algorithm complexities
9. Run benchmark
10. Reload CSV data
11. Exit


### 6. Tests

File:

tests/test_algorithms.cpp

Purpose:

Tests the core DSA algorithms independently.

The tests cover:

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


## Data Flow

When the application starts:

stocks.csv
    |
    v
CSVReader
    |
    v
vector<StockData>
    |
    v
StockAnalyzer
    |
    v
Selected Stock
    |
    v
Closing Prices
    |
    v
DSA Algorithms
    |
    v
Analysis Results


## Component Relationships

main.cpp
    |
    v
StockAnalyzer
    |
    +----> StockData
    |
    +----> Algorithms
    |
    +----> CSVReader


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


## Design Principles

### Separation of Responsibilities

Each component has a specific responsibility.

CSVReader handles file input.

StockData represents stock records.

Algorithms contains the DSA implementations.

StockAnalyzer connects the stock data with the algorithms.

main.cpp handles user interaction.


### Modularity

The algorithms are implemented separately from the user interface.

This makes the algorithms easier to understand, reuse, and test.


### Testability

The core algorithms can be tested independently without running the complete application.


### Complexity Awareness

The project documents the time and space complexity of the implemented algorithms.

This makes algorithm efficiency an important part of the project design.


## Directory Structure

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
