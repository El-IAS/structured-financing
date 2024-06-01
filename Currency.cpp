#include "Currency.h"

// Helper function to convert currency to string
std::string currencyToString(Currency currency) {
    switch (currency) {
        case Currency::EUR: return "EUR";
        case Currency::USD: return "USD";
        case Currency::GBP: return "GBP";
        case Currency::JPY: return "JPY";
        default: return "Unknown";
    }
}

// Class for handling currency conversions
CurrencyConverter::CurrencyConverter() {
    // Initialize exchange rates (example values, these should be updated with real-time data)
    exchangeRates[std::make_pair(Currency::USD, Currency::EUR)] = 0.85;
    exchangeRates[std::make_pair(Currency::GBP, Currency::EUR)] = 1.15;
    exchangeRates[std::make_pair(Currency::JPY, Currency::EUR)] = 0.0078;
    // Add more exchange rates as needed
}

double CurrencyConverter::convertToEUR(Currency from, double amount) const {
    if (from == Currency::EUR) return amount;
    return amount * exchangeRates.at(std::make_pair(from, Currency::EUR));
}

double CurrencyConverter::convert(Currency from, Currency to, double amount) const {
    if (from == to) return amount;
    return amount * exchangeRates.at(std::make_pair(from, to));
}
