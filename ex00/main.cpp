/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:32:59 by fmoulin           #+#    #+#             */
/*   Updated: 2026/04/02 14:50:36 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat a("Sov", 42);
		Bureaucrat b("Caracole", 150);
		
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		// a.incrementGrade(42);
		b.decrementGrade(1);
	}
	catch (std::exception & e)
	{
		std::cout	<< "Error: "
					<< e.what()
					<< std::endl;
	}
}
