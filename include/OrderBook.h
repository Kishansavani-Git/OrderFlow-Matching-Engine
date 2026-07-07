#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <vector>
#include "Order.h"

class OrderBook
{
private:
    std::vector<Order*> buyOrders;
    std::vector<Order*> sellOrders;

public:
    void addOrder(Order* order);

    void displayBuyOrders() const;

    void displaySellOrders() const;

    std::vector<Order*>& getBuyOrders();

    std::vector<Order*>& getSellOrders();
};

#endif
