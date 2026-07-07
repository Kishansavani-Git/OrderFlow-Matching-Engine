#ifndef MATCHINGENGINE_H
#define MATCHINGENGINE_H

#include "OrderBook.h"
#include "TradeHistory.h"

class MatchingEngine
{
private:
    TradeHistory tradeHistory;

public:
    void matchOrders(OrderBook& book);

    void showTradeHistory() const;
};

#endif
