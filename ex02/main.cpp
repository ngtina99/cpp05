/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:32:06 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/13 16:03:07 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

// Remember. Since grade 1 is the highest one and 150 the lowest,
// incrementing a grade 3 should give a grade 2 to the bureaucrat.

// Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception

int	main() {

	Bureaucrat pedroB("Pedro", 149);
	std::cout << pedroB;

	RobotomyRequestForm formRobotomy("Robotomy");
	try
	{
		std::cout << "Pedro with too low grade try to sign a RobotomyForm." << std::endl;
		pedroB.signForm(formRobotomy);
		pedroB.executeForm(formRobotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	PresidentialPardonForm formPresidential("Presidential");
	try
	{
		std::cout << "Pedro with too low grade try to sign a PresidentialPardonForm." << std::endl;
		pedroB.signForm(formPresidential);
		pedroB.executeForm(formPresidential);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	ShrubberyCreationForm formShrubbery("Shrubbery");
	try
	{
		std::cout << "Pedro with too low grade try to sign a ShrubberyCreationForm." << std::endl;
		pedroB.signForm(formShrubbery);
		pedroB.executeForm(formShrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat JoaoB("Joao", 1);
	std::cout << JoaoB;

	RobotomyRequestForm formRobotomy2("Robotomy2");
	try
	{
		std::cout << "Joao execute a RobotomyForm 4 times in a row." << std::endl;
		JoaoB.signForm(formRobotomy2);
		JoaoB.executeForm(formRobotomy2);
		JoaoB.executeForm(formRobotomy2);
		JoaoB.executeForm(formRobotomy2);
		JoaoB.executeForm(formRobotomy2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	PresidentialPardonForm formPresidential2("Presidential2");
	try
	{
		std::cout << "Joao execute a PresidentialPardonForm." << std::endl;
		JoaoB.signForm(formPresidential2);
		JoaoB.executeForm(formPresidential2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	ShrubberyCreationForm formShrubbery2("Shrubbery2");
	try
	{
		std::cout << "Joao execute a ShrubberyCreationForm." << std::endl;
		JoaoB.signForm(formShrubbery2);
		JoaoB.executeForm(formShrubbery2);
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
