/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:11:58 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/17 18:47:37 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const int Bureaucrat::_minGrade = 150;
const int Bureaucrat::_maxGrade = 1;

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
			  << " with grade " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name): _name(name), _grade(150) {
	std::cout << "Bureaucrat constructor called for " << this->_name
			  << " with grade " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade) {
	if(this->_grade < _maxGrade)
		throw(GradeTooHighException());		
	if(this->_grade > _minGrade)
		throw(GradeTooLowException());
	std::cout << "Bureaucrat constructor called for " << this->_name
			  << " with grade " << this->_grade << std::endl;
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

void	Bureaucrat::incrGrade() {
	this->_grade--;
	if(this->_grade < _maxGrade)
		throw(GradeTooHighException());
	std::cout << "Bureaucrat " << this->_name << " grade incremented to " << this->_grade << std::endl;
}

void	Bureaucrat::decrGrade() {
	this->_grade++;
	if(this->_grade > _minGrade)
		throw(GradeTooLowException());
	std::cout << "Bureaucrat " << this->_name << " grade decremented to " << this->_grade << std::endl;	
}

std::string const &Bureaucrat::getName() const {
	return(this->_name);
}

int	const &Bureaucrat::getGrade() const {
	return(this->_grade);
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return(MYRED "Grade is Too Low" MYEOF);
} 

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return(MYRED "Grade is Too High" MYEOF);
}

void	Bureaucrat::signForm(AForm &formToSign) {
	try {
		formToSign.beSigned(*this);
		std::cout << MYGREEN << this->_name << " signed " << formToSign.getName() << MYEOF << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->_name << " couldn't sign " << formToSign.getName() << " because: ";
		std::cerr << e.what() <<'\n';
	}
}

void	Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << MYGREEN << this->_name << " executed " << form.getName() << MYEOF << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->_name << " couldn't execute " << form.getName() << " because: ";
		std::cerr << e.what() <<'\n';
	}
}

std::ostream &operator<<( std::ostream &op, const Bureaucrat &copy) {
	return(op << MYBLUE << copy.getName() << ", bureaucrat grade " << copy.getGrade() << MYEOF << std::endl);
}
