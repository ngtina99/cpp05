/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:12:13 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/15 07:29:59 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	
	private:
	
		std::string const _name;
		int grade;

	public:

		/* Orthodox Canonical Form */
		/* Default Constructor with no parameter */
		Bureaucrat ();
		/* Default Constructor with parameter */
		Bureaucrat( std:: string &name );
		Bureaucrat( int grade );
		Bureaucrat( std:: string &name, int grade );
		/* Copy Constructor */
		Bureaucrat ( const Bureaucrat &copy); /* passing the existing object */
		/* Copy Assignment Operator */
		Bureaucrat	&operator=( const Bureaucrat &rhs );
		/* Destructor */
		~Bureaucrat();

		std::string const	&getName() const;
		int const getGrade() const;
		
		
		
} 

std::ostream &operator<<( std::ostream &op, const Bureaucrat &copy)

#endif