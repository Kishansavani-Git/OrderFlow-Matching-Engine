#include "../include/Stock.h"
#include <iostream>

Stock::Stock(const std::string& symbol,
             const std::string& companyName)
    : symbol(symbol),
      companyName(companyName)
{
}

std::string Stock::getSymbol() const
{
    return symbol;
}

std::string Stock::getCompanyName() const
{
    return companyName;
}

void Stock::display() const
{
    std::cout << symbol << " (" << companyName << ")";
}
