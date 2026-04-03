/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:51:48 by fmoulin           #+#    #+#             */
/*   Updated: 2026/04/03 17:55:17 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const &name, int const &gradeRequiredToSign, int const &gradeRequiredToExecute) : _name(name), _isSigned(false), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (_gradeRequiredToSign < 1 || _gradeRequiredToExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeRequiredToSign > 150 || _gradeRequiredToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeRequiredToSign(copy._gradeRequiredToSign), _gradeRequiredToExecute(copy._gradeRequiredToExecute)
{	
}

AForm &AForm::operator =(const AForm &src)
{
	if (this != &src)
		this->_isSigned = src._isSigned;
	return (*this);
}

AForm::~AForm()
{
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return("grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("grade too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return("form not signed");
}

const std::string&	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int	AForm::getGradeRequiredToSign() const
{
	return (this->_gradeRequiredToSign);
}

int	AForm::getGradeRequiredToExecute() const
{
	return (this->_gradeRequiredToExecute);
}

std::ostream	&operator <<(std::ostream &oc, const AForm &src)
{
	oc	<< RED
		<< "Name: "
		<< src.getName()
		<< ", is signed: "
		<< src.getIsSigned()
		<< ", grade required to sign: "
		<< src.getGradeRequiredToSign()
		<< ", grade required to execute: "
		<< src.getGradeRequiredToExecute()
		<< RESET;
	
	return (oc);
}

void	AForm::beSigned(Bureaucrat const &src)
{
	if (src.getGrade() <= this->_gradeRequiredToSign)
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const
{	
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeRequiredToExecute)
		throw AForm::GradeTooLowException();
	executeAction();
}
