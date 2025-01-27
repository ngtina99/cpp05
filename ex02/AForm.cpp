/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:34:37 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/19 01:15:36 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("defaultForm"), _signed(false), _gradeSign(150), _gradeExecute(150) {
	std::cout << "AForm default constructor called for " << this->_name
			<< " with signing grade " << this->_gradeSign <<
			" and execution grade " << this->_gradeExecute << std::endl;
}

AForm::AForm( std::string const &name ): _name(name), _signed(false), _gradeSign(150), _gradeExecute(150) {
	std::cout << "AForm  constructor called for " << this->_name
			<< " with signing grade " << this->_gradeSign <<
			" and execution grade " << this->_gradeExecute << std::endl;
}

AForm::AForm( int const gradeSign, int const gradeExecute ): _name("formName"), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	if(this->_gradeExecute <_maxGrade || this->_gradeSign < _maxGrade )
		throw(GradeTooHighException());
	if(this->_gradeExecute >_minGrade || this->_gradeSign >_minGrade ) //change this try catch maybe later to fix
		throw(GradeTooLowException());
	std::cout << "AForm  constructor called for " << this->_name
			<< " with signing grade " << this->_gradeSign <<
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

AForm::AForm( std::string const &name, int const gradeSign, int const gradeExecute ): _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	if(this->_gradeExecute <_maxGrade || this->_gradeSign < _maxGrade )
		throw(GradeTooHighException());
	if(this->_gradeExecute >_minGrade || this->_gradeSign >_minGrade )
		throw(GradeTooLowException());
	std::cout << "AForm  constructor called for " << this->_name
			<< " with signing grade " << this->_gradeSign <<
			" and execution grade " << this->_gradeExecute << std::endl;
}

AForm::AForm (const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeSign(copy._gradeSign), _gradeExecute(copy._gradeExecute) {
	std::cout << "AForm copy constructor called with " << this->_name << std::endl;
}

AForm	&AForm::operator=( const AForm &rhs ) {
	if (this !=&rhs)
		// this->_gradeExecute = rhs._gradeExecute;
		// this->_gradeSign = rhs._gradeExecute;
		this->_signed = rhs._signed; //only non-const memeber!!
	return (*this);
}

AForm::~AForm() {
	std::cout << "AForm destructor called for " << this->_name << std::endl;
}

void	AForm::beSigned(Bureaucrat &signatory) {
	if (signatory.getGrade() > this->_gradeSign)
		throw (AForm::GradeTooLowException());
	this->_signed = true;
}

std::string const &AForm::getName() const {
	return(this->_name);
}

std::string	AForm::getSigned() const {
	if (this->_signed == true)
		return("signed");
	else
		return("not signed");
}

int const AForm::getGradeSign() const {
	return( this->_gradeSign);
}

int const AForm::getGradeExecute() const {
	return( this->_gradeExecute);
}

bool AForm::getSignedBool() const {
	return( this->_signed);
}

const char *AForm::GradeTooLowException::what() const throw() {
	return( MYRED "Grade is Too Low" MYEOF);
}

const char *AForm::GradeTooHighException::what() const throw() {
	return(MYRED "Grade is Too High" MYEOF);
}

const char *AForm::FormNotSignedException::what() const throw() {
	return(MYRED "Form is Not Signed" MYEOF);
}

std::ostream	&operator<<( std::ostream &op, const AForm &copy ) {
	return( op << MYBLUE << copy.getName() << " is " << copy.getSigned() << ", form signing grade " << copy.getGradeSign() << ", form execution grade " << copy.getGradeExecute() << MYEOF << std::endl);
}
