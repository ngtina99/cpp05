/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:23:40 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/27 03:07:15 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145,137), _target("defaultTarget") {
	std::cout << "ShrubberyCreationForm default constructor called for " << this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145,137), _target(target) {
	std::cout << "ShrubberyCreationForm default constructor called for " << this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm ( const ShrubberyCreationForm &copy ) : AForm("ShrubberyCreationForm", 145,137), _target(copy._target) {
	std::cout << "ShrubberyCreationForm copy constructor called with " << this->_target << std::endl;
}

ShrubberyCreationForm    &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &rhs ) {
	return *this; //everything is constants
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
		std::ofstream outfile;
		outfile.open((this->_target+"_shrubbery").c_str());	
		//or std::string fn fn = this->_target+"_shrubbery" outfile(fn)
	// 		fileout.open((this->_target + "_shrubbery").c_str(), std::ios::out);
	// if (!fileout)
	// 	throw(FileNotOpen());	
		outfile << TREE;
		outfile.close();
	}
}
