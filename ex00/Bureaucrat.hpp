/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:12:13 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/15 08:53:20 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	
	private:
	
		static const int _maxGrade = 1;
		static const int _minGrade = 150;
		std::string const _name;
		int _grade;

	public:

		/* Orthodox Canonical Form */
		/* Default Constructor with no parameter */
		Bureaucrat ();
		/* Default Constructor with parameter */
		Bureaucrat( const std:: string &name );
		Bureaucrat( int grade );
		Bureaucrat( const std:: string &name, int grade );
		/* Copy Constructor */
		Bureaucrat ( const Bureaucrat &copy); /* passing the existing object */
		/* Copy Assignment Operator */
		Bureaucrat	&operator=( const Bureaucrat &rhs );
		/* Destructor */
		~Bureaucrat();

		std::string const	&getName() const;
		int const getGrade() const;

		void	incrGrade();
		void	decrGrade();
		
		/* Bureaucrat::GradeTooHighException
		Bureaucrat::GradeTooLowException nested classes */

		class GradeTooHighException : public std::exception {
			
			public:

				const char *what() const throw();

		};

		class GradeTooLowException : public std::exception {

			public:

				const char *what() const throw();
		};

};

std::ostream &operator<<( std::ostream &op, const Bureaucrat &copy)

#endif