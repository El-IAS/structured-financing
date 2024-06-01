#include "Currency.h"
#include "Entity.h"
#include "Facility.h"
#include "Part.h"
#include "Deal.h"
#include <iostream>
#include <vector>

int main() {
    // Créer un emprunteur
    Borrower borrower("Air France");

    // Créer des prêteurs
    Lender lender1("BNP Bank");
    Lender lender2("Société Générale");

    // Créer des facilities
    std::vector<Lender> lenders = {lender1, lender2};
    Facility facility1("01/01/2024", "01/01/2029", 2500000, 0.05, Currency::EUR, lenders);
    Facility facility2("01/01/2024", "01/01/2029", 3000000, 0.04, Currency::USD, lenders);

    // Créer un deal
    std::vector<Lender> pool = {lender2};
    Deal deal("SZB1234", lender1, pool, borrower, 5000000, "01/01/2024", "01/01/2030", "open");

    // Afficher l'état initial du deal
    std::cout << "Initial state of the deal:" << std::endl;
    deal.display();
    std::cout << std::endl;

    // Ajouter des facilities au deal
    deal.addFacility(facility1);
    deal.addFacility(facility2);

    // Créer des parts (remboursements)
    Part part1(1000000); // Montant remboursé en EUR
    Part part2(2000000); // Montant remboursé en EUR
    Part part3(2000000); // Montant remboursé en EUR

    // Ajouter des parts au deal
    deal.addPart(part1);
    deal.addPart(part2);
    deal.addPart(part3);

    // Afficher les informations du deal après les ajouts
    std::cout << "Final state of the deal:" << std::endl;
    deal.display();

    return 0;
}
