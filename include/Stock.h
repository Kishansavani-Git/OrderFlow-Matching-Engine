#ifndef STOCK_H
#define STOCK_H

#include <string>

class Stock
{
private:
    std::string symbol;
    std::string companyName;

public:
    Stock(const std::string& symbol,
          const std::string& companyName);

    std::string getSymbol() const;

    std::string getCompanyName() const;

    void display() const;
};

#endif
