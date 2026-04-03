/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:51:52 by fmoulin           #+#    #+#             */
/*   Updated: 2026/04/03 14:28:03 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeRequiredToSign;
	const int			_gradeRequiredToExecute;
public:
	Form(std::string const &name, int const &gradeRequiredToSign, int const &gradeRequiredToExecute);
	Form(const Form &copy);
	Form &operator =(const Form &src);
	~Form();

	std::string	getName() const;
	bool		getIsSigned();
	int			getGradeRequiredToSign() const;
	int			getGradeRequiredToExecute() const;

	void		beSigned(Bureaucrat &src);

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

	class WrongNbr : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

std::ostream	&operator <<(std::ostream &oc, Form &src);

#endif