#include "../include/MarketOrder.h"
#include <iostream>

MarketOrder::MarketOrder(int id,
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

std::string MarketOrder::getOrderType() const
{
    return "Market Order";
}

void MarketOrder::display() const
{
    std::cout << "\n========== " << getOrderType() << " ==========\n";
    Order::display();
}
