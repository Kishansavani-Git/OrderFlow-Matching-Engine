#include "../include/Trader.h"
#include <iostream>

Trader::Trader(int id, const std::string& name)
    : traderId(id), traderName(name)
{
}

int Trader::getTraderId() const
{
    return traderId;
}

std::string Trader::getTraderName() const
{
    return traderName;
}

void Trader::display() const
{
    std::cout << "Trader ID   : " << traderId << '\n';
    std::cout << "Trader Name : " << traderName << '\n';
}