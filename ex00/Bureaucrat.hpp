/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:33:05 by fmoulin           #+#    #+#             */
/*   Updated: 2026/03/31 20:24:30 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator = (const Bureaucrat &src);
	~Bureaucrat();
	
	const	std::string& getName() const;
	int getGrade() const;
	void	incrementGrade(int nbr);
	void	decrementGrade(int nbr);
	
	class GradeTooHighException : public std::exception
	{
	public:
		const char*	what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		const char*	what() const throw();
	};
	
	class WrongNbr : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);


# endif