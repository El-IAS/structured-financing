#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Part.h"
#include <vector>

// Class Portfolio
class Portfolio {
private:
    std::vector<Part> parts;

public:
    void addPart(const Part& part);
    double getTotalPaid() const;
    void display() const;
};

#endif // PORTFOLIO_H
