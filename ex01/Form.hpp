/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:34:34 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/19 00:04:04 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {

	private:

		std::string const _name;
		bool	_signed; //default false at construction
		int const _gradeSign; // constant grade required to sign it.
		int const _gradeExecute; // constant grade required to execute it.
		static const int _minGrade = 150;
		static const int _maxGrade = 1;

	public:

		/* Orthodox Canonical Form */
		/* Default Constructor with no parameter */
		Form ();
		/* Default Constructor with parameter */
		Form ( const std:: string &name );
		Form( int const gradeSign, int const gradeExecute );
		Form( const std:: string &name, int const gradeSign, int const gradeExecute );
		/* Copy Constructor */
		Form ( const Form &copy); /* passing the existing object */
		/* Copy Assignment Operator */
		Form	&operator=( const Form &rhs );
		/* Destructor */
		~Form();

		std::string const &getName() const;
		std::string getSigned() const;
		int const getGradeSign() const;
		int const getGradeExecute() const;

		void	beSigned(Bureaucrat &copy);

		class GradeTooHighException : public std::exception {
			
			public:

				const char *what() const throw();

		};

		class GradeTooLowException : public std::exception {

			public:

				const char *what() const throw();
		};
};

std::ostream &operator<<( std::ostream &op, const Form &copy);

#endif