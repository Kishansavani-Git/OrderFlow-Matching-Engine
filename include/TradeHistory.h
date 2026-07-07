#ifndef TRADEHISTORY_H
#define TRADEHISTORY_H

#include <vector>
#include "Trade.h"

class TradeHistory
{
private:
    std::vector<Trade> history;

public:
    void addTrade(const Trade& trade);

    void displayTrades() const;
};

#endif
