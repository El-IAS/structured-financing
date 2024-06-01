#ifndef DEAL_H
#define DEAL_H

#include "Currency.h"
#include "Entity.h"
#include "Facility.h"
#include "Part.h"
#include "Portfolio.h"
#include <string>
#include <vector>

// Class Deal
class Deal {
private:
    std::string contractNumber;
    Borrower borrower;
    Lender agent;
    std::vector<Lender> pool;
    double amount;
    std::string startDate;
    std::string endDate;
    std::string status;
    std::vector<Facility> facilities;
    Portfolio portfolio;
    CurrencyConverter converter;

    void updateStatus();

public:
    Deal(const std::string& contractNumber, const Lender& agent, const std::vector<Lender>& pool,
         const Borrower& borrower, double amount, const std::string& startDate,
         const std::string& endDate, const std::string& status);
    void addFacility(const Facility& facility);
    void addPart(const Part& part);
    void display() const;
};

#endif // DEAL_H
