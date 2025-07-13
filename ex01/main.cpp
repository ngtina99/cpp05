/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:32:06 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/17 15:42:41 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {

	try
	{
		std::cout << "Try to create a Form with 151 sign grade." << std::endl;
		Form formA("151Form", 151, 150);
		std::cout << formA;	
	}
	catch( std::exception& e )
	{
		std::cout << "Form initalization failed because: ";
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Try to create a Form with 0 sign grade." << std::endl;
		Form formA("151Form", 0, 150);
		std::cout << formA;	
	}
	catch( std::exception& e )
	{
		std::cout << "Form initalization failed because: ";
		std::cerr << e.what() << '\n';
	}

	Bureaucrat pedroB("Pedro", 2);
	std::cout << pedroB;
	Form formB("form1", 1, 1);
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

	Form formC("form2", 2, 2);
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

	Form formD("form3", 3, 3);
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
}
