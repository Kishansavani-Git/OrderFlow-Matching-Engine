#include "../include/Order.h"

#include <iostream>

Order::Order(int id,
             const Trader& trader,
             const Stock& stock,
             int qty,
             double price,
             OrderSide side,
             OrderStatus status)
    : orderId(id),
      trader(trader),
      stock(stock),
      quantity(qty),
      price(price),
      side(side),
      status(status)
{
}

Order::~Order()
{
}

int Order::getOrderId() const
{
    return orderId;
}

Trader Order::getTrader() const
{
    return trader;
}

Stock Order::getStock() const
{
    return stock;
}

int Order::getQuantity() const
{
    return quantity;
}

double Order::getPrice() const
{
    return price;
}

OrderSide Order::getSide() const
{
    return side;
}

OrderStatus Order::getStatus() const
{
    return status;
}

void Order::setQuantity(int qty)
{
    quantity = qty;
}

void Order::setStatus(OrderStatus status)
{
    this->status = status;
}

void Order::display() const
{
    std::cout << "Order ID : " << orderId << '\n';
    std::cout << "Trader   : " << trader.getTraderName() << '\n';

    std::cout << "Stock    : ";
    stock.display();
    std::cout << '\n';

    std::cout << "Side     : ";

    if (side == OrderSide::BUY)
        std::cout << "BUY\n";
    else
        std::cout << "SELL\n";

    std::cout << "Status   : ";

    switch(status)
    {
    case OrderStatus::PENDING:
        std::cout << "Pending";
        break;

    case OrderStatus::PARTIALLY_FILLED:
        std::cout << "Partially Filled";
        break;

    case OrderStatus::FILLED:
        std::cout << "Filled";
        break;

    case OrderStatus::CANCELLED:
        std::cout << "Cancelled";
        break;
    }

    std::cout << '\n';

    std::cout << "Quantity : " << quantity << '\n';
    std::cout << "Price    : " << price << '\n';
}
