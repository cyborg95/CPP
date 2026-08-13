#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    Dog dog;
    Cat cat;
    Animal animal;

    animal.makeSound();
    dog.makeSound();
    cat.makeSound();

    return 0;
}