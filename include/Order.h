#ifndef ORDER_H
#define ORDER_H

#include <string>

#include "Trader.h"
#include "Stock.h"
#include "OrderSide.h"
#include "OrderStatus.h"

class Order
{
protected:
    int orderId;
    Trader trader;
    Stock stock;
    int quantity;
    double price;
    OrderSide side;
    OrderStatus status;

public:
    Order(int id,
          const Trader& trader,
          const Stock& stock,
          int qty,
          double price,
          OrderSide side,
          OrderStatus status = OrderStatus::PENDING);

    virtual ~Order();

    int getOrderId() const;

    Trader getTrader() const;

    Stock getStock() const;

    int getQuantity() const;

    double getPrice() const;

    OrderSide getSide() const;

    OrderStatus getStatus() const;

    void setQuantity(int qty);

    void setStatus(OrderStatus status);

    virtual std::string getOrderType() const = 0;

    virtual void display() const;
};

#endif
