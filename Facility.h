#ifndef FACILITY_H
#define FACILITY_H

#include "Currency.h"
#include "Entity.h"
#include <string>
#include <vector>

// Utility function to calculate the duration between two dates in years
double calculateDuration(const std::string& startDate, const std::string& endDate);

// Class Facility
class Facility {
private:
    std::string startDate;
    std::string endDate;
    double amount;
    double interestRate;
    Currency currency;
    std::vector<Lender> lenders;

public:
    Facility(const std::string& startDate, const std::string& endDate, double amount, double interestRate, Currency currency, std::vector<Lender> lenders);
    double calculateInterest() const;
    Currency getCurrency() const;
    double getAmount() const;
    double getInterestRate() const;
    void display() const;
};

#endif // FACILITY_H
