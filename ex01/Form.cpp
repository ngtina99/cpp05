/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:34:37 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/17 18:41:16 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const int Form::_minGrade = 150;
const int Form::_maxGrade = 1;

Form::Form(): _name("defaultForm"), _signed(false), _gradeSign(150), _gradeExecute(150) {
	std::cout << "Form default constructor called for " << this->_name
			<< " with signing grade " << this->_gradeSign <<
			" and execution grade " << this->_gradeExecute << std::endl;
}

Form::Form( std::string const &name ): _name(name), _signed(false), _gradeSign(150), _gradeExecute(150) {
	std::cout << "Form  constructor called for " << this->_name
			<< " with signing grade " << this->_gradeSign <<
			" and execution grade " << this->_gradeExecute << std::endl;
}

Form::Form( int const gradeSign, int const gradeExecute ): _name("formName"), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	if(this->_gradeExecute <_maxGrade || this->_gradeSign < _maxGrade )
		throw(GradeTooHighException());
	if(this->_gradeExecute >_minGrade || this->_gradeSign >_minGrade )
		throw(GradeTooLowException());
	std::cout << "Form  constructor called for " << this->_name
			<< " with signing grade " << this->_gradeSign <<
			" and execution grade " << this->_gradeExecute << std::endl;
}

Form::Form( std::string const &name, int const gradeSign, int const gradeExecute ): _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	if(this->_gradeExecute <_maxGrade || this->_gradeSign < _maxGrade )
		throw(GradeTooHighException());
	if(this->_gradeExecute >_minGrade || this->_gradeSign >_minGrade )
		throw(GradeTooLowException());
	std::cout << "Form  constructor called for " << this->_name
			<< " with signing grade " << this->_gradeSign <<
			" and execution grade " << this->_gradeExecute << std::endl;
}

Form::Form (const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeSign(copy._gradeSign), _gradeExecute(copy._gradeExecute) {
	std::cout << "Form copy constructor called with " << this->_name << std::endl;
}

Form	&Form::operator=( const Form &rhs ) {
	if (this !=&rhs)
		this->_signed = rhs._signed;
	return (*this);
}

Form::~Form() {
	std::cout << "Form destructor called for " << this->_name << std::endl;
}

void	Form::beSigned(Bureaucrat &signatory) {
	if (signatory.getGrade() > this->_gradeSign)
		throw (Form::GradeTooLowException());
	this->_signed = true;
}

std::string const &Form::getName() const {
	return(this->_name);
}

std::string	Form::getSigned() const {
	if (this->_signed == true)
		return("signed");
	else
		return("not signed");
}

int const &Form::getGradeSign() const {
	return( this->_gradeSign);
}

int const &Form::getGradeExecute() const {
	return( this->_gradeExecute);
}

const char *Form::GradeTooLowException::what() const throw() {
	return( MYRED "Grade is Too Low" MYEOF);
}

const char *Form::GradeTooHighException::what() const throw() {
	return(MYRED "Grade is Too High" MYEOF);
}

std::ostream	&operator<<( std::ostream &op, const Form &copy ) {
	return( op << MYBLUE << copy.getName() << " is " << copy.getSigned() << ", form signing grade " << copy.getGradeSign() << ", form execution grade " << copy.getGradeExecute() << MYEOF << std::endl);
}
