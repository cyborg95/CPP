#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "===== DiamondTrap Test =====" << std::endl;

    DiamondTrap diamond("Diamond");

    std::cout << "\n--- whoAmI ---" << std::endl;
    diamond.whoAmI();

    std::cout << "\n--- Attack ---" << std::endl;
    diamond.attack("Enemy");

    std::cout << "\n--- Damage ---" << std::endl;
    diamond.takeDamage(40);

    std::cout << "\n--- Repair ---" << std::endl;
    diamond.beRepaired(20);

    std::cout << "\n--- FragTrap ability ---" << std::endl;
    diamond.highFive();

    std::cout << "\n--- ScavTrap ability ---" << std::endl;
    diamond.guardGate();

    std::cout << "\n===== End =====" << std::endl;

    return 0;
}