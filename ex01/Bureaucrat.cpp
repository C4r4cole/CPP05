/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:33:08 by fmoulin           #+#    #+#             */
/*   Updated: 2026/04/02 18:23:10 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &src)
{
	if (this != &src)
	{
		this->_grade = src._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const	std::string& Bureaucrat::getName() const
{
	return(_name);
}

int Bureaucrat::getGrade() const
{
	return(_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("grade too low");
}

const char* Bureaucrat::WrongNbr::what() const throw()
{
	return("Nbr cannot be negative");
}

void	Bureaucrat::incrementGrade(int nbr)
{
	int newGrade;
	
	if (nbr <= 0)
		throw Bureaucrat::WrongNbr();
		
	newGrade = this->_grade - nbr;
	if (newGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = newGrade;
}

void	Bureaucrat::decrementGrade(int nbr)
{
	int newGrade;
	
	if (nbr <= 0)
		throw Bureaucrat::WrongNbr();
		
	newGrade = this->_grade + nbr;
	if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = newGrade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os	<< bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade();

	return (os);
}

void	Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
	
	if (form.getIsSigned())
	{
		std::cout 	<< this
					<< " signed "
					<< form
					<< std::endl;
	}
	else
	{
		std::cout	<< this
					<< " couldn't sign "
					<< form
					<< " because grade required is too low"
					<< std::endl;
	}
}
