#include "Entity.h"
#include <iostream>

// Class Entity (base class for Borrower and Lender)
Entity::Entity(const std::string& name) : name(name) {}

std::string Entity::getName() const {
    return name;
}

// Class Borrower
Borrower::Borrower(const std::string& name) : Entity(name) {}

void Borrower::display() const {
    std::cout << "Borrower: " << name << std::endl;
}

// Class Lender
Lender::Lender(const std::string& name) : Entity(name) {}

void Lender::display() const {
    std::cout << "Lender: " << name << std::endl;
}
