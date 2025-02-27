/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:32:06 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/17 15:43:27 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main() {

	Bureaucrat pedroB("Pedro", 149);
	std::cout << pedroB;
	RobotomyRequestForm formRobotomy("Robotomy");
	try
	{
		std::cout << "Pedro with too low grade try to sign a RobotomyForm." << std::endl;
		pedroB.signForm(formRobotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Pedro try to excecute a RobotomyForm." << std::endl;
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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Pedro try to execute a PresidentialPardonForm." << std::endl;
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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Pedro try to execute a ShrubberyCreationForm." << std::endl;
		pedroB.executeForm(formShrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat joaoB("Joao", 1);
	std::cout << joaoB;
	try
	{
		joaoB.signForm(formRobotomy);
		std::cout << "Joao execute a RobotomyForm 4 times in a row." << std::endl;
		joaoB.executeForm(formRobotomy);
		joaoB.executeForm(formRobotomy);
		joaoB.executeForm(formRobotomy);
		joaoB.executeForm(formRobotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		joaoB.signForm(formPresidential);
		std::cout << "Joao execute a PresidentialPardonForm." << std::endl;
		joaoB.executeForm(formPresidential);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		joaoB.signForm(formShrubbery);
		std::cout << "Joao execute a ShrubberyCreationForm." << std::endl;
		joaoB.executeForm(formShrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Pedro try to execute a RobotomyForm again." << std::endl;
		pedroB.executeForm(formRobotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Pedro try to execute a PresidentialPardonForm again." << std::endl;
		pedroB.executeForm(formPresidential);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Pedro try to execute a ShrubberyCreationForm again." << std::endl;
		pedroB.executeForm(formShrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
