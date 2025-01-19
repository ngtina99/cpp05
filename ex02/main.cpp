/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:32:06 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/19 01:01:00 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
// Please note that exception classes don’t have to be designed in
// Orthodox Canonical Form. But every other class has to.

// Remember. Since grade 1 is the highest one and 150 the lowest,
// incrementing a grade 3 should give a grade 2 to the bureaucrat.

// Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception

int	main() {

	// try
	// {
	// 	Bureaucrat wrongB("Miguel", 151);
	// }
	// catch( std::exception& e )
	// {
		
	// 	std::cout << "Miguel initalization failed with a grade 151: ";
	// 	std::cerr << e.what() << '\n';
	// }

	// try
	// {
	// 	Bureaucrat wrongB("Miguel", 0);
	// }
	// catch( std::exception& e )
	// {
		
	// 	std::cout << "Miguel initalization failed with a grade 0: ";
	// 	std::cerr << e.what() << '\n';
	// }
	try
	{
		std::cout << "Try to create a Form with too low sign grade." << std::endl;
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
		std::cout << "Try to create a Form with too high sign grade." << std::endl;
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
