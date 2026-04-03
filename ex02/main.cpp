/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:32:59 by fmoulin           #+#    #+#             */
/*   Updated: 2026/04/03 15:19:37 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	
	try
	{
		for (int i = 0; i < 3; i++)
			std::cout << std::endl;
			
		Bureaucrat Sov("Sov", 42);
		Bureaucrat Caracole("Caracole", 150);
		Bureaucrat Golgoth("Golgoth", 52);
		Form	windForm01("wind1", 50, 50);
		
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
		// Sov.signForm(windForm01);
		// Golgoth.signForm(windForm01);

		for (int i = 0; i < 3; i++)
			std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout	<< "Error: "
					<< e.what()
					<< std::endl;
	}
}
