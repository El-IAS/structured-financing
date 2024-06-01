#include "Part.h"
#include <iostream>

// Class Part
Part::Part(double amount) : amount(amount) {}

double Part::getAmount() const {
    return amount;
}

void Part::display() const {
    std::cout << "Part amount: " << amount << std::endl;
}
