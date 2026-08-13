#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {

    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;

    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {

    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;

    std::cout << "ScavTrap  constructor called for " << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << name
                  << " cannot attack."
                  << std::endl;
        return;
    }

    std::cout << name
              << " attacks " << target
              << ", causing " << attackDamage
              << " points of damage!"
              << std::endl;

    energyPoints--;
}

void ScavTrap::guardGate() {
    std::cout << name << " is now guarding the gate!" << std::endl;
}

