#include "Facility.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <chrono>

// Utility function to calculate the duration between two dates in years
double calculateDuration(const std::string& startDate, const std::string& endDate) {
    std::tm tmStart = {};
    std::tm tmEnd = {};
    std::istringstream ssStart(startDate);
    std::istringstream ssEnd(endDate);
    ssStart >> std::get_time(&tmStart, "%d/%m/%Y");
    ssEnd >> std::get_time(&tmEnd, "%d/%m/%Y");
    std::chrono::system_clock::time_point timeStart = std::chrono::system_clock::from_time_t(std::mktime(&tmStart));
    std::chrono::system_clock::time_point timeEnd = std::chrono::system_clock::from_time_t(std::mktime(&tmEnd));
    std::chrono::duration<double, std::ratio<3600 * 24 * 365>> duration = timeEnd - timeStart;
    return duration.count();
}

// Class Facility
Facility::Facility(const std::string& startDate, const std::string& endDate, double amount, double interestRate, Currency currency, std::vector<Lender> lenders)
    : startDate(startDate), endDate(endDate), amount(amount), interestRate(interestRate), currency(currency), lenders(lenders) {}

double Facility::calculateInterest() const {
    double duration = calculateDuration(startDate, endDate);
    return amount * interestRate * duration;
}

Currency Facility::getCurrency() const {
    return currency;
}

double Facility::getAmount() const {
    return amount;
}

double Facility::getInterestRate() const {
    return interestRate;
}

void Facility::display() const {
    std::cout << "Facility from " << startDate << " to " << endDate << " with amount " << amount << " " << currencyToString(currency)
              << " and interest rate " << interestRate << " calculated interest: " << calculateInterest() << std::endl;
}
