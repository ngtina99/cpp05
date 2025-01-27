/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:32:06 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/27 03:10:17 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

// Please note that exception classes don’t have to be designed in
// Orthodox Canonical AForm. But every other class has to.

// Remember. Since grade 1 is the highest one and 150 the lowest,
// incrementing a grade 3 should give a grade 2 to the bureaucrat.

// Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception

int	main() {

	Bureaucrat pedroB("Pedro", 2);
	Bureaucrat JoaoB("Pedro", 2);
	Bureaucrat MiguelB("Pedro", 2);
	std::cout << pedroB;
	std::cout << JoaoB;
	std::cout << MiguelB;

	AForm formB("form1", 1, 1);
	std::cout << formB;
	try
	{
		std::cout << "Pedro with too low grade try to sign a form." << std::endl;
		pedroB.signForm(formB);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	AForm formC("form2", 2, 2);
	std::cout << formC;
	try
	{
		std::cout << "Pedro with equal grade try to sign a form." << std::endl;
		pedroB.signForm(formC);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	AForm formD("form3", 3, 3);
	std::cout << formD;
	try
	{
		std::cout << "Pedro with a higher grade try to sign a form." << std::endl;
		pedroB.signForm(formD);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		try
	{
		std::cout << "Pedro with too low grade try to sign a form." << std::endl;
		pedroB.signForm(formB);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	AForm formC("form2", 2, 2);
	std::cout << formC;
	try
	{
		std::cout << "Pedro with equal grade try to sign a form." << std::endl;
		pedroB.signForm(formC);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	AForm formD("form3", 3, 3);
	std::cout << formD;
	try
	{
		std::cout << "Pedro with a higher grade try to sign a form." << std::endl;
		pedroB.signForm(formD);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// std::cout << std::cout << "\e[1;1H\e[2J";
	// try
	// {
	// 	Bureaucrat	*b = new Bureaucrat("Bob", 30);
	// 	Bureaucrat	*b1 = new Bureaucrat("Marley", 10);
	// 	ShrubberyCreationForm	*scf = new ShrubberyCreationForm();
	// 	RobotomyRequestForm		*rrf = new RobotomyRequestForm();
	// 	PresidentialPardonForm	*ppf = new PresidentialPardonForm();
	// 	b->signForm(*scf);
	// 	b->signForm(*rrf);
	// 	b1->signForm(*ppf);
	// 	b->executeForm(*rrf);
	// 	b->executeForm(*scf);
	// 	b1->executeForm(*ppf);
	// 	delete(b);
	// 	delete(scf);
	// 	delete(rrf);
	// 	delete(ppf);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// return (0);
}
