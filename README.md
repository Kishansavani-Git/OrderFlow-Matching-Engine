# OrderFlow — Stock Exchange Order Matching Engine

A console-based **stock exchange order matching engine** written in C++, simulating how real exchanges match buy and sell orders using **price-time priority**. Built to demonstrate core Object-Oriented Programming design in a realistic, non-trivial domain.

## Overview

OrderFlow models the core mechanics of an exchange's matching system:

- Traders place **Limit Orders** and **Market Orders** to buy or sell a stock.
- The **Order Book** maintains buy orders (highest price first) and sell orders (lowest price first).
- The **Matching Engine** matches the best buy against the best sell whenever their prices cross, executing trades — including **partial fills** when quantities don't line up exactly.
- Every executed trade is logged to a **Trade History**.

## Features

- Price-time priority order matching (buy orders sorted descending, sell orders sorted ascending)
- Partial order matching with automatic quantity adjustment
- Order lifecycle tracking: `Pending → Partially Filled → Filled`
- Trade execution logging with full trade history
- Clean separation of concerns across modular components

## OOP Concepts Demonstrated

| Concept | Where |
|---|---|
| **Abstraction** | `Order` is an abstract base class exposing a common interface (`getOrderType()`, `display()`) |
| **Inheritance** | `LimitOrder` and `MarketOrder` derive from `Order` |
| **Polymorphism** | `OrderBook` and `MatchingEngine` operate on `Order*` pointers, dispatching to the correct derived behavior at runtime |
| **Encapsulation** | `Trader`, `Stock`, `Trade`, and `Order` keep internal state `private`/`protected`, exposed only through getters |
| **Composition** | `Order` is composed of a `Trader` and a `Stock`; `Trade` is composed of two `Trader`s and a `Stock`; `MatchingEngine` owns a `TradeHistory` |

## Project Structure

```
OrderFlow/
├── include/              # Header files (class declarations)
│   ├── Order.h           # Abstract base class
│   ├── LimitOrder.h
│   ├── MarketOrder.h
│   ├── OrderBook.h
│   ├── MatchingEngine.h
│   ├── Trade.h
│   ├── TradeHistory.h
│   ├── Trader.h
│   ├── Stock.h
│   ├── OrderSide.h       # enum class: BUY / SELL
│   └── OrderStatus.h     # enum class: PENDING / PARTIALLY_FILLED / FILLED / CANCELLED
├── src/                  # Implementation files
│   ├── Order.cpp
│   ├── LimitOrder.cpp
│   ├── MarketOrder.cpp
│   ├── OrderBook.cpp
│   ├── MatchingEngine.cpp
│   ├── Trade.cpp
│   ├── TradeHistory.cpp
│   ├── Trader.cpp
│   └── Stock.cpp
└── main.cpp              # Demo scenario
```

## How It Works

1. **Orders are added** to the `OrderBook`, which automatically sorts buy orders by price (highest first) and sell orders by price (lowest first) — this is what gives priority to the most competitive orders.
2. **The `MatchingEngine`** repeatedly compares the best available buy and sell order. If the buy price is greater than or equal to the sell price, a trade executes at the sell order's price for the smaller of the two quantities.
3. **Quantities update** on both sides after a match; an order is marked `FILLED` and removed once its quantity hits zero, or `PARTIALLY_FILLED` if some quantity remains.
4. **Every trade is recorded** in the `TradeHistory` and can be displayed at any time.

## Getting Started

### Prerequisites
- A C++17-compatible compiler (e.g. `g++`)

### Build & Run

```bash
g++ -std=c++17 -Iinclude main.cpp src/*.cpp -o OrderFlow
./OrderFlow
```

### Sample Output

```
=========== BEFORE MATCHING ===========

========== BUY ORDERS ==========

========== Limit Order ==========
Order ID : 2
Trader   : Amit
Stock    : AAPL (Apple Inc.)
Side     : BUY
Status   : Pending
Quantity : 80
Price    : 252
...

=========== MATCHING ===========

========== TRADE EXECUTED ==========
Buyer    : Amit
Seller   : Kishan
Stock    : AAPL (Apple Inc.)
Quantity : 30
Price    : 245
...
```

## Possible Future Improvements

- Order cancellation support
- Input validation (reject non-positive price/quantity)
- Market orders that execute at best available price rather than a fixed price
- Support for multiple stocks in a single run
- Persisting trade history to a file/database
- Unit tests for matching logic

## License

This project was built for educational purposes as part of academic coursework / self-learning in C++ and OOP design.
