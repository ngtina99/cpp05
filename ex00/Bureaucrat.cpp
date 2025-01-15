/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:11:58 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/15 16:44:31 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//If the grade is out of range, both of them will throw the same exceptions as the constructor.

Bureaucrat::Bureaucrat(): _name("defaultName"), _grade(150) {
	std::cout << "Bureaucrat default constructor called for " << this->_name
			  << "with grade " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(int grade): _name("defaultName"), _grade(grade) {
	if(this->_grade < _maxGrade)
		throw(GradeTooHighException());		
	if(this->_grade > _minGrade)
		throw(GradeTooLowException());
	std::cout << "Bureaucrat constructor called for " << this->_name
			  << "with grade " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name): _name(name), _grade(150) {
	std::cout << "Bureaucrat constructor called for " << this->_name
			  << "with grade " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade) {
	if(this->_grade < _maxGrade)
		throw(GradeTooHighException());		
	if(this->_grade > _minGrade)
		throw(GradeTooLowException());
	std::cout << "Bureaucrat constructor called for " << this->_name
			  << "with grade " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade (copy._grade) {
	std::cout << "Bureaucrat copy constructor called with " << this->_name << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called for " << this->_name << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "Bureaucrat copy assignment operator called with " << this->_name << std::endl;
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

GradeTooHighException 

