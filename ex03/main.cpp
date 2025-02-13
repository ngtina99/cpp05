/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:32:06 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/13 23:20:56 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main() {

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "InternFirstJob");

	delete rrf;
	
	AForm* ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "InternSecondJob");

	delete ppf;

	AForm* scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "InternThirdJob");

	delete scf;
	
	AForm* random;
	random = someRandomIntern.makeForm("random", "InternThirdJob");

	delete random;

	AForm* nullPtr;
	nullPtr = someRandomIntern.makeForm("", "InternThirdJob");

	delete nullPtr;

}
