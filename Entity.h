#ifndef ENTITY_H
#define ENTITY_H

#include <string>

// Class Entity (base class for Borrower and Lender)
class Entity {
protected:
    std::string name;

public:
    Entity(const std::string& name);
    std::string getName() const;
    virtual void display() const = 0; // Pure virtual function
};

// Class Borrower
class Borrower : public Entity {
public:
    Borrower(const std::string& name);
    void display() const override;
};

// Class Lender
class Lender : public Entity {
public:
    Lender(const std::string& name);
    void display() const override;
};

#endif // ENTITY_H
