/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:32:06 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/17 15:41:30 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {

	try
	{
		Bureaucrat wrongB("Miguel", 151);
		std::cout << "Miguel initalization succeed with a grade 151!";
	}
	catch( std::exception& e )
	{
		
		std::cout << "Miguel initalization failed with a grade 151: ";
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat wrongB("Miguel", 0);
		std::cout << "Miguel initalization succeed with a grade 0! ";
	}
	catch( std::exception& e )
	{
		
		std::cout << "Miguel initalization failed with a grade 0: ";
		std::cerr << e.what() << '\n';
	}
	
	Bureaucrat *pedroB = new Bureaucrat("Pedro", 149);
	std::cout << *pedroB;
	try
	{
		pedroB->decrGrade();
		std::cout << *pedroB;
	}
	catch( std::exception& e )
	{
		std::cout << "Pedro failed with a grade " << pedroB->getGrade() << std::endl;
		std::cerr << e.what() << '\n';
	}
	try
	{
		pedroB->decrGrade();
		std::cout << *pedroB;
	}
	catch( std::exception& e )
	{
		std::cout << "Pedro failed with a grade " << pedroB->getGrade() << ": ";
		std::cerr << e.what() << '\n';
	}

	delete pedroB;
	
	Bureaucrat joaoB("Joao", 2);
	std::cout << joaoB;
	try
	{
		joaoB.incrGrade();
		std::cout << joaoB;
	}
	catch( std::exception& e )
	{
		std::cout << "Joao failed with a grade " << joaoB.getGrade() << std::endl;
		std::cerr << e.what() << '\n';
	}
	try
	{
		joaoB.incrGrade();
		std::cout << joaoB;
	}
	catch( std::exception& e )
	{
		std::cout << "Joao failed with a grade " << joaoB.getGrade() << ": ";
		std::cerr << e.what() << '\n';
	}
}
