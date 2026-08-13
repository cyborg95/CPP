#include "FragTrap.hpp"

int main(void)
{
    FragTrap bob("Bob");

    bob.attack("Enemy");
    bob.takeDamage(40);
    bob.beRepaired(20);
    bob.highFive();

    return 0;
}