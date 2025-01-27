/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:23:33 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/27 03:07:11 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("defaultTarget") {
	std::cout << "RobotomyRequestForm default constructor called for " << this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm default constructor called for " << this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm ( const RobotomyRequestForm &copy ) : AForm("RobotomyRequestForm", 72, 45), _target(copy._target) {
	std::cout << "RobotomyRequestForm copy constructor called with " << this->_target << std::endl;
}

RobotomyRequestForm    &RobotomyRequestForm::operator=( const RobotomyRequestForm &rhs ) {
	return *this; //everything is constants
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called for " << this->_target << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {

	static int number;
	
	if (this->getSignedBool() == false)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getGradeExecute())
		throw (Bureaucrat::GradeTooLowException());
	
	std::cout << MYPURPLE << "*making drilling noises...*" << MYEOF << std::endl;
	if (number++ % 2)
		std::cout << MYPURPLE << this->_target << " has been robotomized successfully" << MYEOF << std::endl;
	else
		std::cout << MYPURPLE << this->_target << "'s robotomy failed" << MYEOF << std::endl;
}
