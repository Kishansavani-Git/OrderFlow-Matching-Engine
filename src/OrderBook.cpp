#include "../include/OrderBook.h"
#include <iostream>
#include <algorithm>

using namespace std;

void OrderBook::addOrder(Order* order)
{
    if(order->getSide() == OrderSide::BUY)
    {
        buyOrders.push_back(order);

        sort(buyOrders.begin(), buyOrders.end(),
            [](Order* a, Order* b)
            {
                return a->getPrice() > b->getPrice();
            });
    }
    else
    {
        sellOrders.push_back(order);

        sort(sellOrders.begin(), sellOrders.end(),
            [](Order* a, Order* b)
            {
                return a->getPrice() < b->getPrice();
            });
    }
}

void OrderBook::displayBuyOrders() const
{
    cout << "\n========== BUY ORDERS ==========\n";

    if(buyOrders.empty())
    {
        cout << "No Buy Orders\n";
        return;
    }

    for(Order* order : buyOrders)
    {
        order->display();
        cout << '\n';
    }
}

void OrderBook::displaySellOrders() const
{
    cout << "\n========== SELL ORDERS ==========\n";

    if(sellOrders.empty())
    {
        cout << "No Sell Orders\n";
        return;
    }

    for(Order* order : sellOrders)
    {
        order->display();
        cout << '\n';
    }
}

vector<Order*>& OrderBook::getBuyOrders()
{
    return buyOrders;
}

vector<Order*>& OrderBook::getSellOrders()
{
    return sellOrders;
}
