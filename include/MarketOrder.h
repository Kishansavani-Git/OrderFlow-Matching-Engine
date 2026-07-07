#ifndef MARKETORDER_H
#define MARKETORDER_H

#include "Order.h"

class MarketOrder : public Order
{
public:
    MarketOrder(int id,
                const Trader& trader,
                const Stock& stock,
                int qty,
                double price,
                OrderSide side);

    std::string getOrderType() const override;

    void display() const override;
};

#endif
