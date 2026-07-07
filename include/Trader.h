#ifndef TRADER_H
#define TRADER_H

#include <string>

class Trader
{
private:
    int traderId;
    std::string traderName;

public:
    Trader(int id, const std::string& name);

    int getTraderId() const;
    std::string getTraderName() const;

    void display() const;
};

#endif