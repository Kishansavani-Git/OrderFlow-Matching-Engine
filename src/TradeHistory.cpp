#include "../include/TradeHistory.h"
#include <iostream>

using namespace std;

void TradeHistory::addTrade(const Trade& trade)
{
    history.push_back(trade);
}

void TradeHistory::displayTrades() const
{
    cout << "\n========== TRADE HISTORY ==========\n";

    if(history.empty())
    {
        cout << "No Trades Executed.\n";
        return;
    }

    for(int i = 0; i < history.size(); i++)
    {
        cout << "\nTrade #" << i + 1 << '\n';

        history[i].display();

        cout << "----------------------------------\n";
    }
}
