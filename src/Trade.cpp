#include "../include/Trade.h"
#include <iostream>

Trade::Trade(const Trader& buyer,
             const Trader& seller,
             const Stock& stock,
             int quantity,
             double price)
    : buyer(buyer),
      seller(seller),
      stock(stock),
      quantity(quantity),
      price(price)
{
}

void Trade::display() const
{
    std::cout << "\n========== TRADE EXECUTED ==========\n";

    std::cout << "Buyer    : "
              << buyer.getTraderName() << '\n';

    std::cout << "Seller   : "
              << seller.getTraderName() << '\n';

    std::cout << "Stock    : ";
    stock.display();
    std::cout << '\n';

    std::cout << "Quantity : "
              << quantity << '\n';

    std::cout << "Price    : "
              << price << '\n';
}
