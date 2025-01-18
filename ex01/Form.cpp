/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:34:37 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/18 23:42:17 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("defaultForm"), _signed(false), _gradeSign(150), _gradeExecute(150) {
	std::cout << "Form default constructor called for " << this->_name
			<< "with sign grade " << this->_gradeSign <<
			" and execution grade " << this->_gradeExecute << std::endl;
}

Form::Form( std::string const &name ): _name(name), _signed(false), _gradeSign(150), _gradeExecute(150) {
	st8d::cout << "Form  constructor called for " << this->_name
			<< "with sign grade " << this->_gradeSign <<
			" and execution grade " << this->_gradeExecute << std::endl;
}

Form::Form( int const gradeSign, int const gradeExecute ): _name("formName"), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	if(this->_gradeExecute <_maxGrade || this->_gradeSign < _maxGrade )
		throw(GradeTooHighException());
	if(this->_gradeExecute >_minGrade || this->_gradeSign >_minGrade ) //change this try catch maybe later to fix
		throw(GradeTooLowException());
	std::cout << "Form  constructor called for " << this->_name
			<< "with sign grade " << this->_gradeSign <<
			" and execution grade " << this->_gradeExecute << std::endl;
}

//example
// Bureaucrat::Bureaucrat(int grade): _name("default")
// {
// 	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
// 	" with grade of " << grade << std::endl;
// 	try
// 	{
// 		this->setGrade(grade);
// 	}
// 	catch(Bureaucrat::GradeTooHighException &e)
// 	{
// 		std::cerr << "\033[33mConstructing " << this->getName() <<
// 		" failed: " << e.what() << std::endl <<
// 		"Grade now set to 1" << "\033[0m" << std::endl;
// 		this->setGrade(1);
// 	}
// 	catch(Bureaucrat::GradeTooLowException &e)
// 	{
// 		std::cerr << "\033[33mConstructing " << this->getName() <<
// 		" failed: " << e.what() << std::endl <<
// 		"Grade now set to 150" << "\033[0m" << std::endl;
// 		this->setGrade(150);
// 	}
// }

Form::Form( std::string const &name, int const gradeSign, int const gradeExecute ): _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	if(this->_gradeExecute <_maxGrade || this->_gradeSign < _maxGrade )
		throw(GradeTooHighException());
	if(this->_gradeExecute >_minGrade || this->_gradeSign >_minGrade )
		throw(GradeTooLowException());
	std::cout << "Form  constructor called for " << this->_name
			<< "with sign grade " << this->_gradeSign <<
			" and execution grade " << this->_gradeExecute << std::endl;
}

Form::Form (const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeSign(copy._gradeSign), _gradeExecution(copy._gradeExecution) {
	std::cout << "Form copy constructor called with " << this->name << std::endl;
}

Form	&Form::operator=( const Form &rhs ) {
	if (this !=&rhs)
		this->_gradeExecute = rhs._gradeExecute;
		this->_gradeSign = rhs._gradeExecute;
		this->_signed = rhs._signed; //only non-const memeber!!
	return (*this);
}

Form::~Form() {
	std::cout << "Form detructor called for " << this->name << std::endl;
}

void	Form::beSigned(Bureaucrat &signatory) {
	if (signatory.getGrade() > this->_gradeSign)
		throw (Form::GradeTooLowException);
	this->_signed = true;
}

std::string const &Form::getName() const {
	return(this->_name);
}

std::string	Form::getSigned() const {
	if (this->_signed == true)
		return("signed");
	if (this->_signed == false)
		return("not signed");
}

int const Form::getGradeSign() const {
	return( this->_gradeSign);
}

int const Form::getGradExecution() const {
	return( this->_gradeExecution);
}

const char *Form::GradeTooLowException::what() const throw() {
	return( "\033[1;34mGrade is Too Low\033[0m");
}

const char *Form::GradeTooHighException::what() const throw() {
	return("\033[1;31mGrade is Too High\033[0m");
}

std::ostream	&operator<<( std::ostream &op, const Form &copy ) {
	return( op << "\033[1;34m" << copy.getName() << " is " << copy.getSigned() << " , form sign grade " << copy.getGradeSign() << ", form execution grade " << copy.getGaredExecution() << std::endl);
}
