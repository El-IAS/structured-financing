#include "Portfolio.h"
#include <iostream>

// Class Portfolio
void Portfolio::addPart(const Part& part) {
    parts.push_back(part);
}

double Portfolio::getTotalPaid() const {
    double totalPaid = 0;
    for (const auto& part : parts) {
        totalPaid += part.getAmount();
    }
    return totalPaid;
}

void Portfolio::display() const {
    std::cout << "Portfolio:" << std::endl;
    for (const auto& part : parts) {
        part.display();
    }
    std::cout << "Total amount paid in portfolio: " << getTotalPaid() << std::endl;
}
