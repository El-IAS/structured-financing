#ifndef PART_H
#define PART_H

// Class Part
class Part {
private:
    double amount;

public:
    Part(double amount);
    double getAmount() const;
    void display() const;
};

#endif // PART_H
