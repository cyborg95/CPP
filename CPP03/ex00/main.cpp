#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clap("Bob");

    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    clap.takeDamage(20);
    clap.attack("Enemy");
    clap.beRepaired(5);

    return 0;
}