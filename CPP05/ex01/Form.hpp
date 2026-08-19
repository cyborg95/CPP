#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
	std::string _name;
	bool _isSigned;
	int _gradeToSign;
	int _gradeToExecute;
public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	~Form();
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif