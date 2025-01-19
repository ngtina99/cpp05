/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:11:58 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/19 00:52:37 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
//If the grade is out of range, both of them will throw the same exceptions as the constructor.

Bureaucrat::Bureaucrat(): _name("defaultName"), _grade(150) {
	std::cout << "Bureaucrat default constructor called for " << this->_name
			  << "with grade " << this->_grade << std::endl;
}
 
//When you write throw Bureaucrat::GradeTooHighException();, you're creating an instance of that class 
//and throwing it as an exception.
// The parentheses () indicate that the default constructor of
// GradeTooHighException is being called to create an instance.

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

int	const Bureaucrat::getGrade() const {
	return(this->_grade);
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return("\033[1;31mGrade is Too Low\033[0m");
} 

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return("\033[1;31mGrade is Too High\033[0m");
}

void	Bureaucrat::signForm(Form &formToSign) {
	try {
		formToSign.beSigned(*this);
		std::cout << "\033[1;32m" << this->_name << " signed " << formToSign.getName() << "\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->_name << " couldn't sign " << formToSign.getName() << " because: ";
		std::cerr << e.what() <<'\n';
	}
}

std::ostream &operator<<( std::ostream &op, const Bureaucrat &copy) {
	/*<name>, bureaucrat grade <grade>*/
	return(op << "\033[1;34m" << copy.getName() << ", bureaucrat grade " << copy.getGrade() << "\033[0m" << std::endl);
}
