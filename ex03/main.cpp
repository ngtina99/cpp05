/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:32:06 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/13 23:32:57 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main() {

	Bureaucrat joaoB("Joao", 1);
	std::cout << joaoB;

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "InternFirstJob");

	AForm* ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "InternSecondJob");

	AForm* scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "InternThirdJob");

	try
	{
		joaoB.signForm(*rrf);
		std::cout << "Joao execute a RobotomyForm 4 times in a row." << std::endl;
		joaoB.executeForm(*rrf);
		joaoB.executeForm(*rrf);
		joaoB.executeForm(*rrf);
		joaoB.executeForm(*rrf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		joaoB.signForm(*ppf);
		std::cout << "Joao execute a PresidentialPardonForm." << std::endl;
		joaoB.executeForm(*ppf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		joaoB.signForm(*scf);
		std::cout << "Joao execute a ShrubberyCreationForm." << std::endl;
		joaoB.executeForm(*scf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	AForm* random;
	random = someRandomIntern.makeForm("random", "InternThirdJob");

	AForm* nullPtr;
	nullPtr = someRandomIntern.makeForm("", "InternThirdJob");

	delete rrf;
	delete ppf;
	delete scf;
	delete random;
	delete nullPtr;

}
