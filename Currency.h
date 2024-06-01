#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <map>

// Enum for Currency
enum class Currency {
    EUR,
    USD,
    GBP,
    JPY
};

// Helper function to convert currency to string
std::string currencyToString(Currency currency);

// Class for handling currency conversions
class CurrencyConverter {
private:
    std::map<std::pair<Currency, Currency>, double> exchangeRates;

public:
    CurrencyConverter();
    double convertToEUR(Currency from, double amount) const;
    double convert(Currency from, Currency to, double amount) const;
};

#endif // CURRENCY_H
