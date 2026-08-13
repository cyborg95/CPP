#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap bob("Bob");

    bob.attack("Enemy");
    bob.takeDamage(30);
    bob.beRepaired(10);
    bob.guardGate();

    return 0;
}