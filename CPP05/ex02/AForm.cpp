#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default Form"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &copy)
    : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

AForm &AForm::operator=(const AForm &copy)

{
    if (this != &copy)
    {
        _isSigned = copy._isSigned;
        _gradeToSign = copy._gradeToSign;
        _gradeToExecute = copy._gradeToExecute;
    }
    return *this;
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

const char *AForm::GradeTooLowToExecuteException::what() const throw()
{
    return "Grade is too low to execute the form!";
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowToExecuteException();
    executeAction();
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
    return out;
}
