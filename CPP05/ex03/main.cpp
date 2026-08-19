#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
    Intern intern;
    Bureaucrat boss("Boss", 1);

    AForm* form;

    std::cout << "===== Shrubbery =====" << std::endl;

    form = intern.makeForm("shrubbery creation", "garden");

    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n===== Robotomy =====" << std::endl;

    form = intern.makeForm("robotomy request", "Bender");

    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n===== Presidential Pardon =====" << std::endl;

    form = intern.makeForm("presidential pardon", "Arthur Dent");

    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n===== Invalid form =====" << std::endl;

    form = intern.makeForm("some random form", "Nobody");

    if (form)
        delete form;

    return 0;
}