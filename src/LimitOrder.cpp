#include "../include/LimitOrder.h"
#include <iostream>

LimitOrder::LimitOrder(int id,
                       const Trader& trader,
                       const Stock& stock,
                       int qty,
                       double price,
                       OrderSide side)
    : Order(id,
            trader,
            stock,
            qty,
            price,
            side,
            OrderStatus::PENDING)
{
}

std::string LimitOrder::getOrderType() const
{
    return "Limit Order";
}

void LimitOrder::display() const
{
    std::cout << "\n========== " << getOrderType() << " ==========\n";
    Order::display();
}
