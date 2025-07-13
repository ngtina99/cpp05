/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:05:07 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/27 01:44:46 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

	private:

		static AForm *makeRobotomy(std::string const &target);
		static AForm *makeShrubbery(std::string const &target);
		static AForm *makePresidential(std::string const &target);

	public:

		Intern();
		~Intern();
		Intern(Intern &copy);
		Intern &operator=(Intern &rhs);

		AForm	*makeForm(std::string formName, std::string formTarget);

};

#endif