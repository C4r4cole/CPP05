/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:32:59 by fmoulin           #+#    #+#             */
/*   Updated: 2026/04/06 18:05:24 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	
	try
	{
		for (int i = 0; i < 3; i++)
			std::cout << std::endl;
			
		Bureaucrat Sov("Sov", 42);
		Bureaucrat Caracole("Caracole", 150);
		Bureaucrat Coriolis("Coriolis", 24);
		Bureaucrat Golgoth("Golgoth", 4);
		PresidentialPardonForm	Form01("windForm");
		
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
		Coriolis.signForm(Form01);

		for (int i = 0; i < 3; i++)
			std::cout << std::endl;

		Form01.execute(Golgoth);
	}
	catch (std::exception & e)
	{
		std::cout	<< "Error: "
					<< e.what()
					<< std::endl;
	}
}
