/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:22:25 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/13 22:59:31 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("defaultTarget") {
	std::cout << "PresidentialPardonForm default constructor called for " << this->_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm constructor called for " << this->_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm ( const PresidentialPardonForm &copy ) : AForm("PresidentialPardonForm", 25, 5), _target(copy._target) {
	std::cout << "PresidentialPardonForm copy constructor called with " << this->_target << std::endl;
}

PresidentialPardonForm    &PresidentialPardonForm::operator=( const PresidentialPardonForm &rhs ) {
	return *this; //everything is constants
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called for " << this->_target << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {

	static int number;
	
	if (this->getSignedBool() == false)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getGradeExecute())
		throw (Bureaucrat::GradeTooLowException());
	std::cout << MYPURPLE << this->_target << " has been pardoned by Zaphod Beeblerox." << MYEOF << std::endl;
}


