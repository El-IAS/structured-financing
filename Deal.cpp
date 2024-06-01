#include "Deal.h"
#include <iostream>

// Class Deal
Deal::Deal(const std::string& contractNumber, const Lender& agent, const std::vector<Lender>& pool,
           const Borrower& borrower, double amount, const std::string& startDate,
           const std::string& endDate, const std::string& status)
    : contractNumber(contractNumber), agent(agent), pool(pool), borrower(borrower),
      amount(amount), startDate(startDate), endDate(endDate), status(status) {}

void Deal::addFacility(const Facility& facility) {
    facilities.push_back(facility);
    double interest = facility.calculateInterest();
    double amountInEUR = converter.convertToEUR(facility.getCurrency(), facility.getAmount());
    double interestInEUR = converter.convertToEUR(facility.getCurrency(), interest);

    std::cout << "Added facility with amount " << facility.getAmount() << " " << currencyToString(facility.getCurrency())
              << " and interest rate " << facility.getInterestRate() << std::endl;

    if (facility.getCurrency() != Currency::EUR) {
        std::cout << "Converted amount: " << facility.getAmount() << " " << currencyToString(facility.getCurrency())
                  << " to " << amountInEUR << " EUR" << std::endl;
    }

    std::cout << "Calculated interest to be added: " << interestInEUR << " EUR" << std::endl;
    updateStatus();
}

void Deal::addPart(const Part& part) {
    portfolio.addPart(part);
    std::cout << "Added part with amount " << part.getAmount() << std::endl;
    updateStatus();
}

void Deal::updateStatus() {
    double totalAmountGathered = 0;
    for (const auto& facility : facilities) {
        totalAmountGathered += converter.convertToEUR(facility.getCurrency(), facility.getAmount());
    }

    double totalInterest = 0;
    for (const auto& facility : facilities) {
        totalInterest += converter.convertToEUR(facility.getCurrency(), facility.calculateInterest());
    }

    double totalPaid = portfolio.getTotalPaid();
    double totalToReimburse = totalAmountGathered + totalInterest;

    if (totalAmountGathered >= amount && status != "All money needed gathered") {
        status = "All money needed gathered";
        std::cout << "=======================================================\n"
                  << "Status updated: " << status << std::endl
                  << "=======================================================\n";
    }

    if (totalPaid >= totalToReimburse && status != "Finished and paid") {
        status = "Finished and paid";
        std::cout << "=======================================================\n"
                  << "Status updated: " << status << std::endl
                  << "=======================================================\n";
    }

    std::cout << "Updated Deal Information:\n"
              << "=======================================================\n"
              << "Total money gathered: " << totalAmountGathered << " EUR\n"
              << "Total interest: " << totalInterest << " EUR\n"
              << "Total money reimbursed: " << totalPaid << " EUR\n"
              << "Money still to reimburse: " << (totalToReimburse - totalPaid) << " EUR\n"
              << "=======================================================\n";
}

void Deal::display() const {
    double totalInterest = 0;
    for (const auto& facility : facilities) {
        totalInterest += converter.convertToEUR(facility.getCurrency(), facility.calculateInterest());
    }
    double totalPaid = portfolio.getTotalPaid();
    double totalToReimburse = 0;
    for (const auto& facility : facilities) {
        totalToReimburse += converter.convertToEUR(facility.getCurrency(), facility.getAmount());
    }
    totalToReimburse += totalInterest;
    double moneyStillToReimburse = totalToReimburse - totalPaid;

    std::cout << "==================== Deal Information ====================\n";
    std::cout << "Contract Number: " << contractNumber << "\n";
    std::cout << "Managed by: " << agent.getName() << "\n";
    std::cout << "Borrower: " << borrower.getName() << "\n";
    std::cout << "Status: " << status << "\n";
    std::cout << "Amount: " << amount << " EUR\n";
    std::cout << "Start Date: " << startDate << "\n";
    std::cout << "End Date: " << endDate << "\n";
    std::cout << "----------------------------------------------------------\n";
    std::cout << "Facilities:\n";
    for (const auto& facility : facilities) {
        facility.display();
    }
    std::cout << "----------------------------------------------------------\n";
    portfolio.display();
    std::cout << "----------------------------------------------------------\n";
    std::cout << "Money still to reimburse: " << moneyStillToReimburse << " EUR\n";
    std::cout << "==========================================================\n";
}
