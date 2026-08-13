#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("ClapTrap"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap default constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "ClapTrap copy constructor called for " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    
    std::cout << "ClapTrap assignment operator called for " << name << std::endl;

    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string& target) {

    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << name
                  << " cannot attack." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;

    energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
   if (hitPoints == 0)
    {
        std::cout << name
                  << " is already out of HP."
                  << std::endl;
        return;
    }

    if (amount >= hitPoints)
        hitPoints = 0;
    else
        hitPoints -= amount;

    std::cout << name
              << " takes " << amount
              << " points of damage!"
              << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << name
                  << " cannot be repaired."
                  << std::endl;
        return;
    }

    std::cout << name
              << " repairs itself for "
              << amount << " HP!"
              << std::endl;

    hitPoints += amount;
    energyPoints--;

}

