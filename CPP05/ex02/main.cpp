#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 140);

    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << "\n===== SHRUBBERY =====" << std::endl;

    boss.signForm(shrub);
    boss.executeForm(shrub);

    std::cout << "\n===== ROBOTOMY =====" << std::endl;

    boss.signForm(robot);
    boss.executeForm(robot);

    std::cout << "\n===== PRESIDENTIAL PARDON =====" << std::endl;

    boss.signForm(pardon);
    boss.executeForm(pardon);

    std::cout << "\n===== LOW GRADE TEST =====" << std::endl;

    worker.signForm(pardon);
    worker.executeForm(pardon);

    return 0;
}