#include "../include/MatchingEngine.h"
#include "../include/Trade.h"

#include <iostream>
#include <algorithm>

using namespace std;

void MatchingEngine::matchOrders(OrderBook& book)
{
    auto& buyOrders = book.getBuyOrders();
    auto& sellOrders = book.getSellOrders();

    if (buyOrders.empty() || sellOrders.empty())
    {
        cout << "No Orders Available\n";
        return;
    }

    while (!buyOrders.empty() && !sellOrders.empty())
    {
        Order* buy = buyOrders.front();
        Order* sell = sellOrders.front();

        if (buy->getPrice() < sell->getPrice())
        {
            cout << "\nNo More Matches Possible.\n";
            break;
        }

        int tradeQty = min(buy->getQuantity(), sell->getQuantity());

        Trade trade(
            buy->getTrader(),
            sell->getTrader(),
            buy->getStock(),
            tradeQty,
            sell->getPrice()
        );

        trade.display();

        // Save Trade
        tradeHistory.addTrade(trade);

        // Update quantities
        buy->setQuantity(buy->getQuantity() - tradeQty);
        sell->setQuantity(sell->getQuantity() - tradeQty);

        // Update status
        if (buy->getQuantity() == 0)
        {
            buy->setStatus(OrderStatus::FILLED);
            buyOrders.erase(buyOrders.begin());
        }
        else
        {
            buy->setStatus(OrderStatus::PARTIALLY_FILLED);
        }

        if (sell->getQuantity() == 0)
        {
            sell->setStatus(OrderStatus::FILLED);
            sellOrders.erase(sellOrders.begin());
        }
        else
        {
            sell->setStatus(OrderStatus::PARTIALLY_FILLED);
        }

        cout << "\n------------------------------------------\n";
    }
}

void MatchingEngine::showTradeHistory() const
{
    tradeHistory.displayTrades();
}