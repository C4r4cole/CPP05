/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:51:48 by fmoulin           #+#    #+#             */
/*   Updated: 2026/04/08 17:41:45 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern &Intern::operator =(const Intern &src)
{
	(void)src;
	return (*this);
}

Intern::~Intern()
{
}

static AForm	*makeShrubberyCreation(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*makeRobotomyRequest(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makePresidentialPardon(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string const &formName, std::string const &formTarget) const
{
	std::string	formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*		(*formMakers[3])(std::string const &) = {makeShrubberyCreation, makeRobotomyRequest, makePresidentialPardon};
	
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (formMakers[i](formTarget));
		}
	}
	std::cout << "This Intern is really incompetent! Fired!" << std::endl;
	return (NULL);
}

