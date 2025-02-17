/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:23:40 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/17 18:43:53 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145,137), _target("defaultTarget") {
	std::cout << "ShrubberyCreationForm default constructor called for " << this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145,137), _target(target) {
	std::cout << "ShrubberyCreationForm constructor called for " << this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm ( const ShrubberyCreationForm &copy ) : AForm("ShrubberyCreationForm", 145,137), _target(copy._target) {
	std::cout << "ShrubberyCreationForm copy constructor called with " << this->_target << std::endl;
}

ShrubberyCreationForm    &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &rhs ) {
	(void) rhs;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called for " << this->_target << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

	if (this->getSignedBool() == false)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getGradeExecute())
		throw (Bureaucrat::GradeTooLowException());
	else {
		std::string fileName = this->_target + "_shrubbery";
		std::ofstream outfile(fileName.c_str());	
		outfile << TREE;
	}
}
