/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:51:48 by fmoulin           #+#    #+#             */
/*   Updated: 2026/04/03 15:17:35 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const &name, int const &gradeRequiredToSign, int const &gradeRequiredToExecute) : _name(name), _isSigned(false), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (_gradeRequiredToSign < 1 || _gradeRequiredToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeRequiredToSign > 150 || _gradeRequiredToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeRequiredToSign(copy._gradeRequiredToSign), _gradeRequiredToExecute(copy._gradeRequiredToExecute)
{	
}

Form &Form::operator =(const Form &src)
{
	if (this != &src)
		this->_isSigned = src._isSigned;
	return (*this);
}

Form::~Form()
{
}

const char* Form::GradeTooHighException::what() const throw()
{
	return("grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("grade too low");
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getIsSigned()
{
	return (this->_isSigned);
}

int	Form::getGradeRequiredToSign() const
{
	return (this->_gradeRequiredToSign);
}

int	Form::getGradeRequiredToExecute() const
{
	return (this->_gradeRequiredToExecute);
}

std::ostream	&operator <<(std::ostream &oc, Form &src)
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

void	Form::beSigned(Bureaucrat &src)
{
	if (src.getGrade() <= this->_gradeRequiredToSign)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

