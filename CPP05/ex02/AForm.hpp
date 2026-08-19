#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
private:
	std::string _name;
	bool _isSigned;
	int _gradeToSign;
	int _gradeToExecute;
public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	~AForm();
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);
	void execute(const Bureaucrat &executor) const;

	virtual void executeAction() const = 0;



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

	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowToExecuteException : public std::exception
	{
	public:
		const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif