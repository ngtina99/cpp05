/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:05:05 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/13 22:23:48 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(Intern &copy) {
	std::cout << "Intern copy constructor called" << std::endl;		
	*this = copy;
}

Intern &Intern::operator=(Intern &rhs) {
	std::cout << "Intern copy assignment operator called" << std::endl;
	if(this == &rhs)
		return (*this);
	return (*this);
}

AForm	*Intern::makeForm(std::string &formName, std::string &formTarget) {

	std::string formType[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	AForm *(*formConstructors[3]) (std::string const &) = {
		ShrubberyCreationForm(formTarget),
		RobotomyRequestForm(formTarget),
		PresidentialPardonForm(formTarget)
	};

	i = 0;
	while (i  < 3) {
		if(formType[i] == &formName) {
			std::cout << MYGREEN "Intern creates "  MYEOF<< formName << std::endl;
			return (formConstructors[i](formTarget));
		}
		i++;
	}
	std::cerr << MYRED "Error: Form " << formName << " does not exist!" MYEOF<< std::endl;
	return(NULL);
}
