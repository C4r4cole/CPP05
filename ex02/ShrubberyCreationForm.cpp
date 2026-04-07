/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:51:48 by fmoulin           #+#    #+#             */
/*   Updated: 2026/04/07 16:34:56 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator =(const ShrubberyCreationForm &src)
{
	if (this != &src)
		AForm::operator=(src);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const char *ShrubberyCreationForm::FileCannotOpenException::what() const throw()
{
	return ("Error: cannot open!");
};

void	ShrubberyCreationForm::executeAction() const
{
	std::string		FileName;
	std::ofstream	AsciiTree;
	
	FileName = this->_target + "_shrubbery";
	AsciiTree.open(FileName.c_str());
	if (!AsciiTree)
		throw FileCannotOpenException();
	AsciiTree	<< "   /\\" 
				<< std::endl
				<< "  /**\\"
				<< std::endl
				<< " /****\\"
				<< std::endl
				<< "   ||"
				<< std::endl;
}