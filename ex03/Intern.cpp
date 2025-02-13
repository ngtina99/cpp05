/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:05:05 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/13 23:21:33 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

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

AForm *Intern::makeRobotomy(std::string const &target) {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidential(std::string const &target) {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeShrubbery(std::string const &target) {
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget) {

	if (formName.empty()) {
		std::cerr <<MYRED "Error: Form name cannot be empty" MYEOF<< std::endl;
		return (NULL);
	}

	std::string formType[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	AForm *(*formConstructors[3]) (std::string const &) = {
		makeRobotomy,
		makeShrubbery,
		makePresidential
	};

	int i = 0;
	while (i < 3) {
		if(formType[i] == formName) {
			std::cout << MYGREEN "Intern creates "  << formName << MYEOF << std::endl;
			return (formConstructors[i](formTarget));
		}
		i++;
	}
	std::cerr << MYRED "Error: Form " << formName << " is not an acceptable input" MYEOF<< std::endl;
	return (NULL);
}
