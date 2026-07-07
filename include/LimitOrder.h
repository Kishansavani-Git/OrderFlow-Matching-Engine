#ifndef LIMITORDER_H
#define LIMITORDER_H

#include "Order.h"

class LimitOrder : public Order
{
public:
    LimitOrder(int id,
               const Trader& trader,
               const Stock& stock,
               int qty,
               double price,
               OrderSide side);

    std::string getOrderType() const override;

    void display() const override;
};

#endif
