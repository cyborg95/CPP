#include "Weapon.hpp"

Weapon::Weapon() : _type("default") {
    std::cout << "Weapon created with default type." << std::endl;
}

Weapon::Weapon(const std::string &type) : _type(type) {
    std::cout << "Weapon created with type: " << _type << std::endl;
}

Weapon::~Weapon() {
    std::cout << "Weapon destroyed." << std::endl;
}

const std::string &Weapon::getType() const {
    return _type;
}

void Weapon::setType(const std::string &type) {
    _type = type;
}