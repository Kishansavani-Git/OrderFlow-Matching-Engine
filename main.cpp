#include <iostream>

#include "Trader.h"
#include "Stock.h"
#include "OrderSide.h"
#include "LimitOrder.h"
#include "MarketOrder.h"
#include "OrderBook.h"
#include "MatchingEngine.h"

using namespace std;

int main()
{
    Trader kishan(101, "Kishan");
    Trader amit(102, "Amit");
    Trader rahul(103, "Rahul");
    Trader riya(104, "Riya");

    Stock apple("AAPL", "Apple Inc.");

    // BUY ORDERS
    LimitOrder buy1(
        1,
        kishan,
        apple,
        100,
        248,
        OrderSide::BUY
    );

    LimitOrder buy2(
        2,
        amit,
        apple,
        80,
        252,
        OrderSide::BUY
    );

    LimitOrder buy3(
        3,
        rahul,
        apple,
        70,
        250,
        OrderSide::BUY
    );

    // SELL ORDERS
    MarketOrder sell1(
        4,
        riya,
        apple,
        40,
        249,
        OrderSide::SELL
    );

    MarketOrder sell2(
        5,
        kishan,
        apple,
        30,
        245,
        OrderSide::SELL
    );

    MarketOrder sell3(
        6,
        amit,
        apple,
        50,
        247,
        OrderSide::SELL
    );

    OrderBook book;

    book.addOrder(&buy1);
    book.addOrder(&buy2);
    book.addOrder(&buy3);

    book.addOrder(&sell1);
    book.addOrder(&sell2);
    book.addOrder(&sell3);

    cout << "\n=========== BEFORE MATCHING ===========\n";

    book.displayBuyOrders();
    book.displaySellOrders();

    MatchingEngine engine;

    cout << "\n=========== MATCHING ===========\n";

    engine.matchOrders(book);

    cout << "\n=========== AFTER MATCHING ===========\n";

    book.displayBuyOrders();
    book.displaySellOrders();

    cout << "\n=========== TRADE HISTORY ===========\n";

    engine.showTradeHistory();

    return 0;
}
