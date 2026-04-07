/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:32:59 by fmoulin           #+#    #+#             */
/*   Updated: 2026/04/07 18:02:22 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
	srand(time(NULL));
	try
	{
		for (int i = 0; i < 3; i++)
			std::cout << std::endl;
			
		Bureaucrat Sov("Sov", 42);
		Bureaucrat Caracole("Caracole", 150);
		Bureaucrat Coriolis("Coriolis", 24);
		Bureaucrat Golgoth("Golgoth", 4);
		ShrubberyCreationForm	Form01("sandForm");
		RobotomyRequestForm		Form02("waterForm");
		PresidentialPardonForm	Form03("windForm");
		
		std::cout << Sov << std::endl;
		std::cout << Caracole << std::endl;
		std::cout << Golgoth << std::endl;

		for (int i = 0; i < 3; i++)
			std::cout << std::endl;
			
		//   TEST INCREMENTATION TOO HIGH   //
		// Sov.incrementGrade(42);
		
		//   TEST INCREMENTATION TOO LOW   //
		// Caracole.decrementGrade(1);
		
		//   TEST SIGN FORM PERMISSION   //
		Sov.signForm(Form01);
		Golgoth.signForm(Form02);
		Coriolis.signForm(Form03);

		for (int i = 0; i < 3; i++)
			std::cout << std::endl;

		Form01.execute(Golgoth);
		Form02.execute(Golgoth);
		Form03.execute(Golgoth);
	}
	catch (std::exception & e)
	{
		std::cout	<< "Error: "
					<< e.what()
					<< std::endl;
	}
}
