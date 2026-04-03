/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:51:52 by fmoulin           #+#    #+#             */
/*   Updated: 2026/04/03 17:28:40 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeRequiredToSign;
	const int			_gradeRequiredToExecute;
public:
	AForm(std::string const &name, int const &gradeRequiredToSign, int const &gradeRequiredToExecute);
	AForm(const AForm &copy);
	AForm &operator =(const AForm &src);
	virtual ~AForm();

	const std::string&	getName() const;
	bool				getIsSigned() const;
	int					getGradeRequiredToSign() const;
	int					getGradeRequiredToExecute() const;

	void				beSigned(Bureaucrat const &src);
	void				execute(Bureaucrat const &executor) const;
	virtual void		executeAction() const = 0;

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
};

std::ostream	&operator <<(std::ostream &oc, const AForm &src);

#endif