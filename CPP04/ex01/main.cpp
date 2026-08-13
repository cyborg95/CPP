#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "Dog type: " << j->getType() << std::endl;
    std::cout << "Cat type: " << i->getType() << std::endl;

    j->makeSound();
    i->makeSound();

    delete j;
    delete i;

    std::cout << "\n--- Brain test ---" << std::endl;

    Dog dog;
    Cat cat;

    dog.getBrain()->setIdea(0, "I want food!");
    cat.getBrain()->setIdea(0, "I want to sleep!");

    std::cout << dog.getBrain()->getIdea(0) << std::endl;
    std::cout << cat.getBrain()->getIdea(0) << std::endl;

    return 0;
}