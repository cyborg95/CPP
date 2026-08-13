#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "===== Correct polymorphism =====" << std::endl;

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << "\n===== Wrong polymorphism =====" << std::endl;

    const WrongAnimal* wrongCat = new WrongCat();

    wrongCat->makeSound();

    delete wrongCat;

    return 0;
}