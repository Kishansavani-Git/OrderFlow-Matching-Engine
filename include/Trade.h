#ifndef TRADE_H
#define TRADE_H

#include "Trader.h"
#include "Stock.h"

class Trade
{
private:
    Trader buyer;
    Trader seller;
    Stock stock;
    int quantity;
    double price;

public:
    Trade(const Trader& buyer,
          const Trader& seller,
          const Stock& stock,
          int quantity,
          double price);

    void display() const;
};

#endif
